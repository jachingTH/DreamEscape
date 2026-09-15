---
type: source_file_summary
source: "DreamEscape/Lobby/LobbyGameState.cpp"
source_sha256: "1F02796589CE92B0CCFA4C7CA1D4BCF57C0F2171CA23541408914486EA69BA02"
source_encoding: "CP949"
source_modified: "2026-08-29T00:34:49"
last_updated: "2026-09-15"
---

# LobbyGameState.cpp

선택된 로비 맵 인덱스의 네트워크 공유.

## 파일 정보

- 원본: [Source/DreamEscape/Lobby/LobbyGameState.cpp](../../../../Source/DreamEscape/Lobby/LobbyGameState.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 22줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- SelectedMapIndex를 0으로 초기화한다.
- GetLifetimeReplicatedProps에 SelectedMapIndex만 등록한다.
- 클라이언트의 OnRep_SelectedMapIndex에서 OnMapChanged를 방송한다.

## 구현 함수 위치

- [L4](../../../../Source/DreamEscape/Lobby/LobbyGameState.cpp#L4): `ALobbyGameState::ALobbyGameState()`
- [L10](../../../../Source/DreamEscape/Lobby/LobbyGameState.cpp#L10): `ALobbyGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)`
- [L18](../../../../Source/DreamEscape/Lobby/LobbyGameState.cpp#L18): `ALobbyGameState::OnRep_SelectedMapIndex()`

## 연결 파일

- [LobbyGameState.h](LobbyGameState.h.md)

[전체 소스 인덱스로](../../../README.md)
