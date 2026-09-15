---
type: source_file_summary
source: "DreamEscape/DreamEscapePlayerController.h"
source_sha256: "2E7F36AB28AF744019062D13EC295FB8A90AE14287F9285DC20821FA31EC7601"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# DreamEscapePlayerController.h

입력 매핑과 터치 조작 UI를 준비하는 기본 플레이어 컨트롤러.

## 파일 정보

- 원본: [Source/DreamEscape/DreamEscapePlayerController.h](../../../Source/DreamEscape/DreamEscapePlayerController.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 57줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- 기본 매핑 목록과 모바일에서 제외할 매핑 목록을 분리한다.
- 터치 위젯 클래스/인스턴스 및 bForceTouchControls를 보관한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API ADreamEscapePlayerController : public APlayerController`
- [L30](../../../Source/DreamEscape/DreamEscapePlayerController.h#L30): `TArray<UInputMappingContext*> DefaultMappingContexts` — `UPROPERTY(EditAnywhere, Category="Input|Input Mappings")`
- [L34](../../../Source/DreamEscape/DreamEscapePlayerController.h#L34): `TArray<UInputMappingContext*> MobileExcludedMappingContexts` — `UPROPERTY(EditAnywhere, Category="Input|Input Mappings")`
- [L38](../../../Source/DreamEscape/DreamEscapePlayerController.h#L38): `TSubclassOf<UUserWidget> MobileControlsWidgetClass` — `UPROPERTY(EditAnywhere, Category="Input|Touch Controls")`
- [L42](../../../Source/DreamEscape/DreamEscapePlayerController.h#L42): `TObjectPtr<UUserWidget> MobileControlsWidget` — `UPROPERTY()`
- [L46](../../../Source/DreamEscape/DreamEscapePlayerController.h#L46): `bool bForceTouchControls = false` — `UPROPERTY(EditAnywhere, Config, Category = "Input|Touch Controls")`

## 연결 파일

- [DreamEscapePlayerController.cpp](DreamEscapePlayerController.cpp.md)

[전체 소스 인덱스로](../../README.md)
