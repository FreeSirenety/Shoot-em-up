#include "Player.h"
#include "KeyboardInput.h"
#include "MouseInput.h"
#include "MovementPattern.h"

Player::Player()
{
	m_parent = nullptr;
	m_sprite = nullptr;
	m_collider = nullptr;

	m_velocity = Vector2(0, 0);
	pattern = new MovementPattern(100, Vector2(300, 300));
}

Player::Player(Vector2 position, Vector2 size, ObjectType::Type type)
{
	m_parent = nullptr;
	m_collider = nullptr;
	m_sprite = nullptr;

	m_position = position;
	m_size = size;
	m_originalPosition = position;
	m_originalSize = size;
	m_lastPosition = position;

	m_velocity = Vector2(0, 0);

	m_type = type;
}

void Player::updateCurrent(float deltaTime)
{
	/*handleInput(m_keyboard, m_mouse);
	if (m_movingDown && m_velocity.m_y < 200.f)
	{
		m_velocity.m_y += 100 * deltaTime;
	}

	if (m_movingUp && m_velocity.m_y > -200.f)
	{
		m_velocity.m_y += -100 * deltaTime;
	}

	m_position += m_velocity * deltaTime;*/

	MovementPattern *pattern = new MovementPattern(100, Vector2(300, 300));
	Vector2 newPos = pattern->move(getPosition(), deltaTime, 10000);
	m_position = newPos;
}

void Player::setMouseInput(MouseInput* input)
{
	m_mouse = input;
}

void Player::setKeyboardInput(KeyboardInput *input)
{
	m_keyboard = input;
}

void Player::handleInput(KeyboardInput *keyboard, MouseInput *mouse)
{
	if (keyboard->isDown('w'))
	{
		m_movingUp = true;
	}
	else 
	{
		m_movingUp = false;
	}

	if (keyboard->isDown('s'))
	{
		m_movingDown = true;
	}
	else
	{
		m_movingDown = false;;
	}
}