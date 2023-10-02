#include "Sprite.h"


Sprite::Sprite()
{
	m_image = loadSprite("../SampleImages/BMP/fighter_plane1.bmp");

	m_imagePos.x = 0;
	m_imagePos.y = 0;
	m_imagePos.h = 132;
	m_imagePos.x = 174;

	m_imageX = 0.0;
	m_imageY = 0.0;
}

Sprite::~Sprite()
{
	SDL_DestroySurface(m_image);
}

SDL_Surface* Sprite::loadSprite(char const* path)
{
	SDL_Surface* image = SDL_LoadBMP(path);
	
	if (!image)
	{
		std::cout << "Failed to load bitmap!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
	}

	return image;
}

void Sprite::update(double deltaTime)
{
	switch (m_direction)
	{
		case Direction::NONE:
			m_imageX += 0.0;
			m_imageY += 0.0;
			break;
		case Direction::UP:
			m_imageY = m_imageY - (5 * deltaTime);
			break;
		case Direction::DOWN:
			m_imageY = m_imageY + (5 * deltaTime);
			break;
		case Direction::RIGHT:
			m_imageX = m_imageX + (5 * deltaTime);
			break;
		case Direction::LEFT:
			m_imageX = m_imageX - (5 * deltaTime);
			break;
	}

	m_imagePos.x = m_imageX;
	m_imagePos.y = m_imageY;
	
}

void Sprite::draw(SDL_Surface* windowSurface)
{
	SDL_BlitSurface(m_image, nullptr, windowSurface, &m_imagePos);
}

void Sprite::handleEvents(SDL_Event const& event)
{
	switch (event.type)
	{
	case SDL_EVENT_KEY_DOWN:
		Uint8 const* key = SDL_GetKeyboardState(nullptr); // returns an array of the states of all keys

		if (key[SDL_SCANCODE_W] == 1)
			m_direction = Direction::UP;
		else if (key[SDL_SCANCODE_S] == 1)
			m_direction = Direction::DOWN;
		else if (key[SDL_SCANCODE_A] == 1)
			m_direction = Direction::LEFT;
		else if (key[SDL_SCANCODE_D] == 1)
			m_direction = Direction::RIGHT;
		else
			m_direction = Direction::NONE;
		break;
	}
}


