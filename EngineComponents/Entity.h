#pragma once
#include <string>
#include "GameObject.h"
#include "Entity.h"
#include "Vector2D.h"
#include "Structs.h"

//base class for all world entities; Only used for instances
class CEntity : public CGameObject
{
public:
	CEntity( const std::string& name = "none", const std::string displayName = "none", EEntityType entityType = EEntityType::EntType_Invalid);
	std::string GetName() const;
	std::string GetDisplayName() const;
	EEntityType GetType() const;
private:
	std::string name = "none"; //name of definition ex: "weaponIronSword"
	std::string nameDisplay = "none"; //name to display in UI ex: "Iron Sword"
	EEntityType type = EntType_Invalid;
};