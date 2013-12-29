#include "KeyboardInput.h"

KeyboardInput::KeyboardInput()
{
	for (int i = 0; i < 256; i++)
	{
		m_current[i] = false;
		m_previous[i] = false;
	}
}

bool KeyboardInput::isDown(int key)
{
	return m_current[key];
}

bool KeyboardInput::isDownOnce(int key)
{
	return m_current[key] && !m_previous[key];
}

void KeyboardInput::postUpdate()
{
	for (int i = 0; i < 256; i++)
	{
		m_previous[i] = m_current[i];
	}
}