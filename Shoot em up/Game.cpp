#include "Game.h"
#include "DrawManager.h"
#include "Sprite.h"
#include "SpriteManager.h"
#include "GameObject.h"
#include "Entity.h"
#include "Collider.h"
#include "Vector2.h"
#include "InputHandler.h"
#include "KeyboardInput.h"
#include "MouseInput.h"
#include "Player.h"
#include "Button.h"
#include "MenuState.h"
#include "StateManager.h"
#include "GameState.h"

#include "SDL.h"

Game::Game()
{
	initialize();
	run();
	cleanup();
}

//Initialization method where all values will be initialized
void Game::initialize()
{
	m_isRunning = true;

	m_ticks = 0;
	m_deltaTime = 0;

	m_windowWidth = 1024;
	m_windowHeight = 640;

	m_window = SDL_CreateWindow("Platformer", 
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		m_windowWidth, m_windowHeight,
		SDL_WINDOW_OPENGL);

	m_drawManager = new DrawManager();
	m_drawManager->initialize(m_window, m_windowWidth, m_windowHeight);

	m_spriteManager = new SpriteManager(m_drawManager);

	m_spriteManager->initialize("../resources/sprites/");

	m_keyboard = new KeyboardInput;
	m_mouse = new MouseInput;

	m_inputHandler = new InputHandler(this, m_keyboard, m_mouse);

	m_stateManager = new StateManager(m_inputHandler);

	m_menuState = new MenuState(m_mouse, m_stateManager, m_spriteManager);
	m_gameState = new GameState(m_keyboard, m_mouse, m_stateManager, m_spriteManager);

	m_stateManager->addState(StateManager::CurrentState::GAME, m_gameState);
	m_stateManager->addState(StateManager::CurrentState::MENU, m_menuState);

	m_stateManager->setCurrentState(StateManager::CurrentState::MENU);
}

//Run method containing the main game loop	
void Game::run()
{
	
	//The main Game Loop
	while (m_isRunning)
	{
		updateDeltaTime();
		m_inputHandler->handleEvent();

		m_stateManager->updateCurrentState(m_deltaTime);

		m_drawManager->clear();
		m_stateManager->drawCurrentState(m_drawManager);
		m_drawManager->present();
		m_mouse->postUpdate();
		m_keyboard->postUpdate();
		SDL_Delay(10);
	}

	save();

	cleanup();
}

void Game::updateDeltaTime()
{
	unsigned int ticks = SDL_GetTicks();
	unsigned int delta = ticks - m_ticks;
	m_ticks = ticks;
	m_deltaTime = (float)delta * 0.001f;
}

//Cleanup method where the memory management is held
void Game::cleanup()
{

}

void Game::setRunning(bool running)
{
	m_isRunning = running;
}

void Game::save()
{

}