// Copyright AttackOG Jack Cullen,. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "InteractableItemsBase.generated.h"

class ABloodforgedPlayerController;
class USkeletalMeshComponent;
class UGameplayAbility;
class UWidgetComponent;
class USphereComponent;

UENUM(BlueprintType)
enum class EItemState : uint8
{
	EIS_Dropped UMETA(DisplayName = "Dropped"),
	EIS_Unequipped UMETA(DisplayName = "Unequipped"),
	EIS_Equipped UMETA(DisplayName = "Equipped"),
	
	EIS_Max UMETA(DisplayName = "DefaultMax")
};


UCLASS(Abstract)
class BLOODFORGED_API AInteractableItemsBase : public AActor
{
	GENERATED_BODY()

public:
	AInteractableItemsBase();

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	// Triggers a gameplay ability for item pickup
	UFUNCTION(BlueprintCallable)
	void Interact(AActor* Interactor, UAbilitySystemComponent* ASC);

	// Gameplay ability to apply when picked up (e.g., PickupWeapon, PickupPotion)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Ability")
	TSubclassOf<UGameplayAbility> PickupAbilityClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Info")
	FGameplayTag ItemTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Info")
	int32 Quantity = 1;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UWidgetComponent> WidgetComponent;

private:
	UPROPERTY(ReplicatedUsing = OnRep_ItemState, VisibleAnywhere, Category = "Item|Properties")
	EItemState ItemState;

	UFUNCTION()
	void OnRep_ItemState();
	
public:
	UFUNCTION(BlueprintCallable)
	void ShowPickupWidget(bool bShowPickupWidget) const;

	void SetItemState(EItemState State);
	
	FORCEINLINE USphereComponent* GetSphereComponent() const { return SphereComponent; }
	
};
