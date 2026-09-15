---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/UI/ShooterBulletCounterUI.h"
source_sha256: "9E08FBEAC684063ABD36D8A714AD7ECC2D88851AA587B4D2F97DF858FA999322"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterBulletCounterUI.h

탄약과 피격 표시용 Blueprint 확장 위젯.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/UI/ShooterBulletCounterUI.h](../../../../../Source/DreamEscape/Variant_Shooter/UI/ShooterBulletCounterUI.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 26줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- BP_UpdateBulletCounter와 BP_Damaged를 BlueprintImplementableEvent로 선언한다.
- 화면 디자인과 연출은 파생 Widget Blueprint에 있다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API UShooterBulletCounterUI : public UUserWidget`
- [L20](../../../../../Source/DreamEscape/Variant_Shooter/UI/ShooterBulletCounterUI.h#L20): `void BP_UpdateBulletCounter(int32 MagazineSize, int32 BulletCount)` — `UFUNCTION(BlueprintImplementableEvent, Category="Shooter", meta=(DisplayName = "UpdateBulletCounter"))`
- [L24](../../../../../Source/DreamEscape/Variant_Shooter/UI/ShooterBulletCounterUI.h#L24): `void BP_Damaged(float LifePercent)` — `UFUNCTION(BlueprintImplementableEvent, Category="Shooter", meta=(DisplayName = "Damaged"))`

## 연결 파일

- [ShooterBulletCounterUI.cpp](ShooterBulletCounterUI.cpp.md)

[전체 소스 인덱스로](../../../../README.md)
