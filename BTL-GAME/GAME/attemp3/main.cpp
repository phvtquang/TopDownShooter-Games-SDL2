#include <iostream>
#include "stdafx.h"
#include "game.h"
using namespace std;




int main(int argc, char* args[])
{
	srand((unsigned)time(0));
	int flags = 4; //4 for nomal and 1 for fullscreen
	game game;
	game.init(SCREEN_WIDTH,SCREEN_HEIGHT,flags);
	game.gameloop();
	SDL_Delay(4000);
	return 0;
}