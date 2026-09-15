---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/ShooterCharacter.h"
source_sha256: "116FD06CB1B12E3E4A9D928CECC87DB4ED7339D6EF14080DADD38C5C5E702D06"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterCharacter.h

무기 교체·발사와 피해/사망을 다루는 플레이어 캐릭터.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/ShooterCharacter.h](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 187줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- ADreamEscapeCharacter 및 IShooterWeaponHolder를 상속한다.
- 발사/무기 전환 입력, 소유 무기 목록, 별도 MaxHP=500/CurrentHP와 팀 정보를 보관한다.
- 탄약/피해 이벤트와 Blueprint 사망 이벤트를 제공한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API AShooterCharacter : public ADreamEscapeCharacter, public IShooterWeaponHolder`
- [L29](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L29): `UPawnNoiseEmitterComponent* PawnNoiseEmitter` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))`
- [L35](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L35): `UInputAction* FireAction` — `UPROPERTY(EditAnywhere, Category ="Input")`
- [L39](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L39): `UInputAction* SwitchWeaponAction` — `UPROPERTY(EditAnywhere, Category ="Input")`
- [L43](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L43): `FName FirstPersonWeaponSocket = FName("HandGrip_R")` — `UPROPERTY(EditAnywhere, Category ="Weapons")`
- [L47](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L47): `FName ThirdPersonWeaponSocket = FName("HandGrip_R")` — `UPROPERTY(EditAnywhere, Category ="Weapons")`
- [L51](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L51): `float MaxAimDistance = 10000.0f` — `UPROPERTY(EditAnywhere, Category ="Aim", meta = (ClampMin = 0, ClampMax = 100000, Units = "cm"))`
- [L55](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L55): `float MaxHP = 500.0f` — `UPROPERTY(EditAnywhere, Category="Health")`
- [L62](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L62): `uint8 TeamByte = 0` — `UPROPERTY(EditAnywhere, Category="Team")`
- [L66](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L66): `FName DeathTag = FName("Dead")` — `UPROPERTY(EditAnywhere, Category="Team")`
- [L75](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L75): `float RespawnTime = 5.0f` — `UPROPERTY(EditAnywhere, Category ="Destruction", meta = (ClampMin = 0, ClampMax = 10, Units = "s"))`
- [L124](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L124): `void DoStartFiring()` — `UFUNCTION(BlueprintCallable, Category="Input")`
- [L128](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L128): `void DoStopFiring()` — `UFUNCTION(BlueprintCallable, Category="Input")`
- [L132](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L132): `void DoSwitchWeapon()` — `UFUNCTION(BlueprintCallable, Category="Input")`
- [L177](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.h#L177): `void BP_OnDeath()` — `UFUNCTION(BlueprintImplementableEvent, Category="Shooter", meta = (DisplayName = "On Death"))`
- 이벤트: `DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBulletCountUpdatedDelegate, int32, MagazineSize, int32, Bullets);`
- 이벤트: `DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDamagedDelegate, float, LifePercent);`

## 연결 파일

- [ShooterCharacter.cpp](ShooterCharacter.cpp.md)
- [DreamEscapeCharacter.h](../DreamEscapeCharacter.h.md)
- [ShooterWeaponHolder.h](Weapons/ShooterWeaponHolder.h.md)

[전체 소스 인덱스로](../../../README.md)
