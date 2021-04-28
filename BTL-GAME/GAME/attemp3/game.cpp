#include "game.h"

game::game()
{

}

void game::init(int SCREEN_WIDTH, int SCREEN_HEIGHT, Uint32 flags)
{
	//INIT ALL SDL COMPONENTS
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

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
	wall = IMG_LoadTexture(maingamerenderer, "peanut/sWall.png");
	mapRECT = { 16 ,16 ,287,287};
	map = IMG_LoadTexture(maingamerenderer, "peanut/sMap.png");
	enemyTex = IMG_LoadTexture(maingamerenderer, "peanut/enemey.png");
	enemyBlow = IMG_LoadTexture(maingamerenderer, "peanut/sEnemyDead.png");
	enemyBlow2 = IMG_LoadTexture(maingamerenderer, "peanut/explosion.png");
	bulletTex = IMG_LoadTexture(maingamerenderer, "peanut/sBullet.png");

	//menu
	menu = IMG_LoadTexture(maingamerenderer, "peanut/menu2.png");


	//load MUSIC 
	//gMusic = Mix_LoadMUS("21_sound_effects_and_music/beat.wav");
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	bulletsound = Mix_LoadWAV("peanut/aDeath.wav");
	zombiesound = Mix_LoadWAV("peanut/zombiedie.wav");
	enemyblow = Mix_LoadWAV("peanut/enemyblow.wav");
	gMusic = Mix_LoadMUS("peanut/background.mp3");


	//LOAD FONT AND  TEXT AND HEALTHBAR
	healbox = 5;
	HEALTHBARTexture = IMG_LoadTexture(maingamerenderer, "peanut/healbargood.png");
	scoreBOX = { SCREEN_WIDTH / 2, 100 , 100, 100  };
	healthbardesrect = { SCREEN_WIDTH - 200 ,scoreBOX.y, 172,44 };
	healthbarsourcerect = {0, healbox * 150,630, 150 };
	gFont = TTF_OpenFont("peanut/font2.ttf", 20);
	textColor = { 0, 0, 0 };

	//LOAD HEART
	heart = IMG_LoadTexture(maingamerenderer, "peanut/heart.png");
	heartRect = { SCREEN_WIDTH - 200 - 55 - 15 , scoreBOX.y - 15 , 44 + 20 ,44 + 20 };

	//set health and score
	health = 10000;
	score = 0;

	//setmouse
	mousedown = false;
	
}

void game::showmenu()
{

	//SDL_RenderClear(maingamerenderer);
	SDL_RenderCopy(maingamerenderer, map, &mapRECT, NULL);
	SDL_RenderCopy(maingamerenderer, menu, NULL, NULL);
	SDL_RenderPresent(maingamerenderer);

}


