---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h"
source_sha256: "7AAB107A63F20743FD04F0AC98AECF52F9988D0CC802B464428E6759F7131213"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterProjectile.h

투사체 충돌과 직접/폭발 피해 처리.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 109줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- SphereCollision, ProjectileMovement, 피해/소음/폭발/지연 파괴 설정을 선언한다.
- 기본 피해 25, 폭발 반경 500, 지연 파괴 5초이며 폭발 기본값은 false다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API AShooterProjectile : public AActor`
- [L23](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h#L23): `USphereComponent* CollisionComponent` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))`
- [L27](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h#L27): `UProjectileMovementComponent* ProjectileMovement` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))`
- [L33](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h#L33): `float NoiseLoudness = 3.0f` — `UPROPERTY(EditAnywhere, Category="Projectile|Noise", meta = (ClampMin = 0, ClampMax = 100))`
- [L37](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h#L37): `float NoiseRange = 3000.0f` — `UPROPERTY(EditAnywhere, Category="Projectile|Noise", meta = (ClampMin = 0, ClampMax = 100000, Units = "cm"))`
- [L41](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h#L41): `FName NoiseTag = FName("Projectile")` — `UPROPERTY(EditAnywhere, Category="Noise")`
- [L45](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h#L45): `float PhysicsForce = 100.0f` — `UPROPERTY(EditAnywhere, Category="Projectile|Hit", meta = (ClampMin = 0, ClampMax = 50000))`
- [L49](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h#L49): `float HitDamage = 25.0f` — `UPROPERTY(EditAnywhere, Category="Projectile|Hit", meta = (ClampMin = 0, ClampMax = 100))`
- [L53](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h#L53): `TSubclassOf<UDamageType> HitDamageType` — `UPROPERTY(EditAnywhere, Category="Projectile|Hit")`
- [L57](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h#L57): `bool bDamageOwner = false` — `UPROPERTY(EditAnywhere, Category="Projectile|Hit")`
- [L61](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h#L61): `bool bExplodeOnHit = false` — `UPROPERTY(EditAnywhere, Category="Projectile|Explosion")`
- [L65](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h#L65): `float ExplosionRadius = 500.0f` — `UPROPERTY(EditAnywhere, Category="Projectile|Explosion", meta = (ClampMin = 0, ClampMax = 5000, Units = "cm"))`
- [L72](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h#L72): `float DeferredDestructionTime = 5.0f` — `UPROPERTY(EditAnywhere, Category="Projectile|Destruction", meta = (ClampMin = 0, ClampMax = 10, Units = "s"))`
- [L103](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.h#L103): `void BP_OnProjectileHit(const FHitResult& Hit)` — `UFUNCTION(BlueprintImplementableEvent, Category="Projectile", meta = (DisplayName = "On Projectile Hit"))`

## 연결 파일

- [ShooterProjectile.cpp](ShooterProjectile.cpp.md)

[전체 소스 인덱스로](../../../../README.md)
