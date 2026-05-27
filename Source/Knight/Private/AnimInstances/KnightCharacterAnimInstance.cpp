// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/KnightCharacterAnimInstance.h"
#include "Characters/KnightBaseCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


void UKnightCharacterAnimInstance::NativeInitializeAnimation()
{
	OwningCharacter = Cast<AKnightBaseCharacter>(TryGetPawnOwner());

	if(OwningCharacter)
	{
		OwningMovementComponent = OwningCharacter->GetCharacterMovement();
	}

}

void UKnightCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	if(!OwningCharacter || !OwningMovementComponent)
		return;

	GroundSpeed = OwningCharacter->GetVelocity().Size2D();

	bHasAcceleration = OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D() > 0.f;

}
