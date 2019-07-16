#include "game.hpp"
#include "util.hpp"
#include "input.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace GameVariables
{
	const char *GAME_NAME = "SDL2 2D GAME ENGINE";
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
}

Game::Game()
{
}

Game::~Game()
{
}

bool Game::init()
{
	int flags = 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		Util::logError("Initalizing failure", "SDL Subsystems failed to initialize properly", SDL_GetError());
		return false;
	}

	if (_verbose)
	{
		Util::logInfo("SDL Subsystems initialized");
	}

	_graphics = new Graphics(GameVariables::GAME_NAME, GameVariables::SCREEN_WIDTH, GameVariables::SCREEN_HEIGHT);
	_graphics->setRenderColor(Color::white());

	/* Custom class initialization */

	/* End of class initialization */

	_isRunning = true;
	return true;
}

void Game::handleUserInput()
{
	this->_input.beginNewFrame();

	if (SDL_PollEvent(&this->_event))
	{
		if (this->_event.type == SDL_QUIT)
		{
			exit();
		}
		else if (this->_event.type == SDL_KEYDOWN)
		{
			if (this->_event.key.repeat == 0)
				this->_input.keyDownEvent(this->_event);
		}
		else if (this->_event.type == SDL_KEYUP)
		{
			this->_input.keyUpEvent(this->_event);
		}
	}

	if (this->_input.wasKeyPressed(SDL_SCANCODE_ESCAPE))
	{
		exit();
	}
}

void Game::update()
{
	/* Updating of game classes */

	/* End of updating */
}

void Game::render()
{
	_graphics->fillBackground();

	/* Rendering of different classes */

	/* End of rendering */

	_graphics->flip();
}

void Game::exit()
{
	_isRunning = false;
	SDL_Quit();
}

bool Game::running()
{
	return _isRunning;
}

void Game::run()
{
	unsigned int last = SDL_GetTicks();
	unsigned int current;

	while (this->running())
	{
		current = SDL_GetTicks();

		this->handleUserInput();
		this->update();

		if (current - last >= (1000 / _framerate))
		{
			this->render();
			last = current;
		}

		SDL_Delay(10);
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
