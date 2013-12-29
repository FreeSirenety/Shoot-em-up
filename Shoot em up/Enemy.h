#pragma once

#include "Vector2.h"

#include "Entity.h"

#include "MovementPattern.h"

class Enemy : public Entity
{
public:
	Enemy();

	Enemy(Vector2 position, Vector2 size, ObjectType::Type type);

	void setMovementPattern(EPattern pattern, float radious, Vector2 middlePoint);

	void setPatternSpeed(float speed);

	void setPatternDirection(bool direction);

	virtual void updateCurrent(float deltaTime);


private:
	EPattern m_pattern;

	MovementPattern *m_movePattern;

	float m_speed;
};