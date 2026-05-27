// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class KNIGHT_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	template <class T>
	T* GetOwingPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T,APawn>::Value,"'T' Template Parameter to GetPawn must be derived from APawn");
		return CastChecked<T>(GetOwner());


	}

	APawn* GetOwingPawn() const
	{
		return GetOwingPawn<APawn>();

	}

	template<class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' Template Parameter to GetController must be derived from AController");
		return GetOwingPawn<APawn>()->GetController<T>();
	}
		
};
