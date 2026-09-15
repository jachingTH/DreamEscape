---
type: source_file_summary
source: "DreamEscape/Lobby/LobbyGameMode.h"
source_sha256: "682016B53DFCBDC45399E6F004CE0A80AE24307E8483ABE86DF304DF7C798B27"
source_encoding: "CP949"
source_modified: "2026-08-30T21:49:04"
last_updated: "2026-09-15"
---

# LobbyGameMode.h

로비의 맵 선택과 서버 레벨 전환.

## 파일 정보

- 원본: [Source/DreamEscape/Lobby/LobbyGameMode.h](../../../../Source/DreamEscape/Lobby/LobbyGameMode.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 50줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- AGameModeBase 파생 클래스에 StartGame, SetSelectedMap, NextMap, PrevMap을 노출한다.
- AvailableMaps와 별도의 맵 표시 정보 필드를 선언하지만 구현의 맵 선택은 LobbyGameState의 목록을 사용한다.
- CheckAllPlayersReady는 일반 C++ 함수이며 RPC가 아니다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API ALobbyGameMode : public AGameModeBase`
- [L20](../../../../Source/DreamEscape/Lobby/LobbyGameMode.h#L20): `void StartGame()` — `UFUNCTION(BlueprintCallable, Category = "Lobby")`
- [L24](../../../../Source/DreamEscape/Lobby/LobbyGameMode.h#L24): `void SetSelectedMap(int32 MapIndex)` — `UFUNCTION(BlueprintCallable, Category = "Lobby")`
- [L27](../../../../Source/DreamEscape/Lobby/LobbyGameMode.h#L27): `void NextMap()` — `UFUNCTION(BlueprintCallable, Category = "Lobby")`
- [L30](../../../../Source/DreamEscape/Lobby/LobbyGameMode.h#L30): `void PrevMap()` — `UFUNCTION(BlueprintCallable, Category = "Lobby")`
- [L34](../../../../Source/DreamEscape/Lobby/LobbyGameMode.h#L34): `TArray<FMapSelectionData> AvailableMaps` — `UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Lobby | Maps")`
- [L38](../../../../Source/DreamEscape/Lobby/LobbyGameMode.h#L38): `FString MapDisplayName` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapData")`
- [L42](../../../../Source/DreamEscape/Lobby/LobbyGameMode.h#L42): `TSoftObjectPtr<UWorld> MapLevelAsset` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapData")`
- [L46](../../../../Source/DreamEscape/Lobby/LobbyGameMode.h#L46): `TSoftObjectPtr<UTexture2D> MapThumbnail` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MapData")`

## 연결 파일

- [LobbyGameMode.cpp](LobbyGameMode.cpp.md)
- [LobbyTypes.h](LobbyTypes.h.md)

[전체 소스 인덱스로](../../../README.md)
