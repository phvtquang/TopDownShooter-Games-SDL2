#include "player.h"

player::player()
{
	
	//init player
	facingLeft = false;
	idle = true;

	//init idle animation clip
	frameClipIdle = 0;
	FRAME_Idle = 4;
	DELAY_Idle = 10;
	setClipIdle();

	//init moving animation clip
	frameClipMoving = 0; 
	FRAME_MOVING = 7;
	DELAY_MOVING = 7;
	setClipsMoving();

	//init start position
	px = 100;
	py = 100;

	//init destionation position
	playerdesRect = { 50,50,80,80 };
}

void player::MoveLeft()
{
	//facingLeft = true;
	idle = false;
	px -= playerconstants::WALK_SPEED;
	
}

void player::MoveRight()
{
	//facingLeft = false;
	idle = false;
	px += playerconstants::WALK_SPEED;
}

void player::MoveUp()
{
	idle = false;
	py -= playerconstants::WALK_SPEED;
}

void player::MoveDown()
{
	idle = false;
	py += playerconstants::WALK_SPEED;
}


void player::setClipsMoving()
{
	for (int i = 0; i < 7; i++)
	{
		clipsMOVING[i].x = i * 40;
		clipsMOVING[i].y = 0;
		clipsMOVING[i].w = 40;
		clipsMOVING[i].h = 40;
	}
}


void player::setClipIdle()
{
	for (int i = 0; i < 4; i++)
	{
		clipsIDLE[i].x = i * 40;
		clipsIDLE[i].y = 0;
		clipsIDLE[i].w = 40;
		clipsIDLE[i].h = 40;
	}
}



void player::getinput()
{
	const Uint8* key = SDL_GetKeyboardState(NULL);
	idle = true;
	if (key[SDL_SCANCODE_W]) {
		player::MoveUp();
		idle = false;

	}
	if (key[SDL_SCANCODE_A]) {
		player::MoveLeft();
		idle = false;
	}
	if (key[SDL_SCANCODE_D]) {

		player::MoveRight();
		idle = false;
	}
	if (key[SDL_SCANCODE_S]) {
		player::MoveDown();
		idle = false;
	}

	int mouseposx;
	int mouseposy;
	SDL_GetMouseState(&mouseposx, &mouseposy);
	if (mouseposx < playerdesRect.x)
	{
		facingLeft = true;
	}
	else
	{
		facingLeft = false;
	}
	
}

void player::setdesrect() {
	playerdesRect.x = px;
	playerdesRect.y = py;
}

void player::animationIDLE()
{
	frameClipIdle++;
	if (frameClipIdle >= FRAME_Idle * DELAY_Idle) frameClipIdle = 0;
	playersourceRect = clipsIDLE[frameClipIdle / DELAY_Idle];
}

void player::animationMOVING()
{
	frameClipMoving++;
	if (frameClipMoving >= FRAME_MOVING * DELAY_MOVING) frameClipMoving = 0;
	playersourceRect = clipsMOVING[frameClipMoving / DELAY_MOVING];
}

void player::playeranimation()
{
	setdesrect();
	if (idle == true) {
		animationIDLE();
	}
	else
	{
		animationMOVING();
	}
}

