---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/ShooterCharacter.cpp"
source_sha256: "1300CEBB00F36FD88604EB574265C96E939AA0ED731BE2D09C3F0A49ED8E65C7"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterCharacter.cpp

무기 교체·발사와 피해/사망을 다루는 플레이어 캐릭터.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 328줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- BeginPlay에서 CurrentHP를 MaxHP로 설정하고 입력에 발사·교체를 연결한다.
- 사망 중에는 이동/시점/점프/발사를 제한한다. 무기 전환은 소유 목록을 순환한다.
- 중복 무기 종류가 아니면 새 무기를 만들고 기존 무기를 비활성화한 뒤 새 무기를 활성화한다.
- 카메라 라인트레이스로 조준 위치를 계산하고 Pitch 입력으로 반동을 적용한다.
- 사망 시 무기·이동·입력을 중단하고 점수 및 사망 이벤트를 처리한다. 타이머 후 Destroy하며 재생성은 컨트롤러가 처리한다.
- PlayFiringMontage와 일부 무기 콜백은 비어 있다. 부모 CurrentHealth와 별도 CurrentHP가 공존한다.

## 구현 함수 위치

- [L16](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L16): `AShooterCharacter::AShooterCharacter()`
- [L25](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L25): `AShooterCharacter::BeginPlay()`
- [L36](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L36): `AShooterCharacter::EndPlay(EEndPlayReason::Type EndPlayReason)`
- [L44](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L44): `AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)`
- [L62](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L62): `AShooterCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)`
- [L85](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L85): `AShooterCharacter::DoAim(float Yaw, float Pitch)`
- [L94](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L94): `AShooterCharacter::DoMove(float Right, float Forward)`
- [L103](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L103): `AShooterCharacter::DoJumpStart()`
- [L112](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L112): `AShooterCharacter::DoJumpEnd()`
- [L121](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L121): `AShooterCharacter::DoStartFiring()`
- [L130](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L130): `AShooterCharacter::DoStopFiring()`
- [L139](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L139): `AShooterCharacter::DoSwitchWeapon()`
- [L169](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L169): `AShooterCharacter::AttachWeaponMeshes(AShooterWeapon* Weapon)`
- [L182](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L182): `AShooterCharacter::PlayFiringMontage(UAnimMontage* Montage)`
- [L187](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L187): `AShooterCharacter::AddWeaponRecoil(float Recoil)`
- [L193](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L193): `AShooterCharacter::UpdateWeaponHUD(int32 CurrentAmmo, int32 MagazineSize)`
- [L198](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L198): `AShooterCharacter::GetWeaponTargetLocation()`
- [L215](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L215): `AShooterCharacter::AddWeaponClass(const TSubclassOf<AShooterWeapon>& WeaponClass)`
- [L249](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L249): `AShooterCharacter::OnWeaponActivated(AShooterWeapon* Weapon)`
- [L259](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L259): `AShooterCharacter::OnWeaponDeactivated(AShooterWeapon* Weapon)`
- [L264](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L264): `AShooterCharacter::OnSemiWeaponRefire()`
- [L269](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L269): `AShooterCharacter::FindWeaponOfType(TSubclassOf<AShooterWeapon> WeaponClass)`
- [L285](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L285): `AShooterCharacter::Die()`
- [L318](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L318): `AShooterCharacter::OnRespawn()`
- [L324](../../../../Source/DreamEscape/Variant_Shooter/ShooterCharacter.cpp#L324): `AShooterCharacter::IsDead()`

## 연결 파일

- [ShooterCharacter.h](ShooterCharacter.h.md)
- [ShooterWeapon.h](Weapons/ShooterWeapon.h.md)
- [ShooterGameMode.h](ShooterGameMode.h.md)

[전체 소스 인덱스로](../../../README.md)
