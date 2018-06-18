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
	return 1; // something´s wrong
	}

	while (g_bRunning)
	{
	render();
	}

	// Clean up SDL
	SDL_Quit();*/
	AllocConsole();
	freopen("CON", "w", stdout);


	// commented due Game is a singleton now
	// g_game = new Game();

	if (TheGame::getInstance()->init("Chapter 1", 100, 100, 640, 480, SDL_WINDOW_SHOWN))
	{
		std::cout << "game init success\n";
		while (TheGame::getInstance()->running())
		{
			TheGame::getInstance()->handleEvents();
			TheGame::getInstance()->update();
			TheGame::getInstance()->render();

			SDL_Delay(50); //add the Delay
		}
	}
	else
	{
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}
	
	// g_game->init("Chapter 1", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

	std::cout << "game closing...\n";
	TheGame::getInstance()->clean();

	return 0;
}