// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "BloodforgedPlayerController.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Bloodforged/AbilitySystem/BloodforgedAbilitySystComp.h"
#include "Bloodforged/Input/BloodforgedInputComponent.h"
#include "Characters/CharacterBase.h"
#include "Inventory/InventoryManagerComponent.h"
#include "Net/UnrealNetwork.h"

ABloodforgedPlayerController::ABloodforgedPlayerController()
{
	bReplicates = true;
	InventoryManagerComponent = CreateDefaultSubobject<UInventoryManagerComponent>("Inventory");
	InventoryManagerComponent->SetIsReplicated(true);
}

void ABloodforgedPlayerController::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABloodforgedPlayerController, InventoryManagerComponent);
}

void ABloodforgedPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerCharacter = Cast<ACharacterBase>(GetPawn());
}

void ABloodforgedPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UBloodforgedInputComponent* BloodforgedEnhancedInput = CastChecked<UBloodforgedInputComponent>(InputComponent);

	BloodforgedEnhancedInput->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
	BloodforgedEnhancedInput->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
	BloodforgedEnhancedInput->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
//	BloodforgedEnhancedInput->BindAction(InputPickupAction, ETriggerEvent::Triggered, this, &ThisClass::InputPickupPressed);
}

void ABloodforgedPlayerController::InputPickupPressed()
{
	if (PlayerCharacter)
	{
		PlayerCharacter->EquipButtonPressed();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "PlayerCharacter is not valid in bloodforged player controller");
	}
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

UInventoryManagerComponent* ABloodforgedPlayerController::GetInventoryManager() const
{
	return InventoryManagerComponent;
}

