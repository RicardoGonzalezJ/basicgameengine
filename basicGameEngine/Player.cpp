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

void Player::handleInput() {

	/*if (TheInputHandler::Instance()->joysticksInitialized())
	{
		if (TheInputHandler::Instance()->xvalue(0, 1) > 0 ||
			TheInputHandler::Instance()->xvalue(0, 1) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0,
				1));
		}
		if (TheInputHandler::Instance()->yvalue(0, 1) > 0 ||
			TheInputHandler::Instance()->yvalue(0, 1) < 0)
		{
			m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0,
				1));
		}
		if (TheInputHandler::Instance()->xvalue(0, 2) > 0 ||
			TheInputHandler::Instance()->xvalue(0, 2) < 0)
		{
			m_velocity.setX(1 * TheInputHandler::Instance()->xvalue(0,
				2));
		}
		if (TheInputHandler::Instance()->yvalue(0, 2) > 0 ||
			TheInputHandler::Instance()->yvalue(0, 2) < 0)
		{
			m_velocity.setY(1 * TheInputHandler::Instance()->yvalue(0,
				2));
		}

		if (TheInputHandler::Instance()->getButtonState(0, 3))
		{
			m_velocity.setX(1);
		}
	}*/

	// using mouse
	/*if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(-1);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;*/

	// using keyboard 
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}

}

void Player::update() {
	// m_x -= 1;
	// m_position.setX(m_position.getX() - 1);
	// m_position.setY(m_position.getY() + 1);
	m_velocity.setX(0);
	m_velocity.setY(0);

	handleInput(); // add our function

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	// m_velocity.setX(-1);
	// m_acceleration.setX(-1);

	SDLGameObject::update();
}

void Player::clean() {

}