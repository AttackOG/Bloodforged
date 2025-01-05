// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "BloodforgedPlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Bloodforged/AbilitySystem/BloodforgedAbilitySystComp.h"
#include "Bloodforged/AbilitySystem/BloodforgedAbilitySystemLibrary.h"
#include "Bloodforged/Input/BloodforgedInputComponent.h"

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

	UBloodforgedInputComponent* BloodforgedEnhancedInput = CastChecked<UBloodforgedInputComponent>(InputComponent);
	
	BloodforgedEnhancedInput->BindAction(InputPickupAction, ETriggerEvent::Triggered, this, &ABloodforgedPlayerController::InputPickupPressed);
	BloodforgedEnhancedInput->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
}

void ABloodforgedPlayerController::InputPickupPressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Picked up");
}

void ABloodforgedPlayerController::AbilityInputTagPressed(const FGameplayTag InputTag)
{
	if (GetAbilitySystemComponent()) GetAbilitySystemComponent()->AbilityInputTagPressed(InputTag);
	
}

void ABloodforgedPlayerController::AbilityInputTagReleased(const FGameplayTag InputTag)
{
	if (GetAbilitySystemComponent()) GetAbilitySystemComponent()->AbilityInputReleased(InputTag);
}

void ABloodforgedPlayerController::AbilityInputTagHeld(const FGameplayTag InputTag)
{
	if (GetAbilitySystemComponent()) GetAbilitySystemComponent()->AbilityInputTagHeld(InputTag);
	
}

UBloodforgedAbilitySystComp* ABloodforgedPlayerController::GetAbilitySystemComponent()
{
	if (BloodforgedAbilitySystemComponent == nullptr)
	{
		BloodforgedAbilitySystemComponent = Cast<UBloodforgedAbilitySystComp>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return BloodforgedAbilitySystemComponent;
}

