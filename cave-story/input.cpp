#include "input.h"

/*
 * Keeps track of keyboard state
 */

// When new frame begins, clear pressedKeys and releasedKeys
void Input::beginNewFrame() {
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

// When a key is pressed add it to pressedKeys and heldKeys
void Input::keyDownEvent(const SDL_Event& event) {
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

// When a key is released, add it to releasedKeys and remove it from heldKeys
void Input::keyUpEvent(const SDL_Event& event) {
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

// Return value from pressedKeys
bool Input::wasKeyPressed(SDL_Scancode key) {
	return this->_pressedKeys[key];
}

// Return value from releasedKeys
bool Input::wasKeyReleased(SDL_Scancode key) {
	return this->_releasedKeys[key];
}

// Return value from heldKeys
bool Input::isKeyHeld(SDL_Scancode key) {
	return this->_heldKeys[key];
}