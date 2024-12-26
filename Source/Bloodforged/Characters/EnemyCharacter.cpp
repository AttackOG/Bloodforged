// Bloodforged Unreal Engine 5 game created by AttackOG.


#include "EnemyCharacter.h"

#include "Bloodforged/AbilitySystem/BloodforgedAbilitySystComp.h"
#include "Bloodforged/AbilitySystem/BloodforgedAttributeSet.h"

AEnemyCharacter::AEnemyCharacter()
{
	
	WeaponMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("WeaponMesh");
	WeaponMeshComponent->SetupAttachment(GetMesh(), FName("weapon_r"));
	WeaponMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	AbilitySystemComponent = CreateDefaultSubobject<UBloodforgedAbilitySystComp>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UBloodforgedAttributeSet>("AttributeSet");
}

int32 AEnemyCharacter::GetLevel()
{
	return EnemyLevel;
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	InitAbilityActorInfo();
}

void AEnemyCharacter::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Cast<UBloodforgedAbilitySystComp>(AbilitySystemComponent)->AbilityActorInfoSet();
}
