// Copyright AttackOG Jack Cullen,. All Rights Reserved.


#include "MMC_MaxStamina.h"

#include "Bloodforged/AbilitySystem/BloodforgedAttributeSet.h"
#include "Bloodforged/Interfaces/CombatInterface.h"

UMMC_MaxStamina::UMMC_MaxStamina()
{
	EnduranceDef.AttributeToCapture = UBloodforgedAttributeSet::GetEnduranceAttribute();
	EnduranceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	EnduranceDef.bSnapshot = false;
	RelevantAttributesToCapture.Add(EnduranceDef);
}

float UMMC_MaxStamina::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	// Gather tags from source and target
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();
	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;
	float Endurance = 0.f;
	GetCapturedAttributeMagnitude(EnduranceDef, Spec, EvaluationParameters, Endurance);
	Endurance = FMath::Max<float>(Endurance, 0.f);
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetLevel();
	return 80 + 2.5f * Endurance + 10.f * PlayerLevel;
}
