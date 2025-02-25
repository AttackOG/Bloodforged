// Bloodforged Unreal Engine 5 game created by AttackOG.

#pragma once

#include "AbilitySystemInterface.h"
#include "CoreMinimal.h"
#include "Bloodforged/Interfaces/CombatInterface.h"
#include "Components/CombatComponent.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

class UCombatComponent;
class AInteractableItemsBase;
class UGameplayAbility;
class UGameplayEffect;
class UAttributeSet;
class UAbilitySystemComponent;

UCLASS(Abstract)
class BLOODFORGED_API ACharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	ACharacterBase();

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostInitializeComponents() override;

	UFUNCTION(BlueprintCallable)
	void EquipButtonPressed();

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	virtual void InitAbilityActorInfo();
	

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;

	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const;
	void InitializeDefaultAttributes() const;
	void AddCharacterAbilities() const;

	UPROPERTY(EditAnywhere, Category = "Attributes")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
	
private:
	UPROPERTY(ReplicatedUsing = OnRep_InteractableItem)
	TObjectPtr<AInteractableItemsBase> OverlappingItem;

	UFUNCTION()
	void OnRep_InteractableItem(AInteractableItemsBase* LastItem);

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCombatComponent> CombatComponent;

	UFUNCTION(Server, Reliable)
	void ServerEquipButtonPressed();

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

	UFUNCTION(BlueprintCallable)
	void SetOverlappingItem(AInteractableItemsBase* Item);

	UFUNCTION(BlueprintPure, BlueprintCallable)
	bool IsWeaponEquipped();
};

inline void ACharacterBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (CombatComponent)
	{
		CombatComponent->Character = this;
	}
}
