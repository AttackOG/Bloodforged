// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "BloodforgedAbilitySystComp.h"

void UBloodforgedAbilitySystComp::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UBloodforgedAbilitySystComp::EffectApplied);
}

void UBloodforgedAbilitySystComp::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                                const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	EffectAssetTags.Broadcast(TagContainer);
}
