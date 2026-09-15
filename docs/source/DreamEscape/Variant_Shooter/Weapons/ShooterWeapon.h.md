---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h"
source_sha256: "94146B3E07892B9E9E5D1A1127B80CBA0B32DE06D0CBC16898089986970A9040"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterWeapon.h

소유자 인터페이스를 통해 동작하는 1·3인칭 무기.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 180줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- 두 메시, 투사체 클래스, 탄창, 연사/반동/조준/애니메이션/소음 설정을 보관한다.
- 장착·활성화·발사·중단 및 탄약/메시 조회 함수를 제공한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API AShooterWeapon : public AActor`
- [L29](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L29): `USkeletalMeshComponent* FirstPersonMesh` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))`
- [L33](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L33): `USkeletalMeshComponent* ThirdPersonMesh` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))`
- [L42](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L42): `TSubclassOf<AShooterProjectile> ProjectileClass` — `UPROPERTY(EditAnywhere, Category="Ammo")`
- [L46](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L46): `int32 MagazineSize = 10` — `UPROPERTY(EditAnywhere, Category="Ammo", meta = (ClampMin = 0, ClampMax = 100))`
- [L53](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L53): `UAnimMontage* FiringMontage` — `UPROPERTY(EditAnywhere, Category="Animation")`
- [L57](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L57): `TSubclassOf<UAnimInstance> FirstPersonAnimInstanceClass` — `UPROPERTY(EditAnywhere, Category="Animation")`
- [L61](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L61): `TSubclassOf<UAnimInstance> ThirdPersonAnimInstanceClass` — `UPROPERTY(EditAnywhere, Category="Animation")`
- [L65](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L65): `float AimVariance = 0.0f` — `UPROPERTY(EditAnywhere, Category="Aim", meta = (ClampMin = 0, ClampMax = 90, Units = "Degrees"))`
- [L69](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L69): `float FiringRecoil = 0.0f` — `UPROPERTY(EditAnywhere, Category="Aim", meta = (ClampMin = 0, ClampMax = 100))`
- [L73](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L73): `FName MuzzleSocketName` — `UPROPERTY(EditAnywhere, Category="Aim")`
- [L77](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L77): `float MuzzleOffset = 10.0f` — `UPROPERTY(EditAnywhere, Category="Aim", meta = (ClampMin = 0, ClampMax = 1000, Units = "cm"))`
- [L81](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L81): `bool bFullAuto = false` — `UPROPERTY(EditAnywhere, Category="Refire")`
- [L85](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L85): `float RefireRate = 0.5f` — `UPROPERTY(EditAnywhere, Category="Refire", meta = (ClampMin = 0, ClampMax = 5, Units = "s"))`
- [L101](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L101): `float ShotLoudness = 1.0f` — `UPROPERTY(EditAnywhere, Category="Perception", meta = (ClampMin = 0, ClampMax = 100))`
- [L105](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L105): `float ShotNoiseRange = 3000.0f` — `UPROPERTY(EditAnywhere, Category="Perception", meta = (ClampMin = 0, ClampMax = 100000, Units = "cm"))`
- [L109](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L109): `FName ShotNoiseTag = FName("Shot")` — `UPROPERTY(EditAnywhere, Category="Perception")`
- [L128](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L128): `void OnOwnerDestroyed(AActor* DestroyedActor)` — `UFUNCTION()`
- [L162](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L162): `USkeletalMeshComponent* GetFirstPersonMesh() const` — `UFUNCTION(BlueprintPure, Category="Weapon")`
- [L166](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.h#L166): `USkeletalMeshComponent* GetThirdPersonMesh() const` — `UFUNCTION(BlueprintPure, Category="Weapon")`

## 연결 파일

- [ShooterWeapon.cpp](ShooterWeapon.cpp.md)
- [ShooterWeaponHolder.h](ShooterWeaponHolder.h.md)

[전체 소스 인덱스로](../../../../README.md)
