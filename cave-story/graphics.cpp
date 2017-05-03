#include <SDL.h>
#include "graphics.h"

/*
 * Holds graphics info!
 */


Graphics::Graphics() {
	// Window should be 640x480, no flags right now (I guess?)
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "Cave Story");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
}