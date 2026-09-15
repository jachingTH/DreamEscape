---
type: source_file_summary
source: "DreamEscape/DreamEscapeCharacter.h"
source_sha256: "09D5C332BEE7CE3762D49E120680A60B4F8A2575A89F18419DD02912E63FCFFB"
source_encoding: "CP949"
source_modified: "2026-09-01T23:18:03"
last_updated: "2026-09-15"
---

# DreamEscapeCharacter.h

1인칭 이동, 체력, 스태미나, 6칸 인벤토리 및 HUD 연결의 공통 캐릭터.

## 파일 정보

- 원본: [Source/DreamEscape/DreamEscapeCharacter.h](../../../Source/DreamEscape/DreamEscapeCharacter.h)
- 구분: 헤더: 타입·멤버·호출 계약
- 총 249줄. 현재 Source의 정적 분석 기준.

## 선언과 사용 목적

- ACharacter를 상속하며 HorrorCharacter, ShooterCharacter, ShooterNPC의 기반이다.
- FirstPersonMesh와 FirstPersonCameraComponent, 이동/점프/시점 InputAction과 DefaultMappingContext를 선언한다.
- 체력·스태미나·선택 슬롯·슬롯 내용 변경용 동적 델리게이트 4종과 상태 변경 함수를 제공한다.
- 기본 걷기 400, 달리기 750, 최소 시작 스태미나 20. 헤더의 StaminaDrainRate=25는 생성자에서 20으로 덮어쓴다.
- 체력·스태미나·인벤토리에 자체 Replicated 표기나 Server RPC는 없다.

## 프로퍼티·노출 함수·이벤트

