#pragma once
#include "stdafx.h"
class enemy
{
private:
	



	

public:
	enemy();
	//current position
	float px, py;
	long long countdead;
	void updatePos(SDL_Rect playerrect);
	bool faceLeft;
	bool isDead;
	bool isBoss;
	int bosshealth = 10;
	SDL_Rect enemyDesRect;
};

