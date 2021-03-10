#include <iostream>
#include <SDL.h>
using namespace std;

int main(int argc, char* args[]) {

	//====================================================
	//init everything , all the systems of SDL
	//Use this function to initialize the SDL library. This must be called before using most other SDL functions.
	SDL_Init(SDL_INIT_EVERYTHING);
	//====================================================


	//=============================================================================================
	/*	create a window with a title , "SDL PROGRAM"
		with 800px in width , and 600px in height , 800x600
		learned SDL_CreateWindow("name",x,y,w,h,flags)
	*/
	SDL_Window* window = SDL_CreateWindow("SDL PROGRAM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	//or
	/*
	
	SDL_Window* window = NULL;
	window = SDL_CreateWindow(etc);
	
	*/
	//===========================================================================================


	//============================================================
	/*
		create a renderer for the window above 
		learn SDL_CreateRenderer()
	*/
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	//SDL_RenderClear(renderer);
	//SDL_RenderPresent(renderer);
	//============================================================

	

	//====================================================
	/*
		delay the program 
		learn SDL_Delay(int time)
	*/
	//	SDL_Delay(3000);
	//====================================================
	
	SDL_Event e; //event handle
	bool quit = false; //main loop flag

	int r=0, g=0, b=0;

	while (!quit) {
		while (SDL_PollEvent(&e) > 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				r = rand() % 255;
				g = rand() % 255;
				b = rand() % 255;	
			}
		}
		SDL_SetRenderDrawColor(renderer, r, g, b, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}
		
	//=====================================================


	//destroy and clear renderer , end of program
	//Destroy the renderer created above
	SDL_DestroyRenderer(renderer);

	//Destroy the window created above
	SDL_DestroyWindow(window);

	//Close all the systems of SDL initialized at the top
	SDL_Quit();
	return 0;
}