#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <map>

struct SDL_Window;
struct SDL_Renderer; 

class Graphics {

public: 
	Graphics();
	~Graphics();

	/*
	 * Load image into _spriteSheets map if it doesn't already exist (allows us to load only once) 
	 * Returns the image from the map
	 */
	SDL_Surface* loadImage(const std::string &filePath); 

	/*
	 * Draws image to certain part of the screen
	 * source - what we are drawing (spriteSheet)
	 * sourceRectangle - what part of the source (spriteSheet) to draw
	 * destinationRectangle - where on the screen we are drawing
	 */
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/*
	 * renders everything to screen
	 */
	void flip();

	/*
	 * clears screen
	 */
	void clear();

	/*
	 * return renderer so we can use it elsewhere
	 */
	SDL_Renderer* getRenderer() const;
private: 
	SDL_Window* _window; // where we draw to
	SDL_Renderer* _renderer; // actually does the drawing

	std::map<std::string, SDL_Surface*> _spriteSheets; // holds all spriteSheets we've loaded
};

#endif