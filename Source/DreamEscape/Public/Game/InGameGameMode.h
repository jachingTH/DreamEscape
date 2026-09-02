#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InGameGameMode.generated.h"

UCLASS()
class DREAMESCAPE_API AInGameGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AInGameGameMode();

    virtual void PostSeamlessTravel() override;
    virtual void PostLogin(APlayerController* NewPlayer) override;
};