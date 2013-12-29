#pragma once

#include "Vector2.h"
#include "State.h"

class Button;
class MouseInput;
class Sprite;
class DrawManager;
class StateManager;
class GameObject;
class SpriteManager;

enum MenuButtons
{
	PLAYGAME,
	HIGHSCORE,
	OPTIONS,
	EXIT,
	COUNT
};

class MenuState : public State
{
public:
	MenuState(MouseInput *mouse, StateManager *manager, SpriteManager *spriteManager);

	~MenuState();

	void setButton(MenuButtons type, Sprite *sprite, Vector2 position, Vector2 size);

	void buttonAction(MenuButtons button);

	void update(float deltaTime);

	void isButtonPressed();

	void draw(DrawManager *manager);

	void addObject(GameObject *object);

	void pause();

	void exit();

	void initialize();

private:
	struct ButtonPair
	{
		MenuButtons m_type;
		Button *m_button;
	};

private:
	ButtonPair *m_buttons[COUNT];

	MouseInput *m_mouse;

	StateManager *m_stateManager;

	SpriteManager *m_spriteManager;
};