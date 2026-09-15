---
type: source_file_summary
source: "DreamEscape/Variant_Horror/HorrorPlayerController.cpp"
source_sha256: "17A2C2795572B331F0CA65E6D8CF9E3EEA3C5BDCDAF0FE043A4FFB809393F162"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# HorrorPlayerController.cpp

호러 UI와 터치·키보드 입력 매핑 관리.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Horror/HorrorPlayerController.cpp](../../../../Source/DreamEscape/Variant_Horror/HorrorPlayerController.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 98줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- 카메라 매니저로 DreamEscapeCameraManager를 지정한다.
- BeginPlay에서 필요하면 로컬 터치 위젯을 생성한다.
- OnPossess에서 로컬 HorrorCharacter인 경우 HorrorUI를 생성하고 SetupCharacter로 연결한다.
- SetupInputComponent에서 기본/비터치 매핑을 등록한다.

## 구현 함수 위치

- [L14](../../../../Source/DreamEscape/Variant_Horror/HorrorPlayerController.cpp#L14): `AHorrorPlayerController::AHorrorPlayerController()`
- [L20](../../../../Source/DreamEscape/Variant_Horror/HorrorPlayerController.cpp#L20): `AHorrorPlayerController::BeginPlay()`
- [L44](../../../../Source/DreamEscape/Variant_Horror/HorrorPlayerController.cpp#L44): `AHorrorPlayerController::OnPossess(APawn* aPawn)`
- [L67](../../../../Source/DreamEscape/Variant_Horror/HorrorPlayerController.cpp#L67): `AHorrorPlayerController::SetupInputComponent()`
- [L94](../../../../Source/DreamEscape/Variant_Horror/HorrorPlayerController.cpp#L94): `AHorrorPlayerController::ShouldUseTouchControls()`

## 연결 파일

- [HorrorPlayerController.h](HorrorPlayerController.h.md)
- [DreamEscapeCameraManager.h](../DreamEscapeCameraManager.h.md)
- [HorrorCharacter.h](HorrorCharacter.h.md)
- [HorrorUI.h](UI/HorrorUI.h.md)
- [DreamEscape.h](../DreamEscape.h.md)

[전체 소스 인덱스로](../../../README.md)
