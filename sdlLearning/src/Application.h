#pragma once

#include "SDL3/SDL.h"
#include <iostream>

#include "Sprite.h"

class Application
{
public:
	Application();
	~Application();

	void loop();
	void update(double deltaTime);
	void draw();
	
private:
	Sprite m_spaceship;

	SDL_Window* m_window;
	SDL_Surface* m_windowSurface;
	SDL_Event m_windowEvent;
	
};

