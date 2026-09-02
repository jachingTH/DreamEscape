#include "PlayerStatusWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UPlayerStatusWidget::UpdateHealth(float Current, float Max)
{
	// 0 나누기 방지
	if (Max <= 0.0f)
	{
		return;
	}

	// 0.0 ~ 1.0 범위로 비율 안전 제한
	const float HealthRatio = FMath::Clamp(Current / Max, 0.0f, 1.0f);

	// 프로그레스 바 게이지 갱신
	if (ProgressBar_Health)
	{
		ProgressBar_Health->SetPercent(HealthRatio);
	}

	// 텍스트 백분율 (예: "100%") 갱신
	if (Text_HealthPercent)
	{
		const int32 Percent = FMath::Clamp(FMath::RoundToInt(HealthRatio * 100.0f), 0, 100);
		Text_HealthPercent->SetText(FText::FromString(FString::Printf(TEXT("%d%%"), Percent)));
	}
}

void UPlayerStatusWidget::UpdateStamina(float Current, float Max)
{
	// 0 나누기 방지
	if (Max <= 0.0f)
	{
		return;
	}

	// 0.0 ~ 1.0 범위로 비율 안전 제한
	const float StaminaRatio = FMath::Clamp(Current / Max, 0.0f, 1.0f);

	// 프로그레스 바 게이지 갱신
	if (ProgressBar_Stamina)
	{
		ProgressBar_Stamina->SetPercent(StaminaRatio);
	}

	// 텍스트 백분율 (예: "100%") 갱신
	if (Text_StaminaPercent)
	{
		const int32 Percent = FMath::Clamp(FMath::RoundToInt(StaminaRatio * 100.0f), 0, 100);
		Text_StaminaPercent->SetText(FText::FromString(FString::Printf(TEXT("%d%%"), Percent)));
	}
}