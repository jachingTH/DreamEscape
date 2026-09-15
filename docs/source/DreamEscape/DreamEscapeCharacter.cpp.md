---
type: source_file_summary
source: "DreamEscape/DreamEscapeCharacter.cpp"
source_sha256: "92B8AD2D05A6EF84C4BF31E724528571FEFE7B735C425BB2DAD435EFBDC4669C"
source_encoding: "CP949"
source_modified: "2026-09-01T22:56:50"
last_updated: "2026-09-15"
---

# DreamEscapeCharacter.cpp

1인칭 이동, 체력, 스태미나, 6칸 인벤토리 및 HUD 연결의 공통 캐릭터.

## 파일 정보

- 원본: [Source/DreamEscape/DreamEscapeCharacter.cpp](../../../Source/DreamEscape/DreamEscapeCharacter.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 334줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- 생성자에서 캡슐, 카메라, 소유자 전용 1인칭 메시를 구성하고 체력/스태미나를 초기화한다.
- BeginPlay에서 게임 입력 모드와 매핑 컨텍스트를 설정하고 인벤토리 6칸을 만든다. 로컬 컨트롤러에 HUD를 생성하고 상태 이벤트를 하위 위젯에 연결한 뒤 초기 값을 방송한다.
- SetupPlayerInputComponent는 Jump, Move, Look, MouseLook을 연결한다. 기본 클래스에서 Sprint나 슬롯 숫자 키는 직접 연결하지 않는다.
- ModifyHealth/ModifyStamina는 범위를 제한한 후 이벤트를 발행한다. 슬롯 선택은 0~5, 내용 변경은 유효 인덱스만 허용한다.
- Tick의 UpdateStamina는 이동 중 달리기에만 초당 20을 소비하고, 그 외 초당 15를 회복한다. 고갈 시 StopSprint를 호출한다.
- 이 저장소 버전에서 인벤토리 이벤트 연결은 BeginPlay의 HUD 초기화 경로에서 수행한다.

## 구현 함수 위치

- [L29](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L29): `ADreamEscapeCharacter::ADreamEscapeCharacter()`
- [L74](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L74): `ADreamEscapeCharacter::BeginPlay()`
- [L149](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L149): `ADreamEscapeCharacter::Tick(float DeltaTime)`
- [L160](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L160): `ADreamEscapeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)`
- [L193](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L193): `ADreamEscapeCharacter::MoveInput(const FInputActionValue& Value)`
- [L199](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L199): `ADreamEscapeCharacter::LookInput(const FInputActionValue& Value)`
- [L205](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L205): `ADreamEscapeCharacter::DoMove(float Right, float Forward)`
- [L214](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L214): `ADreamEscapeCharacter::DoAim(float Yaw, float Pitch)`
- [L223](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L223): `ADreamEscapeCharacter::DoJumpStart()`
- [L228](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L228): `ADreamEscapeCharacter::DoJumpEnd()`
- [L236](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L236): `ADreamEscapeCharacter::ModifyHealth(float Amount)`
- [L246](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L246): `ADreamEscapeCharacter::ModifyStamina(float Amount)`
- [L256](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L256): `ADreamEscapeCharacter::SelectInventorySlot(int32 SlotIndex)`
- [L266](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L266): `ADreamEscapeCharacter::SetInventorySlot(int32 SlotIndex, const FInventorySlotData& NewItemData)`
- [L279](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L279): `ADreamEscapeCharacter::StartSprint()`
- [L292](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L292): `ADreamEscapeCharacter::StopSprint()`
- [L301](../../../Source/DreamEscape/DreamEscapeCharacter.cpp#L301): `ADreamEscapeCharacter::UpdateStamina(float DeltaTime)`

## 연결 파일

- [DreamEscapeCharacter.h](DreamEscapeCharacter.h.md)
- [DreamEscapeInGameHUD.h](Public/DreamEscapeInGameHUD.h.md)
- [PlayerStatusWidget.h](Public/PlayerStatusWidget.h.md)
- [InventoryBarWidget.h](Public/InventoryBarWidget.h.md)

[전체 소스 인덱스로](../../README.md)
