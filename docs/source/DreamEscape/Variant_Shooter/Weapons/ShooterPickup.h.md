---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/Weapons/ShooterPickup.h"
source_sha256: "EE8D1FC68A71D4089CF37F2825115C7CB5814441A159036CE436EB8CD9AA28F8"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterPickup.h

데이터 테이블 기반 무기 지급 및 재등장.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.h](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 96줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- FWeaponTableRow에 표시 메시와 지급할 무기 클래스를 정의한다.
- 픽업 액터에 충돌/메시, 데이터 테이블 행, 재등장 타이머와 Blueprint 이벤트를 선언한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `struct FWeaponTableRow : public FTableRowBase`
- 타입: `class DREAMESCAPE_API AShooterPickup : public AActor`
- [L24](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.h#L24): `TSoftObjectPtr<UStaticMesh> StaticMesh` — `UPROPERTY(EditAnywhere)`
- [L28](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.h#L28): `TSubclassOf<AShooterWeapon> WeaponToSpawn` — `UPROPERTY(EditAnywhere)`
- [L41](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.h#L41): `USphereComponent* SphereCollision` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))`
- [L45](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.h#L45): `UStaticMeshComponent* Mesh` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))`
- [L51](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.h#L51): `FDataTableRowHandle WeaponType` — `UPROPERTY(EditAnywhere, Category="Pickup")`
- [L58](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.h#L58): `float RespawnTime = 4.0f` — `UPROPERTY(EditAnywhere, Category="Pickup", meta = (ClampMin = 0, ClampMax = 120, Units = "s"))`
- [L81](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.h#L81): `virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)` — `UFUNCTION()`
- [L90](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.h#L90): `void BP_OnRespawn()` — `UFUNCTION(BlueprintImplementableEvent, Category="Pickup", meta = (DisplayName = "OnRespawn"))`
- [L94](../../../../../Source/DreamEscape/Variant_Shooter/Weapons/ShooterPickup.h#L94): `void FinishRespawn()` — `UFUNCTION(BlueprintCallable, Category="Pickup")`

## 연결 파일

- [ShooterPickup.cpp](ShooterPickup.cpp.md)

[전체 소스 인덱스로](../../../../README.md)
