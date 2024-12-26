// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "OverlayWidgetController.h"
#include "AttributeSet.h"
#include "Bloodforged/AbilitySystem/BloodforgedAbilitySystComp.h"
#include "Bloodforged/AbilitySystem/BloodforgedAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UBloodforgedAttributeSet* BloodforgedAttributeSet = CastChecked<UBloodforgedAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(BloodforgedAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(BloodforgedAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(BloodforgedAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(BloodforgedAttributeSet->GetMaxMana());
	OnStaminaChanged.Broadcast(BloodforgedAttributeSet->GetStamina());
	OnMaxStaminaChanged.Broadcast(BloodforgedAttributeSet->GetMaxStamina());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UBloodforgedAttributeSet* BloodforgedAttributeSet = CastChecked<UBloodforgedAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BloodforgedAttributeSet->GetHealthAttribute()).AddLambda
	(
		[this](const FOnAttributeChangeData& Data)
		{
			OnHealthChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BloodforgedAttributeSet->GetMaxHealthAttribute()).AddLambda
	(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxHealthChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BloodforgedAttributeSet->GetManaAttribute()).AddLambda
	(
		[this](const FOnAttributeChangeData& Data)
		{
			OnManaChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BloodforgedAttributeSet->GetMaxManaAttribute()).AddLambda
	(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxManaChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BloodforgedAttributeSet->GetStaminaAttribute()).AddLambda
	(
		[this](const FOnAttributeChangeData& Data)
		{
			OnStaminaChanged.Broadcast(Data.NewValue);
		}
	);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BloodforgedAttributeSet->GetMaxStaminaAttribute()).AddLambda
	(
		[this](const FOnAttributeChangeData& Data)
		{
			OnMaxStaminaChanged.Broadcast(Data.NewValue);
		}
	);

	Cast<UBloodforgedAbilitySystComp>(AbilitySystemComponent)->EffectAssetTags.AddLambda
	(
		[this] (const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					MessageWidgetRowDelegate.Broadcast(*Row);
				}
			}
		}
	);
}