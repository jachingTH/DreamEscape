---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/AI/ShooterAIController.h"
source_sha256: "B7B0FC1A28D139C91AF4525479A3656168902895A3EB1FB0744D84865A415D4E"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterAIController.h

NPC StateTree 실행과 AI Perception 이벤트 중계.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.h](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 85줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- AAIController 파생이며 StateTreeAI/AIPerception 컴포넌트를 선언한다.
- 현재 대상과 Enemy 팀 태그, 일반 단일 델리게이트 2개를 보관한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API AShooterAIController : public AAIController`
- [L25](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.h#L25): `UStateTreeAIComponent* StateTreeAI` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))`
- [L29](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.h#L29): `UAIPerceptionComponent* AIPerception` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))`
- [L35](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.h#L35): `FName TeamTag = FName("Enemy")` — `UPROPERTY(EditAnywhere, Category="Shooter")`
- [L62](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.h#L62): `void OnPawnDeath()` — `UFUNCTION()`
- [L79](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.h#L79): `void OnPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)` — `UFUNCTION()`
- [L83](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterAIController.h#L83): `void OnPerceptionForgotten(AActor* Actor)` — `UFUNCTION()`
- 이벤트: `DECLARE_DELEGATE_TwoParams(FShooterPerceptionUpdatedDelegate, AActor*, const FAIStimulus&);`
- 이벤트: `DECLARE_DELEGATE_OneParam(FShooterPerceptionForgottenDelegate, AActor*);`

## 연결 파일

- [ShooterAIController.cpp](ShooterAIController.cpp.md)

[전체 소스 인덱스로](../../../../README.md)
