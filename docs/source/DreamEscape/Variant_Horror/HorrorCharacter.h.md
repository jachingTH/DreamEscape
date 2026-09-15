---
type: source_file_summary
source: "DreamEscape/Variant_Horror/HorrorCharacter.h"
source_sha256: "DCC0109B11B130DF0E75385112B1404EEABF68DEA6577BF2DA6FE1A783DD8ACB"
source_encoding: "UTF-8"
source_modified: "2026-09-01T22:42:45"
last_updated: "2026-09-15"
---

# HorrorCharacter.h

손전등과 스프린트 타이머를 추가하는 호러 캐릭터.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Horror/HorrorCharacter.h](../../../../Source/DreamEscape/Variant_Horror/HorrorCharacter.h)
- 저장소의 현재 코드 기준으로 확인했다.

## 주요 내용

- ADreamEscapeCharacter를 상속하고 SpotLight, SprintAction, bSprinting, bRecovering, SprintMeter를 선언한다.
- SprintFixedTickTime=0.03333, SprintTime=3, RecoveringWalkSpeed=150이다.
- DoStartSprint/DoEndSprint는 BlueprintCallable이며, 게이지와 달리기 상태 델리게이트를 제공한다.
- 별도 WalkSpeed/SprintSpeed 선언은 주석 처리되어 부모 값을 사용한다. SetSprinting 함수는 이 저장소에 없다.

## 연결 파일

- [HorrorCharacter.cpp](HorrorCharacter.cpp.md)
- [DreamEscapeCharacter.h](../DreamEscapeCharacter.h.md)

[전체 소스 인덱스로](../../../README.md)
