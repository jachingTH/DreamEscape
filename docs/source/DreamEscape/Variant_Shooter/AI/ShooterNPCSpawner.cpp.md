---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.cpp"
source_sha256: "866DD10F717E7EBDCE01FBEDFE1E0515540D3000FAE7F3EF14D29DB26E41136F"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterNPCSpawner.cpp

정해진 위치에서 제한 횟수만큼 NPC 생성.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.cpp](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 85줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- BeginPlay에서 SpawnCount가 양수이면 최초 생성 타이머를 예약한다.
- 캡슐의 Transform에서 NPC를 생성하고 사망 이벤트를 구독한다. 영역 내 무작위 위치를 고르지는 않는다.
- 사망마다 SpawnCount를 줄이고 남은 횟수가 있으면 재생성을 예약한다.
- EndPlay에서 생성 타이머를 정리한다.

## 구현 함수 위치

- [L13](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.cpp#L13): `AShooterNPCSpawner::AShooterNPCSpawner()`
- [L32](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.cpp#L32): `AShooterNPCSpawner::BeginPlay()`
- [L44](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.cpp#L44): `AShooterNPCSpawner::EndPlay(EEndPlayReason::Type EndPlayReason)`
- [L52](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.cpp#L52): `AShooterNPCSpawner::SpawnNPC()`
- [L72](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.cpp#L72): `AShooterNPCSpawner::OnNPCDied()`

## 연결 파일

- [ShooterNPCSpawner.h](ShooterNPCSpawner.h.md)
- [ShooterNPC.h](ShooterNPC.h.md)

[전체 소스 인덱스로](../../../../README.md)
