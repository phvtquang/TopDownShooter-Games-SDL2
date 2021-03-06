#pragma once
#include "stdafx.h"

namespace playerconstants {
	const float WALK_SPEED = 5.0f;
}

class player
{
public:
	player();

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

	//get player moving input
	void getinput();

	//set destionation rectangle after moving (update px andd py)
	void setdesrect();

	//set animation clip
	void setClipsMoving();
	void setClipIdle();

	//set animation 
	void animationIDLE();
	void animationMOVING();
	void playerupdate();

	// "true" if player is facing left
	bool facingLeft;

	// "true" if player not moving
	bool idle;

	//PLAYER SOURCE AND DES RECT
	SDL_Rect playersourceRect;
	SDL_Rect playerdesRect;

	//current position
	int px, py;

private:
	

	//for moving animation
	int FRAME_MOVING; //7
	int DELAY_MOVING; // 7
	SDL_Rect clipsMOVING[7];

	//for idle animation
	int FRAME_Idle; //4
	int DELAY_Idle; //4
	SDL_Rect clipsIDLE[4];

	int frameClip; // ++ 

	
};

