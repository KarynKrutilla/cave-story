#ifndef INPUT_H
#define INPUT_H

#include <SDL.h>
#include <map>

class Input {

public:
	void beginNewFrame(); // called at the beginning of each new frame - resets keys that aren't needed
	void keyUpEvent(const SDL_Event& event); // called when a key is pressed
	void keyDownEvent(const SDL_Event& event); // called when a key is released

	bool wasKeyPressed(SDL_Scancode key); // has the given key been pressed during this frame
	bool wasKeyReleased(SDL_Scancode key); // has the given key been released during this frame
	bool isKeyHeld(SDL_Scancode key); // is the given key currently being held during this frame

private: 
	std::map<SDL_Scancode, bool> _heldKeys; // stores keys that have been held
	std::map<SDL_Scancode, bool> _pressedKeys; // stores keys that have been pressed
	std::map<SDL_Scancode, bool> _releasedKeys; // stores keys that have been relased

};

#endif
