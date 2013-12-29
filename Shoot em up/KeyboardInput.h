#pragma once

class KeyboardInput
{

	friend class InputHandler;

public:
	KeyboardInput();

	bool isDown(int key);
	bool isDownOnce(int key);

	void postUpdate();

private:
	bool m_current[256];
	bool m_previous[256];
};