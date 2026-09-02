// LobbyPlayerState.cpp
#include "Lobby/LobbyPlayerState.h"
#include "Net/UnrealNetwork.h"

ALobbyPlayerState::ALobbyPlayerState()
{
    bReplicates = true;
}

void ALobbyPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ALobbyPlayerState, bIsReady);
}

void ALobbyPlayerState::Server_SetReady_Implementation(bool bNewReady)
{
    bIsReady = bNewReady;
    OnRep_IsReady(); // 서버 로컬에서도 동일 처리
}

bool ALobbyPlayerState::Server_SetReady_Validate(bool bNewReady)
{
    return true;
}

void ALobbyPlayerState::OnRep_IsReady()
{
    // 로비 UI 갱신 이벤트 트리거 (필요 시 바인딩)
}

void ALobbyPlayerState::CopyProperties(APlayerState* NewPlayerState)
{
    Super::CopyProperties(NewPlayerState);

    if (NewPlayerState)
    {
        // 1. 전달받은 새 PlayerState를 ALobbyPlayerState로 캐스팅
        ALobbyPlayerState* TargetPS = Cast<ALobbyPlayerState>(NewPlayerState);
        if (TargetPS)
        {
            // 2. 심리스 트래블 이후에도 유지할 데이터 복사
            TargetPS->bIsReady = this->bIsReady;

            // 추후 추가되는 데이터(캐릭터 번호, 닉네임 등)가 생기면 여기에 추가:
            // TargetPS->SelectedCharacterIndex = this->SelectedCharacterIndex;
        }
    }
}