// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "BloodforgedAbilitySystComp.h"

void UBloodforgedAbilitySystComp::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UBloodforgedAbilitySystComp::ClientEffectApplied);
}

void UBloodforgedAbilitySystComp::ClientEffectApplied_Implementation(UAbilitySystemComponent* AbilitySystemComponent,
                                                const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	EffectAssetTags.Broadcast(TagContainer);
}
