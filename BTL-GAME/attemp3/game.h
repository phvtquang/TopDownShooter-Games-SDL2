#pragma once
#include "stdafx.h"
#include "player.h"
#include "gun.h"
class game
{
public :
	/*CREATE A GAME WINDOW AND A RENDERER FOR THAT WINDOW , PASSING IN THE WIDTH AND THE HEIGHT OF THAT WINDOW
	* FLAGS 1 for FULLSCREEN , 4 for SHOWN
	*/
	void init(int SCREEN_WIDTH, int SCREEN_HEIGHT, Uint32 flags);	
	void draw();
	void updateplayerfacing();
	void gameloop();

	

private:

	//mouse && angle for gun
	int mouseposx;
	int mouseposy;
	int angle;

	//map
	SDL_Texture* map;

	//player 
	player _player;
	SDL_Texture* playerTexture;
	SDL_Texture* playerTextureidle;

	//gun
	gun _gun;
	SDL_Texture* guntexture;


	//MAIN RENDERER AND WINDOW
	SDL_Renderer* maingamerenderer;
	SDL_Window* maingamewindow;
};

