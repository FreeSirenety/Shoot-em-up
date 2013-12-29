#pragma once

#include <vector>
#include "State.h"

class KeyboardInput;
class DrawManager;
class GameObject;
class StateManager;
class SpriteManager;
class Player;
class MouseInput;

class GameState : public State
{
public:
	GameState(KeyboardInput *input, MouseInput *mouseInput, StateManager *manager, SpriteManager *spriteManager);

	void update(float deltaTime);

	void draw(DrawManager *manager);

	void addObject(GameObject *object);

	void pause();

	void exit();

	void initialize();

private:
	KeyboardInput *m_keyboardInput;

	MouseInput *m_mouseInput;

	StateManager *m_stateManager;

	SpriteManager *m_spriteManager;

	Player *m_player;
};