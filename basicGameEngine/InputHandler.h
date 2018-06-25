#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler {

public:

	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	// joystick methods
	bool getButtonState(int joy, int buttonNumber)
	{
		return m_buttonStates[joy][buttonNumber];
	}
	void initializeJoysticks();
	bool joysticksInitialized() { return m_bJoysticksInitialized; }
	int xvalue(int joy, int stick);
    int yvalue(int joy, int stick);

	// mouse methods
	bool getMouseButtonState(int buttonNumber)
	{
		return m_mouseButtonStates[buttonNumber];
	}
	Vector2D* getMousePosition()
	{
		return m_mousePosition;
	}

	// keyboard function
	bool isKeyDown(SDL_Scancode key);

	void update();
	void clean();


private:

	InputHandler();
	~InputHandler() {}

	static InputHandler* s_pInstance;

	// Joystick variables
	std::vector<std::vector<bool>> m_buttonStates;
	const int m_joystickDeadZone = 10000;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
	std::vector<SDL_Joystick*> m_joysticks;
	bool m_bJoysticksInitialized;

	// mouse variables
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;

	// keyboard variable
	const Uint8* m_keystates;

	// keyboard functions for handle events
	void onKeyDown();
	void onKeyUp();
};

typedef InputHandler TheInputHandler;