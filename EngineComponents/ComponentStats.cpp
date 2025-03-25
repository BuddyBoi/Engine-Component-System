#include "ComponentStats.h"

CComponentStats::CComponentStats( std::shared_ptr<CGameObject> parent )
	: CComponent( "compStats", parent, CompType_Stats)
{

}

void CComponentStats::Run()
{
	printf( "Component STATS DbgPrint: Level: %i, ExperienceCount: %i\n", this->GetExperienceLevel(), this->GetExperiencePoints() );
}

int CComponentStats::GetExperienceLevel() const
{
	return this->experienceLevel;
}
int CComponentStats::GetExperiencePoints() const
{
	return this->experiencePoints;
}
