---
type: source_file_summary
source: "DreamEscape/Private/Player/InGameCharacter.cpp"
source_sha256: "752DA79EC29614E116C3B085F8B5C146243347BF2981D51623522294DDF3005C"
source_encoding: "CP949"
source_modified: "2026-08-28T15:53:51"
last_updated: "2026-09-15"
---

# InGameCharacter.cpp

체력 복제와 액션 RPC의 최소 인게임 캐릭터.

## 파일 정보

- 원본: [Source/DreamEscape/Private/Player/InGameCharacter.cpp](../../../../../Source/DreamEscape/Private/Player/InGameCharacter.cpp)
- 구분: C++ 구현: 실행 흐름·함수 본문
- 총 61줄. 현재 Source의 정적 분석 기준.

## 구현 내용

- 액터 및 이동 복제를 켜고 체력을 초기화한다.
- CurrentHealth를 복제 목록에 등록하며 OnRep에서 로그를 남긴다.
- 액션 요청 위치가 캐릭터에서 5000cm 이내인지 제곱 거리로 검증한다.
- 서버 구현은 멀티캐스트를 호출하고, 멀티캐스트 구현은 위치 로그만 출력한다. 실제 파티클/효과 생성은 없다.

## 구현 함수 위치

- [L5](../../../../../Source/DreamEscape/Private/Player/InGameCharacter.cpp#L5): `AInGameCharacter::AInGameCharacter()`
- [L16](../../../../../Source/DreamEscape/Private/Player/InGameCharacter.cpp#L16): `AInGameCharacter::BeginPlay()`
- [L22](../../../../../Source/DreamEscape/Private/Player/InGameCharacter.cpp#L22): `AInGameCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)`
- [L31](../../../../../Source/DreamEscape/Private/Player/InGameCharacter.cpp#L31): `AInGameCharacter::OnRep_CurrentHealth()`
- [L38](../../../../../Source/DreamEscape/Private/Player/InGameCharacter.cpp#L38): `AInGameCharacter::Server_PerformAction_Validate(const FVector_NetQuantize& TargetLocation)`
- [L45](../../../../../Source/DreamEscape/Private/Player/InGameCharacter.cpp#L45): `AInGameCharacter::Server_PerformAction_Implementation(const FVector_NetQuantize& TargetLocation)`
- [L57](../../../../../Source/DreamEscape/Private/Player/InGameCharacter.cpp#L57): `AInGameCharacter::Multicast_PlayActionFX_Implementation(const FVector_NetQuantize& TargetLocation)`

## 연결 파일

- [InGameCharacter.h](../../Public/Player/InGameCharacter.h.md)

[전체 소스 인덱스로](../../../../README.md)
