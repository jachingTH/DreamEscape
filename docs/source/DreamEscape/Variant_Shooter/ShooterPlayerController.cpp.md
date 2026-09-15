---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/ShooterPlayerController.cpp"
source_sha256: "54BFE30E14649BD3A5BCD8549DA7687CB4F8B90D968A89D58FBC2FF55898B285"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterPlayerController.cpp

탄약/피해 UI 및 캐릭터 재생성.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/ShooterPlayerController.cpp](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 153줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- 로컬 플레이어의 터치 및 탄약 UI를 생성하고 입력 컨텍스트를 등록한다.
- OnPossess에서 파괴 이벤트 및 캐릭터 탄약/피해 이벤트를 연결하고 Player 태그를 부여한다.
- Pawn 파괴 시 탄약 UI를 초기화하고 무작위 PlayerStart에서 CharacterClass를 생성해 Possess한다.
- 탄약과 피해 콜백은 BulletCounterUI의 Blueprint 이벤트로 값을 전달한다.

## 구현 함수 위치

- [L15](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.cpp#L15): `AShooterPlayerController::BeginPlay()`
- [L55](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.cpp#L55): `AShooterPlayerController::SetupInputComponent()`
- [L82](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.cpp#L82): `AShooterPlayerController::OnPossess(APawn* InPawn)`
- [L104](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.cpp#L104): `AShooterPlayerController::OnPawnDestroyed(AActor* DestroyedActor)`
- [L132](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.cpp#L132): `AShooterPlayerController::OnBulletCountUpdated(int32 MagazineSize, int32 Bullets)`
- [L141](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.cpp#L141): `AShooterPlayerController::OnPawnDamaged(float LifePercent)`
- [L149](../../../../Source/DreamEscape/Variant_Shooter/ShooterPlayerController.cpp#L149): `AShooterPlayerController::ShouldUseTouchControls()`

## 연결 파일

- [ShooterPlayerController.h](ShooterPlayerController.h.md)
- [ShooterCharacter.h](ShooterCharacter.h.md)
- [ShooterBulletCounterUI.h](UI/ShooterBulletCounterUI.h.md)
- [DreamEscape.h](../DreamEscape.h.md)

[전체 소스 인덱스로](../../../README.md)