- 타입: `class DREAMESCAPE_API ADreamEscapeCharacter : public ACharacter`
- [L58](../../../Source/DreamEscape/DreamEscapeCharacter.h#L58): `USkeletalMeshComponent* FirstPersonMesh` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))`
- [L62](../../../Source/DreamEscape/DreamEscapeCharacter.h#L62): `UCameraComponent* FirstPersonCameraComponent` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))`
- [L66](../../../Source/DreamEscape/DreamEscapeCharacter.h#L66): `UInputMappingContext* DefaultMappingContext` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))`
- [L70](../../../Source/DreamEscape/DreamEscapeCharacter.h#L70): `UInputAction* JumpAction` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))`
- [L74](../../../Source/DreamEscape/DreamEscapeCharacter.h#L74): `UInputAction* MoveAction` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))`
- [L78](../../../Source/DreamEscape/DreamEscapeCharacter.h#L78): `UInputAction* LookAction` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))`
- [L82](../../../Source/DreamEscape/DreamEscapeCharacter.h#L82): `UInputAction* MouseLookAction` — `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))`
- [L110](../../../Source/DreamEscape/DreamEscapeCharacter.h#L110): `virtual void DoMove(float Right, float Forward)` — `UFUNCTION(BlueprintCallable, Category = "Movement")`
- [L113](../../../Source/DreamEscape/DreamEscapeCharacter.h#L113): `virtual void DoAim(float Yaw, float Pitch)` — `UFUNCTION(BlueprintCallable, Category = "Movement")`
- [L116](../../../Source/DreamEscape/DreamEscapeCharacter.h#L116): `virtual void DoJumpStart()` — `UFUNCTION(BlueprintCallable, Category = "Movement")`
- [L119](../../../Source/DreamEscape/DreamEscapeCharacter.h#L119): `virtual void DoJumpEnd()` — `UFUNCTION(BlueprintCallable, Category = "Movement")`
- [L129](../../../Source/DreamEscape/DreamEscapeCharacter.h#L129): `FOnAttributeChangedSignature OnHealthChanged` — `UPROPERTY(BlueprintAssignable, Category = "Events|Attributes")`
- [L133](../../../Source/DreamEscape/DreamEscapeCharacter.h#L133): `FOnAttributeChangedSignature OnStaminaChanged` — `UPROPERTY(BlueprintAssignable, Category = "Events|Attributes")`
- [L137](../../../Source/DreamEscape/DreamEscapeCharacter.h#L137): `FOnSlotSelectedSignature OnSlotSelected` — `UPROPERTY(BlueprintAssignable, Category = "Events|Inventory")`
- [L141](../../../Source/DreamEscape/DreamEscapeCharacter.h#L141): `FOnInventorySlotUpdatedSignature OnInventorySlotUpdated` — `UPROPERTY(BlueprintAssignable, Category = "Events|Inventory")`
- [L151](../../../Source/DreamEscape/DreamEscapeCharacter.h#L151): `float MaxHealth = 100.0f` — `UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Health")`
- [L154](../../../Source/DreamEscape/DreamEscapeCharacter.h#L154): `float CurrentHealth = 100.0f` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes|Health")`
- [L158](../../../Source/DreamEscape/DreamEscapeCharacter.h#L158): `float MaxStamina = 100.0f` — `UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Stamina")`
- [L161](../../../Source/DreamEscape/DreamEscapeCharacter.h#L161): `float CurrentStamina = 100.0f` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes|Stamina")`
- [L164](../../../Source/DreamEscape/DreamEscapeCharacter.h#L164): `float StaminaDrainRate = 25.0f` — `UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Stamina")`
- [L167](../../../Source/DreamEscape/DreamEscapeCharacter.h#L167): `float StaminaRegenRate = 15.0f` — `UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Stamina")`
- [L171](../../../Source/DreamEscape/DreamEscapeCharacter.h#L171): `float MinStaminaToSprint = 20.0f` — `UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Stamina")`
- [L175](../../../Source/DreamEscape/DreamEscapeCharacter.h#L175): `float WalkSpeed = 400.0f` — `UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")`
- [L178](../../../Source/DreamEscape/DreamEscapeCharacter.h#L178): `float SprintSpeed = 750.0f` — `UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Movement")`
- [L181](../../../Source/DreamEscape/DreamEscapeCharacter.h#L181): `bool bIsSprinting = false` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")`
- [L188](../../../Source/DreamEscape/DreamEscapeCharacter.h#L188): `TArray<FInventorySlotData> InventorySlots` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")`
- [L191](../../../Source/DreamEscape/DreamEscapeCharacter.h#L191): `int32 CurrentSelectedSlotIndex = 0` — `UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")`
- [L195](../../../Source/DreamEscape/DreamEscapeCharacter.h#L195): `TSubclassOf<UDreamEscapeInGameHUD> HUDWidgetClass` — `UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")`
- [L198](../../../Source/DreamEscape/DreamEscapeCharacter.h#L198): `TObjectPtr<UDreamEscapeInGameHUD> HUDWidget` — `UPROPERTY(BlueprintReadOnly, Category = "UI")`
- [L208](../../../Source/DreamEscape/DreamEscapeCharacter.h#L208): `void ModifyHealth(float Amount)` — `UFUNCTION(BlueprintCallable, Category = "Attributes|Health")`
- [L212](../../../Source/DreamEscape/DreamEscapeCharacter.h#L212): `void ModifyStamina(float Amount)` — `UFUNCTION(BlueprintCallable, Category = "Attributes|Stamina")`
- [L216](../../../Source/DreamEscape/DreamEscapeCharacter.h#L216): `void StartSprint()` — `UFUNCTION(BlueprintCallable, Category = "Movement")`
- [L219](../../../Source/DreamEscape/DreamEscapeCharacter.h#L219): `void StopSprint()` — `UFUNCTION(BlueprintCallable, Category = "Movement")`
- [L223](../../../Source/DreamEscape/DreamEscapeCharacter.h#L223): `void SelectInventorySlot(int32 SlotIndex)` — `UFUNCTION(BlueprintCallable, Category = "Inventory")`
- [L227](../../../Source/DreamEscape/DreamEscapeCharacter.h#L227): `void SetInventorySlot(int32 SlotIndex, const FInventorySlotData& NewItemData)` — `UFUNCTION(BlueprintCallable, Category = "Inventory")`
- [L238](../../../Source/DreamEscape/DreamEscapeCharacter.h#L238): `float GetHealthPercent() const` — `UFUNCTION(BlueprintPure, Category = "Attributes")`
- [L241](../../../Source/DreamEscape/DreamEscapeCharacter.h#L241): `float GetStaminaPercent() const` — `UFUNCTION(BlueprintPure, Category = "Attributes")`
- [L244](../../../Source/DreamEscape/DreamEscapeCharacter.h#L244): `bool IsSprinting() const` — `UFUNCTION(BlueprintPure, Category = "Movement")`
- [L247](../../../Source/DreamEscape/DreamEscapeCharacter.h#L247): `int32 GetSelectedSlotIndex() const` — `UFUNCTION(BlueprintPure, Category = "Inventory")`
- 이벤트: `DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeChangedSignature, float, CurrentValue, float, MaxValue);`
- 이벤트: `DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotSelectedSignature, int32, NewSlotIndex);`
- 이벤트: `DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventorySlotUpdatedSignature, int32, SlotIndex, const FInventorySlotData&, NewData);`

## 연결 파일

- [DreamEscapeCharacter.cpp](DreamEscapeCharacter.cpp.md)
- [ItemData.h](ItemData.h.md)

[전체 소스 인덱스로](../../README.md)
