---
type: source_file_summary
source: "DreamEscape/DreamEscapePlayerController.cpp"
source_sha256: "397F08D5237A4D52F88728DA26C7CE2991251EBC4DE9140ADD4D8285A614CFD2"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# DreamEscapePlayerController.cpp

입력 매핑과 터치 조작 UI를 준비하는 기본 플레이어 컨트롤러.

## 파일 정보

- 원본: [Source/DreamEscape/DreamEscapePlayerController.cpp](../../../Source/DreamEscape/DreamEscapePlayerController.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 76줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- 생성자에서 DreamEscapeCameraManager를 지정한다.
- 로컬 플레이어가 터치 조작을 사용할 때 BeginPlay에서 위젯을 만들고 AddToPlayerScreen으로 표시한다.
- SetupInputComponent에서 기본 매핑을 등록하고 터치 모드가 아니면 MobileExcludedMappingContexts도 등록한다.
- ShouldUseTouchControls는 플랫폼의 터치 인터페이스 판정과 강제 옵션을 OR로 결합한다.

## 구현 함수 위치

- [L13](../../../Source/DreamEscape/DreamEscapePlayerController.cpp#L13): `ADreamEscapePlayerController::ADreamEscapePlayerController()`
- [L19](../../../Source/DreamEscape/DreamEscapePlayerController.cpp#L19): `ADreamEscapePlayerController::BeginPlay()`
- [L44](../../../Source/DreamEscape/DreamEscapePlayerController.cpp#L44): `ADreamEscapePlayerController::SetupInputComponent()`
- [L72](../../../Source/DreamEscape/DreamEscapePlayerController.cpp#L72): `ADreamEscapePlayerController::ShouldUseTouchControls()`

## 연결 파일

- [DreamEscapePlayerController.h](DreamEscapePlayerController.h.md)
- [DreamEscapeCameraManager.h](DreamEscapeCameraManager.h.md)
- [DreamEscape.h](DreamEscape.h.md)

[전체 소스 인덱스로](../../README.md)
