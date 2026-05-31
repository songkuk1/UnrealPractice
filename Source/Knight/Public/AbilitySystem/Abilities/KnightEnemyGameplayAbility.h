// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/KnightGameplayAbility.h"
#include "KnightEnemyGameplayAbility.generated.h"

class AKnightEnemyCharacter;
class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class KNIGHT_API UKnightEnemyGameplayAbility : public UKnightGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Knight|Ability")
	AKnightEnemyCharacter* GetKnightEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Knight|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();
	
private:
	TWeakObjectPtr<AKnightEnemyCharacter> CachedKnightEnemyCharacter;
};
