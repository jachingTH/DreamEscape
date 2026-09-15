---
type: source_file_summary
source: "DreamEscape/Public/InventoryBarWidget.h"
source_sha256: "E11FBBF8B308BD30BB382B9F59AAF5D81DC9EAA90BADB0B94B8D8C81A34A16F4"
source_encoding: "UTF-8"
source_modified: "2026-09-01T01:01:19"
last_updated: "2026-09-15"
---

# InventoryBarWidget.h

6칸 인벤토리 바의 UMG 계약.

## 파일 정보

- 원본: [Source/DreamEscape/Public/InventoryBarWidget.h](../../../../Source/DreamEscape/Public/InventoryBarWidget.h)
- 저장소의 현재 코드 기준으로 확인했다.

## 주요 내용

- Slot_0~Slot_5를 필수 BindWidget으로 선언하고 SlotArray에 보관한다.
- NativeConstruct, UpdateSelection, UpdateSlotContent를 선언한다.
- NativeDestruct 재정의는 현재 저장소에 없다.

## 연결 파일

- [InventoryBarWidget.cpp](../Private/InventoryBarWidget.cpp.md)
- [ItemData.h](../ItemData.h.md)

[전체 소스 인덱스로](../../../README.md)
