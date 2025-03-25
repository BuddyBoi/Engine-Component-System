#include "GameObject.h"

CGameObject::CGameObject( const EObjectType objType ) : type( objType )
{

}

void CGameObject::Run()
{
	return;
}

EObjectType CGameObject::GetType() const
{
	return this->type;
}

bool CGameObject::AddComponent( std::shared_ptr<CComponent> component )
{
	components.push_back( component );
	return true;
}

bool CGameObject::RemoveComponent( const EComponentType type )
{
	if ( !this->components.size() )
		return true;

	for ( auto it = components.begin(); it != components.end(); ++it )
	{
		if ( (*it)->GetType() == type )
		{
			components.erase( it );
			return true;
		}
	}

	return false;
}

bool CGameObject::RemoveComponent( const std::string name )
{
	if ( !this->components.size()
		|| !name.size() )
		return true;

	for ( auto it = components.begin(); it != components.end(); ++it )
	{
		if ( (*it)->GetName() == name )
		{
			components.erase( it );
			return true;
		}
	}

	return false;
}

std::shared_ptr<CComponent> CGameObject::GetComponentPtr( const EComponentType type )
{
	if ( !this->components.size()
		|| type == CompType_Invalid
		|| type == CompType_Max )
		return nullptr;

	for ( const auto& component : components )
	{
		if ( component->GetType() == type )
		{
			return component;
		}
	}

	return nullptr;
}

std::shared_ptr<CComponent> CGameObject::GetComponentPtr( const std::string name )
{
	if ( !this->components.size()
		|| !name.size() )
		return nullptr;

	for ( const auto& component : components )
	{
		if ( component->GetName() == name )
		{
			return component;
		}
	}

	return nullptr;
}

void CGameObject::RunComponents()
{
	if ( !this->components.size() )
		return;

	for ( auto& component : this->components )
	{
		component->Run();
	}
}