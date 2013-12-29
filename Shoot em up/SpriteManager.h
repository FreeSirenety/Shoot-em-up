#pragma once

#include <map>
#include <string>

class Sprite;
class DrawManager;
class AnimatedSprite;

class SpriteManager
{
	struct Pair
	{
		struct SDL_Surface *surface;
		struct SDL_Texture *texture;
	};

public:
	SpriteManager(DrawManager *draw_manager);
	~SpriteManager();

	bool initialize(const std::string &directory);
	void cleanup();

	Sprite* load(const std::string &filename, int x, int y, int width, int height); 
	AnimatedSprite* load(const std::string &filename);

private:
	DrawManager *m_draw_manager;

	std::string m_directory;

	std::map<std::string, Pair> m_sprites;
	std::map<std::string, AnimatedSprite*> m_animatedSprites;
};