#include "Entity.h"

//Default constructior for Entity
Entity::Entity()
{
	m_parent = nullptr;
	m_sprite = nullptr;
	m_collider = nullptr;

	m_velocity = Vector2(0, 0);
}

//Constructor where position and size immediately is set
Entity::Entity(Vector2 position, Vector2 size, ObjectType::Type type)
{
	m_parent = nullptr;
	m_collider = nullptr;
	m_sprite = nullptr;

	m_position = position;
	m_size = size;
	m_originalPosition = position;
	m_originalSize = size;
	m_lastPosition = position;

	m_velocity = Vector2(0, 0);

	m_type = type;
}

//Method to set the current velocity of the entity
void Entity::setVelocity(Vector2 velocity)
{
	m_velocity = velocity;
}

//Method to accelerate/deaccelerate the velocity of the object
void Entity::accelerate(Vector2 velocity)
{
	m_velocity += velocity;
}

//Method to get the velocity of the object
Vector2 Entity::getVelocity()
{
	return m_velocity;
}

//Method that overrides the update method in GameObjec, this takes care of the velocity of the object
void Entity::updateCurrent(float deltaTime)
{
	if (m_parent == nullptr)
	{
		m_position += m_velocity * deltaTime;
	}
	else
	{
		m_velocity = m_parent->m_velocity;
		m_position += m_velocity * deltaTime;
	}
}