#include "misterybox.h"

misterybox::misterybox()
{
	boxRect.w = 45;
	boxRect.h = 45;
	boxRect.x = rand() % SCREEN_WIDTH;
	boxRect.y = rand() % SCREEN_HEIGHT;
}
