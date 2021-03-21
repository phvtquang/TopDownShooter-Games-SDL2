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
	enemyBlow = IMG_LoadTexture(maingamerenderer, "peanut/sEnemyDead.png");
	bulletTex = IMG_LoadTexture(maingamerenderer, "peanut/sBullet.png");

	//load MUSIC 
	//gMusic = Mix_LoadMUS("21_sound_effects_and_music/beat.wav");
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	bulletsound = Mix_LoadWAV("peanut/aBullet.wav");
	
}


void game::drawmapplayerandgun()
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
	int health = 200;
	while (run)
	{
		
	
	
		
		frameStart = SDL_GetTicks();
		while (SDL_PollEvent(&e) != 0)
		{
			
			switch (e.type)
			{
			case SDL_KEYDOWN:
			{
				if (e.key.keysym.sym == SDLK_ESCAPE)
				run = false;
				break;
			}
				
			case SDL_MOUSEBUTTONDOWN :
				bullet __bullet;
				__bullet.bulletDesRect.x = _gun.gundesRect.x;
				__bullet.bulletDesRect.y = _gun.gundesRect.y;
				
				SDL_GetMouseState(&mouseposx, &mouseposy);
				mousexbullet.push_back(mouseposx);
				mouseybullet.push_back(mouseposy);
				__bullet.f1 = __bullet.getWAYf1(mouseposx, mouseposy, _gun.gundesRect.x, _gun.gundesRect.y);
				__bullet.f2 = __bullet.getWAYf2(mouseposx, mouseposy, _gun.gundesRect.x, _gun.gundesRect.y);

				_bullet.push_back(__bullet);

				playerx.push_back(_gun.gundesRect.x);
				playery.push_back(_gun.gundesRect.y);
				Mix_PlayChannel(-1, bulletsound, 0);
				break;

			}	
		}

		//map and player and gun
		drawmapplayerandgun();

		
		
		


		//draw bullet
		for (int i = 0; i < _bullet.size(); i++)
		{

			_bullet[i].updatebullet();

			for (int j = 0; j < _enemy.size(); j++)
			{
				if (SDL_HasIntersection(&_enemy[j].enemyDesRect, &_bullet[i].bulletDesRect) && _bullet[i].coll==false )
				{
					_enemy[j].isDead = true;
					_bullet[i].coll = true;
				}	
			}
			if (_bullet[i].disapear() == false && !SDL_HasIntersection(&_bullet[i].bulletDesRect,&_gun.gundesRect) )
			{
				SDL_RenderCopy(maingamerenderer, bulletTex, NULL, &_bullet[i].bulletDesRect);
			}
			
			
			
			
		}

		//draw enemy
		if (_enemy.size() < 200)
		{
			enemy __enemy;
			_enemy.push_back(__enemy);
		}
	
		for (int i = 0; i < _enemy.size(); i++)
		{
			_enemy[i].updatePos(_player.playerdesRect);

			if (_enemy[i].isDead == false)
			{

				if (_enemy[i].faceLeft == true)
				{
					SDL_RenderCopyEx(maingamerenderer, enemyTex, &_player.playersourceRect, &_enemy[i].enemyDesRect, NULL, NULL, SDL_FLIP_HORIZONTAL);
				}
				else
				{
					SDL_RenderCopyEx(maingamerenderer, enemyTex, &_player.playersourceRect, &_enemy[i].enemyDesRect, NULL, NULL, SDL_FLIP_NONE);
				}
			}
			else
			{
				SDL_RenderCopyEx(maingamerenderer, enemyBlow, NULL, &_enemy[i].enemyDesRect, NULL, NULL, SDL_FLIP_NONE);
				_enemy.erase(_enemy.begin() + i);
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

