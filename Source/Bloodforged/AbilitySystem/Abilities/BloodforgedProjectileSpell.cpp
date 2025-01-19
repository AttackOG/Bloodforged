// Copyright AttackOG Jack Cullen,. All Rights Reserved.


#include "BloodforgedProjectileSpell.h"
#include "Bloodforged/Interfaces/CombatInterface.h"
#include "Bloodforged/Magic/BloodforgedProjectile.h"

void UBloodforgedProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                                  const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                                  const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	const bool bIsServer = HasAuthority(&ActivationInfo);
	if (!bIsServer) return;

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(CombatInterface->GetCombatSocketLocation());
	
	GetWorld()->SpawnActorDeferred<ABloodforgedProjectile>(ProjectileClass, SpawnTransform, GetOwningActorFromActorInfo(), Cast<APawn>(GetAvatarActorFromActorInfo()), ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
}
