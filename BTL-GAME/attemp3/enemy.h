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
	SDL_Rect enemyDesRect;
};

