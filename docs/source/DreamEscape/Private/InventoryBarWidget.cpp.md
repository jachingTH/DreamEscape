---
type: source_file_summary
source: "DreamEscape/Private/InventoryBarWidget.cpp"
source_sha256: "B98F03D319F7D493F14A443AA00B8EBC22623853E1D9BEA21AD1D148C072FF24"
source_encoding: "UTF-8"
source_modified: "2026-09-01T01:01:25"
last_updated: "2026-09-15"
---

# InventoryBarWidget.cpp

6개 슬롯 표시 초기화와 선택·내용 갱신.

## 파일 정보

- 원본: [Source/DreamEscape/Private/InventoryBarWidget.cpp](../../../../Source/DreamEscape/Private/InventoryBarWidget.cpp)
- 저장소의 현재 코드 기준으로 확인했다.

## 주요 내용

- NativeConstruct에서 Slot_0~Slot_5를 배열에 넣고 슬롯 번호 1~6 및 기본 선택 0번을 설정한다.
- UpdateSelection은 모든 슬롯의 선택 강조를 갱신한다.
- UpdateSlotContent는 인덱스와 포인터를 검사하고 SetSlotData를 호출한다.
- 이 저장소 버전은 위젯 내부에서 캐릭터 이벤트를 구독하거나 해제하지 않는다. 이벤트 연결은 DreamEscapeCharacter::BeginPlay에서 수행한다.

## 연결 파일

- [InventoryBarWidget.h](../Public/InventoryBarWidget.h.md)
- [InventorySlotWidget.h](../Public/InventorySlotWidget.h.md)
- [DreamEscapeCharacter.h](../DreamEscapeCharacter.h.md)

[전체 소스 인덱스로](../../../README.md)
