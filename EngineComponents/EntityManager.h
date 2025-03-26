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
	void InitEntities(); //create entities for entity list
	void QueueRemoveEntity( const int &id );
	void QueueRemoveEntity( const std::shared_ptr<CEntity>& object );
	void RemoveEntity( const int& id );
	void RemoveEntity( const std::shared_ptr<CEntity>& object );
	void QueueAddEntity( const std::shared_ptr<CEntity>& object );
	void AddEntity( const std::shared_ptr<CEntity>& object );
	void UpdateEntityList(); //todo: rename to UpdateQueue or UpdateEntityList or something
private:
	std::vector<std::shared_ptr<CEntity>> entityList{};
	std::map<std::string, TEntityDefinition> entityDefinitions;
	std::vector<std::shared_ptr<CEntity>> entityListQueuedRemovals;
	std::vector<std::shared_ptr<CEntity>> entityListQueuedAdditions;
};