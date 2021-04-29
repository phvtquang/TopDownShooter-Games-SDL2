#include "game.h"



//LOAD TEXTURE FOR GAME - MENU
void game::loadMenuTexture()
{
	//menu
	menutex[0] = IMG_LoadTexture(maingamerenderer, "peanut/picture1.png");
	menutex[1] = IMG_LoadTexture(maingamerenderer, "peanut/picture2.png");
	menutex[2] = IMG_LoadTexture(maingamerenderer, "peanut/Picture1start.png");
	menutex[3] = IMG_LoadTexture(maingamerenderer, "peanut/Picture1how.png");
	menutex[4] = IMG_LoadTexture(maingamerenderer, "peanut/Picture1setting.png");
	menutex[5] = IMG_LoadTexture(maingamerenderer, "peanut/Picture1quit.png");
	menutex[6] = IMG_LoadTexture(maingamerenderer, "peanut/Picture2resume.png");
	menutex[7] = IMG_LoadTexture(maingamerenderer, "peanut/Picture2how.png");
	menutex[8] = IMG_LoadTexture(maingamerenderer, "peanut/Picture2quit.png");
	menutex[9] = IMG_LoadTexture(maingamerenderer, "peanut/Picture2setting.png");
	menutex[10] = IMG_LoadTexture(maingamerenderer,"peanut/howtoplay.png");
	menutex[11] = IMG_LoadTexture(maingamerenderer, "peanut/settings.png");
	menutex[12] = IMG_LoadTexture(maingamerenderer, "peanut/healthblood.png");
}


//LOAD TEXTURE FOR GAME - PLAYER - GUN - BULLET - MAP - ENEMY
void game::loadMainTexture()
{
	//player 
	playerTexture = IMG_LoadTexture(maingamerenderer, "peanut/crun.png");
	playerTexturerampage = IMG_LoadTexture(maingamerenderer, "peanut/crunrampage.png");
	playerTextureidle = IMG_LoadTexture(maingamerenderer, "peanut/cidle.png");
	playerTextureidlerampage = IMG_LoadTexture(maingamerenderer, "peanut/cidlerampage.png");

	//gun & bullet 
	guntexture = IMG_LoadTexture(maingamerenderer, "peanut/sGun.png");
	rampagegun = IMG_LoadTexture(maingamerenderer, "peanut/gun2.png");
	//cout << SDL_GetError() << endl;
	bulletTex = IMG_LoadTexture(maingamerenderer, "peanut/sBullet.png");

	//the outside wall
	wall = IMG_LoadTexture(maingamerenderer, "peanut/sWall.png");
	//the greenmap
	mapRECT = { 16 ,16 ,287,287 }; //why need this -> cause it is not full filled
	map = IMG_LoadTexture(maingamerenderer, "peanut/sMap.png");

	//enemy
	enemyTex = IMG_LoadTexture(maingamerenderer, "peanut/enemey.png");	//the brown one
	enemyDead = IMG_LoadTexture(maingamerenderer, "peanut/sEnemyDead.png");//enemydead - the black one
	enemyBlow2 = IMG_LoadTexture(maingamerenderer, "peanut/explosion.png");//the explosion if enemy touch player
	
}

//LOAD SOUND FOR GAME
void game::loadSound()
{
	//load MUSIC 
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	bulletsound = Mix_LoadWAV("peanut/aDeath.wav");
	zombiesound = Mix_LoadWAV("peanut/zombiedie.wav");
	enemyblow = Mix_LoadWAV("peanut/Grenade.wav");
	menusound = Mix_LoadWAV("peanut/menusound.wav");
	gMusic = Mix_LoadMUS("peanut/background.mp3");
	rampage = Mix_LoadWAV("peanut/Rampage.wav");
	gameoversound = Mix_LoadWAV("peanut/gameover.wav");
	hitthebox = Mix_LoadWAV("peanut/fortnite.wav");
	//gMusic = Mix_LoadMUS("21_sound_effects_and_music/beat.wav");
}

