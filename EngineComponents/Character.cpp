#include "Character.h"

CCharacter::CCharacter( const TEntityDefinition& characterData, const std::string& nameDisplay )
	: CEntity( characterData.name, nameDisplay, EEntityType::EntType_Character )
{
}
