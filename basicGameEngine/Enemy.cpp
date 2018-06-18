#include "Enemy.h"

// Enemy class implementation using game object
/*void Enemy::load(int x, int y, int width, int height, std::string textureID) {

	GameObject::load(x, y, width, height, textureID);
}

void Enemy::draw(SDL_Renderer* pRenderer) {

	GameObject::draw(pRenderer);
}

void Enemy::update() {

	m_y += 1;
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	std::cout << "m_cF = " << m_currentFrame << std::endl;
}

void Enemy::clean() {

}*/

// Enemy class implementation using SDLGameObject
Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {

}

Enemy::~Enemy()
{
}

void Enemy::draw() {

	SDLGameObject::draw();
}
void Enemy::update() {

	// m_y += 1;
	// m_x += 1;

	//set x and y position using vector2d
	m_position.setX(m_position.getX() + 1);
	m_position.setY(m_position.getY() + 1);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	std::cout << "m_cF = " << m_currentFrame << std::endl;
}

void Enemy::clean() {

}