void game::draw()
{
	SDL_RenderClear(maingamerenderer);
	//draw map
	SDL_RenderCopy(maingamerenderer, map, &mapRECT, NULL);
	SDL_RenderCopy(maingamerenderer, wall, NULL, NULL);
	//get player input
	_player.getinput();
	//draw enemy
	if (_enemy.size() < 50)
	{
		enemy __enemy;
		if (abs(__enemy.enemyDesRect.x - _player.playerdesRect.x) > SCREEN_WIDTH/2 && abs(__enemy.enemyDesRect.y - _player.playerdesRect.y) > SCREEN_HEIGHT/2)
		{
			_enemy.push_back(__enemy);
		}
		
	}

	for (int i = 0; i < _enemy.size(); i++)
	{
		if (_enemy[i].isDead) {
			_enemy[i].countdead++;
			SDL_RenderCopyEx(maingamerenderer, enemyBlow, NULL, &_enemy[i].enemyDesRect, 0, NULL, SDL_FLIP_NONE);
			if (_enemy[i].countdead >= 200)
			{
				_enemy.erase(_enemy.begin() + i);
			}
		}
	}

	for (int i = 0; i < _enemy.size(); i++)
	{
		_enemy[i].updatePos(_player.playerdesRect);
		if (_enemy[i].isDead == false)
		{

			if (_enemy[i].faceLeft == true)
			{
				SDL_RenderCopyEx(maingamerenderer, enemyTex, &_player.playersourceRect, &_enemy[i].enemyDesRect, 0, NULL, SDL_FLIP_HORIZONTAL);
			}
			else
			{
				SDL_RenderCopyEx(maingamerenderer, enemyTex, &_player.playersourceRect, &_enemy[i].enemyDesRect, 0, NULL, SDL_FLIP_NONE);
			}
		}
	


		if (SDL_HasIntersection(&_enemy[i].enemyDesRect, &_player.playerdesRect) && _enemy[i].isDead == false)
		{
			SDL_Rect blowdesRect = { _enemy[i].enemyDesRect.x - 15,_enemy[i].enemyDesRect.y - 15,150,150 };
			SDL_RenderCopyEx(maingamerenderer, enemyBlow2, NULL, &blowdesRect, 0, NULL, SDL_FLIP_NONE);
			Mix_PlayChannel(-1, enemyblow, 0);
			health -= 500;
			_enemy[i].isDead = true;
		}
	}
	//draw player
	if (_player.idle == true)
	{
		_player.animationIDLE();
		_player.playerupdate();
		SDL_RenderCopy(maingamerenderer, playerTextureidle, &_player.playersourceRect, &_player.playerdesRect);
		
	}
	else
	{

		if (_player.facingLeft == true)
		{
			_player.animationMOVING();
			_player.playerupdate();
			SDL_RenderCopyEx(maingamerenderer, playerTexture, &_player.playersourceRect, &_player.playerdesRect, 0, NULL, SDL_FLIP_HORIZONTAL);
		}
		else
		{
			_player.animationMOVING();
			_player.playerupdate();
			SDL_RenderCopyEx(maingamerenderer, playerTexture, &_player.playersourceRect, &_player.playerdesRect, 0, NULL, SDL_FLIP_NONE);
		}

	}

	//draw bullet
	if (mousedown)
	{
		bullet __bullet;
		__bullet.bulletDesRect.x = _gun.gundesRect.x;
		__bullet.bulletDesRect.y = _gun.gundesRect.y;
		SDL_GetMouseState(&mouseposx, &mouseposy);
		__bullet.f1 = __bullet.getWAYf1(mouseposx, mouseposy, _gun.gundesRect.x, _gun.gundesRect.y);
		__bullet.f2 = __bullet.getWAYf2(mouseposx, mouseposy, _gun.gundesRect.x, _gun.gundesRect.y);
		_bullet.push_back(__bullet);
		Mix_PlayChannel(-1, bulletsound, 0);
		delaybullet = 0;
	}
	for (int i = 0; i < _bullet.size(); i++)
	{
		_bullet[i].updatebullet();

		for (int j = 0; j < _enemy.size(); j++)
		{
			if (!_enemy[j].isDead)
			{
				if (SDL_HasIntersection(&_enemy[j].enemyDesRect, &_bullet[i].bulletDesRect) && _bullet[i].coll == false)
				{
					Mix_PlayChannel(-1, zombiesound, 0);
					_enemy[j].isDead = true;
					_bullet[i].coll = true;
					score++;
				}
			}

		}
		if (_bullet[i].disapear() == false && !SDL_HasIntersection(&_bullet[i].bulletDesRect, &_gun.gundesRect))
		{
			SDL_RenderCopy(maingamerenderer, bulletTex, NULL, &_bullet[i].bulletDesRect);
		}
		if (_bullet[i].disapear())
		{
			_bullet.erase(_bullet.begin() + i);
		}
	}

	//draw the gun
	_gun.gunUPDATEPOSITION(_player.playerdesRect.x + 20, _player.playerdesRect.y + 40);
	SDL_GetMouseState(&mouseposx, &mouseposy);
	angle = atan2((mouseposy - _gun.gundesRect.y), (mouseposx - _gun.gundesRect.x)) * 180.0 / 3.14152;	
	SDL_RenderCopyEx(maingamerenderer, guntexture, &_gun.gunsourceRect, &_gun.gundesRect, angle, &_gun.centergunpoint, SDL_FLIP_NONE);
	


	//draw score and healthbar
	textureText = to_string(score);

	//freesurface to reduce memory
	SDL_FreeSurface(textSurface);
	textSurface = TTF_RenderText_Blended(gFont, textureText.c_str(), textColor);
	
	//freetexture to reduce memory
	SDL_DestroyTexture(mTexture);
	mTexture = SDL_CreateTextureFromSurface(maingamerenderer, textSurface);

	scoreBOX = { SCREEN_WIDTH / 2, 100 , textSurface->w, textSurface->h };

	SDL_RenderCopy(maingamerenderer, heart, NULL, &heartRect);
	SDL_RenderCopy(maingamerenderer, mTexture, NULL, &scoreBOX);


	if (health < 8000)
	{
		healbox = 4;
	}
	if (health < 6000)
	{
		healbox = 3;
	}
	if (health < 4000)
	{
		healbox = 2;
	}
	if (health < 2000)
	{
		healbox = 1;
	}
	if (health < 1000)
	{
		healbox = 0;
	}
	if (health <= 0)
	{
		healbox = 6;
	}
	healthbarsourcerect = { 0, healbox * 150,630, 150 };
	SDL_RenderCopy(maingamerenderer, HEALTHBARTexture, &healthbarsourcerect, &healthbardesrect);
	//PRESENT THE RENDERER
	SDL_RenderPresent(maingamerenderer);
}



void game::gameloop()
{
	//GAMELOOP
	Uint32 frameStart, frameTime;
	SDL_Event e;
	bool run = true;
	bool menu = true;
	bool op = false;
	//Mix_PlayMusic(gMusic, -1);

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
					if (menu == true)
					{
						menu = false;
					}
					else
					{
						menu = true;
					}

					break;
			}
				
			case SDL_MOUSEBUTTONDOWN :
			{
				if (op == true) {
					mousedown = true;
				}
				else
				{
					bullet __bullet;
					__bullet.bulletDesRect.x = _gun.gundesRect.x;
					__bullet.bulletDesRect.y = _gun.gundesRect.y;
					SDL_GetMouseState(&mouseposx, &mouseposy);
					__bullet.f1 = __bullet.getWAYf1(mouseposx, mouseposy, _gun.gundesRect.x, _gun.gundesRect.y);
					__bullet.f2 = __bullet.getWAYf2(mouseposx, mouseposy, _gun.gundesRect.x, _gun.gundesRect.y);
					_bullet.push_back(__bullet);
					Mix_PlayChannel(-1, bulletsound, 0);
					delaybullet = 0;
				}
				break;
			}
			case SDL_MOUSEBUTTONUP :
			{
				mousedown = false;
				break;
			}

			}	
		}

		if (menu)
		{
			showmenu();
		}
		else
		{

			//map -> enemy -> player -> gun -> bullet -> UI
			draw();

			//check if lose the game
			if (health <= 0)
			{
				cout << "YOU LOSE" << endl << score;
				run = false;
			}
		}
		

		frameTime = SDL_GetTicks() - frameStart;
		if (1000 / 60 > frameTime)
		{
			SDL_Delay(1000 / 60 - frameTime);
		}
	}

	
	
}



