#include "Vector2D.h"
#include <cmath>

Vector2D::Vector2D()
{

}

Vector2D::Vector2D( const float posx, const float posy )
	: x( posx ), y( posy )
{

}

float Vector2D::GetDistance( const Vector2D& other ) const
{
	float tempX = other.x - this->x;
	float tempY = other.y - this->y;
	return std::sqrt( tempX * tempX + tempY * tempY );
}

void Vector2D::Move( const Vector2D& pos )
{
	this->x += pos.x;
	this->y += pos.y;
}
void Vector2D::MoveAbsolute( const Vector2D& pos )
{
	this->x = pos.x;
	this->y = pos.y;
}
void Vector2D::MoveAbsolute( const float posx, const float posy )
{
	this->x = posx;
	this->y = posy;
}
float Vector2D::GetX() const
{
	return this->x;
}
float Vector2D::GetY() const
{
	return this->y;
}
Vector2D Vector2D::operator+( const Vector2D& other ) const
{

}
Vector2D Vector2D::operator-( const Vector2D& other ) const
{

}
Vector2D Vector2D::operator*( const float amt ) const
{

}
Vector2D Vector2D::operator/( const float amt ) const
{

}
