#include "GameObject.h"

#include "DrawManager.h"
#include "Sprite.h"
#include "Collider.h"

GameObject::GameObject()
{
	m_parent = nullptr;

	m_sprite = nullptr;

	m_collider = nullptr;
}

GameObject::GameObject(Vector2 position, Vector2 size, ObjectType::Type type)
{
	m_position = position;
	m_originalPosition = position;
	m_lastPosition = position;

	m_size = size;
	m_originalSize = size;

	m_parent = nullptr;

	m_sprite = nullptr;

	m_collider = nullptr;

	m_type = type;
}

GameObject::~GameObject()
{
	delete m_sprite;
	m_sprite = nullptr;

	delete m_collider;
	m_collider = nullptr;

	delete m_parent;
	m_parent = nullptr;
}

//Get and set methods for the current sprite of the object
void GameObject::setSprite(Sprite *sprite)
{
	m_sprite = sprite;
}

Sprite *GameObject::getSprite()
{
	return m_sprite;
}

//Get and set methods for the current collider of the object
void GameObject::setCollider(Collider *collider)
{
	m_collider = collider;
}

Collider *GameObject::getCollider()
{
	return m_collider;
}

//Get and set methods for the position of the objects
void GameObject::setPosition(Vector2 position)
{
	m_position = position;
}

Vector2 GameObject::getPosition()
{
	return m_position;
}

//Get and set methods for the size of the object
void GameObject::setSize(Vector2 size)
{
	m_size = size;
}

Vector2 GameObject::getSize()
{
	return m_size;
}

//Get and set methods for the type of the object
void GameObject::setType(ObjectType::Type type)
{
	m_type = type;
}

ObjectType::Type GameObject::getType()
{
	return m_type;
}

//Method to add a children to the current GameObject
void GameObject::addChild(GameObject *child)
{
	child->m_parent = this;
	m_children.push_back(child);
}

//Method to remove a children from the current GameObject
void GameObject::removeChild(GameObject *child)
{
	for(auto it = m_children.begin(); it != m_children.end(); ++it)
	{
		if (*it == child)
		{
			delete *it;
			*it = nullptr;
			m_children.erase(it);
		}
	}
}

void GameObject::draw(DrawManager *drawManager)
{
	drawCurrent(drawManager);
	drawChilds(drawManager);
}

//Method to draw the current object
void GameObject::drawCurrent(DrawManager *drawManager)
{
	drawManager->draw(m_sprite, &m_position, m_size);
}

//Method to draw the childs of the current object
void GameObject::drawChilds(DrawManager *drawManager)
{
	for (auto children : m_children)
	{
		children->draw(drawManager);
	}
}

//Updates the current GameObject
void GameObject::update(float deltaTime)
{
	updateCurrent(deltaTime);
	updateChilds(deltaTime);
}

void GameObject::updateCurrent(float deltaTime)
{
	//Only does something in inherited classes
}

//Updates the childrens of the current object
void GameObject::updateChilds(float deltaTime)
{
	for (auto child : m_children)
	{
		child->update(deltaTime);
	}
}