void game::loadOtherTexture()
{
	//LOAD FONT AND  TEXT AND HEALTHBAR
	healbox = 5;
	HEALTHBARTexture = IMG_LoadTexture(maingamerenderer, "peanut/healbargood.png");
	scoreBOX = { SCREEN_WIDTH / 2, 100 , 100, 100 };
	healthbardesrect = { SCREEN_WIDTH - 200 ,scoreBOX.y, 172,44 };
	healthbarsourcerect = { 0, healbox * 150,630, 150 };
	gFont = TTF_OpenFont("peanut/font2.ttf", 20);
	textColor = { 0, 0, 0 };

	//LOAD HEART
	heart = IMG_LoadTexture(maingamerenderer, "peanut/heart.png");
	heartRect = { SCREEN_WIDTH - 200 - 55 - 15 , scoreBOX.y - 15 , 44 + 20 ,44 + 20 };


	//LOAD MISTERY BOX
	misteryboxTex = IMG_LoadTexture(maingamerenderer, "peanut/ques.png");
	//cout << SDL_GetError() << endl;

	rampagetex = IMG_LoadTexture(maingamerenderer, "peanut/rampage.png");
	gameover = IMG_LoadTexture(maingamerenderer, "peanut/gameover2.png");
	gainhealthtexture = IMG_LoadTexture(maingamerenderer, "peanut/health.png");
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

	//LOADTEXTURE
	loadMenuTexture();
	loadMainTexture();
	loadSound();
	loadOtherTexture();


	

	//set health and score
	health = 10000;
	score = 0;

	//setmouse
	mousedown = false;

	//set maxenemy
	maxenemy = 70;
	
}
int rampagetimer = 0;
int healthtimer = 0;
void game::drawBOX()
{
	//drawmisterybox
	int k = rand() % 10000;
	if (k < 10)
	{
		if (_misterybox.size() < 1)
		{
			misterybox __misterybox;
			_misterybox.push_back(__misterybox);
		}
		
	}
	for (int i = 0; i < _misterybox.size(); i++)
	{
		SDL_RenderCopy(maingamerenderer, misteryboxTex, NULL, &_misterybox[i].boxRect);
	}

	for (int i = 0; i < _misterybox.size(); i++)
	{
		if (SDL_HasIntersection(&_player.playerdesRect, &_misterybox[i].boxRect))
		{
			int e = rand() % 5;
			if (e == 5 || e==4 || e==3)
			{
				Mix_PlayChannel(-1, rampage, 0);
				op = 1000;
				e = 0;
				rampagetimer = 170;
			}
			if (e == 1 || e== 2 )
			{
				Mix_PlayChannel(-1, hitthebox, 0);
				health += 1500;
				e = 0;
				healthtimer = 170;
			}
			if (e == 0)
			{
				bossnum++;
				e = 0;
			}

			
			_misterybox.erase(_misterybox.begin() + i);
		}
	}
}

int menucounter = 0;

