#include "RenderModule.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Texture.h"

RenderModule* RenderModule::Create(SDL_Window* aWindow, SDL_Renderer* aRenderer)
{
	RenderModule* drawer = new RenderModule(aWindow, aRenderer);

	if (!drawer->Init())
	{
		delete drawer;
		drawer = NULL;
	}

	return drawer;
}

RenderModule::RenderModule(SDL_Window* aWindow, SDL_Renderer* aRenderer)
	: myWindow(aWindow)
	, myRenderer(aRenderer)
{
}

RenderModule::~RenderModule(void)
{
}

bool RenderModule::Init()
{
	if (!myWindow)
		return false;

	return true;
}

SDL_Renderer* RenderModule::GetRenderer()
{
	return myRenderer;
}

void RenderModule::Draw(SDL_Texture* texture, int width, int height, int aCellX, int aCellY)
{
	SDL_Rect sizeRect;
	sizeRect.x = 0;
	sizeRect.y = 0;
	sizeRect.w = width;
	sizeRect.h = height;

	SDL_Rect posRect;
	posRect.x = aCellX;
	posRect.y = aCellY;
	posRect.w = sizeRect.w;
	posRect.h = sizeRect.h;

	SDL_RenderCopy(myRenderer, texture, &sizeRect, &posRect);
}

void RenderModule::DrawText(const char* aText, const char* aFontFile, int aX, int aY)
{
	TTF_Font* font = TTF_OpenFont(aFontFile, 24);

	SDL_Color fg = { 255,0,0,255 };
	SDL_Surface* surface = TTF_RenderText_Solid(font, aText, fg);

	SDL_Texture* optimizedSurface = SDL_CreateTextureFromSurface(myRenderer, surface);

	SDL_Rect sizeRect;
	sizeRect.x = 0;
	sizeRect.y = 0;
	sizeRect.w = surface->w;
	sizeRect.h = surface->h;

	SDL_Rect posRect;
	posRect.x = aX;
	posRect.y = aY;
	posRect.w = sizeRect.w;
	posRect.h = sizeRect.h;

	SDL_RenderCopy(myRenderer, optimizedSurface, &sizeRect, &posRect);
	SDL_DestroyTexture(optimizedSurface);
	SDL_FreeSurface(surface);
	TTF_CloseFont(font);
}

Texture RenderModule::LoadImage(const char* imageName)
{
	SDL_Surface* surface = IMG_Load(imageName);
	Texture textureData; 
	textureData.texture = SDL_CreateTextureFromSurface(myRenderer, surface);
	textureData.width = surface->w;
	textureData.height = surface->h;
	return textureData;
}
