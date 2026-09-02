// LobbyGameMode.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LobbyTypes.h"
#include "LobbyGameMode.generated.h"


UCLASS()
class DREAMESCAPE_API ALobbyGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    ALobbyGameMode();

    // 호스트가 호출하는 게임 시작 함수
    UFUNCTION(BlueprintCallable, Category = "Lobby")
    void StartGame();

    // 방장이 UI에서 맵 번호를 고를 때 호출하는 함수
    UFUNCTION(BlueprintCallable, Category = "Lobby")
    void SetSelectedMap(int32 MapIndex);

    UFUNCTION(BlueprintCallable, Category = "Lobby")
    void NextMap();

    UFUNCTION(BlueprintCallable, Category = "Lobby")
    void PrevMap();

    // 에디터에서 자유롭게 등록하는 맵 리스트
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lobby | Maps")
    TArray<FMapSelectionData> AvailableMaps;

    // UI에 표시될 맵 이름 (예: "폐쇄된 병원", "도심 사격장")
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapData")
    FString MapDisplayName;

    // 실제 이동할 레벨 에셋
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapData")
    TSoftObjectPtr<UWorld> MapLevelAsset;

    // UI에 띄울 썸네일 이미지 (선택 사항)
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapData")
    TSoftObjectPtr<UTexture2D> MapThumbnail;

    bool CheckAllPlayersReady() const;
};