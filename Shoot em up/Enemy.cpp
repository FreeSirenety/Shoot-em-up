#include "Enemy.h"

Enemy::Enemy()
{
	m_parent = nullptr;
	m_sprite = nullptr;
	m_collider = nullptr;

	m_velocity = Vector2(0, 0);
}

Enemy::Enemy(Vector2 position, Vector2 size, ObjectType::Type type)
{
	m_position = position;
	m_size = size;
	m_type = type;

	m_originalPosition = position;
	m_originalSize = size;

	m_parent = nullptr;
	m_sprite = nullptr;
	m_collider = nullptr;

	m_velocity = Vector2(0, 0);
}

void Enemy::setMovementPattern(EPattern pattern, float radious, Vector2 middlePoint)
{
	m_movePattern = new MovementPattern(radious, middlePoint);
}

void Enemy::setPatternSpeed(float speed)
{
	m_speed = speed;
}

void Enemy::updateCurrent(float deltaTime)
{
	m_position = m_movePattern->move(m_position, deltaTime, m_speed);
}

void Enemy::setPatternDirection(bool direction)
{
	m_movePattern->setDirection(direction);
}