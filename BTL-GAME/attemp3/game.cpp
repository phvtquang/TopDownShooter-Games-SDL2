#include "game.h"
SDL_Rect tempRect={ 100,100,40,40 };

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
	//create temp surface then load IMG to it
	SDL_Surface* tmpsurface = NULL;
	tmpsurface = IMG_Load("peanut/crun.png");

	//create texture to load it into
	playerTexture = SDL_CreateTextureFromSurface(maingamerenderer, tmpsurface);

	//free temp surface
	SDL_FreeSurface(tmpsurface);

	/// ////////////////////////////////////////////////////////////////////
	//create temp surface then load IMG to it
	tmpsurface = IMG_Load("peanut/cidle.png");

	//create texture to load it into
	playerTextureidle = SDL_CreateTextureFromSurface(maingamerenderer, tmpsurface);

	//free temp surface
	SDL_FreeSurface(tmpsurface);



}

void game::draw()
{
}

void game::update()
{
	
}


void game::gameloop()
{
	SDL_RenderClear(maingamerenderer);
	_player.getinput();
	if (_player.idle == true)
	{
		_player.setdesrect();
		_player.playeranimation();
		SDL_RenderCopy(maingamerenderer, playerTextureidle, &_player.playersourceRect, &_player.playerdesRect);
	}
	else {
		if (_player.facingLeft == true)
		{
			_player.setdesrect();
			_player.playeranimation();
			SDL_RenderCopyEx(maingamerenderer, playerTexture, &_player.playersourceRect, &_player.playerdesRect,NULL,NULL,SDL_FLIP_HORIZONTAL);
		}
		else
		{
			_player.setdesrect();
			_player.playeranimation();
			SDL_RenderCopyEx(maingamerenderer, playerTexture, &_player.playersourceRect, &_player.playerdesRect, NULL, NULL, SDL_FLIP_NONE);
		}

	}
	
	SDL_RenderPresent(maingamerenderer);
}

