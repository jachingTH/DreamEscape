---
type: source_file_summary
source: "DreamEscape/Variant_Horror/HorrorCharacter.cpp"
source_sha256: "B3F3D4670BE1FC85366E9CD0444CD59A47A04A517FE43281B60C86518385F75C"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# HorrorCharacter.cpp

손전등 초기화 및 별도 스프린트 게이지 실행.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Horror/HorrorCharacter.cpp](../../../../Source/DreamEscape/Variant_Horror/HorrorCharacter.cpp)
- 저장소의 현재 코드 기준으로 확인했다.

## 주요 내용

- 생성자에서 카메라에 Spotlight를 붙인다. 부모 걷기/달리기 값을 300/600으로 재설정하는 코드는 없다. 기본 C++ 값은 부모의 400/750이다.
- BeginPlay는 게이지 초기화와 반복 타이머 시작, EndPlay는 타이머 정리를 수행한다.
- SprintAction의 Started/Completed를 DoStartSprint/DoEndSprint에 연결한다.
- 달리기 시작/종료는 bSprinting 및 MaxWalkSpeed를 바꾸고 상태 이벤트를 방송한다. 부모 bIsSprinting과 동기화하는 코드는 없다.
- SprintFixedTick은 속도가 WalkSpeed보다 빠르고 달리는 중이면 게이지를 소비하며 고갈 시 회복 속도를 적용한다. 회복 후 입력 상태에 따라 속도를 복원한다.
- 부모 UpdateStamina와 별도 SprintMeter가 공존한다. UI와 스프린트 자원 통합이 필요한 지점이다.

## 연결 파일

- [HorrorCharacter.h](HorrorCharacter.h.md)

[전체 소스 인덱스로](../../../README.md)
