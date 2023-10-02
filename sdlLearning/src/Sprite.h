#pragma once
#include "SDL3/SDL.h"

#include <iostream>

class Sprite
{
public:
	Sprite();
	~Sprite();

	void update(double deltaTime);
	void draw(SDL_Surface* SDL_windowSurfac);
	SDL_Surface* loadSprite(char const* path);
	void handleEvents(SDL_Event const &event);

	enum class Direction
	{
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

private:
	SDL_Surface* m_image;
	SDL_Rect m_imagePos;

	double m_imageX;
	double m_imageY;

	Direction m_direction;
};

