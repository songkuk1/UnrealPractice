// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NativeGameplayTags.h"


namespace KnightGameplayTags
{
	/** Input Tags **/
	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_EquipAxe);
	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_UnequipAxe);

	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack_Axe);
	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_HeavyAttack_Axe);

	/** Player tags **/
	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Equip_Axe);
	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Unequip_Axe);

	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light_Axe);
	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Heavy_Axe);

	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Weapon_Axe);

	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Equip_Axe);
	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_Unequip_Axe);

	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_JumpToFinisher);

	/** Enemy tags **/
	KNIGHT_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Enemy_Weapon);

}