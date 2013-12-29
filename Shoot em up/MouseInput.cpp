#include "MouseInput.h"

MouseInput::MouseInput()
{
	m_x = 0;
	m_y = 0;
	
	for (int i = 0; i < MB_COUNT; i++)
	{
		m_current[i] = false;
		m_previous[i] = false;
	}
}

int MouseInput::getX() const
{
	return m_x;
}

int MouseInput::getY() const
{
	return m_y;
}

bool MouseInput::isDown(EMouseButton button) const
{
	return m_current[button];
}

bool MouseInput::isDownOnce(EMouseButton button) const
{
	return m_current[button] && !m_previous[button];
}

void MouseInput::postUpdate()
{
	for (int i = 0; i < MB_COUNT; i++)
	{
		m_previous[i] = m_current[i];
	}
}