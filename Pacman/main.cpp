#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "assert.h"
#include "pacman.h"
#include "drawer.h"
#include <iostream>

int main(int argc, char **argv)
{
	/* initialize SDL */
	if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		assert(0 && "Failed to initialize video!");
		exit(-1);
	}
	
	SDL_Window* window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_OPENGL);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if(!window)
	{
		assert(0 && "Failed to create window!");
		exit(-1);
	}

	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	if (TTF_Init() == -1)
	{
		assert(0 && "Failed to create ttf!");
		exit(-1);
	}

	Drawer* drawer = Drawer::Create(window, renderer);
	Pacman* pacman = Pacman::Create(drawer);

	Uint32 frameStart = 0;
	Uint32 frameDuration = 0;
	const Uint32 expectedFrameDuration = 16; //62,5 FPS
	SDL_Event event;

	while (SDL_PollEvent(&event) >= 0)
	{

		frameStart = SDL_GetTicks();

		float deltaTime = static_cast<float>(frameDuration) / 1000;
		
		if (!pacman->Update(deltaTime))
			break;

		
		SDL_RenderClear(renderer);


		pacman->Draw();				

		SDL_RenderPresent(renderer);

		frameDuration = SDL_GetTicks() - frameStart;

		if (frameDuration < expectedFrameDuration)
		{
			Uint32 frameDelay = expectedFrameDuration - frameDuration;
			SDL_Delay(frameDelay);
			frameDuration = expectedFrameDuration;
		}
	}

	delete pacman;
	delete drawer;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit( );

	return 0;
}

