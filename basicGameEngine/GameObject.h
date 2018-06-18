#pragma once

#include <iostream>
#include <SDL.h>
#include "LoaderParams.h"


class GameObject {

public:

	// virtual is a keyword to allow polimorphims in derived class
	// virtual void load(int x, int y, int width, int height, std::string textureID);
	// virtual void draw(SDL_Renderer* pRenderer);
	// GameObject as a Abstract class 
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

protected:

	/*std::string m_textureID;

	int m_currentFrame;
	int m_currentRow;

	int m_x;
	int m_y;

	int m_width;
	int m_height;*/

	// constructor for loading Game objects parameters from LoaderParams class
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};