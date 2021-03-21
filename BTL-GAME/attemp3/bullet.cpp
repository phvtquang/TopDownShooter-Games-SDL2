#include "bullet.h"



float speed = 15.0f;

bullet::bullet()
{
	f1 = 1;
	f2 = 1;
	coll = false;
	bulletSourceRect = { 1 ,1 ,14*2 ,14*2 };


	bulletDesRect = { 0 , 0 , 14*2 ,14*2 };


}


float bullet::getWAYf1(int _mx, int _my, int _sx, int _sy)
{
	float angle = atan2((_my - _sy) , (_mx - _sx));
	//cout << angle << ' ';
	f1 = cos(angle) * speed;
	return f1;
}

float bullet::getWAYf2(int _mx, int _my, int _sx, int _sy)
{
	float angle = atan2((_my - _sy) , (_mx - _sx));
	//cout << angle << ' ';
	f2 = sin(angle) * speed;
	return f2;
}

bool bullet::outofscreen()
{
	if (bulletDesRect.x > 800 || bulletDesRect.y > 800)
	{
		return true;
	}
	else

	{
		return false;

	}
}
bool bullet::disapear()
{
	if (outofscreen())
	{
		return true;
	}
	if (coll) {
		return true;
	}
}
void bullet::updatebullet()
{
	
	//cout << f1 << ' ' << f2 << endl;
	bulletDesRect.x += f1;
	bulletDesRect.y += f2;
}

