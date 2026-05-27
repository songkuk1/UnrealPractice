// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "KnightBaseCharacter.generated.h"


class UKnightAbilitySystemComponent;
class UKnightAttributeSet;
class UDataAsset_StartUpDataBase;
UCLASS()
class KNIGHT_API AKnightBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AKnightBaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	//~ End IAbilitySystemInterface Interface.

protected:
	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UKnightAbilitySystemComponent* KnightAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UKnightAttributeSet* KnightAttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

public:
	FORCEINLINE UKnightAbilitySystemComponent* GetKnightAbilitySystemComponent() const {return KnightAbilitySystemComponent;};
	FORCEINLINE UKnightAttributeSet* GetUKnightAttributeSet() const { return KnightAttributeSet; };


};
