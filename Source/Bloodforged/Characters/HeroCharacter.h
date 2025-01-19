// Bloodforged Unreal Engine 5 game created by AttackOG.

#pragma once

#include "CoreMinimal.h"
#include "CharacterBase.h"
#include "HeroCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BLOODFORGED_API AHeroCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	virtual int32 GetLevel() override;
	
private:
	virtual void InitAbilityActorInfo() override;
};
