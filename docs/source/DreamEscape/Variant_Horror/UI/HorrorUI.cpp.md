---
type: source_file_summary
source: "DreamEscape/Variant_Horror/UI/HorrorUI.cpp"
source_sha256: "5FAB92FC1F734EB0DA9A03EFBD176D05C715360692CA4F399E72D2BC79D80799"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# HorrorUI.cpp

호러 캐릭터의 스프린트 이벤트를 Blueprint 화면에 전달.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Horror/UI/HorrorUI.cpp](../../../../../Source/DreamEscape/Variant_Horror/UI/HorrorUI.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 23줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- SetupCharacter에서 캐릭터의 게이지/상태 델리게이트를 구독한다.
- 수신한 Percent와 bool 값을 각각 Blueprint 구현 이벤트에 전달한다.

## 구현 함수 위치

- [L7](../../../../../Source/DreamEscape/Variant_Horror/UI/HorrorUI.cpp#L7): `UHorrorUI::SetupCharacter(AHorrorCharacter* HorrorCharacter)`
- [L13](../../../../../Source/DreamEscape/Variant_Horror/UI/HorrorUI.cpp#L13): `UHorrorUI::OnSprintMeterUpdated(float Percent)`
- [L19](../../../../../Source/DreamEscape/Variant_Horror/UI/HorrorUI.cpp#L19): `UHorrorUI::OnSprintStateChanged(bool bSprinting)`

## 연결 파일

- [HorrorUI.h](HorrorUI.h.md)
- [HorrorCharacter.h](../HorrorCharacter.h.md)

[전체 소스 인덱스로](../../../../README.md)
