// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "ItemData.h" // 인벤토리 구조체 헤더 (반드시 .generated.h 바로 위에 위치)
#include "DreamEscapeCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
class UDreamEscapeInGameHUD;

struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

// =============================================================================
// [UI 연동용 다이내믹 멀티캐스트 델리게이트 선언]
// - UMG 위젯 및 블루프린트에서 바인딩(AddDynamic)할 수 있도록 전역 매크로로 선언합니다.
// =============================================================================
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeChangedSignature, float, CurrentValue, float, MaxValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotSelectedSignature, int32, NewSlotIndex);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventorySlotUpdatedSignature, int32, SlotIndex, const FInventorySlotData&, NewData);

UCLASS(config = Game)
class DREAMESCAPE_API ADreamEscapeCharacter : public ACharacter
{
	GENERATED_BODY()

	/*
	 * =========================================================================
	 * [헤더 파일 접근 지정자(Access Specifier) 분리 설계 의도]
	 *
	 * 1. 기능(도메인)별 응집도 강화:
	 *    - 이동 컴포넌트, 입력, 캐릭터 스탯, 인벤토리, UI 연동을 독립적인 블록으로 묶어
	 *      특정 시스템을 수정할 때 관련 변수와 함수를 한 블록 내에서 파악할 수 있도록 구성했습니다.
	 *
	 * 2. 캡슐화(Encapsulation) 원칙 준수:
	 *    - 외부에서 직접 수정하면 안 되는 내부 데이터(CurrentHealth, InventorySlots)는 protected로 보호하고,
	 *      외부 액터나 UI가 구독해야 하는 델리게이트와 조작 함수(ModifyHealth 등)는 public으로 개방했습니다.
	 *
	 * 3. 엔진 템플릿과의 호환성 유지:
	 *    - 에픽게임즈 기본 1인칭 캐릭터 템플릿의 계층 구조를 보존하면서 신규 시스템을 모듈 형태로 덧붙였습니다.
	 * =========================================================================
	 */

	 // -------------------------------------------------------------------------
	 // [1. 엔진 기본 컴포넌트 및 입력 프로퍼티 (Private / AllowPrivateAccess)]
	 // - 외부 클래스의 직접 수정을 차단하여 캡슐화를 보호하되,
	 //   에디터 블루프린트 디테일 패널에서는 수정할 수 있도록 AllowPrivateAccess 메타태그를 적용합니다.
	 // -------------------------------------------------------------------------
	 /** 1인칭 뷰 메시 컴포넌트 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* FirstPersonMesh;

	/** 1인칭 카메라 컴포넌트 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	/** 향상된 입력 매핑 컨텍스트 (IMC_Default) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** 점프 입력 액션 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** 이동 입력 액션 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** 시점 회전 입력 액션 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	/** 마우스 룩 입력 액션 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* MouseLookAction;

	// -------------------------------------------------------------------------
	// [2. 생성자 및 엔진 기본 라이프사이클 (Public / Protected)]
	// - 생성자는 엔진이 인스턴스화해야 하므로 public으로 선언합니다.
	// - BeginPlay, Tick, SetupPlayerInputComponent는 엔진 프레임워크 오버라이드 함수이므로 protected로 보호합니다.
	// -------------------------------------------------------------------------
public:
	ADreamEscapeCharacter();

	// [추가] 매 프레임 실시간 스태미나 증감 연산을 위한 Tick 함수 선언
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	/** Enhanced Input 내부 바인딩 처리 함수 */
	void MoveInput(const FInputActionValue& Value);
	void LookInput(const FInputActionValue& Value);

	// -------------------------------------------------------------------------
	// [3. 확장 가능한 캐릭터 동작 인터페이스 (Public Virtual)]
	// - 파생 클래스(Shooter, Horror 캐릭터 등) 또는 외부 컨트롤러에서
	//   오버라이드 및 호출할 수 있도록 public 가상 함수로 개방합니다.
	// -------------------------------------------------------------------------
public:
	UFUNCTION(BlueprintCallable, Category = "Movement")
	virtual void DoMove(float Right, float Forward);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	virtual void DoAim(float Yaw, float Pitch);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	virtual void DoJumpStart();

	UFUNCTION(BlueprintCallable, Category = "Movement")
	virtual void DoJumpEnd();

	// -------------------------------------------------------------------------
	// [4. UI 연동용 이벤트 디스패처 (Public)]
	// - UMG HUD 위젯(`PlayerStatusWidget`, `InventoryBarWidget`)이
	//   캐릭터의 상태 변화를 실시간으로 구독(AddDynamic)할 수 있도록 public으로 개방합니다.
	// -------------------------------------------------------------------------
public:
	/** 체력 변경 시 브로드캐스트 (CurrentHealth, MaxHealth) */
	UPROPERTY(BlueprintAssignable, Category = "Events|Attributes")
	FOnAttributeChangedSignature OnHealthChanged;

