// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystem/KnightAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/KnightGameplayAbility.h"
#include "KnightDebugHelper.h"


void UKnightAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{

	if(!InInputTag.IsValid())
	{
		return;
	}

	for(const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if(!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag))
			continue;

		TryActivateAbility(AbilitySpec.Handle);

	}
}

void UKnightAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{
}

void UKnightAbilitySystemComponent::GrantHeroWeaponAbilities(const TArray<FKnightHeroAbilitySet>& InDefaultWeaponAbilities, int32 ApplyLevel, TArray<FGameplayAbilitySpecHandle>& OutGrantedAbilitySpectHandle)
{
	if (InDefaultWeaponAbilities.IsEmpty())
		return;

	for(const FKnightHeroAbilitySet& AbilitySet : InDefaultWeaponAbilities)
	{
		if(!AbilitySet.IsValid())
			continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		

		OutGrantedAbilitySpectHandle.AddUnique(GiveAbility(AbilitySpec));
	}

}

void UKnightAbilitySystemComponent::RemoveGrantedHeroWeaponAbilities(UPARAM(ref)TArray<FGameplayAbilitySpecHandle>& InspecHandlesToRemove)
{
	if (InspecHandlesToRemove.IsEmpty())
		return;

	for(const FGameplayAbilitySpecHandle& SpecHandle : InspecHandlesToRemove)
	{
		if(SpecHandle.IsValid())
		{
			ClearAbility(SpecHandle);
		}

	}

	InspecHandlesToRemove.Empty();
}
