---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/AI/ShooterAIController.cpp"
source_sha256: "03FADADC89F23D3AAF56382B7ADB9A533130CDDA2397EE357DA971D87DE67D06"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterAIController.cpp

NPC StateTree 실행과 AI Perception 이벤트 중계.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.cpp](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 78줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- StateTree 자동 시작을 끄고 감지/망각 이벤트를 연결한다.
- NPC를 소유하면 팀 태그와 사망 이벤트를 연결하고 StartLogic한다.
- 사망 시 경로 이동과 StateTree를 중단하고 UnPossess 후 컨트롤러를 파괴한다.
- 대상 설정/제거 함수를 제공하고 감지 자극은 ExecuteIfBound로 StateTree 쪽에 전달한다.

## 구현 함수 위치

- [L11](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.cpp#L11): `AShooterAIController::AShooterAIController()`
- [L25](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.cpp#L25): `AShooterAIController::OnPossess(APawn* InPawn)`
- [L43](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.cpp#L43): `AShooterAIController::OnPawnDeath()`
- [L58](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.cpp#L58): `AShooterAIController::SetCurrentTarget(AActor* Target)`
- [L63](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.cpp#L63): `AShooterAIController::ClearCurrentTarget()`
- [L68](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.cpp#L68): `AShooterAIController::OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)`
- [L74](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.cpp#L74): `AShooterAIController::OnPerceptionForgotten(AActor* Actor)`

## 연결 파일

- [ShooterAIController.h](ShooterAIController.h.md)
- [ShooterNPC.h](ShooterNPC.h.md)

[전체 소스 인덱스로](../../../../README.md)
