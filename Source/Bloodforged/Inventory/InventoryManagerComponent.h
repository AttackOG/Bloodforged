// Copyright AttackOG Jack Cullen,. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "InventoryManagerComponent.generated.h"


/*
 *	Manages an inventory
 *
 *	Component that acts as the actual inventory itself, this is added to a Controller and
	contains functions for managing inventory items:
	Add Item
	Remove Item
	Get All Items
	Find Item
	Get Item Count
	Consume Item
*/

UCLASS(BlueprintType)
class BLOODFORGED_API UInventoryManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryManagerComponent();

	UFUNCTION(BlueprintCallable)
	void AddItem(FGameplayTag ItemTag, int32 Quantity = 1);
	UFUNCTION(BlueprintCallable)
	void RemoveItem(FGameplayTag ItemTag, int32 Quantity = 1);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasItem(FGameplayTag ItemTag) const;
	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetItemQuantity(FGameplayTag ItemTag) const;

private:
	// Map to store items and their quantities
	UPROPERTY()
	TMap<FGameplayTag, int32> Inventory;
};
	