#pragma once

#include "GameState.h"

class GameStateMachine
{
public:
	// GameStateMachine();
	// ~GameStateMachine();

	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();

	// std::vector<GameState*>& getGameState() { return m_gameStates; }

private:

	std::vector<GameState*> m_gameStates;


};

