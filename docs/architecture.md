# 전체 구조와 실행 흐름

[코드 안내로](README.md) · [파일 인덱스](source-index.md)

## 두 캐릭터 계열

~~~mermaid
flowchart TD
    Character["ACharacter"] --> Base["ADreamEscapeCharacter"]
    Character --> InGame["AInGameCharacter"]
    Base --> Horror["AHorrorCharacter"]
    Base --> Shooter["AShooterCharacter"]
    Base --> NPC["AShooterNPC"]
    Base --> HUD["UDreamEscapeInGameHUD"]
    HUD --> Status["UPlayerStatusWidget"]
    HUD --> Bar["UInventoryBarWidget"]
    Bar --> Slot["UInventorySlotWidget"]
    InGameGM["AInGameGameMode"] -->|DefaultPawnClass| InGame
~~~

상속 화살표는 부모에서 자식으로 표시한다. HUD 연결은 생성·소유 관계다.

- **DreamEscapeCharacter 계열:** 이동, 상태, HUD, 인벤토리를 공유한다.
- **InGameCharacter 계열:** ACharacter 직접 상속. 체력 복제와 액션 RPC 골격만 있다. 공통 캐릭터의 HUD/인벤토리를 상속하지 않는다.
- 실제 플레이에서 어느 계열이 쓰이는지는 레벨의 GameMode와 Blueprint 기본 클래스 설정을 확인해야 한다.

## 메뉴에서 인게임까지

1. MainMenu는 시작 버튼을 받아 OnStartClicked를 방송한다. 카메라 이동이나 세션 생성을 직접 호출하지 않는다.
2. 외부 호출로 GameInstance의 HostSession을 실행하면 세션 생성 완료 후 Lobby 맵을 listen으로 연다.
3. LobbyPlayerState는 준비 상태를 RPC로 변경한다. LobbyGameState는 선택 맵 인덱스를 복제한다.
4. LobbyGameMode::StartGame은 선택 맵 경로로 ServerTravel한다.
5. InGameGameMode를 사용하는 맵이라면 AInGameCharacter와 ALobbyPlayerState를 기본 클래스로 사용한다.

## 상태와 HUD

~~~mermaid
flowchart LR
    Input["InputAction"] --> Character["DreamEscapeCharacter"]
    Character -->|OnHealthChanged / OnStaminaChanged| Status["PlayerStatusWidget"]
    Character -->|OnSlotSelected / OnInventorySlotUpdated| Bar["InventoryBarWidget"]
    Bar --> Slot["InventorySlotWidget"]
~~~

BeginPlay에서 로컬 HUD를 생성하고 이벤트를 연결한다. 현재 GitHub 저장소의 InventoryBarWidget은 자체 이벤트 구독·해제를 구현하지 않는다.

## 네트워크 책임

| 소유자 | 상태/동작 | 현재 구현 |
|---|---|---|
| GameInstance | 세션 생성·검색·참가·종료 | OnlineSubsystem 비동기 콜백 |
| LobbyGameMode | 맵 선택·여행 | 서버 GameMode 함수 |
| LobbyGameState | SelectedMapIndex | RepNotify 및 DOREPLIFETIME |
| LobbyPlayerState | bIsReady | Reliable 서버 RPC 및 RepNotify |
| InGameCharacter | CurrentHealth | RepNotify |
| InGameCharacter | 액션 요청/효과 | 거리 검증 서버 RPC와 로그 출력 멀티캐스트 |
| DreamEscapeCharacter | 체력·스태미나·인벤토리 | 이 상태들에 대한 자체 복제/RPC 없음 |

## 호러와 슈터

- 호러는 손전등과 SprintMeter를 추가한다. 부모 CurrentStamina와 별도 자원이다.
- 슈터 플레이어와 NPC는 IShooterWeaponHolder를 구현한다. 무기가 소유자에게 조준·반동·HUD·메시 장착을 요청한다.
- 무기는 투사체를 생성하고, 투사체는 충돌/폭발 피해와 물리 충격을 처리한다.
- AIController는 Perception 이벤트를 StateTree에 전달한다. StateTree는 시야 판정·타깃 감지·포커스·발사를 수행한다.
- Shooter/Horror 코드는 현재 저장소에 존재하는 변형 구현이며, DreamEscape 최종 게임에 모두 활성화됐다는 의미는 아니다.

## 빌드

Game/Editor 타깃은 BuildSettingsVersion.V6, Unreal5_7 include 순서, DreamEscape 모듈을 사용한다. Build.cs에는 입력, AI/StateTree, UMG/Slate, 온라인 세션 의존성이 있다.
