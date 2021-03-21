#pragma once
#include "stdafx.h"
class enemy
{
private:
	



	

public:
	enemy();
	//current position
	float px, py;
	void updatePos(SDL_Rect playerrect);
	bool faceLeft;
	bool isDead;
	SDL_Rect enemyDesRect;
};