void game::drawmenu()
{
	SDL_GetMouseState(&mouseposx, &mouseposy);
	SDL_RenderClear(maingamerenderer);
	//render how to play 

	if (first && menu && howtoplay)
	{
		SDL_RenderCopy(maingamerenderer, menutex[10], NULL, NULL);
	} 

	//render setting 
	if (issetting)
	{
		SDL_RenderCopy(maingamerenderer, menutex[11], NULL, NULL);
	}

	if (first && !howtoplay && !issetting)
	{
		if (mouseposx > 362 && mouseposx < 638 && mouseposy > 256 && mouseposy < 342) {
			SDL_RenderCopy(maingamerenderer, menutex[2], NULL, NULL);
			menucounter++;
			if (menucounter == 1000)
			{
				menucounter = 3;
			}
		} else 
		if (mouseposx > 362 && mouseposx < 638 && mouseposy > 362 && mouseposy < 447) {
			SDL_RenderCopy(maingamerenderer, menutex[3], NULL, NULL);
			menucounter++;
			if (menucounter == 1000)
			{
				menucounter = 3;
			}
		} else 
		if (mouseposx > 362 && mouseposx < 638 && mouseposy > 468 && mouseposy < 555) {
			SDL_RenderCopy(maingamerenderer, menutex[4], NULL, NULL);
			menucounter++;
			if (menucounter == 1000)
			{
				menucounter = 3;
			}
		} else 
		if (mouseposx > 362 && mouseposx < 638 && mouseposy > 582 && mouseposy < 667) {
			SDL_RenderCopy(maingamerenderer, menutex[5], NULL, NULL);
			menucounter++;
			if (menucounter == 1000)
			{
				menucounter = 3;
			}
		}
		else 
		{
			SDL_RenderCopy(maingamerenderer, menutex[0], NULL, NULL);
			menucounter = 0;
		}
		
	}
	else if (!first && !howtoplay && !issetting)
	{
		if (mouseposx > 362 && mouseposx < 638 && mouseposy > 256 && mouseposy < 342) {
			SDL_RenderCopy(maingamerenderer, menutex[6], NULL, NULL);
			menucounter++;
			if (menucounter == 1000)
			{
				menucounter = 3;
			}
		} else 
		if (mouseposx > 362 && mouseposx < 638 && mouseposy > 362 && mouseposy < 447) {
			SDL_RenderCopy(maingamerenderer, menutex[7], NULL, NULL);
			menucounter++;
			if (menucounter == 1000)
			{
				menucounter = 3;
			}
		} else 
		if (mouseposx > 362 && mouseposx < 638 && mouseposy > 468 && mouseposy < 555) {
			SDL_RenderCopy(maingamerenderer, menutex[9], NULL, NULL);
			menucounter++;
			if (menucounter == 1000)
			{
				menucounter = 3;
			}
		} else 
		if (mouseposx > 362 && mouseposx < 638 && mouseposy > 582 && mouseposy < 667) {
			SDL_RenderCopy(maingamerenderer, menutex[8], NULL, NULL);
			menucounter++;
			if (menucounter == 1000)
			{
				menucounter = 3;
			}
		}
		else 
		{
			SDL_RenderCopy(maingamerenderer, menutex[1], NULL, NULL);
			menucounter = 0;
		}
	}
	if (menucounter == 2) Mix_PlayChannel(-1, menusound, 0);
	SDL_RenderPresent(maingamerenderer);

}

