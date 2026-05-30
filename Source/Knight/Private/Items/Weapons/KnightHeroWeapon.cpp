// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/KnightHeroWeapon.h"

void AKnightHeroWeapon::AssignGrantedAbilitySpecHandles(const TArray<FGameplayAbilitySpecHandle>& InSpectHandles)
{
	GrantedAbilitySpecHandles = InSpectHandles;
}

TArray<FGameplayAbilitySpecHandle> AKnightHeroWeapon::GetGrantedAbilitySpecHandles() const
{
	return GrantedAbilitySpecHandles;
}
