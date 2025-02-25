// Copyright AttackOG Jack Cullen,. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


class AInteractableItemsBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BLOODFORGED_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCombatComponent();
	friend class ACharacterBase;

	void EquipItem(AInteractableItemsBase* ItemToEquip);

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(Replicated)
	TObjectPtr<AInteractableItemsBase> EquippedItem;

protected:
	virtual void BeginPlay() override;

private:
	TObjectPtr<ACharacterBase> Character;

		
};
