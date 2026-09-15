---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp"
source_sha256: "EC857F4D27012A3651DB7F1C3DDB6B1B2E116EDD86AA5D8B3AFA07C561DEFA72"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterNPC.cpp

무기를 소유하고 발사하는 슈터 AI 캐릭터.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 214줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- BeginPlay에서 자신을 Owner/Instigator로 무기를 생성한다.
- TakeDamage는 별도 CurrentHP를 줄인다. 사망 시 이벤트·팀 점수·충돌 해제·래그돌·지연 파괴를 수행한다.
- 조준은 대상 높이 오프셋과 원뿔 방향 오차를 반영한 라인트레이스로 계산한다.
- StartShooting/StopShooting과 반자동 재발사 콜백으로 무기를 제어한다.
- 몽타주, 반동, HUD, 추가 무기 지급 등 일부 인터페이스 함수 본문은 비어 있다.

## 구현 함수 위치

- [L15](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L15): `AShooterNPC::BeginPlay()`
- [L28](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L28): `AShooterNPC::EndPlay(const EEndPlayReason::Type EndPlayReason)`
- [L36](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L36): `AShooterNPC::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)`
- [L56](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L56): `AShooterNPC::AttachWeaponMeshes(AShooterWeapon* WeaponToAttach)`
- [L68](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L68): `AShooterNPC::PlayFiringMontage(UAnimMontage* Montage)`
- [L73](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L73): `AShooterNPC::AddWeaponRecoil(float Recoil)`
- [L78](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L78): `AShooterNPC::UpdateWeaponHUD(int32 CurrentAmmo, int32 MagazineSize)`
- [L83](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L83): `AShooterNPC::GetWeaponTargetLocation()`
- [L126](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L126): `AShooterNPC::AddWeaponClass(const TSubclassOf<AShooterWeapon>& InWeaponClass)`
- [L131](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L131): `AShooterNPC::OnWeaponActivated(AShooterWeapon* InWeapon)`
- [L136](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L136): `AShooterNPC::OnWeaponDeactivated(AShooterWeapon* InWeapon)`
- [L141](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L141): `AShooterNPC::OnSemiWeaponRefire()`
- [L151](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L151): `AShooterNPC::Die()`
- [L190](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L190): `AShooterNPC::DeferredDestruction()`
- [L195](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L195): `AShooterNPC::StartShooting(AActor* ActorToShoot)`
- [L207](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPC.cpp#L207): `AShooterNPC::StopShooting()`

## 연결 파일

- [ShooterNPC.h](ShooterNPC.h.md)
- [ShooterWeapon.h](../Weapons/ShooterWeapon.h.md)
- [ShooterGameMode.h](../ShooterGameMode.h.md)

[전체 소스 인덱스로](../../../../README.md)
