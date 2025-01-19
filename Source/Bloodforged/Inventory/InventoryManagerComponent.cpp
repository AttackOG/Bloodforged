// Copyright AttackOG Jack Cullen,. All Rights Reserved.


#include "InventoryManagerComponent.h"
#include "Engine/World.h"
#include "NativeGameplayTags.h"
#include "Net/UnrealNetwork.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(InventoryManagerComponent)

class FLifetimeProperty;
struct FReplicationFlags;

void UInventoryManagerComponent::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UInventoryManagerComponent, InventoryList);
}


/*
 * 
This function adds items to an inventory. It checks if the item (identified by InItemTag) already exists in the inventory (Entries). If it does, it increases its quantity by InNumberOfItems and marks it as updated. If the item doesn't exist, it creates a new entry, sets its tag and quantity, and marks it as updated. This ensures efficient item tracking and change management.
 */
void FInventoryList::AddItem(const FGameplayTag& InItemTag, int32 InNumberOfItems)
{
	for (auto EntryIterator = Entries.CreateIterator(); EntryIterator; ++EntryIterator)
	{
		FInventoryEntry& Entry = *EntryIterator;

		if (Entry.ItemTag.MatchesTagExact(InItemTag))
		{
			Entry.Quantity += InNumberOfItems;

			MarkItemDirty(Entry);
			return;
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString("Item added"));
	FInventoryEntry& NewEntry = Entries.AddDefaulted_GetRef();
	NewEntry.ItemTag = InItemTag;
	NewEntry.Quantity = InNumberOfItems;

	MarkItemDirty(NewEntry);
}

void FInventoryList::RemoveItem(const FGameplayTag& InItemTag, int32 InNumberOfItems)
{
	for (auto EntryIterator = Entries.CreateIterator() ; EntryIterator; ++EntryIterator)
	{
		FInventoryEntry& Entry = *EntryIterator;

		if (Entry.ItemTag.MatchesTagExact(InItemTag))
		{
			Entry.Quantity -= InNumberOfItems;
			MarkItemDirty(Entry);
		}
	}
}

bool FInventoryList::bHasEnough(const FGameplayTag& InItemTag, int32 InNumberOfItems)
{
	for (auto EntryIterator = Entries.CreateIterator(); EntryIterator; ++EntryIterator)
	{
		FInventoryEntry& Entry = *EntryIterator;
		if (Entry.ItemTag.MatchesTagExact(InItemTag))
		{
			if (Entry.Quantity >= InNumberOfItems)
			{
				return true;
			}
		}
	}
	return false;
}

void FInventoryList::PreReplicatedRemove(const TArrayView<int32> RemovedIndices, int32 FinalSize)
{
}

void FInventoryList::PostReplicatedAdd(const TArrayView<int32> AddedIndices, int32 FinalSize)
{
}

void FInventoryList::PostReplicatedChange(const TArrayView<int32> ChangedIndices, int32 FinalSize)
{
}

UInventoryManagerComponent::UInventoryManagerComponent(const FObjectInitializer& ObjectInitializer)
{
}


void UInventoryManagerComponent::AddItem(const FGameplayTag& ItemTag, int32 NumberOfItems)
{
	AActor* OwningActor = GetOwner();
	if (!IsValid(OwningActor)) return;

	if (!OwningActor->HasAuthority())
	{
		ServerAddItem(ItemTag, NumberOfItems);
		return;
	}
	InventoryList.AddItem(ItemTag, NumberOfItems);
}

void UInventoryManagerComponent::UseItem(const FGameplayTag& ItemTag, int32 NumberOfItems)
{
	AActor* OwningActor = GetOwner();
	if (!IsValid(OwningActor)) return;

	if (!OwningActor->HasAuthority())
	{
		ServerUseItem(ItemTag, NumberOfItems);
		return;
	}
}

void UInventoryManagerComponent::ServerUseItem_Implementation(const FGameplayTag& ItemTag, int32 NumberOfItems)
{
	AddItem(ItemTag, NumberOfItems);
}

void UInventoryManagerComponent::ServerAddItem_Implementation(const FGameplayTag& ItemTag, int32 NumberOfItems)
{
	if (InventoryList.bHasEnough(ItemTag, NumberOfItems))
	{
		UseItem(ItemTag, NumberOfItems);
	}
}
