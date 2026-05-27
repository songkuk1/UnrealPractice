// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/KnightHeroAnimInstance.h"
#include "Characters/KnightHeroCharacter.h"



 void UKnightHeroAnimInstance::NativeInitializeAnimation()
 {
	 Super::NativeInitializeAnimation();

	 if(OwningCharacter)
	 {
		 OwningHeroCharacter = Cast<AKnightHeroCharacter>(OwningCharacter);



	 }
 }

 void UKnightHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
 {
	 Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	 if(bHasAcceleration)
	 {
		 IdleElpsedTime = 0.f;
		 bShouldEnterRelaxState = false;

	 }
	 else
	 {
		 IdleElpsedTime += DeltaSeconds;

		 bShouldEnterRelaxState = (IdleElpsedTime >= EnterRelaxStateThreshHold);
	 }
 }
