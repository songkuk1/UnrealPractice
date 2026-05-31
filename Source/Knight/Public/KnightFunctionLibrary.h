// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KnightFunctionLibrary.generated.h"

class UKnightAbilitySystemComponent;

UENUM()
enum class EKnightConfirmType : uint8
{
	Yes,
	No

};

/**
 * 
 */
UCLASS()
class KNIGHT_API UKnightFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static UKnightAbilitySystemComponent* NativeGetKnightASCFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "Knight|FunctionLibrary")
	static void AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd);
	
	UFUNCTION(BlueprintCallable, Category = "Knight|FunctionLibrary")
	static void RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove);

	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);


	UFUNCTION(BlueprintCallable, Category = "Knight|FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EKnightConfirmType& OutConfirmType);

};
