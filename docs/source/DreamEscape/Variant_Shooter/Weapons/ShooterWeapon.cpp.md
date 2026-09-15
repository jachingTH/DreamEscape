---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp"
source_sha256: "964C49DA386241A1870919A84D0F62944C23CDAF0C6A6F3EB58013E02EC079B9"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterWeapon.cpp

소유자 인터페이스를 통해 동작하는 1·3인칭 무기.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 218줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- BeginPlay에서 소유자를 인터페이스로 참조하고 탄약을 채우며 메시 장착을 요청한다.
- Activate/Deactivate는 표시와 소유자 알림을 처리하고 비활성화 시 발사를 멈춘다.
- StartFiring/Fire는 연사 간격과 타이머를 처리하고 소유자의 조준 위치로 투사체를 생성한다.
- 발사 시 몽타주/반동/HUD 갱신을 소유자에 요청한다. 탄약이 0 이하이면 즉시 탄창을 채우며 별도 재장전 대기는 없다.
- 소유자 파괴 시 무기를 파괴하고 EndPlay에서 연사 타이머를 정리한다.

## 구현 함수 위치

- [L15](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L15): `AShooterWeapon::AShooterWeapon()`
- [L39](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L39): `AShooterWeapon::BeginPlay()`
- [L57](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L57): `AShooterWeapon::EndPlay(EEndPlayReason::Type EndPlayReason)`
- [L65](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L65): `AShooterWeapon::OnOwnerDestroyed(AActor* DestroyedActor)`
- [L71](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L71): `AShooterWeapon::ActivateWeapon()`
- [L80](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L80): `AShooterWeapon::DeactivateWeapon()`
- [L92](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L92): `AShooterWeapon::StartFiring()`
- [L117](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L117): `AShooterWeapon::StopFiring()`
- [L126](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L126): `AShooterWeapon::Fire()`
- [L156](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L156): `AShooterWeapon::FireCooldownExpired()`
- [L162](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L162): `AShooterWeapon::FireProjectile(const FVector& TargetLocation)`
- [L195](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L195): `AShooterWeapon::CalculateProjectileSpawnTransform(const FVector& TargetLocation)`
- [L210](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L210): `AShooterWeapon::GetFirstPersonAnimInstanceClass()`
- [L215](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp#L215): `AShooterWeapon::GetThirdPersonAnimInstanceClass()`

## 연결 파일

- [ShooterWeapon.h](ShooterWeapon.h.md)
- [ShooterProjectile.h](ShooterProjectile.h.md)
- [ShooterWeaponHolder.h](ShooterWeaponHolder.h.md)

[전체 소스 인덱스로](../../../../README.md)
