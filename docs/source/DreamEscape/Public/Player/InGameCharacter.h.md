---
type: source_file_summary
source: "DreamEscape/Public/Player/InGameCharacter.h"
source_sha256: "61C87246E5F558EE9A317079EBC5A8F2E7667FFDD8E35061ADE8E07CF9BDD6D7"
source_encoding: "CP949"
source_modified: "2026-08-31T23:55:38"
last_updated: "2026-09-15"
---

# InGameCharacter.h

체력 복제와 액션 RPC의 최소 인게임 캐릭터.

## 파일 정보

- 원본: [Source/DreamEscape/Public/Player/InGameCharacter.h](../../../../../Source/DreamEscape/Public/Player/InGameCharacter.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 38줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- ADreamEscapeCharacter가 아닌 ACharacter를 직접 상속한다.
- CurrentHealth는 RepNotify, MaxHealth 기본값은 100이다.
- Server_PerformAction은 검증이 있는 Reliable 서버 RPC, Multicast_PlayActionFX는 Unreliable 멀티캐스트다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API AInGameCharacter : public ACharacter`
- [L19](../../../../../Source/DreamEscape/Public/Player/InGameCharacter.h#L19): `float CurrentHealth` — `UPROPERTY(ReplicatedUsing = OnRep_CurrentHealth, BlueprintReadOnly, Category = "Stats")`
- [L22](../../../../../Source/DreamEscape/Public/Player/InGameCharacter.h#L22): `void OnRep_CurrentHealth()` — `UFUNCTION()`
- [L26](../../../../../Source/DreamEscape/Public/Player/InGameCharacter.h#L26): `void Server_PerformAction(const FVector_NetQuantize& TargetLocation)` — `UFUNCTION(Server, Reliable, WithValidation)`
- [L30](../../../../../Source/DreamEscape/Public/Player/InGameCharacter.h#L30): `void Multicast_PlayActionFX(const FVector_NetQuantize& TargetLocation)` — `UFUNCTION(NetMulticast, Unreliable)`
- [L36](../../../../../Source/DreamEscape/Public/Player/InGameCharacter.h#L36): `float MaxHealth = 100.0f` — `UPROPERTY(EditDefaultsOnly, Category = "Stats")`

## 연결 파일

- [InGameCharacter.cpp](../../Private/Player/InGameCharacter.cpp.md)

[전체 소스 인덱스로](../../../../README.md)
