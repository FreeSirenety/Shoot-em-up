#include "SpriteManager.h"

#include <SDL_image.h>

#pragma comment(lib, "sdl2_image.lib")

#include "Sprite.h"

#include "DrawManager.h"

#include "AnimatedSprite.h"

#include <fstream>
#include <sstream>

SpriteManager::SpriteManager(DrawManager *draw_manager)
{
	m_draw_manager = draw_manager;
}

SpriteManager::~SpriteManager()
{

}

bool SpriteManager::initialize(const std::string &directory)
{
	IMG_Init(IMG_INIT_PNG);

	m_directory = directory;

	return true;
}

void SpriteManager::cleanup()
{
	std::map<std::string, Pair>::iterator it = m_sprites.begin();

	while (it != m_sprites.end())
	{
		SDL_FreeSurface(it->second.surface);
		SDL_DestroyTexture(it->second.texture);
		++it;
	}

	m_sprites.clear();

	IMG_Quit();
}

Sprite* SpriteManager::load(const std::string &filename, int x, int y, int width, int height)
{
	std::map<std::string, Pair>::iterator it = m_sprites.find(filename);

	if (it == m_sprites.end())
	{
		std::string path = m_directory + filename;
		SDL_Surface* surface = IMG_Load(path.c_str());
		if (surface == nullptr)
		{
			return nullptr;
		}

		SDL_Texture *texture = SDL_CreateTextureFromSurface(m_draw_manager->m_renderer, surface);

		Pair pair = {surface, texture};

		m_sprites.insert(std::pair<std::string, Pair> (filename, pair) );
		it = m_sprites.find(filename);
	}

	return new Sprite(it->second.surface, it->second.texture, x, y, width, height);

}

AnimatedSprite* SpriteManager::load(const std::string &filename)
{
	std::map<std::string, AnimatedSprite*>::iterator it = m_animatedSprites.find(filename);

	if (it == m_animatedSprites.end())
	{
		std::ifstream stream;
		stream.open(filename.c_str());
		if (!stream.is_open())
		{
			return nullptr;
		}

		std::string m_spritemap_filename;

		stream >> m_spritemap_filename;

		SDL_Surface *surface = IMG_Load(m_spritemap_filename.c_str());

		if (surface == nullptr)
		{
			return nullptr;
		}
	
		SDL_Texture *texture = SDL_CreateTextureFromSurface(m_draw_manager->m_renderer, surface);
	
		AnimatedSprite *sprite = new AnimatedSprite(surface, texture, 0, 0, 0, 0);
	
		while (!stream.eof())
		{
			int x, y, width, height;
			float duration;
	
			stream >> duration;
			stream >> x;
			stream >> y;
			stream >> width;
			stream >> height;
	
			AnimatedSprite::Frame frame = {duration, x, y, width, height};
			sprite->addFrame(frame);
		}
	
		stream.close();

		m_animatedSprites.insert(std::pair<std::string, AnimatedSprite*> (filename, sprite));
		it = m_animatedSprites.find(filename);
	}
	
	return it->second;
	
}