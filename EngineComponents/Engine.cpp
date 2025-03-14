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
		auto playerHealth = player->GetComponent<CComponentHealth>();
		auto playerPosition = player->GetComponent<CComponentPosition>();
		auto playerStats = player->GetComponent<CComponentStats>();

		if ( !playerHealth->GetIsAlive() )
			continue;

		auto itemSword = GameObjectManager.GetGameObject( "iron_sword_1" );
		if ( !itemSword )
			continue;

		auto itemSwordPosition = itemSword->GetComponent<CComponentPosition>();
		if ( !itemSwordPosition )
			continue;

		float dist = itemSwordPosition->GetPosition().GetDistance( playerPosition->GetPosition() );
		printf( "DISTANCE TO SWORD: %f\n", dist );

		//TEST
		//move player
		if ( GetAsyncKeyState( VK_RIGHT ) )
		{
			playerPosition->Move( 0.50f, 0.0f );
		}

		if ( GetAsyncKeyState( VK_DOWN ) )
		{
			playerPosition->Move( 0.0f, 0.50f );
		}
	}
}