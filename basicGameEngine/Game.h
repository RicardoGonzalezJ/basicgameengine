#pragma once
#ifndef __Game__
#define __Game__

#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

class Game
{
public:
	Game() {};
	~Game() {};

	// Simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	void render();
	void update();
	void handleEvents();
	void clean();

	// a function to access the private m_bRunning variable
	bool running() { return m_bRunning; }

private:

	SDL_Window* m_pWindow = NULL;
	SDL_Renderer* m_pRenderer = NULL;

	int m_currentFrame;
	// TextureManager m_textureManager;

	/*SDL_Texture* m_pTexture; // the new SDL_TEXTURE variable
	SDL_Rect m_sourceRectangle; // the first rectangle
	SDL_Rect m_destinationRectangle; // another rectangle*/

	bool m_bRunning;
};
#endif /* defined(__Game__) */
