#include "object.hpp"

/****Object class****/

Object::Object(SDL_Rect* position, SDL_Texture* texture, SDL_Renderer* renderer):
	position(position),
	cliper(NULL),
	texture(texture),
	rdn(renderer)
{}


//set functions
void Object::setPosition(SDL_Rect* position)
{
	this->position = position;
}

void Object::setCliper(SDL_Rect* cliper)
{
	this->cliper = cliper;
}

void Object::setCenter(int x, int y)
{
	position->x = x-position->w/2;
	position->y = y-position->h/2;
}

void Object::setCenter(SDL_Point* center)
{
	position->x = center->x-position->w/2;
	position->y = center->y-position->h/2;
}

void Object::setDimension(int w, int h)
{
	SDL_Point* center = getCenter();
	position->w = w;
	position->h = h;
	setCenter(center);
}


//get functions
SDL_Rect* Object::getPosition()
{
	return position;
}

SDL_Rect* Object::getCliper()
{
	return cliper;
}

SDL_Point* Object::getCenter()
{
	SDL_Point* center = new SDL_Point;
	center->x = position->x+position->w/2;
	center->y = position->y+position->h/2;
	return center;
}


//rendering
int Object::render()
{
	int flag = SDL_RenderCopy(rdn, texture, cliper, position);
	if(flag!=0)
	{
		printf("%s\n", SDL_GetError());
	}

	return flag;
}

/**** functions ****/

SDL_Texture* loadTexture(const char* path, SDL_Renderer* renderer)
{
	SDL_Surface* surf = NULL;
	SDL_Texture* texture = NULL;

	surf = IMG_Load(path);
	if(surf==NULL)
	{
		printf("IMG_Load:%s\n", IMG_GetError());
		return NULL;
	}

	texture = SDL_CreateTextureFromSurface(renderer, surf);
	if(texture==NULL)
	{
		printf("SDL_CreateTextureFromSurface:%s\n", SDL_GetError());
		return NULL;
	}

	SDL_FreeSurface(surf);
	return texture;
}