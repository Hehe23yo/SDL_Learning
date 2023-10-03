#include "Sprite.h"

int const SPRITESHEET_UP = 0;
int const SPRITESHEET_DOWN = 0;
int const SPRITESHEET_LEFT = 1;
int const SPRITESHEET_RIGHT = 1;

Sprite::Sprite()
{
	

	m_imagePos.x = 0;
	m_imagePos.y = 0;
	m_imagePos.h = 132;
	m_imagePos.x = 174;

	m_imageX = 0.0;
	m_imageY = 0.0;

	//m_spritesheetColumn = 1;
}

Sprite::~Sprite()
{

}



void Sprite::update(double deltaTime)
{
	switch (m_direction)
	{
		case Direction::NONE:
			m_imageX += 0.0;
			m_imageY += 0.0;
			m_sheet.selectSprite(0, 0);
			break;
		case Direction::UP:
			m_imageY = m_imageY - (5 * deltaTime);
			m_sheet.selectSprite(m_spritesheetColumn, SPRITESHEET_UP);
			break;
		case Direction::DOWN:
			m_imageY = m_imageY + (5 * deltaTime);
			m_sheet.selectSprite(m_spritesheetColumn + 4, SPRITESHEET_DOWN);
			break;
		case Direction::RIGHT:
			m_imageX = m_imageX + (5 * deltaTime);
			m_sheet.selectSprite(m_spritesheetColumn + 4, SPRITESHEET_RIGHT);
			break;
		case Direction::LEFT:
			m_imageX = m_imageX - (5 * deltaTime);
			m_sheet.selectSprite(m_spritesheetColumn, SPRITESHEET_LEFT);
			break;
	}

	m_imagePos.x = m_imageX;
	m_imagePos.y = m_imageY;

	m_spritesheetColumn++;

	if (m_spritesheetColumn > 4)
	{
		m_spritesheetColumn = 1;
	}
	
}

void Sprite::draw(SDL_Surface* windowSurface)
{
	m_sheet.drawSelected(windowSurface, &m_imagePos);
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


