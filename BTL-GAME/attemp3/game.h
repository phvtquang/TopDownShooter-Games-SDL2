#pragma once
#include "stdafx.h"
#include "player.h"
#include "gun.h"
#include "enemy.h"
#include "bullet.h"
class game
{
public :
	/*CREATE A GAME WINDOW AND A RENDERER FOR THAT WINDOW , PASSING IN THE WIDTH AND THE HEIGHT OF THAT WINDOW
	* FLAGS 1 for FULLSCREEN , 4 for SHOWN
	*/
	void init(int SCREEN_WIDTH, int SCREEN_HEIGHT, Uint32 flags);	
	void drawmapplayerandgun();
	void gameloop();

	

private:

	//mouse && angle for gun
	int angle;
	int mouseposx;
	int mouseposy;

	//map
	SDL_Texture* map;

	//player 
	player _player;
	SDL_Texture* playerTexture;
	SDL_Texture* playerTextureidle;

	//gun
	gun _gun;
	SDL_Texture* guntexture;

	//bullet
	vector<bullet> _bullet;
	vector<int> mousexbullet;
	vector<int> mouseybullet;
	vector<int> playerx;
	vector<int> playery;

	SDL_Texture* bulletTex;

	//enemy
	vector<enemy> _enemy;
	SDL_Texture* enemyBlow;
	SDL_Texture* enemyBlow2;
	SDL_Texture* enemyTex;
	
	//sound
	Mix_Music* gMusic;

	Mix_Chunk* bulletsound;
	Mix_Chunk* zombiesound;

	//MAIN RENDERER AND WINDOW
	SDL_Renderer* maingamerenderer;
	SDL_Window* maingamewindow;
};

