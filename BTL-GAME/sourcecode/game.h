#pragma once
#include "stdafx.h"
#include "player.h"
#include "gun.h"
#include "enemy.h"
#include "bullet.h"
#include "misterybox.h"
class game
{
public :

	/*CREATE A GAME WINDOW AND A RENDERER FOR THAT WINDOW , PASSING IN THE WIDTH AND THE HEIGHT OF THAT WINDOW
	* FLAGS 1 for FULLSCREEN , 4 for SHOWN
	*/
	void init(int SCREEN_WIDTH, int SCREEN_HEIGHT, Uint32 flags);
	void loadMenuTexture();
	void loadMainTexture();
	void loadSound();
	void loadOtherTexture();
	void drawBOX();
	void drawmenu();
	void draw();
	void gamereset();
	void gameloop();
	
	

private:

	long long health;
	long long score;
	long long maxenemy;

	//mouse pos && angle for gun and bullet
	double angle;
	int mouseposx;
	int mouseposy;
	bool mousedown;
	int delaybullet;
	int boxcounter;

	SDL_Texture* misteryboxTex;
	SDL_Rect misteryboxRect;

	//main game running
	bool run = true;

	//if showing menu
	bool menu = true;

	//if gamer are playing the game
	bool playing = false;

	//make main character OP
	int op = 0;

	//if lose the game
	bool lose = false;

	//if how to play
	bool howtoplay = false;

	//first
	bool first = true;

	//open setting
	bool issetting;

	int sfxvolume = 128;

	int musicvolume = 128;

	int bossnum = 0;

	//menu
	SDL_Texture* menutex[20];
	SDL_Texture* resumemenu;
	SDL_Texture* rampagetex;
	SDL_Texture* gameover;
	SDL_Texture* gainhealthtexture;
	

	//map
	SDL_Texture* map;
	SDL_Texture* wall;
	SDL_Rect mapRECT;

	//camera RECT
	SDL_Rect cameraRect;

	//player 
	player _player;
	SDL_Texture* playerTexture;
	SDL_Texture* playerTexturerampage;
	SDL_Texture* playerTextureidle;
	SDL_Texture* playerTextureidlerampage;
	SDL_Texture* rampagegun;

	//gun
	gun _gun;
	SDL_Texture* guntexture;
	SDL_Rect rampagegundesRect;
	

	//bullet
	vector<bullet> _bullet;
	SDL_Texture* bulletTex;

	//enemy
	vector<enemy> _enemy;
	SDL_Texture* enemyDead;
	SDL_Texture* enemyBlow2;
	SDL_Texture* enemyTex;

	//box
	vector<misterybox> _misterybox;
	
	//sound
	Mix_Music* gMusic;
	Mix_Chunk* bulletsound;
	Mix_Chunk* zombiesound;
	Mix_Chunk* enemyblow;
	Mix_Chunk* menusound;
	Mix_Chunk* rampage;
	Mix_Chunk* gameoversound;
	Mix_Chunk* hitthebox;

	//font and text
	SDL_Color textColor;
	SDL_Surface* textSurface;
	SDL_Texture* mTexture;
	string scoreText;
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

