#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStatusWidget.generated.h"

class UProgressBar;
class UTextBlock;

/**
 * 플레이어 체력 및 스태미나 UI를 제어하는 위젯 클래스
 */
UCLASS()
class DREAMESCAPE_API UPlayerStatusWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	// =========================================================================
	// [UMG 위젯 바인딩 컴포넌트]
	// - UMG 디자이너 상의 위젯 이름과 정확히 일치해야 자동 바인딩됩니다.
	// - TextBlock은 위젯에 배치되지 않았을 경우를 대비해 BindWidgetOptional을 적용합니다.
	// =========================================================================

	/** 체력 프로그레스 바 (필수) */
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> ProgressBar_Health;

	/** 체력 텍스트 표시 (선택) */
	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> Text_HealthPercent;

	/** 스태미나 프로그레스 바 (필수) */
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UProgressBar> ProgressBar_Stamina;

	/** 스태미나 텍스트 표시 (선택) */
	UPROPERTY(meta = (BindWidgetOptional))
	TObjectPtr<UTextBlock> Text_StaminaPercent;

public:
	// =========================================================================
	// [UI 갱신 함수]
	// - 캐릭터의 OnHealthChanged / OnStaminaChanged 델리게이트와 연동
	// =========================================================================

	/** 체력 게이지 및 텍스트 갱신 */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateHealth(float Current, float Max);

	/** 스태미나 게이지 및 텍스트 갱신 */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateStamina(float Current, float Max);
};