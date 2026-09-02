#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemData.h"
#include "InventorySlotWidget.generated.h"

class UImage;
class UBorder;
class UTextBlock;

UCLASS()
class DREAMESCAPE_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_ItemIcon;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UBorder> Border_SelectedHighlight;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_SlotNumber;

	void SetSlotData(const FInventorySlotData& Data);
	void SetSelected(bool bIsSelected);
	void SetSlotNumber(int32 Number);
};