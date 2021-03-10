#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

int main(int argc, char* arg[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	return 0;
}