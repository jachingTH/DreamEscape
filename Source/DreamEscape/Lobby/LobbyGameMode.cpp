// LobbyGameMode.cpp
#include "Lobby/LobbyGameMode.h"
#include "Lobby/LobbyGameState.h"
#include "Lobby/LobbyPlayerState.h"
#include "GameFramework/GameStateBase.h"

ALobbyGameMode::ALobbyGameMode()
{
    bUseSeamlessTravel = true;
    PlayerStateClass = ALobbyPlayerState::StaticClass();
    GameStateClass = ALobbyGameState::StaticClass();
}

bool ALobbyGameMode::CheckAllPlayersReady() const
{
    if (!GameState) return false;

    for (APlayerState* PS : GameState->PlayerArray)
    {
        if (ALobbyPlayerState* LobbyPS = Cast<ALobbyPlayerState>(PS))
        {
            // 방장(호스트)을 제외한 다른 접속자들의 레디 상태 체크
            if (APlayerController* PC = Cast<APlayerController>(LobbyPS->GetOwner()))
            {
                if (!PC->IsLocalController() && !LobbyPS->bIsReady)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void ALobbyGameMode::StartGame()
{
    ALobbyGameState* LobbyGS = GetGameState<ALobbyGameState>();
    if (!LobbyGS)
    {
        UE_LOG(LogTemp, Error, TEXT("[LobbyGameMode] GameState를 찾을 수 없습니다."));
        return;
    }

    // 1. 준비 상태 검증 (테스트 중에는 주석 처리하거나 로그만 출력하여 우회 가능)
    /*
    if (!CheckAllPlayersReady())
    {
        UE_LOG(LogTemp, Warning, TEXT("모든 플레이어가 준비되지 않았습니다."));
        return;
    }
    */

    // 2. GameState의 AvailableMaps 배열 검증 (GameMode의 변수가 아닌 GameState의 배열 검사)
    if (!LobbyGS->AvailableMaps.IsValidIndex(LobbyGS->SelectedMapIndex))
    {
        UE_LOG(LogTemp, Error, TEXT("[LobbyGameMode] 선택된 맵 인덱스가 유효하지 않습니다. (Index: %d, Total: %d)"),
            LobbyGS->SelectedMapIndex, LobbyGS->AvailableMaps.Num());
        return;
    }

    const FMapSelectionData& SelectedMap = LobbyGS->AvailableMaps[LobbyGS->SelectedMapIndex];
    if (SelectedMap.MapLevelAsset.IsNull())
    {
        UE_LOG(LogTemp, Error, TEXT("[LobbyGameMode] 선택된 레벨 에셋 경로가 비어 있습니다."));
        return;
    }

    // 3. 순수 패키지 경로 추출 및 ServerTravel 호출
    FString TargetMapPath = SelectedMap.MapLevelAsset.GetLongPackageName();
    FString TravelURL = FString::Printf(TEXT("%s?listen"), *TargetMapPath);

    UE_LOG(LogTemp, Log, TEXT("[LobbyGameMode] ServerTravel 시작: %s"), *TravelURL);
    GetWorld()->ServerTravel(TravelURL);
}

void ALobbyGameMode::SetSelectedMap(int32 MapIndex)
{
    ALobbyGameState* LobbyGS = GetGameState<ALobbyGameState>();
    if (!LobbyGS) return;

    // GameState의 AvailableMaps 기준으로 인덱스 유효성 검사
    if (!LobbyGS->AvailableMaps.IsValidIndex(MapIndex))
    {
        return;
    }

    // 인덱스 갱신 및 델리게이트 브로드캐스트
    LobbyGS->SelectedMapIndex = MapIndex;
    LobbyGS->OnMapChanged.Broadcast(MapIndex);
}

void ALobbyGameMode::NextMap()
{
    ALobbyGameState* LobbyGS = GetGameState<ALobbyGameState>();
    if (LobbyGS && LobbyGS->AvailableMaps.Num() > 0)
    {
        int32 NextIndex = (LobbyGS->SelectedMapIndex + 1) % LobbyGS->AvailableMaps.Num();
        SetSelectedMap(NextIndex);
    }
}

void ALobbyGameMode::PrevMap()
{
    ALobbyGameState* LobbyGS = GetGameState<ALobbyGameState>();
    if (LobbyGS && LobbyGS->AvailableMaps.Num() > 0)
    {
        int32 PrevIndex = (LobbyGS->SelectedMapIndex - 1 + LobbyGS->AvailableMaps.Num()) % LobbyGS->AvailableMaps.Num();
        SetSelectedMap(PrevIndex);
    }
}