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
	//if no custom display name, use def name
	if ( displayName == "none" )
		displayName = defName;

	TEntityDefinition characterData = this->entityDefinitions[defName];
	std::shared_ptr<CCharacter> character = std::make_shared<CCharacter>( characterData, displayName );
	
	//create and add components
	std::shared_ptr<CComponentHealth> characterHealth = std::make_shared<CComponentHealth>( character, 100.0f );
	Vector2D characterPosVec( 50.0f, 50.0f );
	std::shared_ptr<CComponentPosition> characterPosition = std::make_shared<CComponentPosition>( character, characterPosVec );

	character->AddComponent( characterPosition );
	character->AddComponent( characterHealth );

	//add to list
	this->entityList.push_back( character );
}

void CEntityManager::CreateItem( const std::string& defName, const Vector2D& pos, std::string displayName )
{
	//if no custom display name, use def name
	if ( displayName == "none" )
		displayName = defName;

	TEntityDefinition itemData = this->entityDefinitions[defName];
	std::shared_ptr<CItem> item = std::make_shared<CItem>( itemData, displayName );

	//add to list
	this->entityList.push_back( item );
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
		entity.type = EItemType::ItemType_Weapon;
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
		entity.type = EItemType::ItemType_Weapon;
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
		entity.type = EItemType::ItemType_Weapon;
		entityDefinitions[entity.name] = entity;
	}
}

void CEntityManager::InitEntities()
{
	//TODO: load this from save

	//create player - temporarily use character for player
	this->CreateCharacter( "player", { 100.0f, 100.0f } );

	//create items
	this->CreateItem( "weaponIronSword", { 15.0f, 15.0f } );
	this->CreateItem( "weaponIronSword", { 20.0f, 15.0f } );
	this->CreateItem( "weaponIronSword", { 5.0f, 25.0f } );
	this->CreateItem( "weaponSpecialKingsSword", { 200.0f, 200.0f } );
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