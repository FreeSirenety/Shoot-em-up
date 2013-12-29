#include "GameState.h"
#include "DrawManager.h"
#include "Sprite.h"
#include "GameObject.h"
#include "KeyboardInput.h"
#include "StateManager.h"
#include "Player.h"
#include "SpriteManager.h"
#include "MouseInput.h"
#include "Enemy.h"
#include "SDL.h"

GameState::GameState(KeyboardInput *keyboardInput, MouseInput *mouseInput, StateManager *manager, SpriteManager *spriteManager)
{
	m_keyboardInput = keyboardInput;
	m_mouseInput = mouseInput;
	m_stateManager = manager;
	m_spriteManager = spriteManager;

	m_player = new Player(Vector2(100, 100), Vector2(100, 100), ObjectType::PLAYER);
	m_player->setKeyboardInput(m_keyboardInput);
	m_player->setMouseInput(m_mouseInput);
	m_player->setSprite(m_spriteManager->load("airplane.png", 0, 0, 100, 100));
	addObject(m_player);

	Enemy *enemy = new Enemy(Vector2(800, 500), Vector2(30, 30), ObjectType::ENEMY);
	enemy->setSprite(m_spriteManager->load("airplane.png", 0, 0, 100, 100));
	enemy->setMovementPattern(EPattern::CIRCLE, 50, Vector2(800, 450));
	enemy->setPatternSpeed(3);
	addObject(enemy);

	Enemy *enemy2 = new Enemy(Vector2(800, 550), Vector2(30, 30), ObjectType::ENEMY);
	enemy2->setSprite(m_spriteManager->load("airplane.png", 0, 0, 100, 100));
	enemy2->setMovementPattern(EPattern::CIRCLE, 100, Vector2(800, 450));
	enemy2->setPatternSpeed(3);
	enemy2->setPatternDirection(false);
	addObject(enemy2);

	enemy = new Enemy(Vector2(800, 400), Vector2(30, 30), ObjectType::ENEMY);
	enemy->setSprite(m_spriteManager->load("airplane.png", 0, 0, 100, 100));
	enemy->setMovementPattern(EPattern::CIRCLE, 50, Vector2(800, 450));
	enemy->setPatternSpeed(3);
	addObject(enemy);

	enemy2 = new Enemy(Vector2(80, 350), Vector2(30, 30), ObjectType::ENEMY);
	enemy2->setSprite(m_spriteManager->load("airplane.png", 0, 0, 100, 100));
	enemy2->setMovementPattern(EPattern::CIRCLE, 100, Vector2(800, 450));
	enemy2->setPatternSpeed(3);
	enemy2->setPatternDirection(false);
	addObject(enemy2);

	enemy = new Enemy(Vector2(85, 450), Vector2(30, 30), ObjectType::ENEMY);
	enemy->setSprite(m_spriteManager->load("airplane.png", 0, 0, 100, 100));
	enemy->setMovementPattern(EPattern::CIRCLE, 50, Vector2(800, 450));
	enemy->setPatternSpeed(3);
	addObject(enemy);

	enemy2 = new Enemy(Vector2(90, 450), Vector2(30, 30), ObjectType::ENEMY);
	enemy2->setSprite(m_spriteManager->load("airplane.png", 0, 0, 100, 100));
	enemy2->setMovementPattern(EPattern::CIRCLE, 100, Vector2(800, 450));
	enemy2->setPatternSpeed(3);
	enemy2->setPatternDirection(false);
	addObject(enemy2);

	enemy = new Enemy(Vector2(75, 450), Vector2(30, 30), ObjectType::ENEMY);
	enemy->setSprite(m_spriteManager->load("airplane.png", 0, 0, 100, 100));
	enemy->setMovementPattern(EPattern::CIRCLE, 50, Vector2(800, 450));
	enemy->setPatternSpeed(3);
	addObject(enemy);

	enemy2 = new Enemy(Vector2(700, 450), Vector2(30, 30), ObjectType::ENEMY);
	enemy2->setSprite(m_spriteManager->load("airplane.png", 0, 0, 100, 100));
	enemy2->setMovementPattern(EPattern::CIRCLE, 100, Vector2(800, 450));
	enemy2->setPatternSpeed(3);
	enemy2->setPatternDirection(false);
	addObject(enemy2);
}

void GameState::update(float deltaTime)
{
	for (auto object : m_objects)
	{
		object->update(deltaTime);
	}

	if (m_keyboardInput->isDownOnce('t'))
	{
		m_stateManager->changeCurrentState(StateManager::CurrentState::MENU, StateManager::StateChange::EXIT);
	}
}

void GameState::draw(DrawManager *manager)
{
	for (auto object : m_objects)
	{
		if (object->getSprite() != nullptr)
		{
			object->draw(manager);
		}
	}
}

void GameState::addObject(GameObject *object)
{
	m_objects.push_back(object);
}

void GameState::pause()
{
	//Do nothing on default
}

void GameState::exit()
{
	
}

void GameState::initialize()
{
	
}