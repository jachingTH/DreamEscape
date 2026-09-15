---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.h"
source_sha256: "778869FEFB7B3784CB072B62BDFFB205D6F86D9E6175644D325CE1476D60183B"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterNPCSpawner.h

정해진 위치에서 제한 횟수만큼 NPC 생성.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.h](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 71줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- 캡슐/화살표 컴포넌트, NPCClass, 초기 지연/재생성 지연과 SpawnCount를 선언한다.
- 기본 SpawnCount=1, 초기 및 재생성 지연은 각각 5초다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API AShooterNPCSpawner : public AActor`
- [L22](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.h#L22): `UCapsuleComponent* SpawnCapsule` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))`
- [L25](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.h#L25): `UArrowComponent* SpawnDirection` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))`
- [L31](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.h#L31): `TSubclassOf<AShooterNPC> NPCClass` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPC Spawner")`
- [L35](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.h#L35): `float InitialSpawnDelay = 5.0f` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPC Spawner", meta = (ClampMin = 0, ClampMax = 10))`
- [L39](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.h#L39): `int32 SpawnCount = 1` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPC Spawner", meta = (ClampMin = 0, ClampMax = 100))`
- [L43](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.h#L43): `float RespawnDelay = 5.0f` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="NPC Spawner", meta = (ClampMin = 0, ClampMax = 10))`
- [L68](../../../../../Source/DreamEscape/Variant_Shooter/AI/ShooterNPCSpawner.h#L68): `void OnNPCDied()` — `UFUNCTION()`

## 연결 파일

- [ShooterNPCSpawner.cpp](ShooterNPCSpawner.cpp.md)

[전체 소스 인덱스로](../../../../README.md)
