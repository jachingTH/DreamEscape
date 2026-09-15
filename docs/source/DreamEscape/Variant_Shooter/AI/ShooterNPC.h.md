---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/AI/ShooterNPC.h"
source_sha256: "C2A40F97806EC3FBD1B52FF2AF0570661E1E40FDA451FB5C8EEF3179E7D192DE"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterNPC.h

무기를 소유하고 발사하는 슈터 AI 캐릭터.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 157줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- ADreamEscapeCharacter와 IShooterWeaponHolder를 상속한다.
- 별도 CurrentHP=100, 무기 클래스, 조준 오차/거리, 사망 태그 및 지연 파괴 시간을 선언한다.
- OnPawnDeath와 StartShooting/StopShooting을 제공한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API AShooterNPC : public ADreamEscapeCharacter, public IShooterWeaponHolder`
- [L27](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h#L27): `float CurrentHP = 100.0f` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Damage")`
- [L33](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h#L33): `FName RagdollCollisionProfile = FName("Ragdoll")` — `UPROPERTY(EditAnywhere, Category="Damage")`
- [L37](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h#L37): `float DeferredDestructionTime = 5.0f` — `UPROPERTY(EditAnywhere, Category="Damage")`
- [L41](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h#L41): `uint8 TeamByte = 1` — `UPROPERTY(EditAnywhere, Category="Team")`
- [L45](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h#L45): `FName DeathTag = FName("Dead")` — `UPROPERTY(EditAnywhere, Category="Team")`
- [L52](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h#L52): `TSubclassOf<AShooterWeapon> WeaponClass` — `UPROPERTY(EditAnywhere, Category="Weapon")`
- [L56](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h#L56): `FName FirstPersonWeaponSocket = FName("HandGrip_R")` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Weapons")`
- [L60](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h#L60): `FName ThirdPersonWeaponSocket = FName("HandGrip_R")` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Weapons")`
- [L64](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h#L64): `float AimRange = 10000.0f` — `UPROPERTY(EditAnywhere, Category="Aim")`
- [L68](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h#L68): `float AimVarianceHalfAngle = 10.0f` — `UPROPERTY(EditAnywhere, Category="Aim")`
- [L72](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h#L72): `float MinAimOffsetZ = -35.0f` — `UPROPERTY(EditAnywhere, Category="Aim")`
- [L76](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.h#L76): `float MaxAimOffsetZ = -60.0f` — `UPROPERTY(EditAnywhere, Category="Aim")`
- 이벤트: `DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPawnDeathDelegate);`

## 연결 파일

- [ShooterNPC.cpp](ShooterNPC.cpp.md)
- [DreamEscapeCharacter.h](../../DreamEscapeCharacter.h.md)
- [ShooterWeaponHolder.h](../Weapons/ShooterWeaponHolder.h.md)

[전체 소스 인덱스로](../../../../README.md)
