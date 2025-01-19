// Copyright AttackOG Jack Cullen,. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BloodforgedGameplayAbility.h"
#include "BloodforgedProjectileSpell.generated.h"

class ABloodforgedProjectile;
/**
 * 
 */
UCLASS()
class BLOODFORGED_API UBloodforgedProjectileSpell : public UBloodforgedGameplayAbility
{
	GENERATED_BODY()

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ABloodforgedProjectile> ProjectileClass;
};
