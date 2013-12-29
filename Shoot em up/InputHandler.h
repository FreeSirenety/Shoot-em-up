#pragma once

#include "SDL.h"

class Game;
class KeyboardInput;
class MouseInput;
class Collider;

class InputHandler
{
public:
	InputHandler(Game *game, KeyboardInput *keyboard, MouseInput *mouse);
	~InputHandler();

	void handleEvent();

	Collider *setMouseCollider();

	KeyboardInput *getKeyboard();

	MouseInput *getMouse();

private:
	SDL_Event *m_event;
	Game *m_game;

	KeyboardInput *m_keyboard;
	MouseInput *m_mouse;

	Collider *m_collider;
};