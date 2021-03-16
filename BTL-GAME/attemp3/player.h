#pragma once
#include "stdafx.h"

namespace playerconstants {
	const float WALK_SPEED = 2.0f;
}

class player
{
public:
	player();
	SDL_Rect getplayersourceRect();

	/* void MoveLeft
	 * Moves the player left by -dx
	 */
	void MoveLeft();

	/* void moveRight
	 * Moves the player right by dx
	 */
	void MoveRight();

	/* void moveUp
	 * Moves the player up by dy
	 */
	void MoveUp();

	/* void moveDown
	 * Moves the player down by dy
	 */
	void MoveDown();

	void setdesrect();

	//set animation clip
	void setClipsMoving();
	void setClipIdle();

	void getinput();

	void animationIDLE();
	void animationMOVING();
	void playeranimation();
	bool facingLeft;
	bool idle;

	SDL_Rect playersourceRect;
	SDL_Rect playerdesRect;

private:
	//current position
	float px, py;

	//souceRect
	


	// "true" if player is facing left
	

	// "true" if player not moving
	

	//for moving animation
	int frameClipMoving; // ++
	int FRAME_MOVING; //7
	int DELAY_MOVING; // 7
	SDL_Rect clipsMOVING[7];

	//for idle animation
	int frameClipIdle; // ++ 
	int FRAME_Idle; //4
	int DELAY_Idle; //4
	SDL_Rect clipsIDLE[4];

	
};

