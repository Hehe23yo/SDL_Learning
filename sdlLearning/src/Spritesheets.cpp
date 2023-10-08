#include "Spritesheets.h"

Spritesheets::Spritesheets(char const* path, int row, int column)
{
	int flags = IMG_INIT_PNG | IMG_INIT_JPG; // Passing the formats needed
	int initializedFlags = IMG_Init(flags); // Initializing the formats

	if ((initializedFlags & flags) != flags)
	{
		std::cout << "Failed to initialize image files!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
	}

	m_spritesheetImage = IMG_Load(path);// Loads images if the format specified above is matching

	m_clip.w = m_spritesheetImage->w / column;
	m_clip.h = m_spritesheetImage->h / row;
}

Spritesheets::~Spritesheets()
{
	SDL_DestroySurface(m_spritesheetImage);
}

// For optimizing conversion of 24-bit format of BMP to the surface format of screen
SDL_Surface* Spritesheets::load_BMP(char const* path)
{
	SDL_Surface* optimizedBMP = nullptr;
	SDL_Surface* imageBMP = SDL_LoadBMP(path);

	if (!imageBMP)
	{
		std::cout << "Failed to load BMP!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
	}

	optimizedBMP = SDL_ConvertSurface(imageBMP, imageBMP->format);

	if (!optimizedBMP)
	{
		std::cout << "Failed to load BMP!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
	}

	SDL_DestroySurface(imageBMP);
	return optimizedBMP;
}

// Select the sprite - setting position on spritesheet
void Spritesheets::selectSprite(int x, int y)
{
	m_clip.x = x * m_clip.w;
	m_clip.y = y * m_clip.h;
}

// to draw selected sprite in spritesheet
void Spritesheets::drawSelected(SDL_Surface* windowSurface, SDL_Rect* position)
{
	SDL_BlitSurface(m_spritesheetImage, &m_clip, windowSurface, position);
}