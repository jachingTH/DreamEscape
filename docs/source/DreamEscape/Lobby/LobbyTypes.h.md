---
type: source_file_summary
source: "DreamEscape/Lobby/LobbyTypes.h"
source_sha256: "8DE0CD058D6E0EA71DA8540967D41425E92AE37B10C4DD1FA301362C0AD9B19C"
source_encoding: "CP949"
source_modified: "2026-08-29T00:02:42"
last_updated: "2026-09-15"
---

# LobbyTypes.h

로비 버튼 종류와 맵 선택 정보.

## 파일 정보

- 원본: [Source/DreamEscape/Lobby/LobbyTypes.h](../../../../Source/DreamEscape/Lobby/LobbyTypes.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 33줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- ELobbyButtonType은 Prev, Next, Confirm을 정의한다.
- FMapSelectionData는 표시 이름, 레벨 SoftObjectPtr, 썸네일 SoftObjectPtr를 묶는다.
- 데이터 구조 자체가 네트워크 전송을 수행하지 않는다.

## 프로퍼티·노출 함수·이벤트

- 타입: `enum class ELobbyButtonType : uint8`
- 타입: `struct FMapSelectionData`
- [L25](../../../../Source/DreamEscape/Lobby/LobbyTypes.h#L25): `FString MapDisplayName` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapData")`
- [L28](../../../../Source/DreamEscape/Lobby/LobbyTypes.h#L28): `TSoftObjectPtr<UWorld> MapLevelAsset` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapData")`
- [L31](../../../../Source/DreamEscape/Lobby/LobbyTypes.h#L31): `TSoftObjectPtr<UTexture2D> MapThumbnail` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapData")`

## 연결 파일

- 직접 연결되는 다른 프로젝트 소스 파일 없음.

[전체 소스 인덱스로](../../../README.md)
