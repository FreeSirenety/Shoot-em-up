#pragma once

#include "Entity.h"
#include "Vector2.h"

class KeyboardInput;
class MouseInput;
class MovementPattern;

class Player : public Entity
{
public:
	Player();

	Player(Vector2 position, Vector2 size, ObjectType::Type type);

	virtual void updateCurrent(float deltaTime);

	void setMouseInput(MouseInput* input);

	void setKeyboardInput(KeyboardInput *input);

	void handleInput(KeyboardInput *keyboard, MouseInput *mouse);

private:
	KeyboardInput *m_keyboard;
	MouseInput *m_mouse;

	bool m_movingUp, m_movingDown;

	ObjectType::Type m_type;

	MovementPattern *pattern;
};