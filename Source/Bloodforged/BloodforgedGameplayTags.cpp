// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "BloodforgedGameplayTags.h"

#include "GameplayTagsManager.h"

FBloodforgedGameplayTags FBloodforgedGameplayTags::GameplayTags;

void FBloodforgedGameplayTags::InitializeNativeGameplayTags()
{
	// Primary Attributes
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength"), FString("Responsible for increasing physical damage dealt (melee and weapon-based attacks) and determining the ability to wield heavier weapons."));
	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"), FString("Responsible for increasing magic damage output and boosting the mana or focus resource pool."));
	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Resilience"), FString("Enhances armor to reduce incoming physical damage and improves armor penetration for physical attacks."));
	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Vigor"), FString("Increases the maximum health pool and slightly impacts health regeneration (if used)."));
	GameplayTags.Attributes_Primary_Dexterity = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Dexterity"), FString("Improves weapon accuracy (for ranged weapons like bows), boosts attack speed, and increases critical hit chance for precision-based attacks."));
	GameplayTags.Attributes_Primary_Wisdom = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Wisdom"), FString("Enhances magical resistance to reduce incoming spell damage and increases mana regeneration or cooldown reduction."));
	GameplayTags.Attributes_Primary_Endurance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Endurance"), FString("Increases stamina for running, dodging, and special actions, as well as boosting stamina recovery rate."));
	GameplayTags.Attributes_Primary_Luck = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Luck"), FString("Increases base critical hit chance across all attack types, improves loot quality (better gear, rare items), and affects RNG-based systems such as evasion or hidden secret discovery."));
	
	// Secondary Attributes
	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth"), FString("Represents the player's maximum health, calculated based on Vigor and Resilience."));
	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxMana"), FString("Represents the player's maximum mana, calculated based on Intelligence and Wisdom."));
	GameplayTags.Attributes_Secondary_MaxStamina = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxStamina"), FString("Represents the player's maximum stamina, calculated based on Endurance and Dexterity."));
	GameplayTags.Attributes_Secondary_PhysicalAttackPower = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.PhysicalAttackPower"), FString("Represents the player's physical attack power, calculated based on Strength and Dexterity."));
	GameplayTags.Attributes_Secondary_MagicalAttackPower = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MagicalAttackPower"), FString("Represents the player's magical attack power, calculated based on Intelligence and Wisdom."));
	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitChance"), FString("Represents the player's critical hit chance, calculated based on Luck and Dexterity."));
	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitDamage"), FString("Represents the player's critical damage multiplier, calculated based on Luck and Strength/Intelligence depending on attack type."));
	GameplayTags.Attributes_Secondary_PhysicalDefence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.PhysicalDefence"), FString("Represents the player's physical defense, calculated based on Resilience and Vigor."));
	GameplayTags.Attributes_Secondary_MagicalDefence = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MagicalDefence"), FString("Represents the player's magical defense, calculated based on Wisdom and Intelligence."));
	GameplayTags.Attributes_Secondary_AttackSpeed = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.AttackSpeed"), FString("Represents the player's attack speed, calculated based on Dexterity and Strength."));
	GameplayTags.Attributes_Secondary_DodgeChance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.DodgeChance"), FString("Represents the player's dodge chance, calculated based on Dexterity, Luck, and Endurance."));
	GameplayTags.Attributes_Secondary_StaminaRegenRate = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.StaminaRegenRate"), FString("Represents the player's stamina regeneration rate, calculated based on Endurance and Vigor."));
	GameplayTags.Attributes_Secondary_ManaRegenRate = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ManaRegenRate"), FString("Represents the player's mana regeneration rate, calculated based on Wisdom and Intelligence."));
	GameplayTags.Attributes_Secondary_HealthRegenRate = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.HealthRegenRate"), FString("Represents the player's health regeneration rate, calculated based on Vigor and Endurance."));
	GameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ArmorPenetration"), FString("Represents the player's ability to penetrate enemy armor, calculated based on Strength and Resilience."));
	GameplayTags.Attributes_Secondary_WeaponAccuracy = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.WeaponAccuracy"), FString("Represents the player's weapon accuracy, calculated based on Dexterity and Luck."));
	GameplayTags.Attributes_Secondary_LootQualityModifier = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.LootQualityModifier"), FString("Represents the player's influence on loot quality, calculated based on Luck."));
	GameplayTags.Attributes_Secondary_CooldownReduction = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CooldownReduction"), FString("Represents the player's cooldown reduction for abilities, calculated based on Wisdom and Intelligence."));
	GameplayTags.Attributes_Secondary_BlockStrength = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.BlockStrength"), FString("Represents the player's block strength, calculated based on Resilience and Strength."));

	// Vital Attributes
	GameplayTags.Attributes_Vital_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Health"), FString("Represents the maximum health pool of a character, determining how much damage they can take before dying. Scaled primarily by Vigor, with minor contributions from Resilience and Endurance."));
	GameplayTags.Attributes_Vital_Mana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Mana"), FString("Represents the maximum mana pool, determining the ability to cast spells or use magical abilities. Scaled primarily by Intelligence, with minor contributions from Wisdom."));
	GameplayTags.Attributes_Vital_Stamina = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Stamina"), FString("Represents the maximum stamina pool, determining the ability to perform actions like running, dodging, or special moves. Scaled primarily by Endurance, with minor contributions from Dexterity and Vigor."));
}
