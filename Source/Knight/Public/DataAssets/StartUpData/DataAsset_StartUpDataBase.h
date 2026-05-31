// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UKnightGameplayAbility;
class UKnightAbilitySystemComponent;
class UGameplayEffect;
/**
 * 
 */
UCLASS()
class KNIGHT_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	//ApplyLevel : difficulty of game
	//인자로 넣어준 어빌리티 시스템 컴포넌트에 기본 게임 플레이 어빌리티 부여
	virtual void GiveToAbilitySystemComponent(UKnightAbilitySystemComponent* InASCToGive,int32 ApplyLevel = 1);


protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UKnightGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf< UKnightGameplayAbility>> ReactiveAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf< UGameplayEffect>> StartUpGameplayEffects;

	void GrantAbilities(const TArray<TSubclassOf< UKnightGameplayAbility>>& InAbilityesToGive, UKnightAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);

};
