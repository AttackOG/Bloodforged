// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "BloodforgedWidgetController.h"

void UBloodforgedWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams)
{
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet = WidgetControllerParams.AttributeSet;
}

void UBloodforgedWidgetController::BroadcastInitialValues()
{
	// Being overrided by child class OverlayWidgetController.
}

void UBloodforgedWidgetController::BindCallbacksToDependencies()
{
	// Being overrided by child class OverlayWidgetController.
}
