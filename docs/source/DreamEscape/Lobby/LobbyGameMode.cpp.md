---
type: source_file_summary
source: "DreamEscape/Lobby/LobbyGameMode.cpp"
source_sha256: "D68218571A82F38E92A2722BD857662AF39F588E928E67FB5284E1A7032B05F8"
source_encoding: "CP949"
source_modified: "2026-08-30T16:31:14"
last_updated: "2026-09-15"
---

# LobbyGameMode.cpp

로비의 맵 선택과 서버 레벨 전환.

## 파일 정보

- 원본: [Source/DreamEscape/Lobby/LobbyGameMode.cpp](../../../../Source/DreamEscape/Lobby/LobbyGameMode.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 110줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- 생성자에서 seamless travel, LobbyPlayerState, LobbyGameState를 설정한다.
- CheckAllPlayersReady는 로컬 컨트롤러를 제외한 플레이어의 준비 상태를 검사한다.
- StartGame은 GameState, 선택 인덱스, 맵 에셋을 검증한 뒤 패키지 경로에 ?listen을 붙여 ServerTravel한다.
- StartGame 내부에서는 CheckAllPlayersReady를 호출하지 않는다. 준비 검사는 호출 측 연결을 확인해야 한다.
- SetSelectedMap은 GameState의 인덱스를 변경하고 호스트용 이벤트를 방송한다. NextMap/PrevMap은 목록을 순환한다.

## 구현 함수 위치

- [L7](../../../../Source/DreamEscape/Lobby/LobbyGameMode.cpp#L7): `ALobbyGameMode::ALobbyGameMode()`
- [L14](../../../../Source/DreamEscape/Lobby/LobbyGameMode.cpp#L14): `ALobbyGameMode::CheckAllPlayersReady()`
- [L35](../../../../Source/DreamEscape/Lobby/LobbyGameMode.cpp#L35): `ALobbyGameMode::StartGame()`
- [L76](../../../../Source/DreamEscape/Lobby/LobbyGameMode.cpp#L76): `ALobbyGameMode::SetSelectedMap(int32 MapIndex)`
- [L92](../../../../Source/DreamEscape/Lobby/LobbyGameMode.cpp#L92): `ALobbyGameMode::NextMap()`
- [L102](../../../../Source/DreamEscape/Lobby/LobbyGameMode.cpp#L102): `ALobbyGameMode::PrevMap()`

## 연결 파일

- [LobbyGameMode.h](LobbyGameMode.h.md)
- [LobbyGameState.h](LobbyGameState.h.md)
- [LobbyPlayerState.h](LobbyPlayerState.h.md)

[전체 소스 인덱스로](../../../README.md)
