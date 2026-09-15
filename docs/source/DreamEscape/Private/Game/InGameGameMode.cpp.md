---
type: source_file_summary
source: "DreamEscape/Private/Game/InGameGameMode.cpp"
source_sha256: "4502612B989DF7236F9C8D3CD0337A8BCCABEE52D7788DA5ECC51FF264B4F72A"
source_encoding: "UTF-8"
source_modified: "2026-08-28T16:27:23"
last_updated: "2026-09-15"
---

# InGameGameMode.cpp

네트워크 인게임 진입과 플레이어 상태 연결.

## 파일 정보

- 원본: [Source/DreamEscape/Private/Game/InGameGameMode.cpp](../../../../../Source/DreamEscape/Private/Game/InGameGameMode.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 27줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- bUseSeamlessTravel=true, DefaultPawnClass=AInGameCharacter, PlayerStateClass=ALobbyPlayerState를 설정한다.
- PostSeamlessTravel과 PostLogin은 부모 호출 후 로그를 출력한다.
- 별도 승리·탈출·라운드 루프는 현재 이 파일에 없다.

## 구현 함수 위치

- [L6](../../../../../Source/DreamEscape/Private/Game/InGameGameMode.cpp#L6): `AInGameGameMode::AInGameGameMode()`
- [L13](../../../../../Source/DreamEscape/Private/Game/InGameGameMode.cpp#L13): `AInGameGameMode::PostSeamlessTravel()`
- [L19](../../../../../Source/DreamEscape/Private/Game/InGameGameMode.cpp#L19): `AInGameGameMode::PostLogin(APlayerController* NewPlayer)`

## 연결 파일

- [InGameGameMode.h](../../Public/Game/InGameGameMode.h.md)
- [InGameCharacter.h](../../Public/Player/InGameCharacter.h.md)
- [LobbyPlayerState.h](../../Lobby/LobbyPlayerState.h.md)

[전체 소스 인덱스로](../../../../README.md)
