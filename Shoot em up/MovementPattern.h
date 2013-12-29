#pragma once

#define M_PI 3.141592653589793238462643383279

#include "Vector2.h"

enum EPattern
{
	SQUARE,
	CIRCLE,
	LINE,
	NONE
};

class MovementPattern
{
public:
	MovementPattern(float height, float width, Vector2 middlePoint);
	MovementPattern(float radious, Vector2 middlePoint);

	Vector2 move(Vector2 currentPos, float deltaTime, float speed);

	Vector2 circlePattern(float radious, Vector2 middlePoint, Vector2 currentPos, float deltaTime, float speed);
	Vector2 rectanglePattern(float height, float width, Vector2 middlePoint, Vector2 currentPos, float deltaTime, float speed);

	void setDirection(bool direction);
	bool getDirection();

private:
	bool m_direction;

	float m_height;
	float m_width;

	float m_radious;

	bool m_isCircle;

	Vector2 m_middlePoint;
};