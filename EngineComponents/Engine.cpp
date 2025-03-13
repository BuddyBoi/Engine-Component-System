#include "Engine.h"
#include <Windows.h>

//temp global storage - TODO: add CObjectManager
std::vector<std::shared_ptr<CGameObject>> gameObjects{};
std::shared_ptr<CGameObject> player = nullptr;

CEngine::CEngine()
{

}

//get objects; 
//TODO: support multiple objects of the same name i.e. enemy, enemy, enemy without naming them enemy1, enemy2, etc.
std::shared_ptr<CGameObject> GetGameObject( const std::string& tag )
{
    if ( !tag.size() )
        return nullptr;

    for ( auto object : gameObjects )
    {
        if ( object->GetTag() == tag )
        {
            return object;
        }
    }

    return nullptr;
}

//create objects
void ObjectFactory( const std::string& name, const EObjectType type = ObjType_Invalid )
{
    if ( !type )
        return;

    int index = gameObjects.size() + 1;
    auto object = std::make_shared<CGameObject>( index, type, name );

    //Pawn, create Player object
    if ( type == ObjType_Pawn )
    {
        if ( std::shared_ptr<CGameObject> ptr = GetGameObject( "player" ) )
        {
            printf( "PLAYER ALREADY EXISTS\n" );
            return;
        }

        auto objHealth = std::make_shared<CComponentHealth>( 10, object, 100.0f );
        auto objStats = std::make_shared<CComponentStats>( 20, object );

        object->AddComponent( objHealth );
        object->AddComponent( objStats );

        gameObjects.push_back( object );
    }

    //Character, create npc
    else if ( type == ObjType_Character )
    {
        auto objHealth = std::make_shared<CComponentHealth>( 10, object, 50.0f );
        auto objStats = std::make_shared<CComponentStats>( 20, object );

        object->AddComponent( objHealth );
        object->AddComponent( objStats );

        gameObjects.push_back( object );
    }
}

//setup objects, gameObjects list, localplayer, components, etc.
void CEngine::Setup()
{
    //Player
    ObjectFactory( "player", EObjectType::ObjType_Pawn );

    //Set player ptr
    player = GetGameObject( "player" );
    if ( player == nullptr )
    {
        printf( "SETUP : Failed to find player\n" );
        return;
    }

    //Create enemies and other NPCs
    ObjectFactory( "enemy_1", EObjectType::ObjType_Character );
    ObjectFactory( "enemy_2", EObjectType::ObjType_Character );
    ObjectFactory( "enemy_3", EObjectType::ObjType_Character );
}

void CEngine::Run()
{
    this->Setup();    

    //Game loop example
    while ( true )
    {
        Sleep( 1000 );
        printf( "Running\n" );

        for ( auto& entity : gameObjects )
        {
            auto entityHealth = entity->GetComponent<CComponentHealth>( );
            if ( entityHealth )
            {
                if ( !entityHealth->GetIsAlive() )
                    continue;
            }

            entity->Run();
            entity->RunComponents();
        }

        //tick update test
        player->GetComponent<CComponentHealth>()->Hurt( 10.0f );
    }
}