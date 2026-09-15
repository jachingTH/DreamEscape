---
type: source_file_summary
source: "DreamEscape/Lobby/LobbyPlayerState.cpp"
source_sha256: "D01F5E9C9A3C4152F49EA4CCDE392F335A607FCD0C913EF78681752324DFA855"
source_encoding: "CP949"
source_modified: "2026-08-28T15:09:44"
last_updated: "2026-09-15"
---

# LobbyPlayerState.cpp

플레이어 준비 상태 및 레벨 전환 시 상태 복사.

## 파일 정보

- 원본: [Source/DreamEscape/Lobby/LobbyPlayerState.cpp](../../../../Source/DreamEscape/Lobby/LobbyPlayerState.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 49줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- 복제를 활성화하고 bIsReady를 DOREPLIFETIME에 등록한다.
- Server_SetReady_Implementation에서 값을 변경하고 호스트에도 OnRep_IsReady를 호출한다. Validate는 항상 true다.
- 현재 OnRep_IsReady 본문은 비어 있어 UI 갱신을 직접 수행하지 않는다.
- CopyProperties에서 새 LobbyPlayerState로 준비 상태를 복사한다.

## 구현 함수 위치

- [L5](../../../../Source/DreamEscape/Lobby/LobbyPlayerState.cpp#L5): `ALobbyPlayerState::ALobbyPlayerState()`
- [L10](../../../../Source/DreamEscape/Lobby/LobbyPlayerState.cpp#L10): `ALobbyPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)`
- [L16](../../../../Source/DreamEscape/Lobby/LobbyPlayerState.cpp#L16): `ALobbyPlayerState::Server_SetReady_Implementation(bool bNewReady)`
- [L22](../../../../Source/DreamEscape/Lobby/LobbyPlayerState.cpp#L22): `ALobbyPlayerState::Server_SetReady_Validate(bool bNewReady)`
- [L27](../../../../Source/DreamEscape/Lobby/LobbyPlayerState.cpp#L27): `ALobbyPlayerState::OnRep_IsReady()`
- [L32](../../../../Source/DreamEscape/Lobby/LobbyPlayerState.cpp#L32): `ALobbyPlayerState::CopyProperties(APlayerState* NewPlayerState)`

## 연결 파일

- [LobbyPlayerState.h](LobbyPlayerState.h.md)

[전체 소스 인덱스로](../../../README.md)
