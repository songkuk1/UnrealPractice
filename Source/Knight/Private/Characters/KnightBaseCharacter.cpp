// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/KnightBaseCharacter.h"
#include "AbilitySystem/KnightAbilitySystemComponent.h"
#include "AbilitySystem/KnightAttributeSet.h"


// Sets default values
AKnightBaseCharacter::AKnightBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	KnightAbilitySystemComponent = CreateDefaultSubobject<UKnightAbilitySystemComponent>(TEXT("KnightAbilitySystemComponent"));
	KnightAttributeSet = CreateDefaultSubobject<UKnightAttributeSet>(TEXT("KnightAttributeSet"));
}

UAbilitySystemComponent* AKnightBaseCharacter::GetAbilitySystemComponent() const
{
	return KnightAbilitySystemComponent;
}

void AKnightBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if(KnightAbilitySystemComponent)
	{
		//게임에따라 두개가 같지 않을수있음
		KnightAbilitySystemComponent->InitAbilityActorInfo(this,this);

		ensureMsgf(!CharacterStartUpData.IsNull(),TEXT("Forgot to assign start up data to %s"),*GetName());

	}

}


