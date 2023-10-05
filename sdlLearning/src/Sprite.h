#pragma once
#include "SDL3/SDL.h"
#include <iostream>

#include "Spritesheets.h"

class Sprite
{
public:
	Sprite();
	~Sprite();

	void update(double deltaTime);
	void draw(SDL_Surface* SDL_windowSurfac);
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
	SDL_Rect m_imagePos;

	double m_imageX;
	double m_imageY;

	Direction m_direction;

	Spritesheets m_sheet = { "../sampleImages/BMP/Hero.bmp", 3, 8 };
	int m_spritesheetColumn;
};

