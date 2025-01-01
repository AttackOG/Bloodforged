// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "BloodforgedAssetManager.h"
#include "BloodforgedGameplayTags.h"

UBloodforgedAssetManager& UBloodforgedAssetManager::Get()
{
	check(GEngine);
	UBloodforgedAssetManager* BloodforgedAssetManager = Cast<UBloodforgedAssetManager>(GEngine->AssetManager);
	return *BloodforgedAssetManager;
}

void UBloodforgedAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FBloodforgedGameplayTags::InitializeNativeGameplayTags();
}
