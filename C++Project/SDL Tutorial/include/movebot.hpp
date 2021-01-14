#pragma once

#include "object.hpp"
#include <cmath>

enum MovebotState
{
	BOT_IDLE,
	BOT_FOCUS,
	BOT_MOVE
};


class Movebot: public Object
{
public:
	Movebot(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int size=512);
	virtual ~Movebot();

	double getDirection();
	MovebotState getState();
	int getRadius();

	void update(SDL_Event* e);
	virtual int render();

private:
	int hitbox_radius;
	double direction;
	MovebotState state;

	SDL_Rect* appearance [3];
};