// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/KnightGameplayAbility.h"
#include "KnightHeroGameplayAbility.generated.h"

class AKnightHeroCharacter;
class AKnightHeroController;
/**
 * 
 */
UCLASS()
class KNIGHT_API UKnightHeroGameplayAbility : public UKnightGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Knight|Ability")
	AKnightHeroCharacter* GetKnightHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Knight|Ability")
	AKnightHeroController* GetKnightHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Knight|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<AKnightHeroCharacter> CachedKnightHeroCharacter;
	TWeakObjectPtr<AKnightHeroController> CachedKnightHeroController;

};
