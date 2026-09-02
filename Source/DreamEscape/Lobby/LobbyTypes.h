#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "LobbyTypes.generated.h"

class UWorld;
class UTexture2D;

// [1] 로비 3D 버튼 종류 열거형
UENUM(BlueprintType)
enum class ELobbyButtonType : uint8
{
    Prev UMETA(DisplayName = "Prev"),
    Next UMETA(DisplayName = "Next"),
    Confirm UMETA(DisplayName = "Confirm")
};

// [2] 맵 선택 데이터 구조체
USTRUCT(BlueprintType)
struct FMapSelectionData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapData")
    FString MapDisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapData")
    TSoftObjectPtr<UWorld> MapLevelAsset;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapData")
    TSoftObjectPtr<UTexture2D> MapThumbnail;
};