// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/KnightBaseAnimInstance.h"
#include "KnightCharacterAnimInstance.generated.h"

class AKnightBaseCharacter;
class UCharacterMovementComponent;
/**
 * 
 */


UCLASS()
class KNIGHT_API UKnightCharacterAnimInstance : public UKnightBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);

protected:
	UPROPERTY()
	AKnightBaseCharacter* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly,Category="AnimData|Locomotion")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Locomotion")
	bool bHasAcceleration;


};
