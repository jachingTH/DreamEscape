#include "InventoryBarWidget.h"
#include "InventorySlotWidget.h"

void UInventoryBarWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SlotArray.Empty();
	SlotArray.Add(Slot_0);
	SlotArray.Add(Slot_1);
	SlotArray.Add(Slot_2);
	SlotArray.Add(Slot_3);
	SlotArray.Add(Slot_4);
	SlotArray.Add(Slot_5);

	for (int32 i = 0; i < SlotArray.Num(); ++i)
	{
		if (SlotArray[i])
		{
			SlotArray[i]->SetSlotNumber(i + 1);
			SlotArray[i]->SetSelected(i == 0);
		}
	}
}

void UInventoryBarWidget::UpdateSelection(int32 NewSlotIndex)
{
	for (int32 i = 0; i < SlotArray.Num(); ++i)
	{
		if (SlotArray[i])
		{
			SlotArray[i]->SetSelected(i == NewSlotIndex);
		}
	}
}

void UInventoryBarWidget::UpdateSlotContent(int32 SlotIndex, const FInventorySlotData& Data)
{
	if (SlotArray.IsValidIndex(SlotIndex) && SlotArray[SlotIndex])
	{
		SlotArray[SlotIndex]->SetSlotData(Data);
	}
}