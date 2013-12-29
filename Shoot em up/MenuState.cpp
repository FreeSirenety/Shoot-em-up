#include "MenuState.h"
#include "Button.h"
#include "Collider.h"
#include "MouseInput.h"
#include <iostream>
#include "DrawManager.h"
#include "StateManager.h"
#include "SpriteManager.h"

MenuState::MenuState(MouseInput *mouse, StateManager *manager, SpriteManager *spriteManager)
{
	for (int i = 0; i < COUNT; i++)
	{
		m_buttons[i] = new ButtonPair();
		m_buttons[i]->m_type = (MenuButtons)i;
		m_buttons[i]->m_button = new Button();
	}

	m_mouse = mouse;
	m_stateManager = manager;
	m_spriteManager = spriteManager;
}

MenuState::~MenuState()
{
	for (int i = 0; i < COUNT; i++)
	{
		delete m_buttons[i]->m_button;
		m_buttons[i]->m_button = nullptr;

		delete m_buttons[i];
		m_buttons[i] = nullptr;
	}
}

void MenuState::setButton(MenuButtons type, Sprite *sprite, Vector2 position, Vector2 size)
{
	m_buttons[type]->m_button->setPosition(position);
	m_buttons[type]->m_button->setSize(size);

	m_buttons[type]->m_button->setSprite(sprite);

	Collider *collider = new Collider(position, size);

	m_buttons[type]->m_button->setCollider(collider);
}

void MenuState::buttonAction(MenuButtons button)
{
	switch (button)
	{
	case PLAYGAME:
		std::cout << "Playgame button" << std::endl;
		m_stateManager->changeCurrentState(StateManager::CurrentState::GAME, StateManager::StateChange::EXIT);
		break;
	case HIGHSCORE:
		std::cout << "Highscore button" << std::endl;
		break;
	case OPTIONS:
		std::cout << "Options button" << std::endl;
		break;
	case EXIT:
		std::cout << "Exit button" << std::endl;
		break;
	}
}

void MenuState::update(float deltaTime)
{
	isButtonPressed();
}

void MenuState::isButtonPressed()
{
	if (m_mouse->isDownOnce(EMouseButton::MB_LEFT))
	{
		Collider *collider = new Collider(Vector2(m_mouse->getX(), m_mouse->getY()), Vector2(0, 0));

		for (int i = 0; i < COUNT; i++)
		{
			if (m_buttons[i]->m_button->getCollider()->overlap(*collider))
			{
				buttonAction(m_buttons[i]->m_type);
				return;
			}
		}

		delete collider;
		collider = nullptr;
	}
	
}

void MenuState::draw(DrawManager *manager)
{
	for (int i = 0; i < COUNT; i++)
	{
		manager->draw(m_buttons[i]->m_button->getSprite(), &m_buttons[i]->m_button->getPosition(), m_buttons[i]->m_button->getSize());
	}
	
}

void MenuState::addObject(GameObject *object)
{
	m_objects.push_back(object);
}

void MenuState::pause()
{
	
}

void MenuState::exit()
{
	for (int i = 0; i < COUNT; i++)
	{
		delete m_buttons[i];
		m_buttons[i] = nullptr;
	}
}

void MenuState::initialize()
{
	for (int i = 0; i < COUNT; i++)
	{
		m_buttons[i] = new ButtonPair();
		m_buttons[i]->m_type = (MenuButtons)i;
		m_buttons[i]->m_button = new Button();
	}

	setButton(MenuButtons::PLAYGAME, m_spriteManager->load("airplane.png", 0, 0, 100, 100), Vector2(0, 0), Vector2(100, 100));
	setButton(MenuButtons::OPTIONS, m_spriteManager->load("airplane.png", 0, 0, 100, 100), Vector2(0, 150), Vector2(100, 100));
	setButton(MenuButtons::HIGHSCORE, m_spriteManager->load("airplane.png", 0, 0, 100, 100), Vector2(0, 300), Vector2(100, 100));
	setButton(MenuButtons::EXIT, m_spriteManager->load("airplane.png", 0, 0, 100, 100), Vector2(0, 450), Vector2(100, 100));
}