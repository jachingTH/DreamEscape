---
type: source_file_summary
source: "DreamEscape/Private/Online/DreamEscapeGameInstance.cpp"
source_sha256: "DB0D489C4C0469D21E9882EBEA3C3C4F9779B1BF1CA8CACE5CABA9C65D7911DB"
source_encoding: "CP949"
source_modified: "2026-09-03T16:36:35"
last_updated: "2026-09-15"
---

# DreamEscapeGameInstance.cpp

온라인 세션 생성·검색·참가·종료와 설정 적용.

## 파일 정보

- 원본: [Source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp](../../../../../Source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 200줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- Init에서 사용자 설정을 적용하고 OnlineSubsystem의 SessionInterface와 네트워크 실패 콜백을 등록한다.
- HostSession은 비 LAN, 광고/Presence/로비 사용 설정으로 세션을 생성한다. 성공하면 /Game/Maps/Lobby를 listen으로 연다.
- 검색은 최대 20개이며 PRESENCESEARCH 필터를 사용한다. 결과의 BUILD_VERSION이 0.1.0과 일치하는 항목만 UI 목록으로 보낸다.
- 현재 HostSession은 BUILD_VERSION 설정을 게시하지 않는다. 따라서 이 코드로 생성한 세션이 버전 필터에서 제외될 수 있다.
- JoinGameSession은 인덱스를 검사하고 세션 참가 후 연결 문자열로 ClientTravel한다.
- 종료 완료 또는 인터페이스가 없을 때 MainMenu를 연다. 네트워크 실패도 세션 정리로 이어진다.

## 구현 함수 위치

- [L8](../../../../../Source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp#L8): `UDreamEscapeGameInstance::UDreamEscapeGameInstance()`
- [L10](../../../../../Source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp#L10): `UDreamEscapeGameInstance::Init()`
- [L34](../../../../../Source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp#L34): `UDreamEscapeGameInstance::HostSession(int32 InMaxPlayers)`
- [L66](../../../../../Source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp#L66): `UDreamEscapeGameInstance::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)`
- [L85](../../../../../Source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp#L85): `UDreamEscapeGameInstance::FindGameSessions()`
- [L101](../../../../../Source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp#L101): `UDreamEscapeGameInstance::OnFindSessionsComplete(bool bWasSuccessful)`
- [L133](../../../../../Source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp#L133): `UDreamEscapeGameInstance::JoinGameSession(int32 SearchIndex)`
- [L149](../../../../../Source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp#L149): `UDreamEscapeGameInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)`
- [L173](../../../../../Source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp#L173): `UDreamEscapeGameInstance::CleanupAndDestroySession()`
- [L188](../../../../../Source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp#L188): `UDreamEscapeGameInstance::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)`
- [L197](../../../../../Source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp#L197): `UDreamEscapeGameInstance::OnNetworkFailure(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString)`

## 연결 파일

- [DreamEscapeGameInstance.h](../../Public/Online/DreamEscapeGameInstance.h.md)

[전체 소스 인덱스로](../../../../README.md)
