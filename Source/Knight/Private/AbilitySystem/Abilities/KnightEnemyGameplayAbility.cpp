// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/KnightEnemyGameplayAbility.h"
#include "Components/EnemyCombatComponent.h"
#include "Characters/KnightEnemyCharacter.h"

AKnightEnemyCharacter* UKnightEnemyGameplayAbility::GetKnightEnemyCharacterFromActorInfo() 
{
	if(!CachedKnightEnemyCharacter.IsValid())
	{
		CachedKnightEnemyCharacter = Cast<AKnightEnemyCharacter>(CurrentActorInfo->AvatarActor);

		
	}

	return CachedKnightEnemyCharacter.IsValid() ? CachedKnightEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* UKnightEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo() 
{

	return GetKnightEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}
