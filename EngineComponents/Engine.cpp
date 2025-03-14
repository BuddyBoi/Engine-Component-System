#include "Engine.h"
#include <Windows.h>

//temp global systems
CGameObjectManager GameObjectManager;

CEngine::CEngine()
{

}

//setup objects, gameObjects list, localplayer, components, etc.
void CEngine::Setup()
{
	GameObjectManager = CGameObjectManager( 1 );

	//create player
	GameObjectManager.CreateGameObject( "player", EObjectType::ObjType_Pawn, Vector2D( 10.0f, 10.0f ) );

	//create enemy npcs
	GameObjectManager.CreateGameObject( "enemy_1", EObjectType::ObjType_Character, Vector2D( 15.0f, 10.0f ) );
	GameObjectManager.CreateGameObject( "enemy_2", EObjectType::ObjType_Character, Vector2D( 25.0f, 10.0f ) );
	GameObjectManager.CreateGameObject( "enemy_3", EObjectType::ObjType_Character, Vector2D( 35.0f, 10.0f ) );

	//create creatures
	GameObjectManager.CreateGameObject( "wolf_1", EObjectType::ObjType_Creature, Vector2D( 10.0f, 10.0f ) );

	//create items
	GameObjectManager.CreateGameObject( "iron_sword_1", EObjectType::ObjType_Item, Vector2D( 10.0f, 15.0f ) );
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
			auto entityHealth = entity->GetComponent<CComponentHealth>();
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