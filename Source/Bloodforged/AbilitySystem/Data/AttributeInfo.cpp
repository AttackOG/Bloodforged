// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "AttributeInfo.h"

FBloodforgedAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag,
                                                                  const bool bLogNotFound) const
{
	for (const FBloodforgedAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag))
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Attribute tag not found %s on attribute info %s"), *AttributeTag.ToString(), *GetNameSafe(this));
	}
	return FBloodforgedAttributeInfo();
}
