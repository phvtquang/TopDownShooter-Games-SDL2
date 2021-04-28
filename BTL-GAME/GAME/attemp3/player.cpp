#include "player.h"

player::player()
{
	//init player
	facingLeft = false;
	idle = true;
	frameClip = 0;

	//init idle animation clip
	FRAME_Idle = 4;
	DELAY_Idle = 10;
	setClipIdle();

	//init moving animation clip
	FRAME_MOVING = 7;
	DELAY_MOVING = 7;
	setClipsMoving();

	//init start position
	px = SCREEN_WIDTH / 2;
	py = SCREEN_HEIGHT / 2;

	//init destionation position
	playerdesRect = {px,py,80,80 };
}

void player::setClipsMoving()
{
	for (int i = 0; i < FRAME_MOVING; i++)
	{
		clipsMOVING[i].x = i * 40;
		clipsMOVING[i].y = 0;
		clipsMOVING[i].w = 40;
		clipsMOVING[i].h = 40;
	}
}


void player::setClipIdle()
{
	for (int i = 0; i < FRAME_Idle; i++)
	{
		clipsIDLE[i].x = i * 40;
		clipsIDLE[i].y = 0;
		clipsIDLE[i].w = 40;
		clipsIDLE[i].h = 40;
	}
}

void player::animationIDLE()
{
	frameClip++;
	if (frameClip >= FRAME_Idle * DELAY_Idle) frameClip = 0;
	playersourceRect = clipsIDLE[frameClip / DELAY_Idle];
}

void player::animationMOVING()
{
	frameClip++;
	if (frameClip >= FRAME_MOVING * DELAY_MOVING) frameClip = 0;
	playersourceRect = clipsMOVING[frameClip / DELAY_MOVING];
}

void player::MoveLeft()
{
	idle = false;
	px -= playerconstants::WALK_SPEED;
}

void player::MoveRight()
{
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
}

void player::setdesrect() {
	playerdesRect.x = px;
	playerdesRect.y = py;
}

void player::playerupdate()
{
	//update player position
	setdesrect();
	//update player facing based on mouse position
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

