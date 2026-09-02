// ItemData.h
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemData.generated.h"

/**
 * 인벤토리 6칸 슬롯 각각에 들어갈 아이템 데이터 구조체
 */
USTRUCT(BlueprintType)
struct FInventorySlotData
{
    GENERATED_BODY()

    // 아이템 고유 식별자 (비어있으면 NAME_None)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    FName ItemID = NAME_None;

    // UI에 출력할 2D 아이콘 텍스처 (UE5에서는 TObjectPtr 권장)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TObjectPtr<UTexture2D> ItemIcon = nullptr;

    // 현재 중첩 수량 (예: 배터리 x2, 주사기 x1)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    int32 StackCount = 0;

    // 최대 중첩 가능 수량
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    int32 MaxStackCount = 1;

    // 기본 생성자
    FInventorySlotData()
        : ItemID(NAME_None)
        , ItemIcon(nullptr)
        , StackCount(0)
        , MaxStackCount(1)
    {
    }

    // 편의용 매개변수 생성자
    FInventorySlotData(FName InID, UTexture2D* InIcon, int32 InCount, int32 InMaxCount = 1)
        : ItemID(InID)
        , ItemIcon(InIcon)
        , StackCount(InCount)
        , MaxStackCount(InMaxCount)
    {
    }

    // 슬롯이 비어있는지 확인하는 헬퍼 함수
    bool IsEmpty() const
    {
        return ItemID.IsNone() || StackCount <= 0;
    }
};