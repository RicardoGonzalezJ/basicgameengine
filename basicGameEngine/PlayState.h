#pragma once

#include "GameState.h"

class PlayState : public GameState
{
public:
	// PlayState();
	// ~PlayState();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	std::string getStateID() const { return s_playID; }

private:

	static std::string s_playID;

};

