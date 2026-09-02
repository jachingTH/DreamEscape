#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

class UButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartClickedSignature);

UCLASS()
class DREAMESCAPE_API UMainMenu : public UUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category = "Main Menu")
    FOnStartClickedSignature OnStartClicked;

protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    TObjectPtr<UButton> Btn_MainMenu_GameStart;

    UFUNCTION()
    void StartClickedHandler();

private:
    bool bStartAlreadyClicked = false;
};