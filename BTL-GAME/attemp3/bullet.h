#pragma once
#include "stdafx.h"
#include "player.h"
class bullet :public player
{
public :
	bullet();
	void getbulletWay(int _mx, int _my, int _sx, int _sy);
	void updatebullet(int _mx, int _my, int _sx, int _sy);

	SDL_Rect bulletSourceRect;
	SDL_Rect bulletDesRect;

private:
	

};

