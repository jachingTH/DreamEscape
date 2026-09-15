---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/Weapons/ShooterWeaponHolder.h"
source_sha256: "D432ED6838DFCDAC681614F323189E0F00FED0DE952132F2E96B58745E4B03E8"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterWeaponHolder.h

플레이어/NPC 공통 무기 소유 계약.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeaponHolder.h](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeaponHolder.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 55줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- UShooterWeaponHolder는 Unreal 인터페이스 래퍼이고 IShooterWeaponHolder에 순수 가상 함수 9개가 있다.
- 메시 장착, 몽타주, 반동, HUD, 조준, 무기 지급, 활성/비활성 및 반자동 준비 알림을 정의한다.
- ShooterCharacter와 ShooterNPC가 구현하고 ShooterWeapon/ShooterPickup이 사용한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class UShooterWeaponHolder : public UInterface`
- 타입: `class DREAMESCAPE_API IShooterWeaponHolder`

## 연결 파일

- [ShooterWeaponHolder.cpp](ShooterWeaponHolder.cpp.md)

[전체 소스 인덱스로](../../../../README.md)
