// Copyright AttackOG Jack Cullen,. All Rights Reserved.


#include "WeaponBase.h"

#include "Components/SphereComponent.h"


AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
}
