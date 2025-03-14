#pragma once

class Vector2D
{
public:
	Vector2D();
	Vector2D( const float posx, const float posy );
	float GetDistance( const Vector2D& other ) const;
	void Move( const Vector2D& pos ); //move amount with relative position
	void MoveAbsolute( const Vector2D& pos ); //set position
	void MoveAbsolute( const float posx, const float posy );
	float GetX() const;
	float GetY() const;
	Vector2D operator+( const Vector2D& other ) const;
	Vector2D operator-( const Vector2D& other ) const;
	Vector2D operator*( const float amt ) const;
	Vector2D operator/( const float amt ) const;
private:
	float x = 0.0f;
	float y = 0.0f;
};

