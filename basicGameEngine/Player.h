#pragma once

// #include "GameObject.h"
// now player can inherint from SDLGameObject
#include "SDLGameObject.h"
#include "InputHandler.h"

class Player : public SDLGameObject {

public:

	// void load(int x, int y, int width, int height, std::string textureID);
	// void draw(SDL_Renderer* pRenderer);
	Player(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

private:

	void handleInput();
};