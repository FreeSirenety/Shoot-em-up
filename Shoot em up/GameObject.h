#pragma once

#include "Vector2.h"
#include <vector>

class Sprite;
class Collider;
class DrawManager;

namespace ObjectType
{
	enum Type
	{
		PLAYER,
		ENEMY,
		BUTTON
	};
}


class GameObject
{
	friend class Entity;
	friend class Game;
public:
	//Default constructor
	GameObject();

	//constructor where original position and size is set
	GameObject(Vector2 position, Vector2 size, ObjectType::Type type);

	~GameObject();

	//Get and set methods for the current sprite of the object
	void setSprite(Sprite *sprite);
	Sprite *getSprite();

	//Get and set methods for the current collider of the object
	void setCollider(Collider *collider);
	Collider *getCollider();

	//Get and set methods for the position of the objects
	void setPosition(Vector2 position);
	Vector2 getPosition();

	//Get and set methods for the size of the object
	void setSize(Vector2 size);
	Vector2 getSize();

	//Get and set methods for the type of the object
	void setType(ObjectType::Type type);
	ObjectType::Type getType();

	//Method to add a children to the current GameObject
	void addChild(GameObject *child);

	//Method to remove a children from the current GameObject
	void removeChild(GameObject *child);

	//Method to initiate the drawing of the object ant its childs
	virtual void draw(DrawManager *manager);

	//Method to draw the current object
	virtual void drawCurrent(DrawManager *drawManager);

	//Method to draw the childs of the current object
	void drawChilds(DrawManager *drawManager);

	//Method to initiate the updates of the object ant its childs
	void update(float deltaTime);

	//Updates the current object
	virtual void updateCurrent(float deltaTime);

	//Updates the childrens of the current object
	void updateChilds(float deltaTime);

protected:
	//Vectors to store the current, original and last position of the object
	Vector2 m_position;
	Vector2 m_originalPosition;
	Vector2 m_lastPosition;

	//Vectors to store the current and original size of the object
	Vector2 m_size;
	Vector2 m_originalSize;

	//Sprite pointers to store the current sprite of the object
	Sprite *m_sprite;

	//Collider pointer to keep the collider of the object
	Collider *m_collider;

	//Pointer to the parent of the current gameobject
	GameObject* m_parent;

	//Vector of the childrens of the current object
	std::vector<GameObject*> m_children;

	//Variable to store the velocity of the object
	Vector2 m_velocity;

	ObjectType::Type m_type;
};