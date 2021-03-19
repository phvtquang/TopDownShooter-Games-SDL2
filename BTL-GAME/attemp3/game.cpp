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

	//LOAD TEXTURE
	playerTexture = IMG_LoadTexture(maingamerenderer, "peanut/crun.png");
	playerTextureidle = IMG_LoadTexture(maingamerenderer, "peanut/cidle.png");
	guntexture = IMG_LoadTexture(maingamerenderer, "peanut/sGun.png");
	map = IMG_LoadTexture(maingamerenderer, "peanut/sMap.png");
	enemyTex = IMG_LoadTexture(maingamerenderer, "peanut/enemey.png");
	
}


void game::draw()
{
	SDL_RenderClear(maingamerenderer);

	//draw map
	SDL_RenderCopy(maingamerenderer, map, NULL, NULL);

	//getinput
	_player.getinput();
	//then
	//draw player
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
	//draw the gun
	_gun.gunUPDATEPOSITION(_player.playerdesRect.x + 20, _player.playerdesRect.y + 40);
	SDL_GetMouseState(&mouseposx, &mouseposy);
	angle = atan2(( mouseposy - _gun.gundesRect.y ) , ( mouseposx - _gun.gundesRect.x )) * 180 / 3.14;
	SDL_RenderCopyEx(maingamerenderer, guntexture, &_gun.gunsourceRect, &_gun.gundesRect, angle, &_gun.centergunpoint, SDL_FLIP_NONE);
	
	
	
	
	
}



void game::gameloop()
{
	//GAMELOOP
	Uint32 frameStart, frameTime;
	SDL_Event e;
	bool run = true;
	while (run)
	{
		//map and player and gun
		draw();
		//draw enemy
		for (int i = 1; i <= 40; i++)
		{
			_enemy[i].updatePos(_player.playerdesRect);

			if (_enemy[i].faceLeft == true)
			{
				SDL_RenderCopyEx(maingamerenderer, enemyTex, &_player.playersourceRect, &_enemy[i].enemyDesRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
			}
			else
			{
				SDL_RenderCopyEx(maingamerenderer, enemyTex, &_player.playersourceRect, &_enemy[i].enemyDesRect, NULL, NULL, SDL_FLIP_NONE);
			}

		}
		


		frameStart = SDL_GetTicks();
		while (SDL_PollEvent(&e) != 0)
		{
			
			switch (e.type)
			{
			case SDL_QUIT :
				run = false;
				break;
			case SDL_MOUSEBUTTONDOWN :
				cout << "mouse down" << endl;
				
				break;

			}
			
			
		}

		//PRESENT THE RENDERER
		SDL_RenderPresent(maingamerenderer);
		

		frameTime = SDL_GetTicks() - frameStart;
		if (1000 / 60 > frameTime)
		{
			SDL_Delay(1000 / 60 - frameTime);
		}
	}
	
}

