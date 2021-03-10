#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

	

int main(int argc, char* args[])
{
	//init everything
	SDL_Init(SDL_INIT_EVERYTHING);
	//create window
	SDL_Window* window = NULL;
	window = SDL_CreateWindow("GAME WINDOW", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	//create a renderer for window
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

