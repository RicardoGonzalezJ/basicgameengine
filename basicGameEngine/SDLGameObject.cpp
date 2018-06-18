#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"

// implementation
SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams), m_position(pParams->getX(), pParams->getY()) {
	
	// m_x = pParams->getX();
	// m_y = pParams->getY();
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();

	m_currentFrame = 1;
	m_currentRow = 1;
}

// use of our singleton Game class to get the renderer we want
void SDLGameObject::draw() {
	// TheTextureManager::getInstance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, TheGame::getInstance()->getRender());
	
	// using vector2d class
	TheTextureManager::getInstance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::getInstance()->getRender());

}

void SDLGameObject::update() {

}

void SDLGameObject::clean() {

}