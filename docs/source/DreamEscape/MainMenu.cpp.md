---
type: source_file_summary
source: "DreamEscape/MainMenu.cpp"
source_sha256: "AFE1C85F41465D7C5E9FF4FCD09F0BE8A49C1171FD988B65D362866212630BDE"
source_encoding: "UTF-8"
source_modified: "2026-08-12T23:35:12"
last_updated: "2026-09-15"
---

# MainMenu.cpp

메인 메뉴의 시작 버튼 요청을 외부로 전달하는 UMG 위젯.

## 파일 정보

- 원본: [Source/DreamEscape/MainMenu.cpp](../../../Source/DreamEscape/MainMenu.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 32줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- NativeConstruct에서 기존 버튼 바인딩을 제거한 뒤 StartClickedHandler를 다시 연결한다.
- 처음 클릭할 때 플래그를 true로 바꾸고 OnStartClicked를 방송한다. 이후 클릭은 무시한다.
- 위젯 생성·화면 표시·카메라 180도 회전·레벨 이동은 이 파일에서 구현하지 않는다.
- 동일 위젯 인스턴스를 재사용할 때 클릭 플래그를 초기화하는 코드가 없다.

## 구현 함수 위치

- [L4](../../../Source/DreamEscape/MainMenu.cpp#L4): `UMainMenu::NativeConstruct()`
- [L22](../../../Source/DreamEscape/MainMenu.cpp#L22): `UMainMenu::StartClickedHandler()`

## 연결 파일

- [MainMenu.h](MainMenu.h.md)

[전체 소스 인덱스로](../../README.md)
