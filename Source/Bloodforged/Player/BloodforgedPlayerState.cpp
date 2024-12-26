// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "BloodforgedPlayerState.h"
#include "Bloodforged/AbilitySystem/BloodforgedAbilitySystComp.h"
#include "Bloodforged/AbilitySystem/BloodforgedAttributeSet.h"
#include "Net/UnrealNetwork.h"

ABloodforgedPlayerState::ABloodforgedPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UBloodforgedAbilitySystComp>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UBloodforgedAttributeSet>("AttributeSet");

	SetNetUpdateFrequency(100.f);
}

void ABloodforgedPlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABloodforgedPlayerState, PlayerLevel);
}

void ABloodforgedPlayerState::OnRep_PlayerLevel(int32 OldLevel)
{
}

UAbilitySystemComponent* ABloodforgedPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
