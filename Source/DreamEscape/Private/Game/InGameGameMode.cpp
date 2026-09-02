#include "Game/InGameGameMode.h"
#include "Player/InGameCharacter.h"
#include "Lobby/LobbyPlayerState.h"
#include "GameFramework/PlayerController.h"

AInGameGameMode::AInGameGameMode()
{
    bUseSeamlessTravel = true;
    DefaultPawnClass = AInGameCharacter::StaticClass();
    PlayerStateClass = ALobbyPlayerState::StaticClass();
}

void AInGameGameMode::PostSeamlessTravel()
{
    Super::PostSeamlessTravel();
    UE_LOG(LogTemp, Warning, TEXT("[InGameGameMode] PostSeamlessTravel Complete - Game Loop Started."));
}

void AInGameGameMode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    if (NewPlayer)
    {
        UE_LOG(LogTemp, Log, TEXT("[InGameGameMode] Player Logged In: %s"), *NewPlayer->GetName());
    }
}