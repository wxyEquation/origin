#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

class Object
{
public:
	Object(SDL_Rect* position, SDL_Texture* texture, SDL_Renderer* renderer);

	void setPosition(SDL_Rect* position);
	void setCliper(SDL_Rect* cliper);
	void setCenter(int x, int y);
	void setCenter(SDL_Point* center);
	void setDimension(int w, int h);

	SDL_Rect* getPosition();
	SDL_Rect* getCliper();
	SDL_Point* getCenter();

	virtual int render();

protected:
	SDL_Rect* position;
	SDL_Rect* cliper;
	SDL_Texture* texture;
	SDL_Renderer* rdn;
};

SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer);