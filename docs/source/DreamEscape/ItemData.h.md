---
type: source_file_summary
source: "DreamEscape/ItemData.h"
source_sha256: "C902564D36985F63E8EC149BB510B98D56FAE4C261B0D0046E949923271F4FE4"
source_encoding: "CP949"
source_modified: "2026-08-31T23:25:04"
last_updated: "2026-09-15"
---

# ItemData.h

인벤토리 한 칸의 데이터 구조.

## 파일 정보

- 원본: [Source/DreamEscape/ItemData.h](../../../Source/DreamEscape/ItemData.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 55줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- FInventorySlotData는 UObject가 아닌 BlueprintType USTRUCT다.
- ItemID, ItemIcon, StackCount, MaxStackCount를 저장하며 기본값은 None/null/0/1이다.
- 기본 생성자와 값 지정 생성자가 있다.
- IsEmpty는 ItemID가 None이거나 StackCount가 0 이하이면 true를 반환한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `struct FInventorySlotData`
- [L17](../../../Source/DreamEscape/ItemData.h#L17): `FName ItemID = NAME_None` — `UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")`
- [L21](../../../Source/DreamEscape/ItemData.h#L21): `TObjectPtr<UTexture2D> ItemIcon = nullptr` — `UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")`
- [L25](../../../Source/DreamEscape/ItemData.h#L25): `int32 StackCount = 0` — `UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")`
- [L29](../../../Source/DreamEscape/ItemData.h#L29): `int32 MaxStackCount = 1` — `UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")`

## 연결 파일

- 직접 연결되는 다른 프로젝트 소스 파일 없음.

[전체 소스 인덱스로](../../README.md)
