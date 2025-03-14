#include "GameObjectManager.h"
#include "Components.h"

CGameObjectManager::CGameObjectManager()
{

}

CGameObjectManager::CGameObjectManager( const int id )
{
	this->instance = id;
}

int CGameObjectManager::GetInstance() const
{
	return this->instance;
}

std::vector<std::shared_ptr<CGameObject>> CGameObjectManager::GetGameObjects()
{
    std::vector<std::shared_ptr<CGameObject>> ret{};
    if ( !this->objects.size() )
        return ret;

    return this->objects;
}

std::shared_ptr<CGameObject> CGameObjectManager::GetGameObject( const int id )
{
    if ( !id
        || !this->objects.size() )
        return nullptr;

    for ( auto object : this->objects )
    {
        if ( object->GetInstance() == id )
        {
            return object;
        }
    }

    return nullptr;
}

std::shared_ptr<CGameObject> CGameObjectManager::GetGameObject( const std::string& tag )
{
    if ( !tag.size()
        || !this->objects.size() )
        return nullptr;

    for ( auto object : this->objects )
    {
        if ( object->GetTag() == tag )
        {
            return object;
        }
    }

    return nullptr;
}

void CGameObjectManager::CreateGameObject( const std::string& name, const EObjectType type )
{
    if ( !type )
        return;

    int index = this->objects.size() + 1;
    auto object = std::make_shared<CGameObject>( index, type, name );

    //Pawn, create Player object
    if ( type == ObjType_Pawn )
    {
        if ( std::shared_ptr<CGameObject> ptr = this->GetGameObject( "player" ) )
        {
            printf( "PLAYER ALREADY EXISTS\n" );
            return;
        }

        auto objHealth = std::make_shared<CComponentHealth>( 10, object, 100.0f );
        auto objStats = std::make_shared<CComponentStats>( 20, object );

        object->AddComponent( objHealth );
        object->AddComponent( objStats );

        this->objects.push_back( object );
    }

    //Character, create npc
    else if ( type == ObjType_Character )
    {
        auto objHealth = std::make_shared<CComponentHealth>( 10, object, 50.0f );
        auto objStats = std::make_shared<CComponentStats>( 20, object );

        object->AddComponent( objHealth );
        object->AddComponent( objStats );

        this->objects.push_back( object );
    }
}