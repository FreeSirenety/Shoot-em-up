#pragma once

#include "Vector2.h"

class Collider
{
public:
	Collider();

	Collider(const Vector2 &position, const Vector2 &extension);

	bool overlap(const Collider &other);

	Vector2 m_position;
	Vector2 m_extension;
};