#include "ComponentHealth.h"

CComponentHealth::CComponentHealth( std::shared_ptr<CGameObject> parent, float hp )
	: CComponent( "compHealth", parent, CompType_Health)
{
	this->healthMax = hp;
	this->health = hp;
}

void CComponentHealth::Run()
{
	printf( "Component HEALTH DbgPrint: Health: %f, HealthMax: %f\n", this->health, this->healthMax);
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
