// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "BloodforgedAbilitySystemLibrary.h"
#include "Bloodforged/Player/BloodforgedPlayerState.h"
#include "Bloodforged/UI/HUD/BloodforgedHUD.h"
#include "Bloodforged/UI/WidgetController/BloodforgedWidgetController.h"
#include "Kismet/GameplayStatics.h"

UOverlayWidgetController* UBloodforgedAbilitySystemLibrary::GetOverlayWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ABloodforgedHUD* BloodforgedHUD = Cast<ABloodforgedHUD>(PlayerController->GetHUD()))
		{
			ABloodforgedPlayerState* PlayerState = PlayerController->GetPlayerState<ABloodforgedPlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = PlayerState->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);
			return BloodforgedHUD->GetOverlayWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}

UAttributeMenuWidgetController* UBloodforgedAbilitySystemLibrary::GetAttributeMenuWidgetController(
	const UObject* WorldContextObject)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ABloodforgedHUD* BloodforgedHUD = Cast<ABloodforgedHUD>(PlayerController->GetHUD()))
		{
			ABloodforgedPlayerState* PlayerState = PlayerController->GetPlayerState<ABloodforgedPlayerState>();
			UAbilitySystemComponent* AbilitySystemComponent = PlayerState->GetAbilitySystemComponent();
			UAttributeSet* AttributeSet = PlayerState->GetAttributeSet();
			const FWidgetControllerParams WidgetControllerParams(PlayerController, PlayerState, AbilitySystemComponent, AttributeSet);
			return BloodforgedHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
		}
	}
	return nullptr;
}
