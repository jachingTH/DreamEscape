---
type: source_file_summary
source: "DreamEscape/Variant_Shooter/ShooterGameMode.h"
source_sha256: "10CE4495A899435CEAA0F6FBA57ADBDBD731F74A28039E857A30E688356495C6"
source_encoding: "UTF-8"
source_modified: "2026-06-10T23:46:18"
last_updated: "2026-09-15"
---

# ShooterGameMode.h

팀 점수 누적 및 점수 UI 관리.

## 파일 정보

- 원본: [Source/DreamEscape/Variant_Shooter/ShooterGameMode.h](../../../../Source/DreamEscape/Variant_Shooter/ShooterGameMode.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 42줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- TeamScores 맵과 ShooterUIClass/ShooterUI를 보관한다.
- BeginPlay와 IncrementTeamScore를 선언한다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API AShooterGameMode : public AGameModeBase`
- [L24](../../../../Source/DreamEscape/Variant_Shooter/ShooterGameMode.h#L24): `TSubclassOf<UShooterUI> ShooterUIClass` — `UPROPERTY(EditAnywhere, Category="Shooter")`

## 연결 파일

- [ShooterGameMode.cpp](ShooterGameMode.cpp.md)

[전체 소스 인덱스로](../../../README.md)
