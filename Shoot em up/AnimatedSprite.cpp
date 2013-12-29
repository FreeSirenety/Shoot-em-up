#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite(SDL_Surface *surface, SDL_Texture *texture, int x, int y, int width, int height) : Sprite(surface, texture, x, y, width, height)
{
	m_current_frame = 0;
	m_time = 0.f;
}

void AnimatedSprite::update(float deltaTime)
{
	m_time += deltaTime;

	if (m_time >= m_animation[m_current_frame].duration)
	{
		m_time = 0.f;
		m_current_frame = ++m_current_frame % m_animation.size();

		Frame &frame = m_animation[m_current_frame];
		m_x = frame.x;
		m_y = frame.y;
		m_width = frame.w;
		m_height = frame.h;

		
	}

}

void AnimatedSprite::addFrame(Frame &frame)
{
	m_animation.push_back(frame);
}