// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "HeroCharacter.h"
#include "AbilitySystemComponent.h"
#include "Bloodforged/AbilitySystem/BloodforgedAbilitySystComp.h"
#include "Bloodforged/Player/BloodforgedPlayerController.h"
#include "Bloodforged/Player/BloodforgedPlayerState.h"
#include "Bloodforged/UI/HUD/BloodforgedHUD.h"
#include "Bloodforged/Weapons/Weapon.h"
#include "Net/UnrealNetwork.h"

void AHeroCharacter::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(AHeroCharacter, OverlappingWeapon, COND_OwnerOnly);
}

void AHeroCharacter::InitAbilityActorInfo()
{
	ABloodforgedPlayerState* BloodforgedPlayerState = GetPlayerState<ABloodforgedPlayerState>();
	check(BloodforgedPlayerState);
	BloodforgedPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(BloodforgedPlayerState, this);
	Cast<UBloodforgedAbilitySystComp>(BloodforgedPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = BloodforgedPlayerState->GetAbilitySystemComponent();
	AttributeSet = BloodforgedPlayerState->GetAttributeSet();

	if (ABloodforgedPlayerController* BloodforgedPlayerController = Cast<ABloodforgedPlayerController>(GetController()))
	{
		if (ABloodforgedHUD* BloodforgedHUD = Cast<ABloodforgedHUD>(BloodforgedPlayerController->GetHUD()))
		{
			BloodforgedHUD->InitOverlay(BloodforgedPlayerController, BloodforgedPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
	InitializeDefaultAttributes();
}

void AHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Init ability actor info for the server.
	InitAbilityActorInfo();
	AddCharacterAbilities();
}

void AHeroCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Init ability actor info for the client.
	InitAbilityActorInfo();
}

int32 AHeroCharacter::GetLevel()
{
	const ABloodforgedPlayerState* BloodforgedPlayerState = GetPlayerState<ABloodforgedPlayerState>();
	check(BloodforgedPlayerState);
	
	return BloodforgedPlayerState->GetPlayerLevel();
}

void AHeroCharacter::SetOverlappingWeapon(AWeapon* Weapon)
{
	//This function is called on the server, don't need to show widget on server for anyone as only overlapping character should see it.
	if (OverlappingWeapon)
	{
		OverlappingWeapon->ShowPickupWidget(false);
	}
	OverlappingWeapon = Weapon;
	if (IsLocallyControlled())
	{
		if (OverlappingWeapon)
		{
			OverlappingWeapon->ShowPickupWidget(true);
		}
	}
}

void AHeroCharacter::OnRep_OverlappingWeapon(AWeapon* LastWeapon)
{
	if (OverlappingWeapon)
	{
		OverlappingWeapon->ShowPickupWidget(true);
	}
	if (LastWeapon)
	{
		LastWeapon->ShowPickupWidget(false);
	}
}
