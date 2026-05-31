// Fill out your copyright notice in the Description page of Project Settings.


#include "KnightFunctionLibrary.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/KnightAbilitySystemComponent.h"

UKnightAbilitySystemComponent* UKnightFunctionLibrary::NativeGetKnightASCFromActor(AActor* InActor)
{
    check(InActor);

    return CastChecked<UKnightAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));

}

void UKnightFunctionLibrary::AddGameplayTagToActorIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
    UKnightAbilitySystemComponent* ASC = NativeGetKnightASCFromActor(InActor);

    if(!ASC->HasMatchingGameplayTag(TagToAdd))
    {
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UKnightFunctionLibrary::RemoveGameplayTagFromActorIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
    UKnightAbilitySystemComponent* ASC = NativeGetKnightASCFromActor(InActor);

    if (ASC->HasMatchingGameplayTag(TagToRemove))
    {
        ASC->RemoveLooseGameplayTag(TagToRemove);


    }

}

bool UKnightFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
    UKnightAbilitySystemComponent* ASC = NativeGetKnightASCFromActor(InActor);

    return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UKnightFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EKnightConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? EKnightConfirmType::Yes : EKnightConfirmType::No;
}
