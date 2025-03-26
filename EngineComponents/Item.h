#pragma once
#include "Entities.h"

class CItem : public CEntity
{
public:
	CItem( const TEntityDefinition& itemData, const std::string& displayName );
	int GetValue() const;
	int GetDamage() const;
	float GetRange() const;
	bool GetIsStackable() const;
	bool GetIsRanged() const;
	std::string GetAmmoName() const;
private:
	EItemType type = ItemType_Invalid;

	//TEMP
	//change with muteable structs depending on item type
	float value = 0.0f;
	float damage = 0.0f;
	float range = 0.0f;
	bool isStackable = false;
	bool isRanged = false;
	std::string ammoTypeName = "none"; //item id of ammo type
};