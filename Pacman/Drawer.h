#ifndef DRAWER_H
#define DRAWER_H

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

class Drawer
{
public:
	static Drawer* Create(SDL_Window* aWindow, SDL_Renderer* aRenderer);
	~Drawer(void);

	SDL_Renderer* GetRenderer();
	void Draw(SDL_Texture* texture, int width, int height, int aCellX = 0, int aCellY = 0);
	void DrawText(const char* aText, const char* aFontFile, int aX, int aY);

private:
	Drawer(SDL_Window* aWindow, SDL_Renderer* aRenderer);
	bool Init();
	
	SDL_Window* myWindow;
	SDL_Renderer* myRenderer;	
};

#endif // DRAWER_H