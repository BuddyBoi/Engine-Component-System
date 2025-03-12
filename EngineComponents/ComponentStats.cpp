#include "ComponentStats.h"

CComponentStats::CComponentStats( int id, std::shared_ptr<CGameObject> parent )
    : CComponent( id, parent, CompType_Stats )
{

}