---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/ShooterPlayerController.h"
source_sha256: "98F639C7A5980C8B1F3D21876EF08AF81A6BACF3F7E571F0CEA02FE9D4379482"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterPlayerController.h

탄약/피해 UI 및 캐릭터 재생성.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 86줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- 입력 컨텍스트, 터치 UI, 탄약 UI, 재생성 CharacterClass와 PlayerPawnTag를 선언한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API AShooterPlayerController : public APlayerController`
- [L26](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h#L26): `TArray<UInputMappingContext*> DefaultMappingContexts` — `UPROPERTY(EditAnywhere, Category="Input|Input Mappings")`
- [L30](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h#L30): `TArray<UInputMappingContext*> MobileExcludedMappingContexts` — `UPROPERTY(EditAnywhere, Category="Input|Input Mappings")`
- [L34](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h#L34): `TSubclassOf<UUserWidget> MobileControlsWidgetClass` — `UPROPERTY(EditAnywhere, Category="Input|Touch Controls")`
- [L38](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h#L38): `TObjectPtr<UUserWidget> MobileControlsWidget` — `UPROPERTY()`
- [L42](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h#L42): `bool bForceTouchControls = false` — `UPROPERTY(EditAnywhere, Config, Category = "Input|Touch Controls")`
- [L46](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h#L46): `TSubclassOf<AShooterCharacter> CharacterClass` — `UPROPERTY(EditAnywhere, Category="Shooter|Respawn")`
- [L50](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h#L50): `TSubclassOf<UShooterBulletCounterUI> BulletCounterUIClass` — `UPROPERTY(EditAnywhere, Category="Shooter|UI")`
- [L54](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h#L54): `FName PlayerPawnTag = FName("Player")` — `UPROPERTY(EditAnywhere, Category="Shooter|Player")`
- [L58](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h#L58): `TObjectPtr<UShooterBulletCounterUI> BulletCounterUI` — `UPROPERTY()`
- [L73](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h#L73): `void OnPawnDestroyed(AActor* DestroyedActor)` — `UFUNCTION()`
- [L77](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h#L77): `void OnBulletCountUpdated(int32 MagazineSize, int32 Bullets)` — `UFUNCTION()`
- [L81](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.h#L81): `void OnPawnDamaged(float LifePercent)` — `UFUNCTION()`

## 연결 파일

- [ShooterPlayerController.cpp](ShooterPlayerController.cpp.md)

[전체 소스 인덱스로](../../../README.md)
