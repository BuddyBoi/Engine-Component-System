#pragma once
#include "Components.h"

class CComponentStats : public CComponent
{
public:
    CComponentStats( std::shared_ptr<CGameObject> parent );
    void Run() override;
    int GetExperienceLevel() const;
    int GetExperiencePoints() const;
private:
    int experienceLevel = 1;
    int experiencePoints = 0;
};