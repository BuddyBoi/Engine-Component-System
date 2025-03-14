#include "Engine.h"
#include <Windows.h>

CEngine::CEngine()
{

}

CGameObjectManager GameObjectManager;

//setup objects, gameObjects list, localplayer, components, etc.
void CEngine::Setup()
{
    GameObjectManager = CGameObjectManager( 1 );

    //create player
    GameObjectManager.CreateGameObject( "player", EObjectType::ObjType_Pawn );

    //create enemy npcs
    GameObjectManager.CreateGameObject( "enemy_1", EObjectType::ObjType_Character );
    GameObjectManager.CreateGameObject( "enemy_2", EObjectType::ObjType_Character );
    GameObjectManager.CreateGameObject( "enemy_3", EObjectType::ObjType_Character );
}

void CEngine::Run()
{
    this->Setup();    

    //Game loop example
    while ( true )
    {
        Sleep( 1000 );
        printf( "Running\n" );

        for ( auto& entity : GameObjectManager.GetGameObjects() )
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
        auto player = GameObjectManager.GetGameObject( "player" );
        player->GetComponent<CComponentHealth>()->Hurt( 10.0f );
    }
}