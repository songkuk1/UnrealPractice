// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "AbilitySystem/KnightAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/KnightGameplayAbility.h"
#include "KnightDebugHelper.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UKnightAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGive,ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);

	if (!StartUpGameplayEffects.IsEmpty())
	{

		for(const TSubclassOf< UGameplayEffect>& EffectClass : StartUpGameplayEffects)
		{
			if (!EffectClass)
				continue;

			UGameplayEffect* EffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();
			InASCToGive->ApplyGameplayEffectToSelf(
				EffectCDO,
				ApplyLevel,
				InASCToGive->MakeEffectContext()
			);

		}



	}
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UKnightGameplayAbility>>& InAbilityesToGive, UKnightAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if(InAbilityesToGive.IsEmpty())
		return;

	for(const TSubclassOf<UKnightGameplayAbility>& Ability : InAbilityesToGive)
	{
		if(!Ability)
			continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;


		InASCToGive->GiveAbility(AbilitySpec);

	}
}
