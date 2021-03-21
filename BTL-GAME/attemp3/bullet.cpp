#include "bullet.h"



float speed = 5.0f;

bullet::bullet()
{
	bulletSourceRect = { 1 ,1 ,14*2 ,14*2 };
	bulletDesRect = { 0 , 0 , 14*2 ,14*2 };


}

float f1, f2;
void bullet::getbulletWay(int _mx, int _my, int _sx, int _sy)
{
	float angle = atan((_mx - _sx) / (_my - _sy));
	cout << angle << ' ';
	f1 = cos(angle) * speed;

	f2 = sin(angle) * speed;

}

void bullet::updatebullet(int _mx, int _my, int _sx, int _sy)
{
	getbulletWay(_mx,_my,_sx,_sy);
	cout << f1 << ' ' << f2 << endl;
	bulletDesRect.x += 1;
	bulletDesRect.y += 1;
}
