// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/KnightCharacterAnimInstance.h"
#include "KnightHeroAnimInstance.generated.h"

class AKnightHeroCharacter;
/**
 * 
 */
UCLASS()
class KNIGHT_API UKnightHeroAnimInstance : public UKnightCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	AKnightHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	float EnterRelaxStateThreshHold = 5.f;

	float IdleElpsedTime;

};
