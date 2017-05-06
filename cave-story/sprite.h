#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.H>
#include <string>

class Graphics;

class Sprite{
public:
	Sprite();
	/*
	 * filepath = where image is
	 * sourceX & sourceY = where on the spriteSheet to get the image
	 * width & height = width and height of image on spriteSheet
	 * posX, poxY = where sprite starts on screen
     */
	Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY,
		int width, int height, float posX, float poxY);

	virtual ~Sprite();
	virtual void update();
	void draw(Graphics &graphics, int x, int y);
private: 
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;

	float _x, _y;
}

#endif
