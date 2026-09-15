---
type: source_file_summary
source: "DreamEscape/Public/InventorySlotWidget.h"
source_sha256: "257158238B895DBD8C2582D8CB89A542F4BADB73D9D6CCC98E3EE6D0B4348C26"
source_encoding: "UTF-8"
source_modified: "2026-09-01T00:58:42"
last_updated: "2026-09-15"
---

# InventorySlotWidget.h

단일 슬롯의 아이콘·선택 강조·번호 위젯 선언.

## 파일 정보

- 원본: [Source/DreamEscape/Public/InventorySlotWidget.h](../../../../Source/DreamEscape/Public/InventorySlotWidget.h)
- 저장소의 현재 코드 기준으로 확인했다.

## 주요 내용

- Image_ItemIcon, Border_SelectedHighlight, Text_SlotNumber는 필수 BindWidget이다.
- SetSlotData, SetSelected, SetSlotNumber는 일반 C++ 함수다. 이 저장소 버전에서는 UFUNCTION 또는 BlueprintCallable로 노출하지 않는다.
- 수량 표시용 위젯은 선언하지 않는다.

## 연결 파일

- [InventorySlotWidget.cpp](../Private/InventorySlotWidget.cpp.md)
- [ItemData.h](../ItemData.h.md)

[전체 소스 인덱스로](../../../README.md)