	/** 스태미나 변경 시 브로드캐스트 (CurrentStamina, MaxStamina) */
	UPROPERTY(BlueprintAssignable, Category = "Events|Attributes")
	FOnAttributeChangedSignature OnStaminaChanged;

	/** 선택된 인벤토리 슬롯 번호 변경 시 브로드캐스트 (NewSlotIndex) */
	UPROPERTY(BlueprintAssignable, Category = "Events|Inventory")
	FOnSlotSelectedSignature OnSlotSelected;

	/** 특정 인벤토리 슬롯 데이터 갱신 시 브로드캐스트 (SlotIndex, NewData) */
	UPROPERTY(BlueprintAssignable, Category = "Events|Inventory")
	FOnInventorySlotUpdatedSignature OnInventorySlotUpdated;

	// -------------------------------------------------------------------------
	// [5. 캐릭터 핵심 스탯, 이동 속도, 인벤토리 데이터, HUD 인스턴스 (Protected)]
	// - 외부에서 직접 변수를 수정(오염)하지 못하도록 보호합니다.
	// - 파생 클래스(Child Class)에서는 자유롭게 접근할 수 있도록 protected를 유지합니다.
	// -------------------------------------------------------------------------
protected:
	// 체력 수치
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Health")
	float MaxHealth = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes|Health")
	float CurrentHealth = 100.0f;

	// 스태미나 수치
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Stamina")
	float MaxStamina = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes|Stamina")
	float CurrentStamina = 100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Stamina")
	float StaminaDrainRate = 25.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Stamina")
	float StaminaRegenRate = 15.0f;

	// [추가] 스프린트를 재시작할 수 있는 최소 요구 스태미나
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Stamina")
	float MinStaminaToSprint = 20.0f;

	// [추가] 걷기 / 달리기 기본 이동 속도 및 상태 플래그
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float WalkSpeed = 400.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")
	float SprintSpeed = 750.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	bool bIsSprinting = false;

	// [추가] 매 프레임 스태미나 소모/회복 계산 및 UI 브로드캐스트 처리 함수
	void UpdateStamina(float DeltaTime);

	// 6칸 인벤토리 데이터 배열 및 활성 슬롯 인덱스
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<FInventorySlotData> InventorySlots;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	int32 CurrentSelectedSlotIndex = 0;

	// Phase 4: 마스터 HUD 클래스 템플릿(BP 할당용) 및 뷰포트에 띄운 인스턴스
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UDreamEscapeInGameHUD> HUDWidgetClass;

	UPROPERTY(BlueprintReadOnly, Category = "UI")
	TObjectPtr<UDreamEscapeInGameHUD> HUDWidget;

	// -------------------------------------------------------------------------
	// [6. 게임플레이 로직 및 외부 호출 인터페이스 (Public Functions)]
	// - 대미지 처리, 아이템 획득, 슬롯 선택 등 외부 액터/컨트롤러가
	//   안전하게 캐릭터의 상태를 변경할 수 있도록 제공하는 공개 메서드입니다.
	// -------------------------------------------------------------------------
public:
	/** 체력 가감 및 델리게이트 브로드캐스트 */
	UFUNCTION(BlueprintCallable, Category = "Attributes|Health")
	void ModifyHealth(float Amount);

	/** 스태미나 가감 및 델리게이트 브로드캐스트 */
	UFUNCTION(BlueprintCallable, Category = "Attributes|Stamina")
	void ModifyStamina(float Amount);

	// [추가] 스프린트 시작 / 중단 함수 (Shift 키 바인딩용)
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void StartSprint();

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void StopSprint();

	/** 인벤토리 슬롯 활성화 (0~5) 및 델리게이트 브로드캐스트 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SelectInventorySlot(int32 SlotIndex);

	/** 인벤토리 슬롯 아이템 설정 및 델리게이트 브로드캐스트 */
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetInventorySlot(int32 SlotIndex, const FInventorySlotData& NewItemData);

	// -------------------------------------------------------------------------
	// [7. 상태 조회용 게터 함수 (Public Const / BlueprintPure)]
	// - 원본 변수를 수정하지 않고 안전하게 값만 읽어갈 수 있도록 const 및 Pure로 제공합니다.
	// -------------------------------------------------------------------------
	USkeletalMeshComponent* GetFirstPersonMesh() const { return FirstPersonMesh; }
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
	UDreamEscapeInGameHUD* GetHUDWidget() const { return HUDWidget; }

	UFUNCTION(BlueprintPure, Category = "Attributes")
	float GetHealthPercent() const { return (MaxHealth > 0.0f) ? (CurrentHealth / MaxHealth) : 0.0f; }

	UFUNCTION(BlueprintPure, Category = "Attributes")
	float GetStaminaPercent() const { return (MaxStamina > 0.0f) ? (CurrentStamina / MaxStamina) : 0.0f; }

	UFUNCTION(BlueprintPure, Category = "Movement")
	bool IsSprinting() const { return bIsSprinting; }

	UFUNCTION(BlueprintPure, Category = "Inventory")
	int32 GetSelectedSlotIndex() const { return CurrentSelectedSlotIndex; }
};