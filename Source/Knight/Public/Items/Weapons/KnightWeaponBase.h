// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KnightWeaponBase.generated.h"

class UBoxComponent;

UCLASS()
class KNIGHT_API AKnightWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKnightWeaponBase();
protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Weapons")
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapons")
	UBoxComponent* WeaponCollisionBox;

public :
	FORCEINLINE UBoxComponent* GetWeaponCollisonBox() const { return WeaponCollisionBox; };
};
