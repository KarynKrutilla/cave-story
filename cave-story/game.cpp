#include <SDL.h>

#include "game.h"
#include "graphics.h"

/*
 * Holds info for game loop
 */

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	// init GameLoop here (so we don't have to call it from main)
	this->gameLoop(); 
}

Game::~Game() {

}

void Game::gameLoop() {
	Graphics graphics;
	SDL_Event event;

	while (true) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return;
			}
		}
	}
}
