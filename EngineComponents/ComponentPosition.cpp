#include "ComponentPosition.h"

CComponentPosition::CComponentPosition( int id, std::shared_ptr<CGameObject> parent, const Vector2D& pos )
	: CComponent( id, parent, CompType_Stats ), position( pos )
{

}

void CComponentPosition::Run()
{
	printf( "Component POSITION DbgPrint: X: %f, Y: %f\n", this->GetPosition().GetX(), this->GetPosition().GetY() );
}

Vector2D CComponentPosition::GetPosition() const
{
	return this->position;
}

void CComponentPosition::SetPosition( const Vector2D& pos )
{
	this->position.MoveAbsolute( pos );
}

void CComponentPosition::Move( const Vector2D& pos )
{
	this->position.Move( pos );
}

void CComponentPosition::Move( const float x, const float y )
{
	this->position.Move( Vector2D( x, y ) );
}