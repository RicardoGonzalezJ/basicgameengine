#include "Player.h"

// Player class implementation using game object
/*void Player::load(int x, int y, int width, int height, std::string textureID) {

	GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer) {

	GameObject::draw(pRenderer);
}

void Player::update() {
	m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean() {

}*/

// Player class implementation using SDLGameObject
Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {

}

void Player::draw() {

	SDLGameObject::draw(); 
}

void Player::update() {
	// m_x -= 1;
	m_position.setX(m_position.getX() - 1);
	// m_position.setY(m_position.getY() + 1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean() {

}