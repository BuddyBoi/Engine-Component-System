#pragma once
#include "Objects.h"

#include <vector>
#include <memory>
#include <string>

class CGameObject
{
public:
	CGameObject();
	CGameObject( int id );
	void Run();
	int GetInstance() const;
	std::string GetTag() const;

	bool AddComponent( std::shared_ptr<CComponent> component ); //add existing component object
	bool RemoveComponent( const int id ); //remove component by index
	bool RemoveComponent( const EComponentType type ); //remove component by type
	bool RemoveComponent( const std::string tag ); //remove component by tag; NOTE: unused while one comp per type
	std::shared_ptr<CComponent> GetComponentPtr( const int id ); //get component by index
	std::shared_ptr<CComponent> GetComponentPtr( const EComponentType type ); //get component by type
	std::shared_ptr<CComponent> GetComponentPtr( const std::string tag ); //get component by tag; NOTE: unused while one comp per type
	void RunComponents(); //runs all components

	//templates - must be defined in header
	template <typename T> std::shared_ptr<T> GetComponent()
	{
		if ( !this->components.size() )
			return nullptr;

		for ( const auto& component : this->components )
		{
			//try to cast over to templated type, will automatically compare sizes
			if ( auto testCastType = std::dynamic_pointer_cast<T>(component) )
				return testCastType;
		}
		return nullptr;
	}

	template <typename T> std::shared_ptr<T> GetComponent( int id )
	{
		std::shared_ptr<CComponent> compbase = GetComponentPtr( id );
		if ( compbase == nullptr )
			return nullptr;

		return std::dynamic_pointer_cast<T>(compbase);
	}

	template <typename T> std::shared_ptr<T> GetComponent( EComponentType type )
	{
		std::shared_ptr<CComponent> compbase = this->GetComponentPtr( type );
		if ( compbase == nullptr )
			return nullptr;

		return std::dynamic_pointer_cast<T>(compbase);
	}

	template <typename T> std::shared_ptr<T> GetComponent( std::string tag )
	{
		std::shared_ptr<CComponent> compbase = GetComponentPtr( tag );
		if ( compbase == nullptr )
			return nullptr;

		return std::dynamic_pointer_cast<T>(compbase);
	}
private:
	int instance = 0;
	std::string tag = "none";
	std::vector<std::shared_ptr<CComponent>> components;
};