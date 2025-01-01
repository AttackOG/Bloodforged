// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "BloodforgedPlayerController.h"
#include "EnhancedInputComponent.h"

ABloodforgedPlayerController::ABloodforgedPlayerController()
{
	bReplicates = true;
}

void ABloodforgedPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ABloodforgedPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInput->BindAction(InputPickupAction, ETriggerEvent::Triggered, this, &ABloodforgedPlayerController::InputPickupPressed);
}

void ABloodforgedPlayerController::InputPickupPressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Picked up");
}
