#include "Application.h"


// To initialize the various pointers
Application::Application()
{
	m_window = SDL_CreateWindow("SDL_FIRST", 800, 600, NULL);
	if (!m_window)
	{
		std::cout << "Failed to create window!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
	}

	m_windowSurface = SDL_GetWindowSurface(m_window);
	if (!m_windowSurface)
	{
		std::cout << "Failed to create window!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
	}
}

// To free up space allocated to pointers
Application::~Application()
{
	SDL_DestroySurface(m_windowSurface);
	SDL_DestroyWindow(m_window);
}

// The main Loop
void Application::loop()
{
	bool keepWindowOpen = true;
	while (keepWindowOpen)
	{
		while (SDL_PollEvent(&m_windowEvent) > 0) 
		{
			m_spaceship.handleEvents(m_windowEvent);
			switch (m_windowEvent.type)
			{
				case SDL_EVENT_QUIT:
					keepWindowOpen = false;
					break;
			}
		} 

		update(1.0 / 60.0);
		draw();
	}
}

// To increment the image position using the time passed since last frame
void Application::update(double deltaTime)
{
	m_spaceship.update(deltaTime);
}

// Swap back and front buffer, thereby drawing on window
void Application::draw()
{
	SDL_FillSurfaceRect(m_windowSurface, nullptr, SDL_MapRGB(m_windowSurface->format, 0, 0, 0));
	m_spaceship.draw(m_windowSurface);
	SDL_UpdateWindowSurface(m_window);
}