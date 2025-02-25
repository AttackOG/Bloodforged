// Copyright AttackOG Jack Cullen,. All Rights Reserved.


#include "Components/CombatComponent.h"
#include "Characters/CharacterBase.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Interactables/InteractableItemsBase.h"
#include "Net/UnrealNetwork.h"

UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}

void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UCombatComponent::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCombatComponent, EquippedItem);
}

void UCombatComponent::EquipItem(AInteractableItemsBase* ItemToEquip)
{
	if (Character == nullptr || ItemToEquip == nullptr) return;

	EquippedItem = ItemToEquip;
	EquippedItem->SetItemState(EItemState::EIS_Equipped);
	EquippedItem->SetItemState(EItemState::EIS_Equipped);
	const USkeletalMeshSocket* HandSocket = Character->GetMesh()->GetSocketByName(FName("RightHandSocket"));
	if (HandSocket)
	{
		HandSocket->AttachActor(EquippedItem, Character->GetMesh());
	}
	EquippedItem->SetOwner(Character);
}

