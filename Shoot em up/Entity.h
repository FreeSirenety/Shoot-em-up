#pragma once

#include "GameObject.h"
#include "Vector2.h"

class Entity : public GameObject
{
	friend class Game;
public:
	//Default constructior for Entity
	Entity();

	//Constructor where position and size immediately is set
	Entity(Vector2 position, Vector2 size, ObjectType::Type type);

	//Method to set the current velocity of the entity
	void setVelocity(Vector2 velocity);

	//Method to accelerate/deaccelerate the velocity of the object
	void accelerate(Vector2 velocity);

	//Method to get the velocity of the object
	Vector2 getVelocity();

	//Method that overrides the update method in GameObjec, this takes care of the velocity of the object
	virtual void updateCurrent(float deltaTime);

protected:
	
	
};