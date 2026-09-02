#include "Player/InGameCharacter.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"

AInGameCharacter::AInGameCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    // 액터 및 이동 컴포넌트 네트워크 복제 활성화
    bReplicates = true;
    SetReplicateMovement(true);

    CurrentHealth = MaxHealth;
}

void AInGameCharacter::BeginPlay()
{
    Super::BeginPlay();
}

// 복제 대상 프로퍼티 등록
void AInGameCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    // 체력 변수를 모든 접속 클라이언트에 복제
    DOREPLIFETIME(AInGameCharacter, CurrentHealth);
}

// 클라이언트에서 체력 값이 변경되었을 때 실행되는 콜백
void AInGameCharacter::OnRep_CurrentHealth()
{
    UE_LOG(LogTemp, Log, TEXT("[Client] 체력 동기화 완료: %f"), CurrentHealth);
    // UI 체력 바 업데이트 로직 호출 가능
}

// [서버 실행] 클라이언트의 입력 유효성 검증
bool AInGameCharacter::Server_PerformAction_Validate(const FVector_NetQuantize& TargetLocation)
{
    // 공격 사거리 검증 (예: 5000 유닛 이하인지 확인)
    return FVector::DistSquared(GetActorLocation(), TargetLocation) <= FMath::Square(5000.0f);
}

// [서버 실행] 실제 대미지 연산 및 상태 변경
void AInGameCharacter::Server_PerformAction_Implementation(const FVector_NetQuantize& TargetLocation)
{
    UE_LOG(LogTemp, Warning, TEXT("[Server] 액션 연산 실행 (권한자)"));

    // 서버 권한으로 대상 대미지 처리 (피격 시 대상의 CurrentHealth 차감 등)
    // CurrentHealth = FMath::Clamp(CurrentHealth - 10.0f, 0.0f, MaxHealth);

    // 모든 클라이언트에게 연출 브로드캐스트
    Multicast_PlayActionFX(TargetLocation);
}

// [모든 클라이언트 실행] 시각/음향 연출 처리
void AInGameCharacter::Multicast_PlayActionFX_Implementation(const FVector_NetQuantize& TargetLocation)
{
    // 로컬 사운드 재생, 나이아가라/파티클 이펙트 스폰
    UE_LOG(LogTemp, Log, TEXT("[Client/Host] 액션 이펙트 재생 위치: %s"), *TargetLocation.ToString());
}

