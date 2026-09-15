---
type: source_file_summary
source: "DreamEscape/Private/InventorySlotWidget.cpp"
source_sha256: "BB9120FAB101922A949D7154B3F1DEB0C4D90D90D03DD919AB71FB8253DB7AA3"
source_encoding: "UTF-8"
source_modified: "2026-09-01T00:58:48"
last_updated: "2026-09-15"
---

# InventorySlotWidget.cpp

단일 인벤토리 슬롯의 아이콘과 선택 상태 표시.

## 파일 정보

- 원본: [Source/DreamEscape/Private/InventorySlotWidget.cpp](../../../../Source/DreamEscape/Private/InventorySlotWidget.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 35줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- SetSlotData는 아이콘이 있으면 브러시를 설정해 표시하고 없으면 Hidden 처리한다.
- SetSelected는 선택 강조 Border의 Visible/Hidden을 바꾼다.
- SetSlotNumber는 숫자를 FText로 변환해 표시한다. StackCount/MaxStackCount는 이 구현에서 표시하지 않는다.

## 구현 함수 위치

- [L6](../../../../Source/DreamEscape/Private/InventorySlotWidget.cpp#L6): `UInventorySlotWidget::SetSlotData(const FInventorySlotData& Data)`
- [L21](../../../../Source/DreamEscape/Private/InventorySlotWidget.cpp#L21): `UInventorySlotWidget::SetSelected(bool bIsSelected)`
- [L29](../../../../Source/DreamEscape/Private/InventorySlotWidget.cpp#L29): `UInventorySlotWidget::SetSlotNumber(int32 Number)`

## 연결 파일

- [InventorySlotWidget.h](../Public/InventorySlotWidget.h.md)

[전체 소스 인덱스로](../../../README.md)
