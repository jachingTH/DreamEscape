---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.cpp"
source_sha256: "FA4A8382A203E5599E92DA132CA389FC3E1705EB4E564B41158E8D56A8D256ED"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterProjectile.cpp

투사체 충돌과 직접/폭발 피해 처리.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.cpp](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 167줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- 반경 16 충돌 구와 초기/최대 속도 3000의 이동 컴포넌트를 구성한다.
- BeginPlay에서 발사자를 이동 충돌 무시 대상으로 추가한다.
- 첫 충돌만 처리하고 소음을 발생시킨 뒤 직접 피해 또는 범위 Overlap 탐색을 수행한다.
- 폭발은 액터별 중복 피해를 제거한다. Character에 ApplyDamage, 물리 컴포넌트에 충격을 가한다.
- 충돌 BP 이벤트를 호출하고 설정에 따라 즉시 또는 타이머로 파괴한다.

## 구현 함수 위치

- [L16](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.cpp#L16): `AShooterProjectile::AShooterProjectile()`
- [L39](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.cpp#L39): `AShooterProjectile::BeginPlay()`
- [L47](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.cpp#L47): `AShooterProjectile::EndPlay(EEndPlayReason::Type EndPlayReason)`
- [L55](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.cpp#L55): `AShooterProjectile::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)`
- [L99](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.cpp#L99): `AShooterProjectile::ExplosionCheck(const FVector& ExplosionCenter)`
- [L142](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.cpp#L142): `AShooterProjectile::ProcessHit(AActor* HitActor, UPrimitiveComponent* HitComp, const FVector& HitLocation, const FVector& HitDirection)`
- [L163](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterProjectile.cpp#L163): `AShooterProjectile::OnDeferredDestruction()`

## 연결 파일

- [ShooterProjectile.h](ShooterProjectile.h.md)

[전체 소스 인덱스로](../../../../README.md)
