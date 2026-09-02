#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DreamEscapeInGameHUD.generated.h"

class UPlayerStatusWidget;
class UInventoryBarWidget;

UCLASS()
class DREAMESCAPE_API UDreamEscapeInGameHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget), BlueprintReadOnly, Category = "UI")
	TObjectPtr<UPlayerStatusWidget> WBP_PlayerStatus;

	UPROPERTY(meta = (BindWidget), BlueprintReadOnly, Category = "UI")
	TObjectPtr<UInventoryBarWidget> WBP_InventoryBar;
};