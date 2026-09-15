---
type: source_file_summary
source: "DreamEscape/Variant_Horror/UI/HorrorUI.h"
source_sha256: "2992B05BF0E3B794650E20B1EE9200A9BB830E1DA964BD125B50037DF0D3474C"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# HorrorUI.h

호러 캐릭터의 스프린트 이벤트를 Blueprint 화면에 전달.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Horror/UI/HorrorUI.h](../../../../../Source/DreamEscape/Variant_Horror/UI/HorrorUI.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 42줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- SetupCharacter와 C++ 이벤트 수신 함수 2개를 선언한다.
- 실제 표현은 BP_SprintMeterUpdated/BP_SprintStateChanged 이벤트에서 구현한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API UHorrorUI : public UUserWidget`
- [L26](../../../../../Source/DreamEscape/Variant_Horror/UI/HorrorUI.h#L26): `void OnSprintMeterUpdated(float Percent)` — `UFUNCTION()`
- [L30](../../../../../Source/DreamEscape/Variant_Horror/UI/HorrorUI.h#L30): `void OnSprintStateChanged(bool bSprinting)` — `UFUNCTION()`
- [L36](../../../../../Source/DreamEscape/Variant_Horror/UI/HorrorUI.h#L36): `void BP_SprintMeterUpdated(float Percent)` — `UFUNCTION(BlueprintImplementableEvent, Category="Horror", meta = (DisplayName = "Sprint Meter Updated"))`
- [L40](../../../../../Source/DreamEscape/Variant_Horror/UI/HorrorUI.h#L40): `void BP_SprintStateChanged(bool bSprinting)` — `UFUNCTION(BlueprintImplementableEvent, Category="Horror", meta = (DisplayName = "Sprint State Changed"))`

## 연결 파일

- [HorrorUI.cpp](HorrorUI.cpp.md)

[전체 소스 인덱스로](../../../../README.md)
