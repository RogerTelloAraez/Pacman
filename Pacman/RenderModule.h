#ifndef _RENDERER_H_
#define _RENDERER_H_

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;
struct Texture;

class RenderModule
{
public:
	static RenderModule* Create(SDL_Window* aWindow, SDL_Renderer* aRenderer);
	RenderModule(SDL_Window* aWindow, SDL_Renderer* aRenderer);
	~RenderModule(void);

	SDL_Renderer* GetRenderer();
	void Draw(SDL_Texture* texture, int width, int height, int aCellX = 0, int aCellY = 0);
	void DrawText(const char* aText, const char* aFontFile, int aX, int aY);

	Texture LoadImage(const char* imageName);

private:
	bool Init();

	SDL_Window* myWindow;
	SDL_Renderer* myRenderer;
};

#endif 

