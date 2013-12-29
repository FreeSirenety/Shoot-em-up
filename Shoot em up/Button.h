#pragma once

#include "Entity.h"
#include "Vector2.h"

class Button : public Entity
{
public:
	Button();
	
	Button(Vector2 position, Vector2 size, ObjectType::Type type);

	virtual void action();

private:
};