#include "Container.h"

CContainer::CContainer( const std::string& name, const std::string& displayName )
	: CEntity( name, displayName, EEntityType::EntType_Container )
{
}
