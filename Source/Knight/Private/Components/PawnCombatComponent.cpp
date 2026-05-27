// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/PawnCombatComponent.h"
#include "KnightDebugHelper.h"
#include "Items/Weapons/KnightWeaponBase.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AKnightWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	//이미 등록되어있으면 메세지 출력
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister),TEXT("A named %s has already benn added as carried weapon"),*InWeaponTagToRegister.ToString());
	check(InWeaponToRegister);

	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

	if(bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
	}

	
	const FString WeaponString = FString::Printf(TEXT("A Weapon named : %s has been registered using the tag %s"),*InWeaponToRegister->GetName(), *InWeaponTagToRegister.ToString());
	Debug::Print(WeaponString);

}

AKnightWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if(CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if(AKnightWeaponBase* const* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
			return *FoundWeapon;
	}


	return nullptr;
}

AKnightWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{

	if(CurrentEquippedWeaponTag.IsValid())
		return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
	else
		return nullptr;


}
