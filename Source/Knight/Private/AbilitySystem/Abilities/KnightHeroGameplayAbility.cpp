// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/KnightHeroGameplayAbility.h"
#include "Characters/KnightHeroCharacter.h"
#include "Controllers/KnightHeroController.h"


AKnightHeroCharacter* UKnightHeroGameplayAbility::GetKnightHeroCharacterFromActorInfo()
{
	if(!CachedKnightHeroCharacter.IsValid())
	{
		CachedKnightHeroCharacter = Cast<AKnightHeroCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedKnightHeroCharacter.IsValid()? CachedKnightHeroCharacter.Get() : nullptr;
}

AKnightHeroController* UKnightHeroGameplayAbility::GetKnightHeroControllerFromActorInfo()
{
	if (!CachedKnightHeroController.IsValid())
	{
		CachedKnightHeroController = Cast<AKnightHeroController>(CurrentActorInfo->PlayerController);
	}

	return CachedKnightHeroController.IsValid() ? CachedKnightHeroController.Get() : nullptr;

}

UHeroCombatComponent* UKnightHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	
	return GetKnightHeroCharacterFromActorInfo()->GetHeroCombatComponent();

}
