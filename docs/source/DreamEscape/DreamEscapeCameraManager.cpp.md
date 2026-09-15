---
type: source_file_summary
source: "DreamEscape/DreamEscapeCameraManager.cpp"
source_sha256: "FA0FDC242279AEBE5C68152D0977F61FF01E4BDE5BF23F7DEF2B99D52B5769CB"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# DreamEscapeCameraManager.cpp

1인칭 시점의 상하 회전 범위를 설정하는 카메라 매니저.

## 파일 정보

- 원본: [Source/DreamEscape/DreamEscapeCameraManager.cpp](../../../Source/DreamEscape/DreamEscapeCameraManager.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 11줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- 생성자에서 ViewPitchMin=-70, ViewPitchMax=80을 설정한다.
- DreamEscapePlayerController와 HorrorPlayerController가 이 클래스를 카메라 매니저로 지정한다.

## 구현 함수 위치

- [L6](../../../Source/DreamEscape/DreamEscapeCameraManager.cpp#L6): `ADreamEscapeCameraManager::ADreamEscapeCameraManager()`

## 연결 파일

- [DreamEscapeCameraManager.h](DreamEscapeCameraManager.h.md)

[전체 소스 인덱스로](../../README.md)
