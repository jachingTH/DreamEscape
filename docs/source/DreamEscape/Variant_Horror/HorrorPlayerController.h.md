---
type: source_file_summary
source: "DreamEscape/Variant_Horror/HorrorPlayerController.h"
source_sha256: "5931576DDCF16C7089B5C96AD28A8809B3C1EC883BD794F4D4AAACBBEF33029A"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# HorrorPlayerController.h

호러 UI와 터치·키보드 입력 매핑 관리.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Horror/HorrorPlayerController.h](../../../../Source/DreamEscape/Variant_Horror/HorrorPlayerController.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 69줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- HorrorUIClass/HorrorUI, 매핑 목록과 터치 옵션을 선언한다.
- OnPossess를 통해 소유한 호러 캐릭터를 UI에 연결한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API AHorrorPlayerController : public APlayerController`
- [L25](../../../../Source/DreamEscape/Variant_Horror/HorrorPlayerController.h#L25): `TSubclassOf<UHorrorUI> HorrorUIClass` — `UPROPERTY(EditAnywhere, Category="Horror|UI")`
- [L29](../../../../Source/DreamEscape/Variant_Horror/HorrorPlayerController.h#L29): `TObjectPtr<UHorrorUI> HorrorUI` — `UPROPERTY()`
- [L40](../../../../Source/DreamEscape/Variant_Horror/HorrorPlayerController.h#L40): `TArray<UInputMappingContext*> DefaultMappingContexts` — `UPROPERTY(EditAnywhere, Category ="Input|Input Mappings")`
- [L44](../../../../Source/DreamEscape/Variant_Horror/HorrorPlayerController.h#L44): `TArray<UInputMappingContext*> MobileExcludedMappingContexts` — `UPROPERTY(EditAnywhere, Category="Input|Input Mappings")`
- [L48](../../../../Source/DreamEscape/Variant_Horror/HorrorPlayerController.h#L48): `TSubclassOf<UUserWidget> MobileControlsWidgetClass` — `UPROPERTY(EditAnywhere, Category="Input|Touch Controls")`
- [L55](../../../../Source/DreamEscape/Variant_Horror/HorrorPlayerController.h#L55): `bool bForceTouchControls = false` — `UPROPERTY(EditAnywhere, Config, Category = "Input|Touch Controls")`

## 연결 파일

- [HorrorPlayerController.cpp](HorrorPlayerController.cpp.md)

[전체 소스 인덱스로](../../../README.md)
