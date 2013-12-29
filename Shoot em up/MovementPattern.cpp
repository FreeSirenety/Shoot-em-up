#include "MovementPattern.h"
#include <cmath>
#include <iostream>

MovementPattern::MovementPattern(float height, float width, Vector2 middlePoint)
{
	m_height = height;
	m_width = width;
	m_middlePoint = middlePoint;
	m_isCircle = false;
	m_direction = true;
}

MovementPattern::MovementPattern(float radious, Vector2 middlePoint)
{
	m_radious = radious;
	m_middlePoint = middlePoint;
	m_isCircle = true;
	m_direction = true;
}

Vector2 MovementPattern::move(Vector2 currentPos, float deltaTime, float speed)
{
	if (m_isCircle)
	{
		return circlePattern(m_radious, m_middlePoint, currentPos, deltaTime, speed);
	}
	else
	{

	}
}

Vector2 MovementPattern::circlePattern(float radious, Vector2 middlePoint, Vector2 currentPos, float deltaTime, float speed)
{
	Vector2 radiouscheck;
	Vector2 movement;
	radiouscheck.m_x = (m_middlePoint.m_x - currentPos.m_x);
	radiouscheck.m_y = (m_middlePoint.m_y - currentPos.m_y);

	float circleSize = m_radious * m_radious * M_PI;
	float travelSpeed = circleSize / speed;

	if (radiouscheck.length() > m_radious + 0.002 + travelSpeed * deltaTime)
	{

		radiouscheck.normalize();

		middlePoint = currentPos + radiouscheck * m_radious;
			
		//middlePoint.m_x += radiouscheck.m_x * deltaTime * travelSpeed / 100;
		//middlePoint.m_y += radiouscheck.m_y * deltaTime * travelSpeed / 100;
	}
	else if (radiouscheck.length() < m_radious - 0.002 - travelSpeed * deltaTime)
	{
		radiouscheck.normalize();

		middlePoint = currentPos + radiouscheck * m_radious;
			
		//middlePoint.m_x -= radiouscheck.m_x * deltaTime * travelSpeed / 100;
		//middlePoint.m_y -= radiouscheck.m_y * deltaTime * travelSpeed / 100;
	}
		
		
	float travelAngle = travelSpeed * deltaTime / circleSize * 360;

	if (!m_direction)
	{
		travelAngle = 0 - travelAngle;
	}

	float dx = currentPos.m_x - middlePoint.m_x;
	float dy = currentPos.m_y - middlePoint.m_y;

	Vector2 currentPosition(dx, dy);

	currentPosition.normalize();
	currentPosition *= m_radious;
	currentPosition += middlePoint;

	float angle = (atan2f(dy, dx) + M_PI) * 180 / M_PI;
	float newAngle = angle + travelAngle;
		
	float newDX = -cosf(newAngle / 180 * M_PI);
	float newDY = -sinf(newAngle / 180 * M_PI);

	Vector2 newPos = (Vector2(newDX, newDY) * m_radious) + middlePoint;
	movement += newPos - currentPosition;

	Vector2 actualPosition = movement + currentPos;

	if (actualPosition.length() < m_radious + 1 && actualPosition.length() > m_radious - 1)
	{
		actualPosition.normalize();
		actualPosition *= m_radious;
	}

	return actualPosition;
}

Vector2 MovementPattern::rectanglePattern(float height, float width, Vector2 middlePoint, Vector2 currentPos, float deltaTime, float speed)
{
	float size = height * 2 + width * 2;
	float travelSpeed = size / speed;

	return Vector2(0, 0);
}

void MovementPattern::setDirection(bool direction)
{
	m_direction = direction;
}

bool MovementPattern::getDirection()
{
	return m_direction;
}