#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LobbyTypes.h"
#include "LobbyGameState.generated.h"

// [1] 맵 변경 알림 델리게이트 선언
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMapChanged, int32, NewMapIndex);

UCLASS()
class DREAMESCAPE_API ALobbyGameState : public AGameStateBase
{
    GENERATED_BODY()

public:
    ALobbyGameState();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    // 현재 선택된 맵 인덱스 (서버 -> 클라이언트 복제)
    UPROPERTY(ReplicatedUsing = OnRep_SelectedMapIndex, BlueprintReadOnly, Category = "Lobby")
    int32 SelectedMapIndex = 0;

    UFUNCTION()
    void OnRep_SelectedMapIndex();

    // 맵 목록 데이터 (클라이언트/서버 공용 접근)
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lobby | Maps")
    TArray<FMapSelectionData> AvailableMaps;

    // UI 갱신 바인딩용 델리게이트
    UPROPERTY(BlueprintAssignable, Category = "Lobby")
    FOnMapChanged OnMapChanged;
};