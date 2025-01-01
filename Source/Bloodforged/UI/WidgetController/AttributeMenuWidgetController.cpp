// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "AttributeMenuWidgetController.h"
#include "Bloodforged/AbilitySystem/BloodforgedAttributeSet.h"
#include "Bloodforged/AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	UBloodforgedAttributeSet* AS = CastChecked<UBloodforgedAttributeSet>(AttributeSet);
	check(AttributeInfo);
	for (auto& Pair : AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
		[this, Pair](const FOnAttributeChangeData& Data)
		{
			BroadcastAttributeInfo(Pair.Key, Pair.Value());
		}
	);
	}
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UBloodforgedAttributeSet* BloodforgedAttributeSet = CastChecked<UBloodforgedAttributeSet>(AttributeSet);

	check(AttributeInfo);
	
	for (auto& Pair : BloodforgedAttributeSet->TagsToAttributes)
	{
		BroadcastAttributeInfo(Pair.Key, Pair.Value());
	}
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag,
	const FGameplayAttribute& Attribute) const
{
	FBloodforgedAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(Info);
}