//UPDATE AND DRAW THE GAME
void game::draw()
{
	SDL_RenderClear(maingamerenderer);
	//draw map
	SDL_RenderCopy(maingamerenderer, map, &mapRECT, NULL);
	SDL_RenderCopy(maingamerenderer, wall, NULL, NULL);

	//get player input
	_player.getinput();

	//add enemy to vector if there is less enemy than MAXENEMY
	if (_enemy.size() < maxenemy)
	{
		enemy __enemy;
		//check if the random position is in the screen or not because we need it to be outside
		if (abs(__enemy.enemyDesRect.x - _player.playerdesRect.x) > SCREEN_WIDTH/2 && abs(__enemy.enemyDesRect.y - _player.playerdesRect.y) > SCREEN_HEIGHT/2)
		{
			_enemy.push_back(__enemy);
		}
		
	}
	if (bossnum > 0)
	{
		enemy __enemy;
		__enemy.isBoss = true;
		_enemy.push_back(__enemy);
		bossnum--;
	}

	//for through the enemy vector to check if there is any dead enemy to erase it out -> save memory
	for (int i = 0; i < _enemy.size(); i++)
	{
		if (_enemy[i].isDead) {
			_enemy[i].countdead++;
			SDL_RenderCopyEx(maingamerenderer, enemyDead, NULL, &_enemy[i].enemyDesRect, 0, NULL, SDL_FLIP_NONE);
			if (_enemy[i].countdead >= 200)
			{
				_enemy.erase(_enemy.begin() + i);
			}
		}
	}

	//drawbox
	drawBOX();
	


	//update enemy position base on player position and draw them
	for (int i = 0; i < _enemy.size(); i++)
	{
		_enemy[i].updatePos(_player.playerdesRect);//update
		if (_enemy[i].isDead == false)//the enemy must alive to be draw on the screen
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
	

		//check if enemy touch player and draw the expolison effect
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
		if (!op)
		{
			SDL_RenderCopy(maingamerenderer, playerTextureidle, &_player.playersourceRect, &_player.playerdesRect);

		}
		else
		{
			SDL_RenderCopy(maingamerenderer, playerTextureidlerampage, &_player.playersourceRect, &_player.playerdesRect);
			//cout << SDL_GetError() << endl;
		}
		
		
	}
	else
	{

		if (_player.facingLeft == true)
		{
			_player.animationMOVING();
			_player.playerupdate();
			if (!op)
			{
				SDL_RenderCopyEx(maingamerenderer, playerTexture, &_player.playersourceRect, &_player.playerdesRect, 0, NULL, SDL_FLIP_HORIZONTAL);
			}
			else
			{
				SDL_RenderCopyEx(maingamerenderer, playerTexturerampage, &_player.playersourceRect, &_player.playerdesRect, 0, NULL, SDL_FLIP_HORIZONTAL);
			}
			
		}
		else
		{
			_player.animationMOVING();
			_player.playerupdate();
			if (!op)
			{
				SDL_RenderCopyEx(maingamerenderer, playerTexture, &_player.playersourceRect, &_player.playerdesRect, 0, NULL, SDL_FLIP_NONE);
			}
			else
			{
				SDL_RenderCopyEx(maingamerenderer, playerTexturerampage, &_player.playersourceRect, &_player.playerdesRect, 0, NULL, SDL_FLIP_NONE);
			}
		}

	}

	//add bullet base on mouse state
	if (mousedown)
	{
		bullet __bullet;
		__bullet.bulletDesRect.x = _gun.gundesRect.x;
		__bullet.bulletDesRect.y = _gun.gundesRect.y;
		SDL_GetMouseState(&mouseposx, &mouseposy);
		__bullet.f1 = __bullet.getWAYf1(mouseposx, mouseposy, _gun.gundesRect.x, _gun.gundesRect.y);
		__bullet.f2 = __bullet.getWAYf2(mouseposx, mouseposy, _gun.gundesRect.x, _gun.gundesRect.y);
		_bullet.push_back(__bullet);
		//playsound 
		Mix_PlayChannel(-1, bulletsound, 0);
	}

	//check - update and draw bullet
	for (int i = 0; i < _bullet.size(); i++)
	{
		//update and check
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
					score++;//one enemy dead , gain one score
				}
			}

		}
		SDL_Rect nobulletzone = { _player.playerdesRect.x - 20,_player.playerdesRect.y - 20,_player.playerdesRect.w + 20,_player.playerdesRect.h + 20 };
		//draw the bullet
		if (op)
		{
			if (_bullet[i].disapear() == false && !SDL_HasIntersection(&_bullet[i].bulletDesRect, &nobulletzone))
			{
				SDL_RenderCopy(maingamerenderer, bulletTex, NULL, &_bullet[i].bulletDesRect);
			}
		} else
		if (_bullet[i].disapear() == false && !SDL_HasIntersection(&_bullet[i].bulletDesRect, &_gun.gundesRect))
		{
			SDL_RenderCopy(maingamerenderer, bulletTex, NULL, &_bullet[i].bulletDesRect);
		}
		
		//erase the bullet if out of screen or hit enemy -> save memory
		if (_bullet[i].disapear())
		{
			_bullet.erase(_bullet.begin() + i);
		}
	}

	//UPDATE AND DRAW GUN
	//find the gun's position
	_gun.gunUPDATEPOSITION(_player.playerdesRect.x + 20, _player.playerdesRect.y + 40); //update gun position base on player position

	//CALCULATE GUN ANGLE BASE ON GUN POS AND MOUSE POS
	SDL_GetMouseState(&mouseposx, &mouseposy);
	angle = atan2((mouseposy - _gun.gundesRect.y), (mouseposx - _gun.gundesRect.x)) * 180.0 / 3.14152;	//radian to degrees

	//draw gun
	if (!op)
	{
		SDL_RenderCopyEx(maingamerenderer, guntexture, &_gun.gunsourceRect, &_gun.gundesRect, angle, &_gun.centergunpoint, SDL_FLIP_NONE);
	}
	else
	{
		rampagegundesRect.x = _gun.gundesRect.x;
		rampagegundesRect.y = _gun.gundesRect.y;
		rampagegundesRect.w = 230 / 2;
		rampagegundesRect.h = 80 / 2;
		SDL_RenderCopyEx(maingamerenderer, rampagegun, NULL, &rampagegundesRect, angle, &_gun.centergunpoint2, SDL_FLIP_NONE);
	}

	
	//draw rampage
	if (rampagetimer)
	{
		SDL_RenderCopy(maingamerenderer, rampagetex, NULL, NULL);
	}

	//draw health
	if (healthtimer)
	{
		SDL_RenderCopy(maingamerenderer, gainhealthtexture, NULL, NULL);
	}

	//draw score and healthbar
	scoreText = to_string(score);

	//freesurface to reduce memory
	SDL_FreeSurface(textSurface);
	textSurface = TTF_RenderText_Blended(gFont, scoreText.c_str(), textColor);
	
	//freetexture to reduce memory
	SDL_DestroyTexture(mTexture);
	mTexture = SDL_CreateTextureFromSurface(maingamerenderer, textSurface);

	scoreBOX = { SCREEN_WIDTH / 2, 100 , textSurface->w, textSurface->h };

	SDL_RenderCopy(maingamerenderer, heart, NULL, &heartRect);
	SDL_RenderCopy(maingamerenderer, mTexture, NULL, &scoreBOX);


	//update healthbox sourceRECT 
	if (health == 10000) healbox = 5;
	if (health < 8000) healbox = 4;
	if (health < 6000) healbox = 3;
	if (health < 4000) healbox = 2;
	if (health < 2000) healbox = 1;
	if (health < 1000) healbox = 0;
	if (health <= 0) healbox = 6;
	
	healthbarsourcerect = { 0, healbox * 150,630, 150 };
	//draw healBAR
	SDL_RenderCopy(maingamerenderer, HEALTHBARTexture, &healthbarsourcerect, &healthbardesrect);

	
	
		

	//PRESENT THE RENDERER
	SDL_RenderPresent(maingamerenderer);
}

