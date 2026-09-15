---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/UI/ShooterUI.h"
source_sha256: "B382F9A7A8E84001E1FC9719E7ED295D947FC38BA4382EA852391599EABEAB3B"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterUI.h

팀 점수 표시용 Blueprint 확장 위젯.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/UI/ShooterUI.h](../../../../../Source/DreamEscape/Variant_Shooter/UI/ShooterUI.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 22줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- BP_UpdateScore(TeamByte, Score)를 BlueprintImplementableEvent로 공개한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API UShooterUI : public UUserWidget`
- [L20](../../../../../Source/DreamEscape/Variant_Shooter/UI/ShooterUI.h#L20): `void BP_UpdateScore(uint8 TeamByte, int32 Score)` — `UFUNCTION(BlueprintImplementableEvent, Category="Shooter", meta = (DisplayName = "Update Score"))`

## 연결 파일

- [ShooterUI.cpp](ShooterUI.cpp.md)

[전체 소스 인덱스로](../../../../README.md)
