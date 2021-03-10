#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
using namespace std;

int main(int argc , char*args[])
{
	//init everything
	SDL_Init(SDL_INIT_EVERYTHING);
	//create window
	SDL_Window* window = NULL;
	window = SDL_CreateWindow("GAME WINDOW", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	//create a renderer for window
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);




	//Create a rect;
	SDL_Rect kn_rect;
	kn_rect.x = 0;
	kn_rect.y = 0;
	kn_rect.w = 64;
	kn_rect.h = 64;
	SDL_Rect kn_srect;
	kn_srect.x = 800-64;
	kn_srect.y = 600-64;
	kn_srect.w = 64;
	kn_srect.h = 64;



	//create texture
	SDL_Texture* texture = NULL;
	//create surface
	SDL_Surface* surface = NULL;
	//LOAD BMP
	surface = IMG_Load("Knight-Walk-Sheet.png");
	texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_Surface* surfaceright = NULL;
	SDL_Texture* textureright = NULL;
	surfaceright = IMG_Load("facingleft.png");
	textureright = SDL_CreateTextureFromSurface(renderer, surfaceright);

	//idle 
	SDL_Surface* surfaceidle = NULL;
	SDL_Texture* textureidle = NULL;
	surfaceidle = IMG_Load("Knight-Idle-Sheet.png");
	textureidle = SDL_CreateTextureFromSurface(renderer, surfaceidle);

	

	//loop flag
	bool quit = false;
	SDL_Event input;
	while (!quit)
	{
		while (SDL_PollEvent(&input) != 0)
		{
			if (input.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (input.type == SDL_KEYDOWN)
			{
				switch (input.key.keysym.sym)
				{
				case SDLK_LEFT:
				{
					SDL_RenderClear(renderer);
					if (kn_rect.x > 512-64-64)
					{
						kn_rect.x = 0;
					}
					else {
						kn_rect.x += 64;
					}
					if (kn_srect.x <= 0)
					{
						kn_srect.x = 800;
					}
					else {
						kn_srect.x -=7;
					}
					
					SDL_RenderCopy(renderer, texture, &kn_rect, &kn_srect);
					SDL_RenderPresent(renderer);
					break;
				}
					
				case SDLK_DOWN:
					
					break;
				case SDLK_RIGHT:
				{
					SDL_RenderClear(renderer);
					if (kn_rect.x > 512 - 64 - 64)
					{
						kn_rect.x = 0;
					}
					else {
						kn_rect.x += 64;
					}
					if (kn_srect.x <= 0)
					{
						kn_srect.x = 800;
					}
					else if(kn_srect.x >= 800 )
					{
						kn_srect.x = 0;
					}
					else {
						kn_srect.x += 7;
					}

					SDL_RenderCopy(renderer, textureright, &kn_rect, &kn_srect);
					SDL_RenderPresent(renderer);
					break;
				}
					
					
				case SDLK_UP:
					
					break;
				}

			}
		}
		//SDL_RenderCopy(renderer, textureidle ,&kn_rect, &kn_srect);
		//SDL_RenderPresent(renderer);
	}

	//destroy and clear renderer , end of program
	//Destroy the renderer created above
	SDL_DestroyRenderer(renderer);

	//Destroy the window created above
	SDL_DestroyWindow(window);

	//Close all the systems of SDL initialized at the top
	SDL_Quit();
	return 0;
}
