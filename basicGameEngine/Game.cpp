#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>


bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
	
	std::cout << "bool init start\n";
	//attend to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0)
		{
			std::cout << "Window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);


			}
			else
			{
				std::cout << "renderer init fail\n";
				return false;
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false;
		}
	}
	else
	{
		std::cout << "window init fail\n";
		return false;
	}

	std::cout << "init success\n";

	m_bRunning = true; // everything inited successfully, start the main loop

	// loading image using the texture manager
	// m_textureManager.load("assets/animate-alpha.png", "animate", m_pRenderer);

	// loading image using the texture manager as singleton
	if (!TheTextureManager::getInstance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
	{
		return false;
	}

	if (!TheTextureManager::getInstance()->load("assets/helicopter.png", "helicopter", m_pRenderer))
	{
		return false;
	}

	if (!TheTextureManager::getInstance()->load("assets/arabic_guy_example.png", "enemy", m_pRenderer))
	{
		return false;
	}

	
	// using gameObject class
	// m_go.load(100, 100, 128, 82, "animate");
	// m_player.load(300, 100, 128, 55, "helicopter");

	// using GameObject array
	m_go = new GameObject();
	m_player = new Player();
	m_enemy = new Enemy();
	m_enemy2 = new Enemy();

	m_go->load(100, 100, 128, 82, "animate");
	m_player->load(300, 100, 128, 55, "helicopter");
	m_enemy->load(0, 0, 80, 137, "enemy");
	m_enemy2->load(0, 0, 128, 82, "animate");

	m_gameObjects.push_back(m_go);
	m_gameObjects.push_back(m_player);
	m_gameObjects.push_back(m_enemy);
	m_gameObjects.push_back(m_enemy2);


    // using with SDL_loadBMP
	/*SDL_Surface* pTempSurface = SDL_LoadBMP("assets/animate.bmp");
	if (pTempSurface == 0)
	{
		std::cout << "there is not image loaded..." << SDL_GetError();
	}*/

	// With SDL_image
	/*SDL_Surface* pTempSurface = IMG_Load("assets/animate-alpha.png");
	if (pTempSurface == NULL)
	{
		std::cout << "there is not image loaded..." << SDL_GetError();
	}
	
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

	SDL_FreeSurface(pTempSurface);

	m_sourceRectangle.w = 128;
	m_sourceRectangle.h = 82;

	m_destinationRectangle.x = m_sourceRectangle.x;
	m_destinationRectangle.y = m_sourceRectangle.y;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;*/

	/*if (SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h) < 0)
	{
	std::cout << "SDL_QueryTexture failed. error: %s" << SDL_GetError() << std::endl;
	}
	else {
	//m_sourceRectangle.x = 50;
	// m_sourceRectangle.y = 50;
	m_destinationRectangle.x = m_sourceRectangle.x = 0;
	m_destinationRectangle.y = m_sourceRectangle.y = 0;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;

	}*/

	return true;

}

void Game::render() {
	SDL_RenderClear(m_pRenderer); // clear the render to the draw color

	// SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);

	// Using the textureManager
	// m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
   // m_textureManager.drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);

	// Using the TextureManager as a Singleton class
	/*TheTextureManager::getInstance()->draw("animate", 0, 0, 128, 82, m_pRenderer);

	TheTextureManager::getInstance()->draw("helicopter", 100, 00, 128, 55, m_pRenderer);


	TheTextureManager::getInstance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);
	TheTextureManager::getInstance()->drawFrame("helicopter", 200, 100, 128, 55, 1, m_currentFrame, m_pRenderer);*/

	// using gameObject Class
	// m_go.draw(m_pRenderer);
	// m_player.draw(m_pRenderer);

	// using gameObject array
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(m_pRenderer);
	}

	//for flipping the image 
	// SDL_RenderCopyEx(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_VERTICAL); // pass the horizontal flipping

	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_QUIT:
			m_bRunning = false;
			break;

		default:
			break;
		}
	}
}

void Game::update() {
	//  m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));

	 // using the TextureManager class
	 // m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	// m_go.update();
	// m_player.update();

	// using gameObject array
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
};