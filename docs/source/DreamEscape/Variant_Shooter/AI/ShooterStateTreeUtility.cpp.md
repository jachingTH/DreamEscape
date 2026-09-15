---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp"
source_sha256: "EA242033B68FA7315D95B367B5B84D9FFC750984E77AB19D15EDD5FA52936343"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterStateTreeUtility.cpp

슈터 AI용 시야 조건과 StateTree 태스크 모음.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 361줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- 시야 조건은 전방 각도를 검사하고 대상 높이별 라인트레이스로 가림 여부를 판정한다.
- FaceActor/FaceLocation은 진입 시 포커스를 설정하고 이탈 시 제거한다.
- SetRandomFloat는 지정 범위의 난수를 OutValue에 저장한다.
- ShootAtTarget은 진입/이탈 시 NPC의 발사 시작/중단을 호출한다.
- SenseEnemies는 약한 실행 컨텍스트를 캡처한 감지/망각 콜백을 등록한다. 직접 시야가 있으면 타깃, 없으면 강한 자극의 조사 위치를 갱신한다.
- 이탈 시 감지 콜백을 Unbind한다. 에디터 전용 GetDescription 함수는 노드 설명을 제공한다.

## 구현 함수 위치

- [L13](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L13): `FStateTreeLineOfSightToTargetCondition::TestCondition(FStateTreeExecutionContext& Context)`
- [L73](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L73): `FStateTreeLineOfSightToTargetCondition::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting)`
- [L81](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L81): `FStateTreeFaceActorTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)`
- [L96](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L96): `FStateTreeFaceActorTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)`
- [L110](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L110): `FStateTreeFaceActorTask::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting)`
- [L118](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L118): `FStateTreeFaceLocationTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)`
- [L133](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L133): `FStateTreeFaceLocationTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)`
- [L147](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L147): `FStateTreeFaceLocationTask::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting)`
- [L155](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L155): `FStateTreeSetRandomFloatTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)`
- [L171](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L171): `FStateTreeSetRandomFloatTask::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting)`
- [L179](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L179): `FStateTreeShootAtTargetTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)`
- [L194](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L194): `FStateTreeShootAtTargetTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)`
- [L208](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L208): `FStateTreeShootAtTargetTask::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting)`
- [L214](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L214): `FStateTreeSenseEnemiesTask::EnterState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)`
- [L342](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L342): `FStateTreeSenseEnemiesTask::ExitState(FStateTreeExecutionContext& Context, const FStateTreeTransitionResult& Transition)`
- [L357](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterStateTreeUtility.cpp#L357): `FStateTreeSenseEnemiesTask::GetDescription(const FGuid& ID, FStateTreeDataView InstanceDataView, const IStateTreeBindingLookup& BindingLookup, EStateTreeNodeFormatting Formatting)`

## 연결 파일

- [ShooterStateTreeUtility.h](ShooterStateTreeUtility.h.md)
- [ShooterNPC.h](ShooterNPC.h.md)
- [ShooterAIController.h](ShooterAIController.h.md)

[전체 소스 인덱스로](../../../../README.md)
