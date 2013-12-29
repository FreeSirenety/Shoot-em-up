#pragma once

//Forward Declarations
class DrawManager;
class SpriteManager;
class KeyboardInput;
class MouseInput;
class InputHandler;
class StateManager;
class GameState;
class MenuState;
class Player;

//Game class definition
class Game
{

	friend class InputHandler;

public:
	Game();

private:
	//Initialization method where all values will be initialized
	void initialize();

	//Run method containing the main game loop
	void run();

	//Cleanup method where the memory management is held
	void cleanup();

	//Function to set if the game is running or not
	void setRunning(bool running);

	//Save all the data to data files
	void save();

	//Updates the delta time
	void updateDeltaTime();

private:
	//The game window
	struct SDL_Window *m_window;

	//The main draw manager
	DrawManager *m_drawManager;

	//The main sprite manager
	SpriteManager *m_spriteManager;

	//The main inputs
	InputHandler *m_inputHandler;
	KeyboardInput *m_keyboard;
	MouseInput *m_mouse;

	//The state managers
	StateManager *m_stateManager;
	GameState *m_gameState;
	MenuState *m_menuState;

	//The player
	Player *m_player;

	//Window dimensions
	int m_windowWidth;
	int m_windowHeight;

	//Storing if the game is running or not
	bool m_isRunning;

	//Stores the delta time
	float m_deltaTime;

	//stores the amount of ticks
	float m_ticks;
};

