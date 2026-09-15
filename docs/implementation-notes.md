# 구현 상태와 확인할 사항

[코드 안내로](README.md)

Source 정적 분석에 근거한 기록이다. 런타임 오류 재현이나 빌드 검증 결과와 구분한다.

## 현재 구현된 기반

- 1인칭 이동·점프·시점과 기본 체력·스태미나.
- 6칸 인벤토리 데이터와 아이콘/선택 강조 UI.
- 시작 버튼 이벤트, 온라인 세션 생성·검색·참가·종료.
- 로비 준비 상태 및 선택 맵 인덱스 복제, 서버 맵 전환.
- 호러 스프린트/손전등과 슈터 무기·투사체·StateTree 예제.

## 연결 또는 추가 구현이 필요한 지점

| 영역 | 코드에서 확인한 사실 | 작업 시 확인할 부분 |
|---|---|---|
| 메인 메뉴 | 시작 이벤트만 방송 | 카메라 연출 및 후속 동작 연결 |
| 세션 검색 | BUILD_VERSION=0.1.0 필터 사용, 생성 시 해당 값 게시 없음 | 생성 설정과 검색 필터 일치 |
| 로비 | StartGame에서 CheckAllPlayersReady를 호출하지 않음 | 시작 버튼/서버 로직의 준비 검증 |
| 맵 목록 | SelectedMapIndex만 복제 | 각 참가자의 AvailableMaps 설정 일치 |
| 인게임 RPC | 효과 함수 본문은 로그 출력 | 실제 게임 동작과 효과 구현 |
| 인벤토리 | 수량 표시 및 자체 복제 없음 | 수량 UI·서버 권한 인벤토리 |
| 호러 상태 | SprintMeter와 CurrentStamina가 분리 | HUD 자원과 달리기 조건 통합 |
| 슈터 체력 | CurrentHP와 부모 CurrentHealth가 분리 | 피해와 HUD가 참조할 단일 상태 |
| 빌드 | UMG 공개 의존성이 중복 | 추후 Build.cs 정리 |

## Obsidian 정리 당시 코드와 다른 파일

| 파일 | 현재 GitHub 저장소 기준 |
|---|---|
| [InventoryBarWidget.cpp](source/DreamEscape/Private/InventoryBarWidget.cpp.md) | 캐릭터 이벤트 자체 구독/해제와 NativeDestruct 없음 |
| [InventoryBarWidget.h](source/DreamEscape/Public/InventoryBarWidget.h.md) | NativeDestruct 선언 없음 |
| [InventorySlotWidget.h](source/DreamEscape/Public/InventorySlotWidget.h.md) | 슬롯 설정 함수들이 일반 C++ 함수 |
| [HorrorCharacter.cpp](source/DreamEscape/Variant_Horror/HorrorCharacter.cpp.md) | SetSprinting, 부모 플래그 동기화, 300/600 재설정 없음 |
| [HorrorCharacter.h](source/DreamEscape/Variant_Horror/HorrorCharacter.h.md) | SetSprinting 선언 없음 |

이 차이는 문서에 반영했다. 두 프로젝트의 소스를 동기화하거나 수정하지 않았다.

## 기획과 구현의 구분

루트 README에 있는 정신력 단계, 그리드 시야 차단, 근접 음성, USB 지원, 강제 이탈 및 탈출 루프는 게임 기획이다. 이번 73개 C++ 파일만으로 해당 기능의 완성을 확인할 수 없다. Blueprint·맵·설정과 함께 별도 검증해야 한다.

## 문서 갱신

소스 변경 시 파일별 요약의 구현 설명과 source_sha256을 함께 갱신한다. 새 파일이 생기면 source-index.md에 링크를 추가한다. 함수 위치 링크는 소스 줄 변경 시 재확인한다.
