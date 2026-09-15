---
type: source_file_summary
source: "DreamEscape/Lobby/LobbyGameState.h"
source_sha256: "C97DBF0F4900AF5C8AE7537F4C99CDB9D557E9241A5B941D6B31322275E15AAA"
source_encoding: "CP949"
source_modified: "2026-08-28T23:35:17"
last_updated: "2026-09-15"
---

# LobbyGameState.h

선택된 로비 맵 인덱스의 네트워크 공유.

## 파일 정보

- 원본: [Source/DreamEscape/Lobby/LobbyGameState.h](../../../../Source/DreamEscape/Lobby/LobbyGameState.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 34줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- SelectedMapIndex만 ReplicatedUsing=OnRep_SelectedMapIndex로 선언한다.
- AvailableMaps는 EditDefaultsOnly 배열이며 복제 속성이 아니다. 각 인스턴스의 설정이 맞아야 한다.
- OnMapChanged 이벤트를 Blueprint에 공개한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API ALobbyGameState : public AGameStateBase`
- [L21](../../../../Source/DreamEscape/Lobby/LobbyGameState.h#L21): `int32 SelectedMapIndex = 0` — `UPROPERTY(ReplicatedUsing = OnRep_SelectedMapIndex, BlueprintReadOnly, Category = "Lobby")`
- [L24](../../../../Source/DreamEscape/Lobby/LobbyGameState.h#L24): `void OnRep_SelectedMapIndex()` — `UFUNCTION()`
- [L28](../../../../Source/DreamEscape/Lobby/LobbyGameState.h#L28): `TArray<FMapSelectionData> AvailableMaps` — `UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lobby | Maps")`
- [L32](../../../../Source/DreamEscape/Lobby/LobbyGameState.h#L32): `FOnMapChanged OnMapChanged` — `UPROPERTY(BlueprintAssignable, Category = "Lobby")`
- 이벤트: `DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMapChanged, int32, NewMapIndex);`

## 연결 파일

- [LobbyGameState.cpp](LobbyGameState.cpp.md)
- [LobbyTypes.h](LobbyTypes.h.md)

[전체 소스 인덱스로](../../../README.md)
