#pragma once
// #include "GameObject.h"
// now enemy can inherint from SDLGameObject
#include "SDLGameObject.h"

class Enemy : public SDLGameObject {

public:

	// void load(int x, int y, int width, int height, std::string textureID);
	// void draw(SDL_Renderer* pRenderer);

	Enemy(const LoaderParams* pParams);
	~Enemy();

	virtual void draw();
	virtual void update();
	virtual void clean();

};