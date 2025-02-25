// Copyright AttackOG Jack Cullen,. All Rights Reserved.


#include "InteractableItemsBase.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Net/UnrealNetwork.h"


AInteractableItemsBase::AInteractableItemsBase()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	// Static Mesh
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(StaticMeshComponent);
	StaticMeshComponent->SetCollisionResponseToAllChannels(ECR_Block);
	StaticMeshComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Sphere Collision
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(GetRootComponent());
	SphereComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// UI Widget
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(GetRootComponent());
	WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	WidgetComponent->SetDrawAtDesiredSize(true);
}

void AInteractableItemsBase::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AInteractableItemsBase, ItemState);
}

void AInteractableItemsBase::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		SphereComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
	}
	if (WidgetComponent)
	{
		ShowPickupWidget(false);
	}
}

void AInteractableItemsBase::SetItemState(EItemState State)
{
	ItemState = State;
	switch (ItemState)
	{
	case EItemState::EIS_Equipped:
		ShowPickupWidget(false);
		StaticMeshComponent->SetSimulatePhysics(false);
		StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SphereComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	default:
		break;
	}
}

void AInteractableItemsBase::OnRep_ItemState()
{
	switch (ItemState)
	{
	case EItemState::EIS_Equipped:
		ShowPickupWidget(false);
		StaticMeshComponent->SetSimulatePhysics(false);
		StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		SphereComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		break;
	default:
		break;
	}
}

void AInteractableItemsBase::ShowPickupWidget(bool bShowPickupWidget) const
{
	if (WidgetComponent)
	{
		WidgetComponent->SetVisibility(bShowPickupWidget);
	}
}

void AInteractableItemsBase::Interact(AActor* Interactor, UAbilitySystemComponent* ASC)
{
}