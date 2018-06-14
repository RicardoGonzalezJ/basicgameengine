#pragma once

#include <SDL_image.h>
#include <string>
#include <map>

class TextureManager {

public:

	// load function. Parameters: image file name, id for the texture, renderer we want to use
	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	//draw
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//drawframe take two additional param current frame we want to draw and which row it is on in the sprite sheet
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// this method is to ensure that TM class cannot be create to another objects. 
	static TextureManager* getInstance() {

		if (s_pInstance == NULL)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}

		return s_pInstance;
	}

private:

	// Making TextureManager a Singleton class by set its constructor to private
	TextureManager() {}
	~TextureManager(){}

	//a variable to hold our once instance of the class TextureManager
	static TextureManager* s_pInstance;


	// m_texture key is a string id
	std::map<std::string, SDL_Texture*> m_textureMap;
};

// this is to call class through TheTextureManager. and no create an instance and call the object through getInstance method
typedef TextureManager TheTextureManager;