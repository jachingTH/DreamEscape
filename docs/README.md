# DreamEscape 코드 안내

**현재 저장소의 C++ 구현을 빠르게 파악하기 위한 문서다.** 루트 README의 게임 기획과 구현 완료 여부를 구분해서 읽는다.

- [전체 구조와 실행 흐름](architecture.md)
- [전체 73개 소스 파일 요약](source-index.md)
- [구현 상태와 확인할 사항](implementation-notes.md)

## 먼저 읽을 순서

1. [DreamEscapeCharacter.cpp](source/DreamEscape/DreamEscapeCharacter.cpp.md): 이동, 상태, 인벤토리, HUD가 연결되는 중심.
2. [DreamEscapeInGameHUD.h](source/DreamEscape/Public/DreamEscapeInGameHUD.h.md): 상태창과 인벤토리 바 구성.
3. [DreamEscapeGameInstance.cpp](source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp.md): 온라인 세션 생명주기.
4. [LobbyGameMode.cpp](source/DreamEscape/Lobby/LobbyGameMode.cpp.md): 맵 선택과 서버 전환.
5. [InGameCharacter.cpp](source/DreamEscape/Private/Player/InGameCharacter.cpp.md): 별도 네트워크 캐릭터의 복제/RPC 골격.

## 기능별 시작점

| 수정하려는 기능 | 먼저 볼 파일 | 확인할 내용 |
|---|---|---|
| 시작 버튼 | [MainMenu.cpp](source/DreamEscape/MainMenu.cpp.md) | 중복 클릭 방지, 시작 이벤트 |
| 이동·점프·시점 | [DreamEscapeCharacter.cpp](source/DreamEscape/DreamEscapeCharacter.cpp.md) | 입력 바인딩과 이동 함수 |
| 카메라 상하 각도 | [DreamEscapeCameraManager.cpp](source/DreamEscape/DreamEscapeCameraManager.cpp.md) | Pitch -70~80 |
| 체력·스태미나 표시 | [PlayerStatusWidget.cpp](source/DreamEscape/Private/PlayerStatusWidget.cpp.md) | 비율 계산과 텍스트 |
| 인벤토리 | [InventoryBarWidget.cpp](source/DreamEscape/Private/InventoryBarWidget.cpp.md) | 6개 슬롯 갱신 |
| Steam 세션 | [DreamEscapeGameInstance.cpp](source/DreamEscape/Private/Online/DreamEscapeGameInstance.cpp.md) | Host/Find/Join/Cleanup |
| 로비 준비 | [LobbyPlayerState.cpp](source/DreamEscape/Lobby/LobbyPlayerState.cpp.md) | 서버 RPC와 RepNotify |
| 맵 선택 | [LobbyGameState.cpp](source/DreamEscape/Lobby/LobbyGameState.cpp.md) | 선택 인덱스 복제 |
| 호러 달리기 | [HorrorCharacter.cpp](source/DreamEscape/Variant_Horror/HorrorCharacter.cpp.md) | 별도 스프린트 게이지 |
| 무기 | [ShooterWeapon.cpp](source/DreamEscape/Variant_Shooter/Weapons/ShooterWeapon.cpp.md) | 탄약·발사·연사 |
| AI | [ShooterStateTreeUtility.cpp](source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp.md) | 감지·포커스·발사 태스크 |
| 빌드 의존성 | [DreamEscape.Build.cs](source/DreamEscape/DreamEscape.Build.cs.md) | UMG, Enhanced Input, OnlineSubsystem |

## 문서 범위

- 헤더 36개, 구현 34개, C# 빌드 규칙 3개를 각각 별도 문서로 정리했다.
- 각 문서에서 해당 저장소의 실제 코드와 관련 파일로 이동할 수 있다.
- 기준일: 2026-09-15. 파일별 SHA-256은 문서 상단의 source_sha256에 기록했다.
- Blueprint·맵 에셋의 내부 설정은 분석하지 않았으며 빌드나 플레이 테스트를 수행한 결과 문서가 아니다.
- 원래 Obsidian 정리본과 다른 5개 파일은 이 저장소의 코드에 맞췄다.
