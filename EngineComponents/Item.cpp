#include "Item.h"
#include "Engine.h"

#include <memory>

CItem::CItem( const TEntityDefinition& itemData, const std::string& displayName )
	: CEntity( itemData.name, displayName, EEntityType::EntType_Item )
{
	//temp - load definition struct
	this->damage = itemData.range;
	this->range = itemData.range;
	this->isRanged = itemData.isRanged;
	this->value = itemData.value;
	this->type == itemData.type;
}

int CItem::GetValue() const
{
	return this->value;
}

int CItem::GetDamage() const
{
	return this->damage;
}

float CItem::GetRange() const
{
	return this->range;
}

bool CItem::GetIsStackable() const
{
	return this->isStackable;
}

bool CItem::GetIsRanged() const
{
	return this->isRanged;
}

std::string CItem::GetAmmoName() const
{
	return this->ammoTypeName;
}

