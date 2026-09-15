---
type: source_file_summary
source: "DreamEscape/Public/DreamEscapeInGameHUD.h"
source_sha256: "A0C5F0460960A0B17604E600100B6BD47DF2918150B0DB1646FE20B6FB39546B"
source_encoding: "UTF-8"
source_modified: "2026-09-01T01:03:58"
last_updated: "2026-09-15"
---

# DreamEscapeInGameHUD.h

상태창과 인벤토리 바를 묶는 루트 UMG 위젯.

## 파일 정보

- 원본: [Source/DreamEscape/Public/DreamEscapeInGameHUD.h](../../../../Source/DreamEscape/Public/DreamEscapeInGameHUD.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 21줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- UUserWidget 파생 클래스다. AHUD 파생 클래스가 아니다.
- WBP_PlayerStatus와 WBP_InventoryBar를 필수 BindWidget 프로퍼티로 공개한다.
- 이벤트 연결은 DreamEscapeCharacter 등에서 수행한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API UDreamEscapeInGameHUD : public UUserWidget`
- [L16](../../../../Source/DreamEscape/Public/DreamEscapeInGameHUD.h#L16): `TObjectPtr<UPlayerStatusWidget> WBP_PlayerStatus` — `UPROPERTY(meta = (BindWidget), BlueprintReadOnly, Category = "UI")`
- [L19](../../../../Source/DreamEscape/Public/DreamEscapeInGameHUD.h#L19): `TObjectPtr<UInventoryBarWidget> WBP_InventoryBar` — `UPROPERTY(meta = (BindWidget), BlueprintReadOnly, Category = "UI")`

## 연결 파일

- [DreamEscapeInGameHUD.cpp](../Private/DreamEscapeInGameHUD.cpp.md)

[전체 소스 인덱스로](../../../README.md)
