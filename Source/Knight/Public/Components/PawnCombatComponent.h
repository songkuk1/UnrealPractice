// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

class AKnightWeaponBase;
/**
 * 
 */
UCLASS()
class KNIGHT_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()


private:
	TMap<FGameplayTag, AKnightWeaponBase*> CharacterCarriedWeaponMap;
public:
	//마지막 bool은 생성후 바로 장착할것인지
	UFUNCTION(BlueprintCallable, Category="Knight|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AKnightWeaponBase* InWeaponToRegister,bool bRegisterAsEquippedWeapon = false);

	UFUNCTION(BlueprintCallable, Category = "Knight|Combat")
	AKnightWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	UPROPERTY(BlueprintReadWrite, Category = "Knight|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(BlueprintCallable, Category = "Knight|Combat")
	AKnightWeaponBase* GetCharacterCurrentEquippedWeapon() const;

};
