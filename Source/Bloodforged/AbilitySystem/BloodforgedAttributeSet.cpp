// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "BloodforgedAttributeSet.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

UBloodforgedAttributeSet::UBloodforgedAttributeSet()
{
}

void UBloodforgedAttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, Resilience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, Vigor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, Dexterity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, Wisdom, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, Endurance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, Luck, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, PhysicalAttackPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, MagicalAttackPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, CriticalHitChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, CriticalHitDamage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, PhysicalDefence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, MagicalDefence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, DodgeChance, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, HealthRegenerationRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, ManaRegenerationRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, StaminaRegenerationRate, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, ArmorPenetration, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, WeaponAccuracy, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, LootQuality, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, CooldownReduction, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, BlockStrength, COND_None, REPNOTIFY_Always);
	
	
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBloodforgedAttributeSet, Stamina, COND_None, REPNOTIFY_Always);
	
}

void UBloodforgedAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& EffectProperties)
{
	EffectProperties.EffectContextHandle = Data.EffectSpec.GetContext();
	EffectProperties.SourceAbilitySystemComponent = EffectProperties.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(EffectProperties.SourceAbilitySystemComponent) && EffectProperties.SourceAbilitySystemComponent->AbilityActorInfo.IsValid() && EffectProperties.SourceAbilitySystemComponent->AbilityActorInfo->AvatarActor.IsValid())
	{
		EffectProperties.SourceAvatarActor = EffectProperties.SourceAbilitySystemComponent->AbilityActorInfo->AvatarActor.Get();
		EffectProperties.SourceController = EffectProperties.SourceAbilitySystemComponent->AbilityActorInfo->PlayerController.Get();
		if (EffectProperties.SourceController == nullptr && EffectProperties.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(EffectProperties.SourceAvatarActor))
			{
				EffectProperties.SourceController = Pawn->GetController();
			}
		}
		if (EffectProperties.SourceController)
		{
			EffectProperties.SourceCharacter = Cast<ACharacter>(EffectProperties.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		EffectProperties.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		EffectProperties.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		EffectProperties.TargetCharacter = Cast<ACharacter>(EffectProperties.TargetAvatarActor);
		EffectProperties.TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(EffectProperties.TargetAvatarActor);
	}
}

void UBloodforgedAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties EffectProperties;
	SetEffectProperties(Data, EffectProperties);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	}

	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(), 0.f, GetMaxMana()));
	}

	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina(FMath::Clamp(GetStamina(), 0.f, GetMaxStamina()));
	}
}

void UBloodforgedAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, Strength, OldStrength);
}

void UBloodforgedAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, Intelligence, OldIntelligence);
}

void UBloodforgedAttributeSet::OnRep_Resilience(const FGameplayAttributeData& OldResilience) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, Resilience, OldResilience);
}

void UBloodforgedAttributeSet::OnRep_Vigor(const FGameplayAttributeData& OldVigor) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, Vigor, OldVigor);
}

void UBloodforgedAttributeSet::OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, Dexterity, OldDexterity);
}

void UBloodforgedAttributeSet::OnRep_Wisdom(const FGameplayAttributeData& OldWisdom) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, Wisdom, OldWisdom);
}

void UBloodforgedAttributeSet::OnRep_Endurance(const FGameplayAttributeData& OldEndurance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, Endurance, OldEndurance);
}

void UBloodforgedAttributeSet::OnRep_Luck(const FGameplayAttributeData& OldLuck) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, Luck, OldLuck);
}





void UBloodforgedAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, Health, OldHealth);
}

void UBloodforgedAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, Mana, OldMana);
}

void UBloodforgedAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, Stamina, OldStamina);
}





void UBloodforgedAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, MaxHealth, OldMaxHealth);
}

void UBloodforgedAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, MaxMana, OldMaxMana);
}

void UBloodforgedAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, MaxStamina, OldMaxStamina);
}

void UBloodforgedAttributeSet::OnRep_PhysicalAttackPower(const FGameplayAttributeData& OldPhysicalAttackPower) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, PhysicalAttackPower, OldPhysicalAttackPower);
}

void UBloodforgedAttributeSet::OnRep_MagicalAttackPower(const FGameplayAttributeData& OldMagicalAttackPower) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, MagicalAttackPower, OldMagicalAttackPower);
}

void UBloodforgedAttributeSet::OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, CriticalHitChance, OldCriticalHitChance);
}

void UBloodforgedAttributeSet::OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, CriticalHitDamage, OldCriticalHitDamage);
}

void UBloodforgedAttributeSet::OnRep_PhysicalDefence(const FGameplayAttributeData& OldPhysicalDefence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, PhysicalDefence, OldPhysicalDefence);
}

void UBloodforgedAttributeSet::OnRep_MagicalDefence(const FGameplayAttributeData& OldMagicalDefence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, MagicalDefence, OldMagicalDefence);
}

void UBloodforgedAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, AttackSpeed, OldAttackSpeed);
}

void UBloodforgedAttributeSet::OnRep_DodgeChance(const FGameplayAttributeData& OldDodgeChance) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, DodgeChance, OldDodgeChance);
}

void UBloodforgedAttributeSet::OnRep_HealthRegenerationRate(
	const FGameplayAttributeData& OldHealthRegenerationRate) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, HealthRegenerationRate, OldHealthRegenerationRate);
}

void UBloodforgedAttributeSet::OnRep_ManaRegenerationRate(const FGameplayAttributeData& OldManaRegenerationRate) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, ManaRegenerationRate, OldManaRegenerationRate);
}

void UBloodforgedAttributeSet::OnRep_StaminaRegenerationRate(
	const FGameplayAttributeData& OldStaminaRegenerationRate) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, StaminaRegenerationRate, OldStaminaRegenerationRate);
}

void UBloodforgedAttributeSet::OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, ArmorPenetration, OldArmorPenetration);
}

void UBloodforgedAttributeSet::OnRep_WeaponAccuracy(const FGameplayAttributeData& OldWeaponAccuracy) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, WeaponAccuracy, OldWeaponAccuracy);
}

void UBloodforgedAttributeSet::OnRep_LootQuality(const FGameplayAttributeData& OldLootQuality) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, LootQuality, OldLootQuality);
}

void UBloodforgedAttributeSet::OnRep_CooldownReduction(const FGameplayAttributeData& OldCooldownReduction) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, CooldownReduction, OldCooldownReduction);
}

void UBloodforgedAttributeSet::OnRep_BlockStrength(const FGameplayAttributeData& OldBlockStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBloodforgedAttributeSet, BlockStrength, OldBlockStrength);
}



