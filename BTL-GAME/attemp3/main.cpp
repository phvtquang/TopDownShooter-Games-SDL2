#include <iostream>
#include "stdafx.h"


#include "game.h"
using namespace std;

const int SCREEN_WIDTH = 320*3;
const int SCREEN_HEIGHT = 320*3;

int main(int argc, char* args[])
{
	int flags = 4; //4 for nomal and 1 for fullscreen
	game game;
	game.init(SCREEN_WIDTH,SCREEN_HEIGHT,flags);
	SDL_Delay(5000);
	game.gameloop();
	return 0;
}