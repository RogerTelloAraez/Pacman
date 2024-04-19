#ifndef _TEXTURE_H
#define _TEXTURE_H

struct SDL_Texture;
struct Texture
{
	SDL_Texture* texture;
	int width;
	int height;
};

#endif // DRAWER_H