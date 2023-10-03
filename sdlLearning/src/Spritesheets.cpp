#include "Spritesheets.h"

Spritesheets::Spritesheets(char const* path, int row, int column)
{
	m_spritesheetImage = SDL_LoadBMP(path);

	m_clip.w = m_spritesheetImage->w / column;
	m_clip.h = m_spritesheetImage->h / row;
}

Spritesheets::~Spritesheets()
{
	SDL_DestroySurface(m_spritesheetImage);
}

void Spritesheets::selectSprite(int x, int y)
{
	m_clip.x = x * m_clip.w;
	m_clip.y = y * m_clip.h;
}

void Spritesheets::drawSelected(SDL_Surface* windowSurface, SDL_Rect* position)
{
	SDL_BlitSurface(m_spritesheetImage, &m_clip, windowSurface, position);
}