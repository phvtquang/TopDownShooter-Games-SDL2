#include <iostream>
#include "stdafx.h"


#include "game.h"
using namespace std;

const int SCREEN_WIDTH = 320*3;
const int SCREEN_HEIGHT = 320*3;

int main(int argc, char* args[])
{
	int flags = 1; //4 for nomal and 1 for fullscreen
	game game;
	game.init(SCREEN_WIDTH,SCREEN_HEIGHT,flags);


	Uint32 frameStart, frameTime;
	

	//GAMELOOP
	SDL_Event e;
	bool run = true;
	while (run)
	{
		frameStart = SDL_GetTicks();
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					run = false;
				}
			} else if (e.type == SDL_QUIT)
			{
				run = false;
			}

			game.gameloop();

			
		}
		

	
		

		frameTime = SDL_GetTicks() - frameStart;
		if (1000 / 60 > frameTime)
		{
			SDL_Delay(1000 / 60 - frameTime);	
		}
	}
	
	return 0;
}