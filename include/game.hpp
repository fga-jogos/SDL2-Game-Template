#ifndef GAME_HPP
#define GAME_HPP

#include "graphics.hpp"
#include "input.hpp"
#include "color.hpp"

struct SDL_Window;
struct SDL_Renderer;
class Player;

class Game
{
public:
	Game();
	~Game();

	bool init();

	/*
		Destroy current renderer and render, unload textures from GPU
	 */
	void exit();

	/*
		Returns true if game is currently running
	 */
	bool running();

	/*
		Runs main game loop
	 */
	void run();

	// Setters and Getters

	void setVerbose(bool verbose);
	void setFramerate(int framerate);

private:
	/*
		Configure starting game conditions such as spawn point and labirinth
	 */
	void startGame();

	/*
		Hanles user input as SDL's events
	*/
	void handleUserInput();

	/*
		Update all game objects
	 */
	void update();

	/*
		Render all game objects to screen
	 */
	void render();

	/*
		Process collisions between game objects
	 */
	void handleCollisions();

	bool _verbose;
	int _framerate;

	bool _isRunning;
	Graphics *_graphics;
	Input _input;

	SDL_Event _event;

	// Custom game classes

	// End of custom classes
};

#endif