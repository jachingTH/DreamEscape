---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/AI/EnvQueryContext_Target.cpp"
source_sha256: "25EBF02C5C3615F192B0ED5E57AA332E1C910D47355BAC1EAA0702271F515BB1"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# EnvQueryContext_Target.cpp

EQS에서 사용할 현재 AI 대상 컨텍스트.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/AI/EnvQueryContext_Target.cpp](../../../../../Source/DreamEscape/Variant_Shooter/AI/EnvQueryContext_Target.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 27줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- 질의 Owner가 ShooterAIController이면 GetCurrentTarget을 확인한다.
- 유효한 대상이 있으면 대상 액터, 없으면 컨트롤러 자신을 EQS Actor 컨텍스트로 제공한다.

## 구현 함수 위치

- [L9](../../../../../Source/DreamEscape/Variant_Shooter/AI/EnvQueryContext_Target.cpp#L9): `UEnvQueryContext_Target::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData)`

## 연결 파일

- [EnvQueryContext_Target.h](EnvQueryContext_Target.h.md)
- [ShooterAIController.h](ShooterAIController.h.md)

[전체 소스 인덱스로](../../../../README.md)
