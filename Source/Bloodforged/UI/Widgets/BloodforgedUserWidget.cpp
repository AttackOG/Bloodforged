// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "BloodforgedUserWidget.h"

void UBloodforgedUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}