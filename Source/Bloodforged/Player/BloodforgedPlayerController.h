// Bloodforged Unreal Engine 5 game created by AttackOG.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/PlayerController.h"
#include "BloodforgedPlayerController.generated.h"

class UInventoryManagerComponent;
class UBloodforgedAbilitySystComp;
class UBloodforgedInputConfig;
class UInputAction;
class UInputMappingContext;

/**
 * 
 */
UCLASS()
class BLOODFORGED_API ABloodforgedPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABloodforgedPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
private:
	/*
	 * Input
	 */
	virtual void SetupInputComponent() override;

	UPROPERTY(Replicated, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
	TObjectPtr<UInventoryManagerComponent> InventoryManagerComponent;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> InputPickupAction;
	
	void InputPickupPressed();

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UBloodforgedInputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UBloodforgedAbilitySystComp> BloodforgedAbilitySystemComponent;

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
	
public:
	UBloodforgedAbilitySystComp* GetAbilitySystemComponent();
};
