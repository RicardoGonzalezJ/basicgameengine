#include "Game.h"
#include <Windows.h>
#include <iostream>


/*SDL_Window* g_pWindow = NULL;
SDL_Renderer* g_pRenderer = NULL;

bool g_bRunning = false; // this is make a loop

bool init(const char* title, int xpos, int ypos, int width, int height, int flags) {
//initialize SDL
if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
{
// if suceeded create our window
g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

// if the window creation succeeded create our renderer
if (g_pWindow != 0)
{
g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
}

}
else
{
return false; // sdl could not initialize
}

return true;
}

void render() {
// set to black
SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);

// clear the window to black
SDL_RenderClear(g_pRenderer);

// Show the window
SDL_RenderPresent(g_pRenderer);
}*/

// our game Object
Game* g_game = NULL;

int main(int argc, char* argv[]) {
	/*if (init("Chapter 1: Setting up SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN))
	{
	g_bRunning = true;
	}
	else
	{
	return 1; // something�s wrong
	}

	while (g_bRunning)
	{
	render();
	}

	// Clean up SDL
	SDL_Quit();*/
	AllocConsole();
	freopen("CON", "w", stdout);

	g_game = new Game();

	g_game->init("Chapter 1", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}

	g_game->clean();

	return 0;
}