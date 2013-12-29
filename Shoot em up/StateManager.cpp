#include "StateManager.h"
#include "State.h"

StateManager::StateManager(InputHandler *inputHandler)
{
	m_inputHandler = inputHandler;
}

void StateManager::addState(CurrentState currentState, State *state)
{
	m_states.insert(std::pair<CurrentState, State *> (currentState, state));
}

void StateManager::setCurrentState(CurrentState state)
{
	m_currentState = state;
	m_states.find(m_currentState)->second->initialize();
}

StateManager::CurrentState StateManager::getCurrentState()
{
	return m_currentState;
}

void StateManager::changeCurrentState(CurrentState state, StateChange change)
{
	if (change == StateChange::FREEZE)
	{
		m_states.find(m_currentState)->second->pause();
	}
	else
	{
		m_states.find(m_currentState)->second->exit();
	}

	m_currentState = state;

	m_states.find(m_currentState)->second->initialize();
}

void StateManager::updateCurrentState(float deltaTime)
{
	m_states.find(m_currentState)->second->update(deltaTime);
}

void StateManager::drawCurrentState(DrawManager *manager)
{
	m_states.find(m_currentState)->second->draw(manager);
}