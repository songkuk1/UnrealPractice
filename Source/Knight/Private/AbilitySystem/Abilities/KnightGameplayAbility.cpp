// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/KnightGameplayAbility.h"
#include "AbilitySystem/KnightAbilitySystemComponent.h"
#include "Components/PawnCombatComponent.h"

void UKnightGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo,Spec);

	if(AbilityActivationPolicy == EKnightAbilityActivationPolicy::OnGiven)
	{
		
		if(ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}

	}
}

void UKnightGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo,bReplicateEndAbility,bWasCancelled);

	if (AbilityActivationPolicy == EKnightAbilityActivationPolicy::OnGiven)
	{
		if(ActorInfo)
		{

			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}

	}
}

UPawnCombatComponent* UKnightGameplayAbility::GetPawnCombatComponentFromActorInfo()
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}

UKnightAbilitySystemComponent* UKnightGameplayAbility::GetKnightAbilitySystemComponentFromActorInfo() const
{
	return Cast<UKnightAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);

}
