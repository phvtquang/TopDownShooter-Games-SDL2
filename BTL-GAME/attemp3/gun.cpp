#include "gun.h"

gun::gun()
{
	gunsourceRect = { 0,0,35,15 };
	gundesRect = { 100,100,35 * 2,15 * 2 };
	centergunpoint = { 20,20 };
}

void gun::gunUPDATEPOSITION(int _x, int _y)
{
	gundesRect.x = _x;
	gundesRect.y = _y;
}
