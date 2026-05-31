// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/KnightEnemyCharacter.h"
#include "DataAssets/StartUpData/DataAsset_EnemyStartUpData.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/AssetManager.h"
#include "Components/EnemyCombatComponent.h"

#include "KnightDebugHelper.h"

AKnightEnemyCharacter::AKnightEnemyCharacter()
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//회전 속도
	GetCharacterMovement()->RotationRate = FRotator(0.f, 180.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 300.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

	EnemyCombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>(TEXT("EnemyCombatComponent"));
}

void AKnightEnemyCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitEnemyStartUpData();

}

void AKnightEnemyCharacter::InitEnemyStartUpData()
{
	if (CharacterStartUpData.IsNull())
		return;

	UAssetManager::GetStreamableManager().RequestAsyncLoad(
		CharacterStartUpData.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[this]()
			{
				if(UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.Get())
				{
					LoadedData->GiveToAbilitySystemComponent(KnightAbilitySystemComponent);

					Debug::Print(TEXT("Enemy StartUpData Loaded"), FColor::Green);
				}

			}));


}
