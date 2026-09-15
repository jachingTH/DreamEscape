---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/ShooterGameMode.cpp"
source_sha256: "A56190CEA2BA03DF6AE002E28CAB9CB0AE9C5C7E4600161425927A9AE8E04851"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterGameMode.cpp

팀 점수 누적 및 점수 UI 관리.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/ShooterGameMode.cpp](../../../../Source/DreamEscape/Variant_Shooter/ShooterGameMode.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 33줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- BeginPlay에서 0번 플레이어 컨트롤러로 점수 UI를 생성해 표시한다.
- IncrementTeamScore는 해당 TeamByte 점수를 1 증가시키고 BP_UpdateScore를 호출한다.
- GameState 복제 점수 구현은 이 파일에 없다.

## 구현 함수 위치

- [L9](../../../../Source/DreamEscape/Variant_Shooter/ShooterGameMode.cpp#L9): `AShooterGameMode::BeginPlay()`
- [L18](../../../../Source/DreamEscape/Variant_Shooter/ShooterGameMode.cpp#L18): `AShooterGameMode::IncrementTeamScore(uint8 TeamByte)`

## 연결 파일

- [ShooterGameMode.h](ShooterGameMode.h.md)
- [ShooterUI.h](UI/ShooterUI.h.md)

[전체 소스 인덱스로](../../../README.md)
