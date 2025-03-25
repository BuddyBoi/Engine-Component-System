#pragma once
#include "Objects.h"

class CGameObject
{
public:
	CGameObject( const EObjectType objType );
	void Run();
	EObjectType GetType() const;
	bool AddComponent( std::shared_ptr<CComponent> component ); //add existing component object
	bool RemoveComponent( const EComponentType type ); //remove component by type
	bool RemoveComponent( const std::string name ); //remove component by name; NOTE: unused while one comp per type
	std::shared_ptr<CComponent> GetComponentPtr( const EComponentType type ); //get component by type
	std::shared_ptr<CComponent> GetComponentPtr( const std::string name ); //get component by name; NOTE: unused while one comp per type
	void RunComponents(); //runs all components

	//templates - must be defined in header
	template <typename T> std::shared_ptr<T> GetComponent()
	{
		if ( !this->components.size() )
			return nullptr;

		for ( const auto& component : this->components )
		{
			//try to cast over to templated type, will automatically compare datatypes
			if ( auto testCastType = std::dynamic_pointer_cast<T>(component) )
				return testCastType;
		}
		return nullptr;
	}

	template <typename T> std::shared_ptr<T> GetComponent( EComponentType type )
	{
		std::shared_ptr<CComponent> compbase = this->GetComponentPtr( type );
		if ( compbase == nullptr )
			return nullptr;

		return std::dynamic_pointer_cast<T>(compbase);
	}

	template <typename T> std::shared_ptr<T> GetComponent( std::string name )
	{
		std::shared_ptr<CComponent> compbase = GetComponentPtr( name );
		if ( compbase == nullptr )
			return nullptr;

		return std::dynamic_pointer_cast<T>(compbase);
	}
private:
	EObjectType type = EObjectType::ObjType_Invalid;
	std::vector<std::shared_ptr<CComponent>> components;
};