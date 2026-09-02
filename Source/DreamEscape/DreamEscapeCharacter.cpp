// Copyright Epic Games, Inc. All Rights Reserved.

#include "DreamEscapeCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"

// =============================================================================
// [Phase 4: UMG 및 HUD 서브시스템 필수 헤더]
// - CreateWidget 및 뷰포트 등록을 위한 UserWidget 헤더
// - 마스터 HUD 및 하위 상태창/인벤토리바 위젯 클래스 헤더
// =============================================================================
#include "Blueprint/UserWidget.h"
#include "DreamEscapeInGameHUD.h"
#include "PlayerStatusWidget.h"
#include "InventoryBarWidget.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ADreamEscapeCharacter 생성자

ADreamEscapeCharacter::ADreamEscapeCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// 1. 캡슐 콜리전 세팅
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// 2. 1인칭 카메라를 '캡슐'에 직접 부착 (소켓 의존성 제거, 안정적인 눈높이 고정)
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(0.f, 0.f, 64.f)); // 표준 1인칭 눈높이
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// 3. 엔진 기본 3인칭 전신 메시 숨김 처리 (본인 시야에서 가림)
	GetMesh()->SetOwnerNoSee(true);

	// 4. 1인칭 전용 팔 메시 세팅 (카메라에 부착하여 시점 이동과 일체화)
	FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("First Person Mesh"));
	FirstPersonMesh->SetupAttachment(FirstPersonCameraComponent);
	FirstPersonMesh->SetOnlyOwnerSee(true);
	FirstPersonMesh->SetCollisionProfileName(FName("NoCollision"));
	FirstPersonMesh->bCastDynamicShadow = false;
	FirstPersonMesh->CastShadow = false;
	FirstPersonMesh->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	// 5. 기본 스탯 수치 초기화
	MaxHealth = 100.0f;
	CurrentHealth = 100.0f;
	MaxStamina = 100.0f;
	CurrentStamina = 100.0f;
	StaminaDrainRate = 20.0f;
	StaminaRegenRate = 15.0f;
	CurrentSelectedSlotIndex = 0;

	CurrentHealth = MaxHealth;
	CurrentStamina = MaxStamina;
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	}
}

//////////////////////////////////////////////////////////////////////////
// 게임 시작 라이프사이클 (BeginPlay)

void ADreamEscapeCharacter::BeginPlay()
{
	Super::BeginPlay();

	// -------------------------------------------------------------------------
	// [1. Enhanced Input 매핑 컨텍스트(IMC_Default) 등록]
	// -------------------------------------------------------------------------
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		// 마우스 커서 비활성화 및 뷰포트 고정
		PlayerController->bShowMouseCursor = false;
		FInputModeGameOnly InputModeData;
		PlayerController->SetInputMode(InputModeData);

		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			if (DefaultMappingContext)
			{
				Subsystem->AddMappingContext(DefaultMappingContext, 0);
			}
		}
	}

	// -------------------------------------------------------------------------
	// [2. 인벤토리 6칸 슬롯 메모리 초기화]
	// -------------------------------------------------------------------------
	InventorySlots.Init(FInventorySlotData(), 6);

	// -------------------------------------------------------------------------
	// [3. Phase 4: 마스터 HUD 위젯 동적 생성 및 뷰포트 등록]
	// - 서버/데디케이트 환경이 아닌 '로컬 플레이어 컨트롤러'일 때만 UI를 인스턴스화합니다.
	// - BP 에디터에서 HUDWidgetClass(WBP_InGameHUD)가 유효하게 지정되었는지 검증합니다.
	// -------------------------------------------------------------------------
	APlayerController* PC = Cast<APlayerController>(GetController());
	if (PC && PC->IsLocalController() && HUDWidgetClass)
	{
		HUDWidget = CreateWidget<UDreamEscapeInGameHUD>(PC, HUDWidgetClass);
		if (HUDWidget)
		{
			// 뷰포트 최상단 렌더링 레이어로 등록
			HUDWidget->AddToViewport();

			// -----------------------------------------------------------------
			// [4. 서브 위젯 이벤트 바인딩 (이벤트 드리븐 구조)]
			// - 캐릭터의 수치 변경 델리게이트를 위젯의 갱신 함수에 1:1로 직접 연결합니다.
			// - Tick을 사용하지 않고 변경 시점에만 호출되어 렌더링 비용을 최소화합니다.
			// -----------------------------------------------------------------
			if (HUDWidget->WBP_PlayerStatus)
			{
				OnHealthChanged.AddDynamic(HUDWidget->WBP_PlayerStatus, &UPlayerStatusWidget::UpdateHealth);
				OnStaminaChanged.AddDynamic(HUDWidget->WBP_PlayerStatus, &UPlayerStatusWidget::UpdateStamina);
			}

			if (HUDWidget->WBP_InventoryBar)
			{
				OnSlotSelected.AddDynamic(HUDWidget->WBP_InventoryBar, &UInventoryBarWidget::UpdateSelection);
				OnInventorySlotUpdated.AddDynamic(HUDWidget->WBP_InventoryBar, &UInventoryBarWidget::UpdateSlotContent);
			}
		}
	}

	// -------------------------------------------------------------------------
	// [5. 게임 시작 시점 초기 UI 상태 동기화 브로드캐스트]
	// - 위젯 바인딩 완료 직후 최초 1회 브로드캐스트하여 초기값(100%, 1번 슬롯 등)을 화면에 반영합니다.
	// -------------------------------------------------------------------------
	OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
	OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);
	OnSlotSelected.Broadcast(CurrentSelectedSlotIndex);

	for (int32 i = 0; i < InventorySlots.Num(); ++i)
	{
		OnInventorySlotUpdated.Broadcast(i, InventorySlots[i]);
	}
}

void ADreamEscapeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 실시간 스태미나 증감 계산
	UpdateStamina(DeltaTime);
}

//////////////////////////////////////////////////////////////////////////
// Enhanced Input 바인딩 및 핸들러

void ADreamEscapeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// 점프
		if (JumpAction)
		{
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ADreamEscapeCharacter::DoJumpStart);
			EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ADreamEscapeCharacter::DoJumpEnd);
		}

		// 이동 (WASD)
		if (MoveAction)
		{
			EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADreamEscapeCharacter::MoveInput);
		}

		// 시점 조작 (마우스)
		if (LookAction)
		{
			EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ADreamEscapeCharacter::LookInput);
		}
		if (MouseLookAction)
		{
			EnhancedInputComponent->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &ADreamEscapeCharacter::LookInput);
		}
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component!"), *GetNameSafe(this));
	}
}

void ADreamEscapeCharacter::MoveInput(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();
	DoMove(MovementVector.X, MovementVector.Y);
}

void ADreamEscapeCharacter::LookInput(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	DoAim(LookAxisVector.X, LookAxisVector.Y);
}

void ADreamEscapeCharacter::DoMove(float Right, float Forward)
{
	if (GetController())
	{
		AddMovementInput(GetActorRightVector(), Right);
		AddMovementInput(GetActorForwardVector(), Forward);
	}
}

void ADreamEscapeCharacter::DoAim(float Yaw, float Pitch)
{
	if (GetController())
	{
		AddControllerYawInput(Yaw);
		AddControllerPitchInput(Pitch);
	}
}

void ADreamEscapeCharacter::DoJumpStart()
{
	Jump();
}

void ADreamEscapeCharacter::DoJumpEnd()
{
	StopJumping();
}

//////////////////////////////////////////////////////////////////////////
// 게임플레이 스탯 및 인벤토리 제어 로직

void ADreamEscapeCharacter::ModifyHealth(float Amount)
{
	if (FMath::IsNearlyZero(Amount)) return;

	CurrentHealth = FMath::Clamp(CurrentHealth + Amount, 0.0f, MaxHealth);

	// 체력 변동 시 등록된 위젯으로 이벤트 전파
	OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
}

void ADreamEscapeCharacter::ModifyStamina(float Amount)
{
	if (FMath::IsNearlyZero(Amount)) return;

	CurrentStamina = FMath::Clamp(CurrentStamina + Amount, 0.0f, MaxStamina);

	// 스태미나 변동 시 등록된 위젯으로 이벤트 전파
	OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);
}

void ADreamEscapeCharacter::SelectInventorySlot(int32 SlotIndex)
{
	// 0~5번 슬롯 범위 검증 및 동일 슬롯 중복 선택 방지
	if (SlotIndex >= 0 && SlotIndex < 6 && CurrentSelectedSlotIndex != SlotIndex)
	{
		CurrentSelectedSlotIndex = SlotIndex;
		OnSlotSelected.Broadcast(CurrentSelectedSlotIndex);
	}
}

void ADreamEscapeCharacter::SetInventorySlot(int32 SlotIndex, const FInventorySlotData& NewItemData)
{
	if (InventorySlots.IsValidIndex(SlotIndex))
	{
		InventorySlots[SlotIndex] = NewItemData;
		OnInventorySlotUpdated.Broadcast(SlotIndex, InventorySlots[SlotIndex]);
	}
}

// -------------------------------------------------------------------------
// [스프린트 및 스태미나 실시간 연산]
// -------------------------------------------------------------------------

void ADreamEscapeCharacter::StartSprint()
{
	// 최소 요구 스태미나 이상일 때만 달리기 발동
	if (CurrentStamina > MinStaminaToSprint)
	{
		bIsSprinting = true;
		if (GetCharacterMovement())
		{
			GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
		}
	}
}

void ADreamEscapeCharacter::StopSprint()
{
	bIsSprinting = false;
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	}
}

void ADreamEscapeCharacter::UpdateStamina(float DeltaTime)
{
	// 실제 이동 중인지 검사 (서서 Shift만 누른 상태 방지)
	const bool bIsMoving = GetVelocity().Size2D() > 10.0f;
	const bool bCurrentlySprinting = bIsSprinting && bIsMoving;

	float PrevStamina = CurrentStamina;

	if (bCurrentlySprinting)
	{
		// 1. 달리는 중: 실시간 소모
		CurrentStamina = FMath::Clamp(CurrentStamina - (StaminaDrainRate * DeltaTime), 0.0f, MaxStamina);

		// 스태미나 바닥나면 강제 걷기
		if (CurrentStamina <= 0.0f)
		{
			StopSprint();
		}
	}
	else
	{
		// 2. 걷기/정지: 실시간 자동 회복
		if (CurrentStamina < MaxStamina)
		{
			CurrentStamina = FMath::Clamp(CurrentStamina + (StaminaRegenRate * DeltaTime), 0.0f, MaxStamina);
		}
	}

	// 수치가 변했을 때만 UI 업데이트 브로드캐스트
	if (!FMath::IsNearlyEqual(PrevStamina, CurrentStamina, 0.01f))
	{
		OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);
	}
}