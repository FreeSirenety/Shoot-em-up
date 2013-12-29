#include "Collider.h"
#include <cmath>

Collider::Collider() 
	: m_position(0.f, 0.f)
	, m_extension(0.f, 0.f)
{

}

Collider::Collider(const Vector2 &position, const Vector2 &extension) : m_position(position), m_extension(extension)
{

}

bool Collider::overlap(const Collider &other)
{
	float A = m_extension.m_x * 0.5;
	float B = other.m_extension.m_x * 0.5f;
	float C = (m_position.m_x + A) - (other.m_position.m_x + B);

	if (fabs(C) < A + B)
	{
		float Q = m_extension.m_y * 0.5f;
		float P = other.m_extension.m_y * 0.5f;
		float Z = (m_position.m_y + Q) - (other.m_position.m_y + P);
		if (fabs(Z) < Q + P )
		{
			return true;
		}
	}

	return false;
}