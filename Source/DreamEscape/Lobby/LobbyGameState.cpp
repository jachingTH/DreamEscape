#include "Lobby/LobbyGameState.h"
#include "Net/UnrealNetwork.h"

ALobbyGameState::ALobbyGameState()
{
    // 기본값 초기화
    SelectedMapIndex = 0;
}

void ALobbyGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    // SelectedMapIndex 복제 등록
    DOREPLIFETIME(ALobbyGameState, SelectedMapIndex);
}

void ALobbyGameState::OnRep_SelectedMapIndex()
{
    // 서버로부터 새 인덱스를 복제받았을 때 로컬 UI 갱신 이벤트 브로드캐스트
    OnMapChanged.Broadcast(SelectedMapIndex);
}