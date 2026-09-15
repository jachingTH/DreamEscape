---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/Weapons/ShooterPickup.cpp"
source_sha256: "6BEEBC84244502B3BAC7225DB7479D0ECB817E4608F9B5069C64066C5F90C56F"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterPickup.cpp

데이터 테이블 기반 무기 지급 및 재등장.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.cpp](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 108줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- Pawn 겹침을 감지하는 SphereCollision과 메시를 만든다.
- OnConstruction에서 데이터 테이블의 메시를 동기 로딩하고 BeginPlay에서 무기 클래스를 읽는다.
- 겹친 액터가 IShooterWeaponHolder이면 무기를 지급하고 픽업을 숨긴 후 충돌/틱을 끄고 타이머를 예약한다.
- 재등장 시 BP_OnRespawn을 호출한다. 충돌·틱 재활성화를 위해 해당 BP에서 FinishRespawn을 호출해야 한다.

## 구현 함수 위치

- [L13](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.cpp#L13): `AShooterPickup::AShooterPickup()`
- [L41](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.cpp#L41): `AShooterPickup::OnConstruction(const FTransform& Transform)`
- [L52](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.cpp#L52): `AShooterPickup::BeginPlay()`
- [L63](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.cpp#L63): `AShooterPickup::EndPlay(const EEndPlayReason::Type EndPlayReason)`
- [L71](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.cpp#L71): `AShooterPickup::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)`
- [L92](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.cpp#L92): `AShooterPickup::RespawnPickup()`
- [L101](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.cpp#L101): `AShooterPickup::FinishRespawn()`

## 연결 파일

- [ShooterPickup.h](ShooterPickup.h.md)
- [ShooterWeaponHolder.h](ShooterWeaponHolder.h.md)
- [ShooterWeapon.h](ShooterWeapon.h.md)

[전체 소스 인덱스로](../../../../README.md)
