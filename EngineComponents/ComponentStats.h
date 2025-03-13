#pragma once
#include "Objects.h"

class CComponentStats : public CComponent
{
public:
    CComponentStats( int id, std::shared_ptr<CGameObject> parent );
private:
    int experienceLevel = 1;
    int experiencePoints = 0;
};