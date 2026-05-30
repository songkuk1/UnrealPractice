// Fill out your copyright notice in the Description page of Project Settings.

#include "KnightTypes/KnightStructTypes.h"
#include "AbilitySystem/Abilities/KnightGameplayAbility.h"



bool FKnightHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}