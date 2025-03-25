#pragma once

enum EObjectType
{
	ObjType_Invalid,
	ObjType_Entity,
	ObjType_World,
	ObjType_Level,
	ObjType_Tile,
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

enum EEntityType
{
	EntType_Invalid,
	EntType_Player, //Player character
	EntType_Character, //NPCs
	EntType_Creature, //non-humanoid character
	EntType_Item,
	EntType_Container,
	EntType_Projectile,
	EntType_Static,
	EntType_TriggerZone,
	EntType_Max,
};

enum EItemType
{
	ItemType_Invalid,
	ItemType_Weapon,
	ItemType_Apparel,
	ItemType_Food,
	ItemType_Potion,
	ItemType_Ammo,
	ItemType_Misc,
	ItemType_QuestItem,
	ItemType_Max,
};

/// Entity Definition Structs

struct TEntityDefinition
{
	std::string name = "none";
	std::string displayName = "none";
	bool isRanged = false;
	float value = 0.0f;
	float range = 0.0f;
	float damage = 0.0f;
	EItemType type = EItemType::ItemType_Invalid;
};

struct TItemDefinition
{
};

struct TCharacterDefinition
{
};

struct TProjectileDefinition
{
};