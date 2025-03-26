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

void testRunInput( const std::shared_ptr<CComponentPosition> &playerPosition )
{
	float moveAmount = 1.0f;
	float moveSpeed = 5.0f;
	float move = moveAmount * moveSpeed;

	if ( GetAsyncKeyState( VK_LEFT ) )
	{
		playerPosition->Move( -move, 0.0f );
	}

	if ( GetAsyncKeyState( VK_RIGHT ) )
	{
		playerPosition->Move( move, 0.0f );
	}	

	if ( GetAsyncKeyState( VK_UP ) )
	{
		playerPosition->Move( 0.0f, -move );
	}

	if ( GetAsyncKeyState( VK_DOWN ) )
	{
		playerPosition->Move( 0.0f, move );
	}
}

void CEngine::Run()
{
	this->Setup();

	//Game loop example
	while ( true )
	{
		Sleep( 1000 );
		printf( "Running\n" );

		//update entitylist additions + removals
		EntityManager.UpdateEntityList();

		for ( auto& entity : EntityManager.GetEntityList() )
		{
			if ( entity->GetType() == EEntityType::EntType_Character )
			{
				auto entityHealth = entity->GetComponent<CComponentHealth>();
				if ( !entityHealth )
					continue;

				if ( !entityHealth->GetIsAlive() )
				{
					EntityManager.QueueRemoveEntity( entity );
					continue;
				}
			}

			printf( "IN ENTITY: %s\n", entity->GetName().c_str() );
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

		//gets first defined "weaponIronSword", usually first one created
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
		testRunInput( playerPosition );			

		//hurt enemy, test deleting unalive entity on death
		if ( GetAsyncKeyState( VK_DELETE ) )
		{
			printf( "REMOVING ENEMY" );
			Sleep( 100 );
			auto enemy = EntityManager.GetEntity( "enemyBanditBoss" );
			if ( !enemy )
			{
				printf( "FAILED TO GET ENEMY\n" );
				continue;				
			}

			auto enemyHealth = enemy->GetComponent<CComponentHealth>();
			if ( !enemyHealth )
			{
				printf( "CAN'T GET HEALTH!!\n" );
				Sleep( 100 );
				continue;
			}
			enemyHealth->Hurt( 50.0f );
			printf( "REMOVED HEALTH!!\n" );
			continue;
		}

		//test create enemy
		if ( GetAsyncKeyState( VK_INSERT ) )
		{
			printf( "ADDING ENEMY\n" );
			Sleep( 100 );
			EntityManager.CreateCharacter( "enemyBanditBoss", { 1000.0f, 1000.0f } );
		}
	}
}