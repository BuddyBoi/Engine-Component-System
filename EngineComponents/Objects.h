#pragma once

#include <vector>
#include <memory>
#include <string>

enum EObjectType
{
	ObjType_Invalid,
	ObjType_Pawn, //controllable actor; Player character, player creature, controlable object, etc.
	ObjType_Character, //humnoid actor
	ObjType_Creature, //non-humanoid character actor
	ObjType_Item, //inventory item, pickup item, static non-lootable world item(?)
	ObjType_Container, //inventory container; i.e. chest, storage, locker, backpack, fridge, etc.
	ObjType_Static, //static object for level decor and/or interactions
	ObjType_Misc, //other, undetermined components
	ObjType_Max,
};

enum EComponentType
{
	CompType_Invalid,
	CompType_Health, //health, damage, heal controller
	CompType_Position, //2d or 3d position in scene / level
	CompType_Inventory, //inventory items container
	CompType_Profile, //username, achivements, personalizations
	CompType_Stats, //skills, abilites, stat points
	CompType_Max,
};

class CGameObjectManager;
class CGameObject;
class CComponent;

#include "GameObject.h"
#include "Component.h"
#include "GameObjectManager.h"