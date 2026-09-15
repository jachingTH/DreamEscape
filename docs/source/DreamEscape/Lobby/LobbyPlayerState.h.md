---
type: source_file_summary
source: "DreamEscape/Lobby/LobbyPlayerState.h"
source_sha256: "B04DE47FD3C1C0E896A9B8168710DAEE3FFA1346DEDAA455AA0884E958044884"
source_encoding: "CP949"
source_modified: "2026-08-28T16:23:52"
last_updated: "2026-09-15"
---

# LobbyPlayerState.h

플레이어 준비 상태 및 레벨 전환 시 상태 복사.

## 파일 정보

- 원본: [Source/DreamEscape/Lobby/LobbyPlayerState.h](../../../../Source/DreamEscape/Lobby/LobbyPlayerState.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 33줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- bIsReady는 RepNotify 상태다.
- Server_SetReady는 Server/Reliable/WithValidation RPC다.
- SetPlayerReady 인라인 함수는 로컬 직접 대입이며 서버 RPC와 같지 않다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API ALobbyPlayerState : public APlayerState`
- [L19](../../../../Source/DreamEscape/Lobby/LobbyPlayerState.h#L19): `bool bIsReady = false` — `UPROPERTY(ReplicatedUsing = OnRep_IsReady, BlueprintReadOnly, Category = "Lobby")`
- [L22](../../../../Source/DreamEscape/Lobby/LobbyPlayerState.h#L22): `void OnRep_IsReady()` — `UFUNCTION()`
- [L25](../../../../Source/DreamEscape/Lobby/LobbyPlayerState.h#L25): `void Server_SetReady(bool bNewReady)` — `UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "Lobby")`
- [L28](../../../../Source/DreamEscape/Lobby/LobbyPlayerState.h#L28): `bool IsPlayerReady() const` — `UFUNCTION(BlueprintCallable, Category = "Lobby")`
- [L31](../../../../Source/DreamEscape/Lobby/LobbyPlayerState.h#L31): `void SetPlayerReady(bool bNewReady)` — `UFUNCTION(BlueprintCallable, Category = "Lobby")`

## 연결 파일

- [LobbyPlayerState.cpp](LobbyPlayerState.cpp.md)

[전체 소스 인덱스로](../../../README.md)
