// Copyright AttackOG Jack Cullen,. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interactables/InteractableItemsBase.h"
#include "WeaponBase.generated.h"


UCLASS()
class BLOODFORGED_API AWeaponBase : public AInteractableItemsBase
{
	GENERATED_BODY()

public:
	AWeaponBase();

protected:
	virtual void BeginPlay() override;

private:
};