void game::gamereset()
{
	_bullet.erase(_bullet.begin(), _bullet.end());
	_enemy.erase(_enemy.begin(), _enemy.end());
	_misterybox.erase(_misterybox.begin(), _misterybox.end());
	_player.px = SCREEN_WIDTH / 2;
	_player.py = SCREEN_HEIGHT / 2;
	health = 10000;
	score = 0;
	op = 0;
	rampagetimer = 0;
}




void game::gameloop()
{
	
	SDL_Event e;
	//main game running
	run = true;

	//if showing menu
	menu = true;

	//if gamer are playing the game
	playing = false;

	//make main character OP
	op = 0;

	//if lose the game
	lose = false;

	//if how to play
	howtoplay = false;

	//setting
	issetting = false;

	Mix_PlayMusic(gMusic, -1);

	boxcounter = 0;

	while (run)
	{
		boxcounter++;
		op--;
		rampagetimer--;
		healthtimer--;
		if (rampagetimer < 0)
		{
			rampagetimer = 0;
		}
		if (healthtimer < 0)
		{
			healthtimer = 0;
		}
		if (op < 0)
		{
			op = 0;
			mousedown = false;
		}
		while (SDL_PollEvent(&e) != 0)
		{
			if (playing)
			{
				switch (e.type)
				{
				case SDL_QUIT:
				{
					run = false;
				}
				case SDL_KEYDOWN:
				{
					if (e.key.keysym.sym == SDLK_ESCAPE)
					{
						menu = true;
						playing = false;
						first = false;
					}
							
					break;
				}


				case SDL_MOUSEBUTTONDOWN:
				{
					if (op > 0) {
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
					}
					break;
				}

				case SDL_MOUSEBUTTONUP:
				{
					mousedown = false;
					break;
				}

				}
			} else 
			
			if (menu)
			{
				switch (e.type)
				{
				case SDL_QUIT:
				{
					run = false;
				}

				case SDL_MOUSEBUTTONDOWN:
				{
					SDL_GetMouseState(&mouseposx, &mouseposy);
					//start
					if (!issetting && !howtoplay && mouseposx > 362 && mouseposx < 638 && mouseposy > 256 && mouseposy < 342) {
						playing = true;
						menu = false;
						first = false;
						issetting = false;
					}

					//quit
					if (!issetting && !howtoplay && mouseposx > 362 && mouseposx < 638 && mouseposy > 582 && mouseposy < 668) {
						run = false;
					}

					//restart
					if (!issetting && !howtoplay &&  !first && mouseposx > 362 && mouseposx < 638 && mouseposy > 362 && mouseposy < 447) {
						gamereset();
						menu = false;
						playing = true; // to playing screen
						issetting = false;
						first = false;
						howtoplay = false;
						
					}

					//howtoplay
					if (first && !issetting && mouseposx > 362 && mouseposx < 638 && mouseposy > 362 && mouseposy < 447) {
						howtoplay = true;
					}

					//setting
					if (!howtoplay && mouseposx > 362 && mouseposx < 638 && mouseposy > 468 && mouseposy < 555)
					{
						issetting = true;
					}
					//SFX
					if (issetting && mouseposx > 438 && mouseposx < 494 && mouseposy > 275 && mouseposy < 286)
					{
						sfxvolume -= 10;
						if (sfxvolume < 0)
						{
							sfxvolume = 0;
						}
						Mix_Volume(-1, sfxvolume);
						cout << "lOW SFX TO " << sfxvolume<<  endl;
					}
					if (issetting && mouseposx > 595 && mouseposx < 635 && mouseposy > 258 && mouseposy < 298)
					{
						sfxvolume += 10;
						if (sfxvolume > 128)
						{
							sfxvolume = 128;
						}
						Mix_Volume(-1, sfxvolume);
						cout << "UP SFX TO " << sfxvolume << endl;
					}
					//MUSIC
					if (issetting && mouseposx > 438 && mouseposx < 494 && mouseposy > 370 && mouseposy < 390)
					{
						musicvolume -= 10;
						if (musicvolume < 0)
						{
							musicvolume = 0;
						}
						Mix_VolumeMusic(musicvolume);
						cout << "lOW MUSIC TO " << musicvolume << endl;
					}
					if (issetting && mouseposx > 601 && mouseposx < 639 && mouseposy > 365 && mouseposy < 404)
					{
						musicvolume += 10;
						if (musicvolume > 128)
						{
							musicvolume = 128;
						}
						Mix_VolumeMusic(musicvolume);
						cout << "UP MUSIC TO " << musicvolume << endl;
					}



					break;
				}

				case SDL_KEYDOWN:
				{
					if (e.key.keysym.sym == SDLK_ESCAPE)
					{
						if (howtoplay)
						{
							howtoplay = false;
						}
						if (issetting)
						{
							issetting = false;
						}
					}
						
			

					break;
				}

				}
			}


		}
		//DRAW THING TO THE SCREEN 
		if(menu)
			{
				drawmenu();
			}
			else if (playing)
			{

				//map -> enemy -> player -> gun -> bullet -> UI
				draw();

				//check if lose the game
				if (health <= 0)
				{
					Mix_PlayChannel(-1, gameoversound, 0);
					cout << "YOU LOSE" << endl << score << endl;
					menu = true;
					playing = false;
					issetting = false;
					howtoplay = false;
					first = true;
					gamereset();
					SDL_RenderCopy(maingamerenderer, menutex[12], NULL, NULL);
					SDL_RenderCopy(maingamerenderer, gameover, NULL, NULL);
					SDL_RenderPresent(maingamerenderer);
					SDL_Delay(3300);
					
				}
			}
		


		
	}
}