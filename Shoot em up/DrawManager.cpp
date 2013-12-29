#include "DrawManager.h"

#include "SDL.h"
#include "Sprite.h"
#include <iostream>
#include "Vector2.h"

DrawManager::DrawManager(void)
{
}


DrawManager::~DrawManager(void)
{
}

bool DrawManager::initialize(SDL_Window *window, int width, int height)
{
	m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (m_renderer == nullptr)
	{
		return false;
	}

	return true;
}

void DrawManager::cleanup()
{
	if (m_renderer != nullptr)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
}

void DrawManager::clear()
{
	SDL_SetRenderDrawColor(m_renderer, 0x11, 0x22, 0x33, 0xff);
	SDL_RenderClear(m_renderer);
}

void DrawManager::present()
{
	SDL_RenderPresent(m_renderer);
}

void DrawManager::draw(Sprite *sprite, Vector2 *position, Vector2 size)
{
	if (sprite == nullptr)
	{
		std::cout << "Error, could not load sprite from file!";
		return;
	}

	SDL_Rect src = {sprite->m_x, sprite->m_y, sprite->m_width, sprite->m_height};
	SDL_Rect dst = {position->m_x, position->m_y, size.m_x, size.m_y};
	SDL_RenderCopy(m_renderer, sprite->m_texture, &src, &dst);
}