#pragma once;
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;

class RenderWindow
{
public:
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};