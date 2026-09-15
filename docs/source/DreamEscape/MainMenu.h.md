---
type: source_file_summary
source: "DreamEscape/MainMenu.h"
source_sha256: "E709810101765BC5513702A903BC0679BC7F66C5AC91534BBB59799312AF368E"
source_encoding: "UTF-8"
source_modified: "2026-08-12T23:34:47"
last_updated: "2026-09-15"
---

# MainMenu.h

메인 메뉴의 시작 버튼 요청을 외부로 전달하는 UMG 위젯.

## 파일 정보

- 원본: [Source/DreamEscape/MainMenu.h](../../../Source/DreamEscape/MainMenu.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 31줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- UUserWidget을 상속한다.
- Btn_MainMenu_GameStart는 필수 BindWidget 버튼이다. Designer 이름과 일치해야 한다.
- OnStartClicked는 BlueprintAssignable 이벤트다. bStartAlreadyClicked로 중복 실행을 막는다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API UMainMenu : public UUserWidget`
- [L17](../../../Source/DreamEscape/MainMenu.h#L17): `FOnStartClickedSignature OnStartClicked` — `UPROPERTY(BlueprintAssignable, Category = "Main Menu")`
- [L23](../../../Source/DreamEscape/MainMenu.h#L23): `TObjectPtr<UButton> Btn_MainMenu_GameStart` — `UPROPERTY(meta = (BindWidget))`
- [L26](../../../Source/DreamEscape/MainMenu.h#L26): `void StartClickedHandler()` — `UFUNCTION()`
- 이벤트: `DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartClickedSignature);`

## 연결 파일

- [MainMenu.cpp](MainMenu.cpp.md)

[전체 소스 인덱스로](../../README.md)
