#include "EntityManager.h"
#include "Components.h"

CEntityManager::CEntityManager()
{

}

std::vector<std::shared_ptr<CEntity>> CEntityManager::GetEntityList()
{
	std::vector<std::shared_ptr<CEntity>> ret{};
	if ( !this->entityList.size() )
		return ret;

	return this->entityList;
}

void CEntityManager::CreateCharacter( const std::string& defName, const Vector2D& pos, std::string displayName )
{
	if ( displayName == "none" )
		displayName = defName;

	TEntityDefinition characterData = this->entityDefinitions[defName];
	std::shared_ptr<CCharacter> character = std::make_shared<CCharacter>( characterData, displayName );
	
	std::shared_ptr<CComponentHealth> characterHealth = std::make_shared<CComponentHealth>( character, 100.0f );
	std::shared_ptr<CComponentPosition> characterPosition = std::make_shared<CComponentPosition>( character, pos );

	character->AddComponent( characterPosition );
	character->AddComponent( characterHealth );

	this->entityListQueuedAdditions.push_back( character );
}

void CEntityManager::CreateItem( const std::string& defName, const Vector2D& pos, std::string displayName )
{
	if ( displayName == "none" )
		displayName = defName;

	TEntityDefinition itemData = this->entityDefinitions[defName];
	std::shared_ptr<CItem> item = std::make_shared<CItem>( itemData, displayName );

	std::shared_ptr<CComponentPosition> itemPosition = std::make_shared<CComponentPosition>( item, pos );
	item->AddComponent( itemPosition );

	this->entityListQueuedAdditions.push_back( item );
}

void CEntityManager::InitDefinitions()
{
	//TODO: load these from a game data file

	//player
	{
		TEntityDefinition player{};
		player.name = "player";
		player.displayName = "player"; //TODO: change this if you want the user to customize their name
		entityDefinitions[player.name] = player;
		player.type = EEntityType::EntType_Character;
	}

	//enemy
	{
		TEntityDefinition entity{};
		entity.name = "enemyBandit";
		entity.displayName = "Bandit";
		entityDefinitions[entity.name] = entity;
		entity.type = EEntityType::EntType_Character;
	}

	//enemy boss
	{
		TEntityDefinition entity{};
		entity.name = "enemyBanditBoss";
		entity.displayName = "Bandit Chief";
		entityDefinitions[entity.name] = entity;
		entity.type = EEntityType::EntType_Character;
	}
	
	//iron sword
	{
		TEntityDefinition entity{};
		entity.name = "weaponIronSword";
		entity.displayName = "Iron Sword";
		entity.damage = 5.0f;
		entity.value = 25.0f;
		entity.isRanged = false;
		entity.range = 0.0f; //TODO: add melee range
		entity.type = EEntityType::EntType_Item;
		entityDefinitions[entity.name] = entity;
	}

	//steel sword
	{
		TEntityDefinition entity{};
		entity.name = "weaponSteelSword";
		entity.displayName = "Steel Sword";
		entity.damage = 7.0f;
		entity.value = 40.0f;
		entity.isRanged = false;
		entity.range = 0.0f; //TODO: add melee range
		entity.type = EEntityType::EntType_Item;
		entityDefinitions[entity.name] = entity;
	}

	//UNIQUE - King's Steel Sword
	{
		TEntityDefinition entity{};
		entity.name = "weaponSpecialKingsSword";
		entity.displayName = "Sword of the King";
		entity.damage = 18.0f;
		entity.value = 500.0f;
		entity.isRanged = false;
		entity.range = 0.0f; //TODO: add melee range
		entity.type = EEntityType::EntType_Item;
		entityDefinitions[entity.name] = entity;
	}
}

void CEntityManager::InitEntities()
{
	//TODO: load this from save

	//create player - temporarily use character for player
	this->CreateCharacter( "player", { 100.0f, 100.0f } );

	//enemyBandit, enemyBanditBoss

	//create enemies
	this->CreateCharacter( "enemyBandit", { 500.0f, 200.0f } );
	this->CreateCharacter( "enemyBandit", { 500.0f, 250.0f } );
	this->CreateCharacter( "enemyBandit", { 500.0f, 300.0f } );

	//create items
	this->CreateItem( "weaponIronSword", { 15.0f, 15.0f } );
	this->CreateItem( "weaponIronSword", { 20.0f, 15.0f } );
	this->CreateItem( "weaponIronSword", { 5.0f, 25.0f } );
	this->CreateItem( "weaponSpecialKingsSword", { 200.0f, 200.0f } );
}

void CEntityManager::QueueRemoveEntity( const int& id )
{
	if ( !id )
		return;

	//todo check this
	this->entityListQueuedRemovals.push_back( this->entityList[id] );
}

void CEntityManager::QueueRemoveEntity( const std::shared_ptr<CEntity>&object )
{
	if ( !object )
		return;

	this->entityListQueuedRemovals.push_back( object );
}

void CEntityManager::RemoveEntity( const int& id )
{
	if ( !id )
		return;

	this->RemoveEntity( this->entityList[id] );
}

void CEntityManager::RemoveEntity( const std::shared_ptr<CEntity>&object )
{
	if ( !object )
		return;

	// Use std::remove_if to find and move the shared_ptr to the end
	auto it = std::remove_if( entityList.begin(), entityList.end(),
		[&]( const std::shared_ptr<CEntity>& entityPtr )
	{
		return entityPtr == object;
	} );

	// Erase the elements from the new end of the range
	entityList.erase( it, entityList.end() );
}

void CEntityManager::QueueAddEntity( const std::shared_ptr<CEntity>& object )
{
	if ( !object )
		return;

	this->entityListQueuedAdditions.push_back( object );
}

void CEntityManager::AddEntity( const std::shared_ptr<CEntity>& object )
{
	if ( !object )
		return;

	this->entityList.push_back(object);
}

void CEntityManager::UpdateEntityList()
{
	//removals
	if ( this->entityListQueuedRemovals.size() )
	{
		printf( "Removals to delete: %i\n", (int)this->entityListQueuedRemovals.size() );
		for ( auto obj : this->entityListQueuedRemovals )
		{
			this->RemoveEntity( obj );
		}

		this->entityListQueuedRemovals.clear();
	}

	//additions
	if ( this->entityListQueuedAdditions.size() )
	{
		printf( "Additions to add: %i\n", (int)this->entityListQueuedAdditions.size() );
		for ( auto obj : this->entityListQueuedAdditions )
		{
			this->AddEntity( obj );
		}

		this->entityListQueuedAdditions.clear();
	}
}

std::shared_ptr<CEntity> CEntityManager::GetEntity( const std::string& name )
{
	if ( !name.size()
		|| !this->entityList.size() )
		return nullptr;

	for ( auto object : this->entityList )
	{
		if ( object->GetName() == name )
		{
			return object;
		}
	}

	return nullptr;
}