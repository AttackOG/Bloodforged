// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "CharacterBase.h"
#include "Net/UnrealNetwork.h"
#include"Interactables/InteractableItemsBase.h"
#include "AbilitySystemComponent.h"
#include "Bloodforged/AbilitySystem/BloodforgedAbilitySystComp.h"
#include "Components/CombatComponent.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	CombatComponent = CreateDefaultSubobject<UCombatComponent>("CombatComponent");
	CombatComponent->SetIsReplicated(true);

	/*WeaponStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("WeaponStaticMesh");
	WeaponStaticMesh->SetupAttachment(GetMesh());*/
}

void ACharacterBase::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(ACharacterBase, OverlappingItem, COND_OwnerOnly);
}

void ACharacterBase::InitAbilityActorInfo()
{
}

void ACharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);

	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void ACharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultVitalAttributes, 1.f);
}

void ACharacterBase::AddCharacterAbilities() const
{
	UBloodforgedAbilitySystComp* BloodforgedAbilitySystemComponent = Cast<UBloodforgedAbilitySystComp>(AbilitySystemComponent);
	if (!HasAuthority()) return;

	BloodforgedAbilitySystemComponent->GiveStartupAbilities(StartupAbilities);
}

void ACharacterBase::EquipButtonPressed()
{
	if (CombatComponent)
	{
		if (HasAuthority())
		{
			CombatComponent->EquipItem(OverlappingItem);
		}
		else
		{
			ServerEquipButtonPressed();
		}
	}
}

void ACharacterBase::ServerEquipButtonPressed_Implementation()
{
	if (CombatComponent)
	{
		CombatComponent->EquipItem(OverlappingItem);
	}
}

UAbilitySystemComponent* ACharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ACharacterBase::SetOverlappingItem(AInteractableItemsBase* Item)
{
	if (OverlappingItem)
	{
		OverlappingItem->ShowPickupWidget(false);
	}
	OverlappingItem = Item;
	if (IsLocallyControlled())
	{
		if (OverlappingItem)
		{
			OverlappingItem->ShowPickupWidget(true);
		}
	}
}

bool ACharacterBase::IsWeaponEquipped()
{
	return (CombatComponent && CombatComponent->EquippedItem);
}

void ACharacterBase::OnRep_InteractableItem(AInteractableItemsBase* LastItem)
{
	if (OverlappingItem)
	{
		OverlappingItem->ShowPickupWidget(true);
	}
	if (LastItem)
	{
		LastItem->ShowPickupWidget(false);
	}
}
