#pragma once
#include "stdafx.h"
class enemy
{
private:
	//current position
	float px, py;


	bool isDead;
	

public:
	enemy();
	void updatePos(SDL_Rect playerrect);
	bool faceLeft;
	SDL_Rect enemyDesRect;
};

