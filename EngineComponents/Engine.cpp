#include "Engine.h"

//temp global storage - TODO: add CObjectManager
std::vector<std::shared_ptr<CGameObject>> gameObjects{};
std::shared_ptr<CGameObject> player = nullptr;

CEngine::CEngine()
{

}

//get objects; 
//TODO: support multiple objects of the same name i.e. enemy, enemy, enemy without naming them enemy1, enemy2, etc.
std::shared_ptr<CGameObject> GetGameObject( std::string tag )
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
void ObjectFactory( const std::string& name, const EObjectType type = ObjType_Invalid)
{
    if ( !type )
        //assert "invalid object type" ?
        return;

    int index = gameObjects.size() + 1;
    auto object = std::make_shared<CGameObject>( index );

    //Character, needs health component
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
}

//setup objects, gameObjects list, localplayer, components, etc.
void CEngine::Setup()
{
    //gameObjects and entities
    player = std::make_shared<CGameObject>( 1 );
}

void CEngine::Run()
{
    this->Setup();

    //ObjectList / EntityList
    std::vector<std::shared_ptr<CGameObject>> EntityList;

    //Create Entities
    auto Player = std::make_shared<CGameObject>( 1 );
    auto EnemyOne = std::make_shared<CGameObject>( 2 );

    //Create Components
    auto PlayerHealth = std::make_shared<CComponentHealth>( 1, Player, 100.0f );
    auto EnemyHealth = std::make_shared<CComponentHealth>( 1, EnemyOne, 50.0f );

    //Add components to objects
    Player->AddComponent( PlayerHealth );
    EnemyOne->AddComponent( EnemyHealth );

    //Add objects to EntityList
    EntityList.push_back( Player );
    EntityList.push_back( EnemyOne );

    //Game loop example
    while ( true )
    {
        Sleep( 1000 );
        printf( "Running\n" );

        for ( auto& entity : EntityList )
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

        auto currentPlayer = EntityList[0];
        auto playerHealthComp = currentPlayer->GetComponent<CComponentHealth>( );
        playerHealthComp->Hurt( 10.0f );
    }
}