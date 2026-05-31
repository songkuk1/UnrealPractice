// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/KnightBaseCharacter.h"
#include "KnightEnemyCharacter.generated.h"

class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class KNIGHT_API AKnightEnemyCharacter : public AKnightBaseCharacter
{
	GENERATED_BODY()

public :
	AKnightEnemyCharacter();

protected:
	virtual void PossessedBy(AController* NewController) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UEnemyCombatComponent* EnemyCombatComponent;

public:
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }

private:
	void InitEnemyStartUpData();
};
