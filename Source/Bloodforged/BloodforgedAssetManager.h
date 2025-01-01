// Bloodforged Unreal Engine 5 game created by AttackOG.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "BloodforgedAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class BLOODFORGED_API UBloodforgedAssetManager : public UAssetManager
{
	GENERATED_BODY()

	public:
	static UBloodforgedAssetManager& Get();

	protected:
	virtual void StartInitialLoading() override;
};
