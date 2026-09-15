---
type: source_file_summary
source: "DreamEscape.Target.cs"
source_sha256: "0C25D57F0C2F41C843C179B2F8D959A17D8B48FD1DA006D1FC9BAB29604FD11A"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# DreamEscape.Target.cs

게임 실행 타깃 설정.

## 파일 정보

- 원본: [Source/DreamEscape.Target.cs](../../Source/DreamEscape.Target.cs)
- 구분: C# Unreal 빌드 규칙
- 총 15줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- 게임 실행 타깃 설정.
- DreamEscapeTarget은 TargetRules를 상속한다.
- Type=TargetType.Game, DefaultBuildSettings=V6, IncludeOrderVersion=Unreal5_7을 설정한다.
- ExtraModuleNames에 DreamEscape를 추가한다.

## 연결 파일

- [DreamEscape.Build.cs](DreamEscape/DreamEscape.Build.cs.md)
- [DreamEscapeEditor.Target.cs](DreamEscapeEditor.Target.cs.md)

[전체 소스 인덱스로](../README.md)
