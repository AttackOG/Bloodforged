// Bloodforged Unreal Engine 5 game created by AttackOG.

#pragma once

#include "CoreMinimal.h"
#include "Bloodforged/UI/Widgets/BloodforgedUserWidget.h"
#include "GameFramework/HUD.h"
#include "BloodforgedHUD.generated.h"

class UAttributeMenuWidgetController;
struct FWidgetControllerParams;
class UAbilitySystemComponent;
class UAttributeSet;
class UBloodforgedUserWidget;
class UOverlayWidgetController;
/**
 * 
 */
UCLASS()
class BLOODFORGED_API ABloodforgedHUD : public AHUD
{
	GENERATED_BODY()

public:
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);

private:
	UPROPERTY()
	TObjectPtr<UBloodforgedUserWidget> OverlayWidget;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UBloodforgedUserWidget> OverlayWidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY()
	TObjectPtr<UAttributeMenuWidgetController> AttributeMenuWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;

public:
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WidgetControllerParams);
	UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const FWidgetControllerParams& WidgetControllerParams);
};
