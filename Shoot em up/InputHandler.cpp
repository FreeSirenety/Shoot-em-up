#include "InputHandler.h"

#include "Game.h"
#include "KeyboardInput.h"
#include "MouseInput.h"
#include "Collider.h"

InputHandler::InputHandler(Game *game, KeyboardInput *keyboard, MouseInput *mouse)
{
	m_event = new SDL_Event;
	m_game = game;
	m_keyboard = keyboard;
	m_mouse = mouse;
	m_collider = nullptr;
}

void InputHandler::handleEvent()
{
	while (SDL_PollEvent(m_event))
	{
		if(m_event -> type == SDL_QUIT)
		{
			m_game->setRunning(false);
		}

		if(m_event -> type == SDL_KEYDOWN)
		{
			int index = m_event->key.keysym.sym & 0xFF;
			m_keyboard->m_current[index] = true;
			break;
		}

		if(m_event -> type == SDL_KEYUP)
		{
			int index = m_event->key.keysym.sym & 0xFF;
			m_keyboard->m_current[index] = false;
			break;
		}

		if(m_event -> type == SDL_MOUSEMOTION)
		{
			m_mouse->m_x = m_event->motion.x;
			m_mouse->m_y = m_event->motion.y;
			break;
		}

		if(m_event -> type == SDL_MOUSEBUTTONDOWN)
		{
			if (m_event->button.button == SDL_BUTTON_LEFT)
			{
				m_mouse->m_current[EMouseButton::MB_LEFT] = true;
			}
			if (m_event->button.button == SDL_BUTTON_RIGHT)
			{
				m_mouse->m_current[EMouseButton::MB_RIGHT] = true;
			}
		}

		if(m_event -> type == SDL_MOUSEBUTTONUP)
		{
			if (m_event->button.button == SDL_BUTTON_LEFT)
			{
				m_mouse->m_current[EMouseButton::MB_LEFT] = false;
			}
			if (m_event->button.button == SDL_BUTTON_RIGHT)
			{
				m_mouse->m_current[EMouseButton::MB_RIGHT] = false;
			}
		}

	}

}

InputHandler::~InputHandler()
{
	delete m_event;
	m_event = nullptr;
}

Collider *InputHandler::setMouseCollider()
{
	if (m_mouse->m_current[EMouseButton::MB_LEFT] && m_collider == nullptr)
	{
		m_collider = new Collider(Vector2(m_mouse->m_x, m_mouse->m_y), Vector2(0, 0));
	}
	else if (m_mouse->m_current[EMouseButton::MB_LEFT] == false && m_collider != nullptr)
	{
		delete m_collider;
		m_collider = nullptr;
	}

	return m_collider;
}

KeyboardInput *InputHandler::getKeyboard()
{
	return m_keyboard;
}

MouseInput *InputHandler::getMouse()
{
	return m_mouse;
}