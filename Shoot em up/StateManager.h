#pragma once

#include <map>

class DrawManager;
class InputHandler;
class State;

class StateManager
{

public:

	enum CurrentState
	{
		GAME,
		MENU,
		OPTION,
		PAUSE,
	};

	enum StateChange
	{
		FREEZE,
		EXIT
	};

public:
	StateManager(InputHandler *inputHandler);

	void addState(CurrentState currentState, State *state);

	void setCurrentState(CurrentState state);
	CurrentState getCurrentState();

	void changeCurrentState(CurrentState state, StateChange change);

	void updateCurrentState(float deltaTime);

	void drawCurrentState(DrawManager *manager);

private:
	std::map<CurrentState, State*> m_states;

	InputHandler *m_inputHandler;

	CurrentState m_currentState;
};