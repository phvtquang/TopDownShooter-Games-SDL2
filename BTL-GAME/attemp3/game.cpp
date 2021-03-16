#include "game.h"

void game::init(int SCREEN_WIDTH, int SCREEN_HEIGHT, Uint32 flags)
{
	//INIT ALL SDL COMPONENTS
	SDL_Init(SDL_INIT_EVERYTHING);

	//CREATE A GAME WINDOW
	maingamewindow = NULL;
	maingamewindow = SDL_CreateWindow("PEANUT", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, flags);

	//CREATE A RENDERER FOR GAME
	maingamerenderer = NULL;
	maingamerenderer = SDL_CreateRenderer(maingamewindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);



	/////////////////////////////////////////////////////////////////////////////
	//create texture and load into
	playerTexture = IMG_LoadTexture(maingamerenderer, "peanut/crun.png");

	playerTextureidle = IMG_LoadTexture(maingamerenderer, "peanut/cidle.png");

	guntexture = IMG_LoadTexture(maingamerenderer, "peanut/sGun.png");


}


int mouseposx;
int mouseposy;
void game::draw()
{

	

	if (_player.idle == true)
	{
		_player.playeranimation();
		SDL_RenderCopy(maingamerenderer, playerTextureidle, &_player.playersourceRect, &_player.playerdesRect);
		
	}
	else {
		if (_player.facingLeft == true)
		{
			_player.playeranimation();
			SDL_RenderCopyEx(maingamerenderer, playerTexture, &_player.playersourceRect, &_player.playerdesRect, NULL, NULL, SDL_FLIP_HORIZONTAL);

		}
		else
		{
			_player.playeranimation();
			SDL_RenderCopyEx(maingamerenderer, playerTexture, &_player.playersourceRect, &_player.playerdesRect, NULL, NULL, SDL_FLIP_NONE);

		}

	}

	//render the gun
	_gun.gunUPDATEPOSITION(_player.playerdesRect.x + 20, _player.playerdesRect.y + 40);
	SDL_GetMouseState(&mouseposx, &mouseposy);
	SDL_RenderCopyEx(maingamerenderer, guntexture, &_gun.gunsourceRect, &_gun.gundesRect, -mouseposx, &_gun.centergunpoint, SDL_FLIP_NONE);
	SDL_RenderPresent(maingamerenderer);
}

void game::update()
{
	
}


void game::gameloop()
{
	SDL_RenderClear(maingamerenderer);
	_player.getinput();
	draw();
}

