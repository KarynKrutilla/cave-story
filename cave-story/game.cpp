#include <SDL.h>

#include "game.h"
#include "graphics.h"
#include "input.h"

/*
 * Holds info for game loop
 */

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	// init GameLoop here (so we don't have to call it from main)
	this->gameLoop(); 
}

Game::~Game() {

}

void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;

	int LAST_UPDATE_TIME = SDL_GetTicks();

	// Starts game loop
	while (true) {
		input.beginNewFrame();

		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.repeat == 0) { // Ignore keys that are held down
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			}
			if (event.type == SDL_QUIT) {
				return; // End game when user presses X
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return; // End game when user hits escape
		}

		const int CURRENT_TIME_MILLIS = SDL_GetTicks(); // Time at end of frame
		int ELAPSED_MILLIS = CURRENT_TIME_MILLIS - LAST_UPDATE_TIME; // How long this frame took


		LAST_UPDATE_TIME = CURRENT_TIME_MILLIS; // Time at start of new frame
	}
}


void Game::update(float elapsedTime) {

}
