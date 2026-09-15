---
type: source_file_summary
source: "DreamEscape/Public/Online/DreamEscapeGameInstance.h"
source_sha256: "26A2DFF281AE553E6E0760DEE6D310011EE8FED98BD23D41B1929B920417E0C7"
source_encoding: "CP949"
source_modified: "2026-08-27T23:15:37"
last_updated: "2026-09-15"
---

# DreamEscapeGameInstance.h

온라인 세션 생성·검색·참가·종료와 설정 적용.

## 파일 정보

- 원본: [Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h](../../../../../Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 74줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- FServerListEntry에는 서버 이름, 인원, Ping, 빌드 버전, 검색 인덱스가 있다.
- HostSession, FindGameSessions, JoinGameSession, CleanupAndDestroySession을 Blueprint에 공개한다.
- 서버 목록/실패 알림 델리게이트와 비동기 작업 핸들을 보관한다. CurrentBuildVersion은 0.1.0이다.

## 프로퍼티·노출 함수·이벤트

- 타입: `struct FServerListEntry`
- 타입: `class DREAMESCAPE_API UDreamEscapeGameInstance : public UGameInstance`
- [L15](../../../../../Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h#L15): `FString ServerName` — `UPROPERTY(BlueprintReadOnly)`
- [L16](../../../../../Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h#L16): `int32 CurrentPlayers = 0` — `UPROPERTY(BlueprintReadOnly)`
- [L17](../../../../../Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h#L17): `int32 MaxPlayers = 4` — `UPROPERTY(BlueprintReadOnly)`
- [L18](../../../../../Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h#L18): `int32 Ping = 0` — `UPROPERTY(BlueprintReadOnly)`
- [L19](../../../../../Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h#L19): `FString BuildVersion` — `UPROPERTY(BlueprintReadOnly)`
- [L20](../../../../../Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h#L20): `int32 SearchResultIndex = INDEX_NONE` — `UPROPERTY(BlueprintReadOnly)`
- [L36](../../../../../Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h#L36): `void HostSession(int32 InMaxPlayers = 4)` — `UFUNCTION(BlueprintCallable, Category = "Network|Session")`
- [L39](../../../../../Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h#L39): `void FindGameSessions()` — `UFUNCTION(BlueprintCallable, Category = "Network|Session")`
- [L42](../../../../../Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h#L42): `void JoinGameSession(int32 SearchIndex)` — `UFUNCTION(BlueprintCallable, Category = "Network|Session")`
- [L45](../../../../../Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h#L45): `void CleanupAndDestroySession()` — `UFUNCTION(BlueprintCallable, Category = "Network|Session")`
- [L49](../../../../../Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h#L49): `FOnServerListUpdated OnServerListUpdated` — `UPROPERTY(BlueprintAssignable, Category = "Network|Events")`
- [L52](../../../../../Source/DreamEscape/Public/Online/DreamEscapeGameInstance.h#L52): `FOnSessionFailureMessage OnSessionFailureMessage` — `UPROPERTY(BlueprintAssignable, Category = "Network|Events")`
- 이벤트: `DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnServerListUpdated, const TArray<FServerListEntry>&, ServerList);`
- 이벤트: `DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSessionFailureMessage, const FString&, ErrorMessage);`

## 연결 파일

- [DreamEscapeGameInstance.cpp](../../Private/Online/DreamEscapeGameInstance.cpp.md)

[전체 소스 인덱스로](../../../../README.md)
