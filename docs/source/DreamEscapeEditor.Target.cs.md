---
type: source_file_summary
source: "DreamEscapeEditor.Target.cs"
source_sha256: "D5540C585F269B4EE94509D0022AFDFAB8AC2B49A075962BB7A543D60A543C2E"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# DreamEscapeEditor.Target.cs

Unreal Editor 빌드 타깃 설정.

## 파일 정보

- 원본: [Source/DreamEscapeEditor.Target.cs](../../Source/DreamEscapeEditor.Target.cs)
- 구분: C# Unreal 빌드 규칙
- 총 15줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- Unreal Editor 빌드 타깃 설정.
- DreamEscapeEditorTarget은 TargetRules를 상속한다.
- Type=TargetType.Editor, DefaultBuildSettings=V6, IncludeOrderVersion=Unreal5_7을 설정한다.
- ExtraModuleNames에 DreamEscape를 추가한다.

## 연결 파일

- [DreamEscape.Target.cs](DreamEscape.Target.cs.md)
- [DreamEscape.Build.cs](DreamEscape/DreamEscape.Build.cs.md)

[전체 소스 인덱스로](../README.md)
