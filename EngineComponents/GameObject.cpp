#include "GameObject.h"

CGameObject::CGameObject()
{}

CGameObject::CGameObject( const int id ) : instance( id )
{}

void CGameObject::Run()
{
	printf( "RUNNING OBJECT ID: %i\n", this->instance );
	return;
}

int CGameObject::GetInstance() const
{
	return this->instance;
}

std::string CGameObject::GetTag() const
{
	return this->tag;
}

bool CGameObject::AddComponent( std::shared_ptr<CComponent> component )
{
	components.push_back( component );
	return true;
}

bool CGameObject::RemoveComponent( const int id )
{
	if ( !this->components.size() )
		return true;

	for ( auto it = components.begin(); it != components.end(); ++it )
	{
		if ( (*it)->GetInstance() == id )
		{
			components.erase( it );
			return true;
		}
	}

	return false;
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

bool CGameObject::RemoveComponent( const std::string tag )
{
	if ( !this->components.size()
		|| !tag.size() )
		return true;

	for ( auto it = components.begin(); it != components.end(); ++it )
	{
		if ( (*it)->GetTag() == tag )
		{
			components.erase( it );
			return true;
		}
	}

	return false;
}

std::shared_ptr<CComponent> CGameObject::GetComponentPtr( const int id )
{
	if ( !this->components.size()
		|| !id )
		return nullptr;

	for ( const auto& component : components )
	{
		if ( component->GetInstance() == id )
		{
			return component;
		}
	}

	return nullptr;
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

std::shared_ptr<CComponent> CGameObject::GetComponentPtr( const std::string tag )
{
	if ( !this->components.size()
		|| !tag.size() )
		return nullptr;

	for ( const auto& component : components )
	{
		if ( component->GetTag() == tag )
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