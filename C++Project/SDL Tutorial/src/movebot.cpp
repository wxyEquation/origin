#include "movebot.hpp"
#include <SDL2/SDL_mixer.h>

Movebot::Movebot(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int size):
	Object((new SDL_Rect {x, y, size, size}), texture, renderer),
	hitbox_radius(size/4),
	direction(0),
	state(BOT_IDLE)
{
	appearance[0] = new SDL_Rect {0, 0, 1024, 1024};
	appearance[1] = new SDL_Rect {0, 1024, 1024, 1024};
	appearance[2] = new SDL_Rect {1024, 0, 1024, 1024};

	cliper = appearance[0];
} 

Movebot::~Movebot()
{
	for (int i = 0; i < 3; ++i)
	{
		delete appearance[i];
	}
}

double Movebot::getDirection()
{
	return direction;
}

MovebotState Movebot::getState()
{
	return state;
}

int Movebot::getRadius()
{
	return hitbox_radius;
}

void Movebot::update(SDL_Event* e)
{
	switch(e->type)
	{
		case SDL_MOUSEMOTION:
		{
			SDL_Point* center = getCenter();
			switch(state)
			{
				case BOT_IDLE:
				{
					int x = e->motion.x-center->x;
					int y = e->motion.y-center->y;
					if(hypot(x, y)<=hitbox_radius) {state=BOT_FOCUS;}
					else
					{	
						direction = atan2(y, x)*180/M_PI;
						direction += 45;
					}
					break;
				}

				case BOT_FOCUS:
				{
					int x = e->motion.x-center->x;
					int y = e->motion.y-center->y;
					if(hypot(x, y)>hitbox_radius) 
					{
						state=BOT_IDLE;
						direction = atan2(y, x)*180/M_PI;
						direction += 45;
					}
					break;
				}

				case BOT_MOVE:
				{
					int x = e->motion.xrel;
					int y = e->motion.yrel;
					setCenter(center->x+x, center->y+y);
					break;
				}
			}
			break;
		}

		case SDL_MOUSEBUTTONDOWN:
		{
			if(e->button.button==SDL_BUTTON_LEFT&&e->button.state==SDL_PRESSED&&state==BOT_FOCUS) 
				{state = BOT_MOVE;}
			break;
		}

		case SDL_MOUSEBUTTONUP:
		{
			if(e->button.button==SDL_BUTTON_LEFT&&e->button.state==SDL_RELEASED&&state==BOT_MOVE) 
				{state = BOT_FOCUS;}
			break;
		}

	}
}

int Movebot::render()
{
	switch(state)
	{
		case BOT_IDLE:
		{
			cliper = appearance[0];
			break;
		}

		case BOT_FOCUS:
		{
			cliper = appearance[1];
			break;
		}

		case BOT_MOVE:
		{
			cliper = appearance[2];
			direction +=0.25;
			break;
		}
	}
	int flag = SDL_RenderCopyEx(rdn, texture, cliper, position, direction, NULL, SDL_FLIP_NONE);
	if(flag!=0)
	{
		printf("%s\n", SDL_GetError());
	}

	return flag;
}