#ifndef GAME_H
#define GAME_H
	
#include <iostream>
using namespace std;
#include <SDL.h>


class Game {
public : 
	Game();
	~Game();

private :
	SDL_Renderer* renderer;
	SDL_Window* window;

};

#endif // !GAME_H
