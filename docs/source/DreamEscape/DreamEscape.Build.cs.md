---
type: source_file_summary
source: "DreamEscape/DreamEscape.Build.cs"
source_sha256: "CB2DE6F00F5B1CBEF70AC3C52FA34B7123E58A263C904EA4082F1927A45028A6"
source_encoding: "UTF-8"
source_modified: "2026-09-01T00:46:01"
last_updated: "2026-09-15"
---

# DreamEscape.Build.cs

DreamEscape 모듈 의존성과 헤더 검색 경로 설정.

## 파일 정보

- 원본: [Source/DreamEscape/DreamEscape.Build.cs](../../../Source/DreamEscape/DreamEscape.Build.cs)
- 구분: C# Unreal 빌드 규칙
- 총 48줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- DreamEscape 모듈 의존성과 헤더 검색 경로 설정.
- PCHUsage=UseExplicitOrSharedPCHs를 사용한다.
- 공개 의존성: Core, CoreUObject, Engine, InputCore, EnhancedInput, AIModule, StateTreeModule, GameplayStateTreeModule, UMG, Slate, OnlineSubsystem, OnlineSubsystemSteam, OnlineSubsystemUtils.
- PrivateDependencyModuleNames는 비어 있다. PublicIncludePaths에는 모듈 루트와 Horror/Shooter 하위 폴더가 등록돼 있다.
- UMG가 공개 의존성 목록에 두 번 들어 있다. 이번 문서화에서 코드는 변경하지 않았다.
- 플러그인의 실제 활성화 여부는 .uproject/Config 확인이 필요하며 Source 조사 범위 밖이다.

## 연결 파일

- [DreamEscape.Target.cs](../DreamEscape.Target.cs.md)
- [DreamEscapeEditor.Target.cs](../DreamEscapeEditor.Target.cs.md)

[전체 소스 인덱스로](../../README.md)
