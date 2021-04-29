#include "misterybox.h"

misterybox::misterybox()
{
	boxRect.w = 45;
	boxRect.h = 45;
	boxRect.x = rand() % SCREEN_WIDTH - boxRect.w;
	boxRect.y = rand() % SCREEN_HEIGHT - boxRect.h;
}
