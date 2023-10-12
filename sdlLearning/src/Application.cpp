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

	m_windowRenderer = SDL_CreateRenderer(m_window, NULL, SDL_RENDERER_ACCELERATED);

	SDL_Surface* image = SDL_LoadBMP("../SampleImages/BMP/berries-leaves.bmp");
	SDL_Texture* m_texture = SDL_CreateTextureFromSurface(m_windowRenderer, image);
	if (!m_texture)
	{
		std::cout << "Failed to create texture!" << std::endl;
		std::cout << "SDL Error : " << SDL_GetError() << std::endl;
	}

	SDL_DestroySurface(image);

	SDL_RenderClear(m_windowRenderer);
	SDL_RenderTexture(m_windowRenderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_windowRenderer);

	//SDL_Delay(5000);

	SDL_FRect rect;
	rect.x = 400;
	rect.y = 300;
	rect.w = 80;
	rect.h = 80;
	
	SDL_SetRenderDrawColor(m_windowRenderer, 255, 255, 255, 255);
	SDL_RenderRect(m_windowRenderer, &rect);
	SDL_SetRenderDrawColor(m_windowRenderer, 0, 0, 0, 255);
	SDL_RenderPresent(m_windowRenderer);

	//SDL_Delay(5000);

	SDL_SetRenderDrawColor(m_windowRenderer, 255, 75, 0, 125);
	SDL_RenderFillRect(m_windowRenderer, &rect);
	SDL_RenderPresent(m_windowRenderer);

	//SDL_Delay(5000);

	SDL_SetRenderDrawColor(m_windowRenderer, 255, 254, 251, 255);
	SDL_RenderLine(m_windowRenderer, 0, 0, 800, 600);
	SDL_RenderPoint(m_windowRenderer, 700, 55);
	SDL_RenderPresent(m_windowRenderer);

	SDL_Delay(5000);

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
	SDL_Quit(); // To deinitialize SDL
}

// The main Loop
void Application::loop()
{
	int a = 0;
	bool keepWindowOpen = true;
	while (keepWindowOpen)
	{
		std::cout << a << std::endl;
		a++;
		while (SDL_PollEvent(&m_windowEvent) > 0)  // Gets all events in queue
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
	SDL_UpdateWindowSurface(m_window); // Update the window surface after each drawing
}