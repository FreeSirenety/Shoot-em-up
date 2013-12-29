#pragma once

enum EMouseButton
{
	MB_LEFT,
	MB_RIGHT,
	MB_COUNT
};

class MouseInput
{

	friend class InputHandler;

public:
	MouseInput();

	int getX() const;
	int getY() const;
	bool isDown(EMouseButton button) const;
	bool isDownOnce(EMouseButton button) const;

	void postUpdate();

private:
	bool m_current[MB_COUNT];
	bool m_previous[MB_COUNT];
	int m_x;
	int m_y;
};
