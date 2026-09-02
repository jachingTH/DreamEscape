#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InGameCharacter.generated.h"

UCLASS()
class DREAMESCAPE_API AInGameCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AInGameCharacter();

    // 1. 프로퍼티 복제 규칙 등록 함수 오버라이드
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    // 2. 동기화 변수 (Replication + OnRep)
    UPROPERTY(ReplicatedUsing = OnRep_CurrentHealth, BlueprintReadOnly, Category = "Stats")
    float CurrentHealth;

    UFUNCTION()
    void OnRep_CurrentHealth();

    // 3. 서버 공격 요청 (Server RPC)
    UFUNCTION(Server, Reliable, WithValidation)
    void Server_PerformAction(const FVector_NetQuantize& TargetLocation);

    // 4. 모든 클라이언트 연출 재생 (Multicast RPC)
    UFUNCTION(NetMulticast, Unreliable)
    void Multicast_PlayActionFX(const FVector_NetQuantize& TargetLocation);

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, Category = "Stats")
    float MaxHealth = 100.0f;
};