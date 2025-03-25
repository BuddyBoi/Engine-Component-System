#pragma once
#include "Entities.h"
#include "Vector2D.h"

class CEntityManager
{
public:
	CEntityManager();
	std::vector<std::shared_ptr<CEntity>> GetEntityList(); //gets all entities
	std::shared_ptr<CEntity> GetEntity( const std::string& name ); //gets first entity by name; mainly used for unique entities
	void CreateCharacter( const std::string& defName, const Vector2D& pos, std::string displayName = "none" ); //create a character entity
	void CreateItem( const std::string& defName, const Vector2D& pos, std::string displayName = "none" );
	void InitDefinitions(); //create defs for defs list
	void InitEntities(); //create entities for entity liss
private:
	std::vector<std::shared_ptr<CEntity>> entityList{};
	std::map<std::string, TEntityDefinition> entityDefinitions;
};