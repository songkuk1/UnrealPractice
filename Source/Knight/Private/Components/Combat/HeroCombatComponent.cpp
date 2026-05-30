// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/HeroCombatComponent.h"
#include "Items/Weapons/KnightHeroWeapon.h"

AKnightHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AKnightHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));


}
