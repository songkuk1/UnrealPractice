// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "KnightGameplayAbility.generated.h"

class UPawnCombatComponent;
class UKnightAbilitySystemComponent;

UENUM(BlueprintType)
enum class EKnightAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

/**
 * 
 */
UCLASS()
class KNIGHT_API UKnightGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
protected:
	//~ Begin UGameplayAbility Interface.
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface.
	UPROPERTY(EditDefaultsOnly, Category = "KnightAbility")
	EKnightAbilityActivationPolicy AbilityActivationPolicy = EKnightAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Knight|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Knight|Ability")
	UKnightAbilitySystemComponent* GetKnightAbilitySystemComponentFromActorInfo() const;
};
