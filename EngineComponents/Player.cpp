#include "Player.h"

CPlayer::CPlayer( const std::string& playerName )
	: CEntity( "player", playerName, EEntityType::EntType_Player)
{

}
