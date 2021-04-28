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
	game();
	void init(int SCREEN_WIDTH, int SCREEN_HEIGHT, Uint32 flags);	
	void showmenu();
	void draw();
	void gameloop();
	

private:

	long long health;
	long long score;

	//mouse pos && angle for gun and bullet
	double angle;
	int mouseposx;
	int mouseposy;
	bool mousedown;
	int delaybullet;

	//menu
	SDL_Texture* menu;
	

	//map
	SDL_Texture* map;
	SDL_Texture* wall;
	SDL_Rect mapRECT;

	//camera RECT
	SDL_Rect cameraRect;

	//player 
	player _player;
	SDL_Texture* playerTexture;
	SDL_Texture* playerTextureidle;

	//gun
	gun _gun;
	SDL_Texture* guntexture;

	//bullet
	vector<bullet> _bullet;
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
	Mix_Chunk* enemyblow;

	//font and text
	SDL_Color textColor;
	SDL_Surface* textSurface;
	SDL_Texture* mTexture;
	string textureText;
	SDL_Rect scoreBOX;
	TTF_Font* gFont;

	//healthbar
	SDL_Texture* HEALTHBARTexture;
	SDL_Rect healthbardesrect;
	SDL_Rect healthbarsourcerect;
	
	
	//heart
	SDL_Texture* heart;
	SDL_Rect heartRect;
	int healbox;

	//MAIN RENDERER AND WINDOW
	SDL_Renderer* maingamerenderer;
	SDL_Window* maingamewindow;
};

