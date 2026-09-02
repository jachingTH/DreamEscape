#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemData.h"
#include "InventoryBarWidget.generated.h"

class UInventorySlotWidget;

UCLASS()
class DREAMESCAPE_API UInventoryBarWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInventorySlotWidget> Slot_0;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInventorySlotWidget> Slot_1;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInventorySlotWidget> Slot_2;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInventorySlotWidget> Slot_3;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInventorySlotWidget> Slot_4;
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInventorySlotWidget> Slot_5;

	UPROPERTY()
	TArray<TObjectPtr<UInventorySlotWidget>> SlotArray;

public:
	UFUNCTION()
	void UpdateSelection(int32 NewSlotIndex);

	UFUNCTION()
	void UpdateSlotContent(int32 SlotIndex, const FInventorySlotData& Data);
};