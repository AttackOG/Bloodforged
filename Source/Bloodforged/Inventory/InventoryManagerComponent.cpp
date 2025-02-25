// Copyright AttackOG Jack Cullen,. All Rights Reserved.


#include "InventoryManagerComponent.h"
#include "NativeGameplayTags.h"


UInventoryManagerComponent::UInventoryManagerComponent()
{
}

void UInventoryManagerComponent::AddItem(FGameplayTag ItemTag, int32 Quantity)
{
	if (Inventory.Contains(ItemTag))
	{
		Inventory[ItemTag] += Quantity;
	}
	else
	{
		Inventory.Add(ItemTag, Quantity);
	}
}

void UInventoryManagerComponent::RemoveItem(FGameplayTag ItemTag, int32 Quantity)
{
	if (Quantity <= 0 || !Inventory.Contains(ItemTag)) return;

	Inventory[ItemTag] -= Quantity;
	if (Inventory[ItemTag] <= 0)
	{
		Inventory.Remove(ItemTag);
	}
}

bool UInventoryManagerComponent::HasItem(FGameplayTag ItemTag) const
{
	return Inventory.Contains(ItemTag) && Inventory[ItemTag] > 0;
}

int32 UInventoryManagerComponent::GetItemQuantity(FGameplayTag ItemTag) const
{
	return Inventory.Contains(ItemTag) ? Inventory[ItemTag] : 0;
}