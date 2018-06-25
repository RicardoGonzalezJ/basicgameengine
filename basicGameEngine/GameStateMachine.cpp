#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* pStates)
{
	m_gameStates.push_back(pStates);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}

void GameStateMachine::changeState(GameState* pStates)
{
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->getStateID() == pStates->getStateID())
		{
			return; // do nothing
		}

		if (m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}

	// push back our new state
	m_gameStates.push_back(pStates);

	// initialise it
	m_gameStates.back()->onEnter();
}