#pragma once

#include "SDL3/SDL.h"
#include "SDL3/SDL_image.h"
#include <iostream>

class Spritesheets
{
public:
	Spritesheets(char const* path, int row, int column);
	~Spritesheets();

	void selectSprite(int x, int y);
	void drawSelected(SDL_Surface* windowSurface, SDL_Rect* position);
	SDL_Surface* load_BMP(char const* path);
private:
	SDL_Surface* m_spritesheetImage;
	SDL_Rect m_clip;
};

