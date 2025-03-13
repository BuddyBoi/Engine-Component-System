#include "Engine.h"
#include <Windows.h>

struct Vec2
{
	Vec2( float inx, float iny )
	{
		x = inx;
		y = iny;
	}
	float x;
	float y;
};

void MathExample()
{
	Vec2 pointOne( 2.5f, 5.0f );
	Vec2 pointTwo( 15.0f, 42.0f );

	float tempX = pointTwo.x - pointOne.x;
	float tempY = pointTwo.y - pointOne.y;

	float distance = std::sqrt( tempX * tempX + tempY * tempY );
	printf( "Distance: %f\n", distance );
	Sleep( 5000 );
}

int main()
{
	MathExample();
	//CEngine().Run();
	return 1;
}