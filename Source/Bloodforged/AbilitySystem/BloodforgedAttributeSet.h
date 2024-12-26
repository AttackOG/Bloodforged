// Bloodforged Unreal Engine 5 game created by AttackOG.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "BloodforgedAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceAbilitySystemComponent = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetAbilitySystemComponent = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};

/**
 * 
 */
UCLASS()
class BLOODFORGED_API UBloodforgedAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UBloodforgedAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	/*
	 * Primary Attributes
	 */

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Strength, Category = "Attributes|Primary")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Intelligence, EditAnywhere, Category = "Attributes|Primary")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Resilience, EditAnywhere, Category = "Attributes|Primary")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, Resilience);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Vigor, EditAnywhere, Category = "Attributes|Primary")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, Vigor);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Dexterity, EditAnywhere, Category = "Attributes|Primary")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, Dexterity);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Wisdom, EditAnywhere, Category = "Attributes|Primary")
	FGameplayAttributeData Wisdom;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, Wisdom);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Endurance, EditAnywhere, Category = "Attributes|Primary")
	FGameplayAttributeData Endurance;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, Endurance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Luck, EditAnywhere, Category = "Attributes|Primary")
	FGameplayAttributeData Luck;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, Luck);

	/*
	 * Secondary Attributes
	 */

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxHealth, Category = "Attributes|Secondary") 
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxMana, Category = "Attributes|Secondary") 
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, MaxMana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MaxStamina, Category = "Attributes|Secondary") 
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, MaxStamina);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_PhysicalAttackPower, Category = "Attributes|Secondary") 
	FGameplayAttributeData PhysicalAttackPower;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, PhysicalAttackPower);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MagicalAttackPower, Category = "Attributes|Secondary") 
	FGameplayAttributeData MagicalAttackPower;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, MagicalAttackPower);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalHitChance, Category = "Attributes|Secondary") 
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, CriticalHitChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CriticalHitDamage, Category = "Attributes|Secondary") 
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, CriticalHitDamage);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_PhysicalDefence, Category = "Attributes|Secondary") 
	FGameplayAttributeData PhysicalDefence;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, PhysicalDefence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_MagicalDefence, Category = "Attributes|Secondary") 
	FGameplayAttributeData MagicalDefence;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, MagicalDefence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_AttackSpeed, Category = "Attributes|Secondary") 
	FGameplayAttributeData AttackSpeed;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, AttackSpeed);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_DodgeChance, Category = "Attributes|Secondary") 
	FGameplayAttributeData DodgeChance;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, DodgeChance);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_StaminaRegenerationRate, Category = "Attributes|Secondary") 
	FGameplayAttributeData StaminaRegenerationRate;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, StaminaRegenerationRate);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ManaRegenerationRate, Category = "Attributes|Secondary") 
	FGameplayAttributeData ManaRegenerationRate;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, ManaRegenerationRate);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_HealthRegenerationRate, Category = "Attributes|Secondary") 
	FGameplayAttributeData HealthRegenerationRate;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, HealthRegenerationRate);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ArmorPenetration, Category = "Attributes|Secondary") 
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, ArmorPenetration);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_WeaponAccuracy, Category = "Attributes|Secondary") 
	FGameplayAttributeData WeaponAccuracy;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, WeaponAccuracy);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_LootQuality, Category = "Attributes|Secondary") 
	FGameplayAttributeData LootQuality;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, LootQuality);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CooldownReduction, Category = "Attributes|Secondary") 
	FGameplayAttributeData CooldownReduction;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, CooldownReduction);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_BlockStrength, Category = "Attributes|Secondary") 
	FGameplayAttributeData BlockStrength;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, BlockStrength);

	
	/*
	 * Vital Attributes
	 */

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Attributes|Vital")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Attributes|Vital")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, Mana);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "Attributes|Vital")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UBloodforgedAttributeSet, Stamina);

	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;
	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;
	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;
	UFUNCTION()
	void OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const;
	UFUNCTION()
	void OnRep_Wisdom(const FGameplayAttributeData& OldWisdom) const;
	UFUNCTION()
	void OnRep_Endurance(const FGameplayAttributeData& OldEndurance) const;
	UFUNCTION()
	void OnRep_Luck(const FGameplayAttributeData& OldLuck) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;
	UFUNCTION()
	void OnRep_PhysicalAttackPower(const FGameplayAttributeData& OldPhysicalAttackPower) const;
	UFUNCTION()
	void OnRep_MagicalAttackPower(const FGameplayAttributeData& OldMagicalAttackPower) const;
	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;
	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;
	UFUNCTION()
	void OnRep_PhysicalDefence(const FGameplayAttributeData& OldPhysicalDefence) const;
	UFUNCTION()
	void OnRep_MagicalDefence(const FGameplayAttributeData& OldMagicalDefence) const;
	UFUNCTION()
	void OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed) const;
	UFUNCTION()
	void OnRep_DodgeChance(const FGameplayAttributeData& OldDodgeChance) const;
	UFUNCTION()
	void OnRep_HealthRegenerationRate(const FGameplayAttributeData& OldHealthRegenerationRate) const;
	UFUNCTION()
	void OnRep_ManaRegenerationRate(const FGameplayAttributeData& OldManaRegenerationRate) const;
	UFUNCTION()
	void OnRep_StaminaRegenerationRate(const FGameplayAttributeData& OldStaminaRegenerationRate) const;
	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;
	UFUNCTION()
	void OnRep_WeaponAccuracy(const FGameplayAttributeData& OldWeaponAccuracy) const;
	UFUNCTION()
	void OnRep_LootQuality(const FGameplayAttributeData& OldLootQuality) const;
	UFUNCTION()
	void OnRep_CooldownReduction(const FGameplayAttributeData& OldCooldownReduction) const;
	UFUNCTION()
	void OnRep_BlockStrength(const FGameplayAttributeData& OldBlockStrength) const;
	
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;
	

private:
	static void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& EffectProperties);
};
