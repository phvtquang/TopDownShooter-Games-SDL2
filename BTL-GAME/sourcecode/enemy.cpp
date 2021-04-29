#include "enemy.h"

float enemyspeed = 3.0f;

enemy::enemy()
{
	px = 100;
	py = 100;
	isDead = false;
	faceLeft = false;
	isBoss = false;
	bosshealth = 10;
	enemyDesRect.x = -SCREEN_WIDTH*4 +( rand() % (SCREEN_WIDTH*4 + 1 - -SCREEN_WIDTH*4));
	enemyDesRect.y = -SCREEN_HEIGHT*4 + (rand() % (SCREEN_HEIGHT*4 + 1 - -SCREEN_HEIGHT*4));

	enemyDesRect.w = 40 * 2;
	enemyDesRect.h = 40 * 2;
	countdead = 0;
}

void enemy::updatePos(SDL_Rect playerRECT)
{
	if (isBoss)
	{
		enemyDesRect.w = 40 * 5;
		enemyDesRect.h = 40 * 5;
	}
	if (isDead == false)
	{
		float angle = atan2((playerRECT.y - enemyDesRect.y), (playerRECT.x - enemyDesRect.x));
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
	
	
}
