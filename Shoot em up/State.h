#pragma once

#include <vector>

class DrawManager;
class GameObject;

class State
{
public:
	virtual void pause();

	virtual void exit();

	virtual void initialize();

	virtual void update(float deltaTime);

	virtual void draw(DrawManager *drawManager);

	virtual void addObject(GameObject *object);

protected:
	std::vector<GameObject *> m_objects;
};