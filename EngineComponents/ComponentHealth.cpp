#include "ComponentHealth.h"

CComponentHealth::CComponentHealth( int id, std::shared_ptr<CGameObject> parent, float hp )
	: CComponent( id, parent, CompType_Health )
{
	this->healthMax = hp;
	this->health = hp;
}

void CComponentHealth::Run()
{
	printf( "Component HEALTH DbgPrint: Parent: %i, Name: %s, Health: %f, HealthMax: %f\n", this->GetGameObject()->GetInstance(), this->GetGameObject()->GetTag().c_str(), this->health, this->healthMax);
}

float CComponentHealth::GetHealth() const
{
	return this->health;
}

float CComponentHealth::GetHealthMax() const
{
	return this->healthMax;
}

void CComponentHealth::Hurt( const float& amt )
{
	this->health -= amt;

	if ( this->health < 0.0f )
		this->health = 0.0f;
}

void CComponentHealth::Heal( const float& amt )
{
	this->health += amt;

	if ( this->health > this->healthMax )
		this->health = this->healthMax;
}

bool CComponentHealth::GetIsAlive() const
{
	return (this->health != 0.0f);
}
