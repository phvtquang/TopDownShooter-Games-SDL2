#include "enemy.h"

float enemyspeed = 3.0f;

enemy::enemy()
{
	px = 100;
	py = 100;
	isDead = false;
	faceLeft = false;
	enemyDesRect.x = rand() % ( 700 - 200 + 1 ) +200;
	enemyDesRect.y = rand() % (700 - 200 + 1) + 200;
	enemyDesRect.w = 40 * 2;
	enemyDesRect.h = 40 * 2;
}

void enemy::updatePos(SDL_Rect playerRECT)
{
	float angle = atan2((playerRECT.y -enemyDesRect.y) , (playerRECT.x - enemyDesRect.x));
	float f1, f2;
	f1 = cos(angle) * enemyspeed;

	f2 = sin(angle) * enemyspeed;

	enemyDesRect.x += f1;
	enemyDesRect.y += f2;
	if (enemyDesRect.x > playerRECT.x)
	{
		faceLeft = true;
	} 
	else
	{
		faceLeft = false;
	}
}
