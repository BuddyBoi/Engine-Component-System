#include "Engine.h"
#include <Windows.h>

//temp global systems
CEngine::CEngine()
{

}

//setup objects, gameObjects list, localplayer, components, etc.
void CEngine::Setup()
{
	EntityManager = CEntityManager();
	EntityManager.InitDefinitions();
	EntityManager.InitEntities();
}

void CEngine::Run()
{
	this->Setup();

	//Game loop example
	while ( true )
	{
		Sleep( 1000 );
		printf( "Running\n" );

		for ( auto& entity : EntityManager.GetEntityList() )
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
		auto player = EntityManager.GetEntity( "player" );
		auto playerHealth = player->GetComponent<CComponentHealth>();
		auto playerPosition = player->GetComponent<CComponentPosition>();
		auto playerStats = player->GetComponent<CComponentStats>();

		if ( !playerHealth->GetIsAlive() )
			continue;

		auto itemSword = EntityManager.GetEntity( "weaponIronSword" );
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