// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "AbilitySystem/Abilities/KnightGameplayAbility.h"
#include "AbilitySystem/KnightAbilitySystemComponent.h"
#include "KnightDebugHelper.h"


void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UKnightAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive,ApplyLevel);

	for(const FKnightHeroAbilitySet& AbilitySet : HeroStartUpAbilitySets)
	{
		if(!AbilitySet.IsValid())
			continue;
		Debug::Print(AbilitySet.InputTag.ToString());
		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(AbilitySpec);

	}


}
