#include "InputHandler.h"
#include "Game.h"
#include <iostream>

// implementation
InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler() : m_mousePosition (new Vector2D(0,0))
{
	for (int  i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
}


void InputHandler::initializeJoysticks() {

	std::cout << "Initializing joysticks... \n";

	if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);
	}

	if (SDL_NumJoysticks() > 0)
	{
		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			SDL_Joystick* joy = SDL_JoystickOpen(i);
			if (SDL_JoystickOpen(i))
			{
				m_joysticks.push_back(joy);
				m_joystickValues.push_back(std::make_pair(new Vector2D(0, 0), new Vector2D(0, 0))); // add our pair
				std::cout << "push_back joys\n";

				std::vector<bool> tempButtons;

				for (int j = 0; j < SDL_JoystickNumButtons(joy); j++)
				{
					tempButtons.push_back(false);

				}

				m_buttonStates.push_back(tempButtons);
			}
			else
			{
				std::cout << "Error init joystick: " << SDL_GetError() << "\n";
			}
		}
		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoysticksInitialized = true;

		std::cout << "Initialised " << m_joysticks.size() << " joystick(s)";
	}
	else
	{
		m_bJoysticksInitialized = false;
	}
}

void InputHandler::update() {

	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		m_keystates = SDL_GetKeyboardState(0);

		if (event.type == SDL_QUIT)
		{
			TheGame::getInstance()->quit();
		}

		if (event.type == SDL_JOYAXISMOTION)
		{
			int whichOne = event.jaxis.which;

			// left stick move left or right
			if (event.jaxis.axis == 0)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setX(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setX(-1);
				}
				else
				{
					m_joystickValues[whichOne].first->setX(0);
				}
			}// end left stick move l-r

			 // left stick move up or down
			if (event.jaxis.axis == 1)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setY(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setY(-1);
				}
				else
				{
					m_joystickValues[whichOne].second->setY(0);
				}
			}// left stick move u-d

			 // right stick move left or right
			if (event.jaxis.axis == 3)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setX(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].first->setX(-1);
				}
				else
				{
					m_joystickValues[whichOne].first->setX(0);
				}
			}// end left stick move l-r

			 // right stick move up or down
			if (event.jaxis.axis == 4)
			{
				if (event.jaxis.value > m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setY(1);
				}
				else if (event.jaxis.value < -m_joystickDeadZone)
				{
					m_joystickValues[whichOne].second->setY(-1);
				}
				else
				{
					m_joystickValues[whichOne].second->setY(0);
				}
			}// end rigth stick move u-d

		} // endo of SDL_JOYAXISMOTION

		// listening button events
		if (event.type == SDL_JOYBUTTONDOWN)
		{
			int whichOne = event.jaxis.which;
			m_buttonStates[whichOne][event.jbutton.button] = true;
		}
		if (event.type == SDL_JOYBUTTONUP)
		{
			int whichOne = event.jaxis.which;
			m_buttonStates[whichOne][event.jbutton.button] = false;
		} // SDL_JOYBUTTONDOWN

		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = true;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = true;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = true;
			}
		}// end of SDL_MOUSEBUTTONDOWN

		if (event.type == SDL_MOUSEBUTTONUP)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				m_mouseButtonStates[LEFT] = false;
			}
			if (event.button.button == SDL_BUTTON_MIDDLE)
			{
				m_mouseButtonStates[MIDDLE] = false;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				m_mouseButtonStates[RIGHT] = false;
			}
		}// end of SDL_MOUSEBUTTONDOWN

		if (event.type == SDL_MOUSEMOTION)
		{
			m_mousePosition->setX(event.motion.x);
			m_mousePosition->setY(event.motion.y);
		}
	} // end of while loop
}

void InputHandler::clean() {

	if (m_bJoysticksInitialized)
	{
		for (unsigned int i = 0; i < SDL_NumJoysticks(); ++i) {
			
			SDL_JoystickClose(m_joysticks[i]);
		}
	}
}

int InputHandler::xvalue(int joy, int stick) {

	if (m_joystickValues.size() > 0)
	{
		if (stick == 1)
		{
			return m_joystickValues[joy].first->getX();
		}
		else if (stick == 2)
		{
			return m_joystickValues[joy].second->getX();

		}
	}
	return 0;
}

int InputHandler::yvalue(int joy, int stick)
{
	if (m_joystickValues.size() > 0)
	{
		if (stick == 1)
		{
			return m_joystickValues[joy].first->getY();
		}
		else if (stick == 2)
		{
			return m_joystickValues[joy].second->getY();
		}
	}
	return 0;
}

bool InputHandler::isKeyDown(SDL_Scancode key) 
{
	if (m_keystates != 0)
	{
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}

	return false;
}