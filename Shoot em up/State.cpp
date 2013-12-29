#include "State.h"
#include "DrawManager.h"
#include "GameObject.h"

void State::pause()
{
	//Do nothing on default
}

void State::exit()
{
	//Do nothing on default
}

void State::initialize()
{
	//Do nothing on default
}

void State::update(float deltaTime)
{
	//Do nothing on default
}

void State::draw(DrawManager *manager)
{
	for (auto object : m_objects)
	{
		if (object->getSprite() != nullptr)
		{
			object->draw(manager);
		}
	}
}

void State::addObject(GameObject *object)
{
	m_objects.push_back(object);
}