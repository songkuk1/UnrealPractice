// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_EnemyStartUpData.h"
#include "AbilitySystem/Abilities/KnightEnemyGameplayAbility.h"
#include "AbilitySystem/KnightAbilitySystemComponent.h"


void UDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(UKnightAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	if(!EnemyCombatAbilities.IsEmpty())
	{
		for(const TSubclassOf<UKnightEnemyGameplayAbility>& AbilityClass : EnemyCombatAbilities)
		{
			if (!AbilityClass)
				continue;

			FGameplayAbilitySpec AbilitySpec(AbilityClass);
			AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;

			InASCToGive->GiveAbility(AbilitySpec);

		}


	}

}
