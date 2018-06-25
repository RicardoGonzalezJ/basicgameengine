#pragma once
#ifndef __Game__
#define __Game__

#include <SDL.h>
// #include <SDL_image.h>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "GameStateMachine.h"
// #include "Player.h"

class Game
{
public:
	
	~Game() {};

	// Simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	void render();
	void update();
	void handleEvents();
	void clean();

	// method that return our render. the draw function does not have that habiity anymore-C3. using abstract classes
	SDL_Renderer* getRender() const { return m_pRenderer; }

	// a function to access the private m_bRunning variable
	bool running() { return m_bRunning; }
	void quit() { m_bRunning = false;  }

	// this method is to ensure that Game class cannot be create to another objects. Singleton
	static Game* getInstance() {

		if (s_pInstance == NULL)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}

		return s_pInstance;
	}
	

private:

	Game() {};

	SDL_Window* m_pWindow = NULL;
	SDL_Renderer* m_pRenderer = NULL;

	int m_currentFrame;
	// TextureManager m_textureManager;

	/*SDL_Texture* m_pTexture; // the new SDL_TEXTURE variable
	SDL_Rect m_sourceRectangle; // the first rectangle
	SDL_Rect m_destinationRectangle; // another rectangle*/

	bool m_bRunning;
	// using Player.h
	/*GameObject m_go;
	Player m_player;*/

	// declaring an array of GameObjects for manage GaObs no matter what type is belong to
	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	GameObject* m_enemy2;
	std::vector<GameObject*> m_gameObjects;

	//a variable to hold our once instance of the class TextureManager
	static Game* s_pInstance;

	// gameStateMachine
	GameStateMachine* m_pGameStateMachine;
	
	
};

typedef Game TheGame;
#endif /* defined(__Game__) */
