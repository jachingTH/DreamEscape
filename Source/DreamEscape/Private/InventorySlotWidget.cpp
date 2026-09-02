#include "InventorySlotWidget.h"
#include "Components/Image.h"
#include "Components/Border.h"
#include "Components/TextBlock.h"

void UInventorySlotWidget::SetSlotData(const FInventorySlotData& Data)
{
	if (!Image_ItemIcon) return;

	if (Data.ItemIcon)
	{
		Image_ItemIcon->SetBrushFromTexture(Data.ItemIcon);
		Image_ItemIcon->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		Image_ItemIcon->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UInventorySlotWidget::SetSelected(bool bIsSelected)
{
	if (Border_SelectedHighlight)
	{
		Border_SelectedHighlight->SetVisibility(bIsSelected ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	}
}

void UInventorySlotWidget::SetSlotNumber(int32 Number)
{
	if (Text_SlotNumber)
	{
		Text_SlotNumber->SetText(FText::AsNumber(Number));
	}
}