// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "BloodforgedInputConfig.h"

const UInputAction* UBloodforgedInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag,
	const bool bLogNotFound) const
{
	for (const FBloodforgedInputAction& Action : AbilityInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find ability input action for input tag [%s] for tag on input config [%s]"), *InputTag.ToString(), *GetNameSafe(this))
	}
	return nullptr;
}
