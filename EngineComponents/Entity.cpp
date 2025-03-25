#include "Entity.h"

CEntity::CEntity( const std::string& name, const std::string displayName, EEntityType entityType )
	: CGameObject( EObjectType::ObjType_Entity ), name( name ), nameDisplay( displayName ), type( entityType )
{

}

std::string CEntity::GetName() const
{
	return this->name;
}

std::string CEntity::GetDisplayName() const
{
	return this->nameDisplay;
}

EEntityType CEntity::GetType() const
{
	return this->type;
}
