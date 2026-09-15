---
type: source_file_summary
source: "DreamEscape/Public/PlayerStatusWidget.h"
source_sha256: "46A4693AE8184BEAAF07E9C4BF26D5CE986921996FC6CC606B864838C2D7C7CB"
source_encoding: "CP949"
source_modified: "2026-09-02T00:30:04"
last_updated: "2026-09-15"
---

# PlayerStatusWidget.h

체력·스태미나 비율을 표시하는 위젯.

## 파일 정보

- 원본: [Source/DreamEscape/Public/PlayerStatusWidget.h](../../../../Source/DreamEscape/Public/PlayerStatusWidget.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 54줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- ProgressBar_Health와 ProgressBar_Stamina는 필수 바인딩이다.
- Text_HealthPercent와 Text_StaminaPercent는 선택 바인딩이다.
- UpdateHealth/UpdateStamina를 이벤트 수신 및 Blueprint 호출에 사용한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API UPlayerStatusWidget : public UUserWidget`
- [L26](../../../../Source/DreamEscape/Public/PlayerStatusWidget.h#L26): `TObjectPtr<UProgressBar> ProgressBar_Health` — `UPROPERTY(meta = (BindWidget))`
- [L30](../../../../Source/DreamEscape/Public/PlayerStatusWidget.h#L30): `TObjectPtr<UTextBlock> Text_HealthPercent` — `UPROPERTY(meta = (BindWidgetOptional))`
- [L34](../../../../Source/DreamEscape/Public/PlayerStatusWidget.h#L34): `TObjectPtr<UProgressBar> ProgressBar_Stamina` — `UPROPERTY(meta = (BindWidget))`
- [L38](../../../../Source/DreamEscape/Public/PlayerStatusWidget.h#L38): `TObjectPtr<UTextBlock> Text_StaminaPercent` — `UPROPERTY(meta = (BindWidgetOptional))`
- [L48](../../../../Source/DreamEscape/Public/PlayerStatusWidget.h#L48): `void UpdateHealth(float Current, float Max)` — `UFUNCTION(BlueprintCallable, Category = "UI")`
- [L52](../../../../Source/DreamEscape/Public/PlayerStatusWidget.h#L52): `void UpdateStamina(float Current, float Max)` — `UFUNCTION(BlueprintCallable, Category = "UI")`

## 연결 파일

- [PlayerStatusWidget.cpp](../Private/PlayerStatusWidget.cpp.md)

[전체 소스 인덱스로](../../../README.md)
