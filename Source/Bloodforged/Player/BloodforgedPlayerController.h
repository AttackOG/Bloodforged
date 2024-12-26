// Bloodforged Unreal Engine 5 game created by AttackOG.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BloodforgedPlayerController.generated.h"

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

private:
	/*
	 * Input
	 */
	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> InputPickupAction;
	
	void InputPickupPressed();
	
};
