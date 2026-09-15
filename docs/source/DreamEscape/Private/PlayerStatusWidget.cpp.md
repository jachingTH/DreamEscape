---
type: source_file_summary
source: "DreamEscape/Private/PlayerStatusWidget.cpp"
source_sha256: "A25C201C6738740BAC302EF43EA1079B4E7E73618AE9D22D6BEADADAF77A7740"
source_encoding: "CP949"
source_modified: "2026-09-02T00:37:42"
last_updated: "2026-09-15"
---

# PlayerStatusWidget.cpp

체력·스태미나 비율을 표시하는 위젯.

## 파일 정보

- 원본: [Source/DreamEscape/Private/PlayerStatusWidget.cpp](../../../../Source/DreamEscape/Private/PlayerStatusWidget.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 53줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- Max가 0 이하이면 갱신을 중단한다.
- Current/Max를 0~1로 제한해 ProgressBar에 반영한다.
- 비율에 100을 곱해 반올림하고 0~100% 텍스트로 표시한다.
- 이벤트 구독은 이 위젯 자체가 아니라 DreamEscapeCharacter에서 수행한다.

## 구현 함수 위치

- [L5](../../../../Source/DreamEscape/Private/PlayerStatusWidget.cpp#L5): `UPlayerStatusWidget::UpdateHealth(float Current, float Max)`
- [L30](../../../../Source/DreamEscape/Private/PlayerStatusWidget.cpp#L30): `UPlayerStatusWidget::UpdateStamina(float Current, float Max)`

## 연결 파일

- [PlayerStatusWidget.h](../Public/PlayerStatusWidget.h.md)

[전체 소스 인덱스로](../../../README.md)
