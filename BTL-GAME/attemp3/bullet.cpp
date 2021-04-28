#include "bullet.h"



float speed = 15.0f; //speed that the bullet going on the screen

bullet::bullet()
{
	f1 = 0;
	f2 = 0;
	coll = false; //check if the bullet hit any enemy before
	bulletSourceRect = { 1 ,1 ,14*2 ,14*2 };
	bulletDesRect = { 0 , 0 , 14*2 ,14*2 };
}

float bullet::getWAYf1(int _mx, int _my, int _sx, int _sy)
{
	float angle = atan2((_my - _sy) , (_mx - _sx));
	f1 = cos(angle) * speed;
	return f1;
}

float bullet::getWAYf2(int _mx, int _my, int _sx, int _sy)
{
	float angle = atan2((_my - _sy) , (_mx - _sx));
	f2 = sin(angle) * speed;
	return f2;
}

//check if bullet out of screen or not
bool bullet::outofscreen()
{
	if (bulletDesRect.x > SCREEN_WIDTH || bulletDesRect.y > SCREEN_HEIGHT || bulletDesRect.x < 0 || bulletDesRect.y < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//bullet disapear when hit enemy or out of screen
bool bullet::disapear()
{
	if (outofscreen())
	{
		return true;
	}
	if (coll) {
		return true;
	}
	return false;
}

//update bullet desRect
void bullet::updatebullet()
{
	bulletDesRect.x += f1;
	bulletDesRect.y += f2;
}

