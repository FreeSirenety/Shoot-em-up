#include "Button.h"
#include <iostream>

Button::Button()
{
	
}
	
Button::Button(Vector2 position, Vector2 size, ObjectType::Type type)
{
	m_position = position;
	m_size = size;

	m_type = type;
}

void Button::action()
{
	//Do nothing by default
}