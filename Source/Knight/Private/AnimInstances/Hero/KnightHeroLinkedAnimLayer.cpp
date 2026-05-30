// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstances/Hero/KnightHeroLinkedAnimLayer.h"
#include "AnimInstances/KnightHeroAnimInstance.h"


UKnightHeroAnimInstance* UKnightHeroLinkedAnimLayer::GetHeroAnimInstance() const
{
    return Cast<UKnightHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());

}
