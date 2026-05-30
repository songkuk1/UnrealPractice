// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/KnightBaseAnimInstance.h"
#include "KnightHeroLinkedAnimLayer.generated.h"


class UKnightHeroAnimInstance;
/**
 * 
 */
UCLASS()
class KNIGHT_API UKnightHeroLinkedAnimLayer : public UKnightBaseAnimInstance
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, meta =(BlueprintThreadSafe))
	UKnightHeroAnimInstance* GetHeroAnimInstance() const;



	
};
