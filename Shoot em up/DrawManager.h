#pragma once

class Sprite;
class Vector2;

class DrawManager
{
	friend class SpriteManager;
public:
	public:
	DrawManager();
	~DrawManager();

	bool initialize(struct SDL_Window *window, int width, int height);
	void cleanup();

	void clear();
	void present();

	void draw(Sprite *sprite, Vector2 *posititon, Vector2 size);

private:
	struct SDL_Renderer *m_renderer;
};

