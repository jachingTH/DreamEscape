#include "MainMenu.h"
#include "Components/Button.h"

void UMainMenu::NativeConstruct()
{
    Super::NativeConstruct();

    if (Btn_MainMenu_GameStart)
    {
        Btn_MainMenu_GameStart->OnClicked.RemoveDynamic(
            this,
            &UMainMenu::StartClickedHandler
        );

        Btn_MainMenu_GameStart->OnClicked.AddDynamic(
            this,
            &UMainMenu::StartClickedHandler
        );
    }
}

void UMainMenu::StartClickedHandler()
{
    if (bStartAlreadyClicked)
    {
        return;
    }

    bStartAlreadyClicked = true;

    OnStartClicked.Broadcast();
}