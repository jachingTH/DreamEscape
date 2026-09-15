---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h"
source_sha256: "95924A1AEE4E989425EA3490C2552B7CF314EA5B2354CDCCACCE24F0BF956A58"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterStateTreeUtility.h

슈터 AI용 시야 조건과 StateTree 태스크 모음.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 309줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- LineOfSightToTargetCondition과 해당 인스턴스 데이터를 정의한다.
- FaceActor, FaceLocation, SetRandomFloat, ShootAtTarget, SenseEnemies 태스크와 인스턴스 데이터를 정의한다.
- Condition/Task 구조체이며 UObject나 Actor 클래스가 아니다. 이동 태스크나 Evaluator는 이 파일에 없다.

## 프로퍼티·노출 함수·이벤트

- 타입: `struct FStateTreeLineOfSightToTargetConditionInstanceData`
- 타입: `struct FStateTreeLineOfSightToTargetCondition : public FStateTreeConditionCommonBase`
- 타입: `struct FStateTreeFaceActorInstanceData`
- 타입: `struct FStateTreeFaceActorTask : public FStateTreeTaskCommonBase`
- 타입: `struct FStateTreeFaceLocationInstanceData`
- 타입: `struct FStateTreeFaceLocationTask : public FStateTreeTaskCommonBase`
- 타입: `struct FStateTreeSetRandomFloatData`
- 타입: `struct FStateTreeSetRandomFloatTask : public FStateTreeTaskCommonBase`
- 타입: `struct FStateTreeShootAtTargetInstanceData`
- 타입: `struct FStateTreeShootAtTargetTask : public FStateTreeTaskCommonBase`
- 타입: `struct FStateTreeSenseEnemiesInstanceData`
- 타입: `struct FStateTreeSenseEnemiesTask : public FStateTreeTaskCommonBase`
- [L24](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L24): `AShooterNPC* Character` — `UPROPERTY(EditAnywhere, Category = "Context")`
- [L28](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L28): `AActor* Target` — `UPROPERTY(EditAnywhere, Category = "Condition")`
- [L32](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L32): `float LineOfSightConeAngle = 35.0f` — `UPROPERTY(EditAnywhere, Category = "Condition")`
- [L36](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L36): `int32 NumberOfVerticalLineOfSightChecks = 5` — `UPROPERTY(EditAnywhere, Category = "Condition")`
- [L40](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L40): `bool bMustHaveLineOfSight = true` — `UPROPERTY(EditAnywhere, Category = "Condition")`
- [L81](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L81): `TObjectPtr<AAIController> Controller` — `UPROPERTY(EditAnywhere, Category = Context)`
- [L85](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L85): `TObjectPtr<AActor> ActorToFaceTowards` — `UPROPERTY(EditAnywhere, Category = Input)`
- [L123](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L123): `TObjectPtr<AAIController> Controller` — `UPROPERTY(EditAnywhere, Category = Context)`
- [L127](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L127): `FVector FaceLocation = FVector::ZeroVector` — `UPROPERTY(EditAnywhere, Category = Parameter)`
- [L165](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L165): `float MinValue = 0.0f` — `UPROPERTY(EditAnywhere, Category = Parameter)`
- [L169](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L169): `float MaxValue = 0.0f` — `UPROPERTY(EditAnywhere, Category = Parameter)`
- [L173](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L173): `float OutValue = 0.0f` — `UPROPERTY(EditAnywhere, Category = Output)`
- [L208](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L208): `TObjectPtr<AShooterNPC> Character` — `UPROPERTY(EditAnywhere, Category = Context)`
- [L212](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L212): `TObjectPtr<AActor> Target` — `UPROPERTY(EditAnywhere, Category = Input)`
- [L250](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L250): `TObjectPtr<AShooterAIController> Controller` — `UPROPERTY(EditAnywhere, Category = Context)`
- [L254](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L254): `TObjectPtr<AShooterNPC> Character` — `UPROPERTY(EditAnywhere, Category = Context)`
- [L258](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L258): `TObjectPtr<AActor> TargetActor` — `UPROPERTY(EditAnywhere, Category = Output)`
- [L262](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L262): `FVector InvestigateLocation = FVector::ZeroVector` — `UPROPERTY(EditAnywhere, Category = Output)`
- [L266](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L266): `bool bHasTarget = false` — `UPROPERTY(EditAnywhere, Category = Output)`
- [L270](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L270): `bool bHasInvestigateLocation = false` — `UPROPERTY(EditAnywhere, Category = Output)`
- [L274](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L274): `FName SenseTag = FName("Player")` — `UPROPERTY(EditAnywhere, Category = Parameter)`
- [L278](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L278): `float DirectLineOfSightCone = 85.0f` — `UPROPERTY(EditAnywhere, Category = Parameter)`
- [L282](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.h#L282): `float LastStimulusStrength = 0.0f` — `UPROPERTY(EditAnywhere)`

## 연결 파일

- [ShooterStateTreeUtility.cpp](ShooterStateTreeUtility.cpp.md)

[전체 소스 인덱스로](../../../../README.md)
