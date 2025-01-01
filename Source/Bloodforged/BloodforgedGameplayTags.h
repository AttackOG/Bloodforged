// Bloodforged Unreal Engine 5 game created by AttackOG.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * 
 */

struct FBloodforgedGameplayTags
{
public:
	static const FBloodforgedGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	// Primary Attributes
	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Resilience;
	FGameplayTag Attributes_Primary_Vigor;
	FGameplayTag Attributes_Primary_Dexterity;
	FGameplayTag Attributes_Primary_Wisdom;
	FGameplayTag Attributes_Primary_Endurance;
	FGameplayTag Attributes_Primary_Luck;

	// Secondary Attributes
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_MaxMana;
	FGameplayTag Attributes_Secondary_MaxStamina;
	FGameplayTag Attributes_Secondary_PhysicalAttackPower;
	FGameplayTag Attributes_Secondary_MagicalAttackPower;
	FGameplayTag Attributes_Secondary_CriticalHitChance;
	FGameplayTag Attributes_Secondary_CriticalHitDamage;
	FGameplayTag Attributes_Secondary_PhysicalDefence;
	FGameplayTag Attributes_Secondary_MagicalDefence;
	FGameplayTag Attributes_Secondary_AttackSpeed;
	FGameplayTag Attributes_Secondary_DodgeChance;
	FGameplayTag Attributes_Secondary_StaminaRegenRate;
	FGameplayTag Attributes_Secondary_ManaRegenRate;
	FGameplayTag Attributes_Secondary_HealthRegenRate;
	FGameplayTag Attributes_Secondary_ArmorPenetration;
	FGameplayTag Attributes_Secondary_WeaponAccuracy;
	FGameplayTag Attributes_Secondary_LootQualityModifier;
	FGameplayTag Attributes_Secondary_CooldownReduction;
	FGameplayTag Attributes_Secondary_BlockStrength;

	// Vital Attributes
	FGameplayTag Attributes_Vital_Health;
	FGameplayTag Attributes_Vital_Mana;
	FGameplayTag Attributes_Vital_Stamina;

private:
	static FBloodforgedGameplayTags GameplayTags;
};