#include "game.h"
#include "logger.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

Game::Game()
{}

Game::~Game()
{}

bool Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		Logger::logError("Initalizing failure", "SDL Subsystems failed to initialize properly", SDL_GetError());
		return false;
	}

	if (_verbose)
	{
		Logger::logInfo("SDL Subsystems initialized");
	}

	_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

	if (!_window)
	{
		Logger::logError("Initalizing failure", "Window creation failure", SDL_GetError());
		return false;
	}

	if (_verbose)
	{
		Logger::logInfo("Window created");
	}

	_renderer = SDL_CreateRenderer(_window, -1, 0);

	if (!_renderer)
	{
		Logger::logError("Initalizing failure", "Renderer creation failure", SDL_GetError());
		return false;
	}

	if (_verbose)
	{
		Logger::logInfo("Renderer created");
	}

	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255); // Standard background color set to white

	/* Custom class initialization */


	/* End of class initialization */

	_isRunning = true;
	return true;
}

void Game::handleUserInput()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		_isRunning = false;
		break;
	
	/* Custom user input */



	/* End of custom user input */
	
	default:
		break;
	}
}

void Game::update()
{
	/* Updating of game classes */

	/* End of updating */
}

void Game::render()
{
	SDL_RenderClear(_renderer);

	/* Rendering of different classes */



	/* End of rendering */
	
	SDL_RenderPresent(_renderer);
}

void Game::exit()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

bool Game::running()
{
	return _isRunning;
}

void Game::run()
{
	while (this->running())
	{
		this->handleUserInput();
		this->update();
		this->render();

		SDL_Delay(1000 / _framerate);
	}
}

// Getters and Setters

void Game::setFramerate(int framerate)
{
	this->_framerate = framerate;
}

void Game::setVerbose(bool verbose)
{
	this->_verbose = verbose;
}