// LobbyPlayerState.h
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "LobbyPlayerState.generated.h"

UCLASS()
class DREAMESCAPE_API ALobbyPlayerState : public APlayerState
{
    GENERATED_BODY()

public:
    ALobbyPlayerState();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    // ★ 부모(APlayerState)의 CopyProperties를 오버라이드 선언
    virtual void CopyProperties(APlayerState* PlayerState) override;

    UPROPERTY(ReplicatedUsing = OnRep_IsReady, BlueprintReadOnly, Category = "Lobby")
    bool bIsReady = false;

    UFUNCTION()
    void OnRep_IsReady();

    UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "Lobby")
    void Server_SetReady(bool bNewReady);

    UFUNCTION(BlueprintCallable, Category = "Lobby")
    bool IsPlayerReady() const { return bIsReady; }

    UFUNCTION(BlueprintCallable, Category = "Lobby")
    void SetPlayerReady(bool bNewReady) { bIsReady = bNewReady; }
};