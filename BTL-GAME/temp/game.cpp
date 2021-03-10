#include "game.h"

Game::Game()
{
	SDL_Init();
	SDL_CreateWindowAndRenderer(800,600,0,&renderer,&window);
}

Game::~Game()
{

}