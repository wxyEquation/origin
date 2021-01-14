#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <stdio.h>
#include <algorithm>
#include <cmath>

#include "object.hpp"
#include "movebot.hpp"


int main(int argv, char* args[])
{
	//Initialize Section
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);
	if(TTF_Init()<0)
	{
		printf("TTF_Init: %s\n", TTF_GetError());
	}
	if(!IMG_Init(IMG_INIT_PNG))
	{
		printf("IMG_Init: %s\n", IMG_GetError());
	}
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	
	//Load Section
	SDL_Window* win = SDL_CreateWindow(\
		"Hello world", \
		SDL_WINDOWPOS_UNDEFINED, \
		SDL_WINDOWPOS_UNDEFINED, \
		1657, 1024, \
		SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer* rdn = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(rdn, 255, 255, 255, 255);
	SDL_Surface* screen = SDL_GetWindowSurface(win);
	SDL_Rect screen_rect = {0, 0, screen->w, screen->h};

	//open resource
	SDL_Texture* bot_tex = loadTexture("res/movebot.png", rdn);
	Mix_Chunk* click = Mix_LoadWAV("res/beep.wav");
	Mix_Music* bgm = Mix_LoadMUS("res/spacebot.wav");

	TTF_Font* font_default = TTF_OpenFont("res/Bahnschrift.ttf", 48);
	if(font_default==NULL)
	{
		printf("TTF_OpenFont: %s\n", SDL_GetError());
	}
	SDL_Surface* pause = TTF_RenderUTF8_Shaded(\
		font_default, \
		"Game Paused", 
		{255,255,255},
		{0,0,0});
	SDL_SetColorKey(pause, SDL_TRUE, 0);
	SDL_Texture* pause_tex = SDL_CreateTextureFromSurface(rdn, pause);
	int pause_w = pause->w;
	int pause_h = pause->h;
	SDL_FreeSurface(pause); 

	//Game Loop
	SDL_Event e;
	bool quit = false;
	bool active = true;
	int current_time = SDL_GetTicks();
	SDL_Point center = {screen->w/2, screen->h/2};
	SDL_Point center_f = {pause_w/2, pause_h/2};

	Movebot* sprite[50];
	sprite[0] = new Movebot(bot_tex, rdn, center.x-256, center.y-256);
	int count = 1;
	Mix_PlayMusic(bgm, -1);
	while(!quit)
	{
		//event loop
		while(SDL_PollEvent(&e)!=0)
		{
			if(e.type==SDL_QUIT||(e.type==SDL_KEYDOWN&&e.key.keysym.sym==SDLK_ESCAPE))
			{
				Mix_HaltMusic();
				quit=true;
			}
			else if(e.type==SDL_MOUSEBUTTONDOWN&&e.button.button==SDL_BUTTON_RIGHT)
			{
				if((e.button.clicks=1)&&(count<50))
				{
					count++;
					sprite[count-1] = new Movebot(bot_tex, rdn, center.x-256, center.y-256);
				}
			}
			else if(e.type==SDL_KEYDOWN&&e.key.keysym.sym==SDLK_SPACE)
			{
				active = !active;
				if(Mix_PausedMusic()==1)
				{
					Mix_ResumeMusic();
				}
				else
				{
					Mix_PauseMusic();
				}
			}
			else if(active)
			{
				for (int i = 0; i < count; ++i)
				{
					sprite[i]->update(&e);
				}
			}
			
		}
		
		if(active||SDL_GetTicks()-current_time>3000)
		{
			current_time = SDL_GetTicks();
			if(count > 1)
			{
				delete sprite[count-1];
				Mix_PlayChannel(-1, click, 0);
				count--;
			}
		}

		//things to do
		SDL_SetRenderDrawColor(rdn, 30, 45, 75, 255);
		SDL_RenderClear(rdn);
		for (int i =0; i < count; ++i)
		{
			sprite[i]->render();	
		}
		if(!active)
		{
			SDL_Rect message = {center.x-center_f.x, center.y-center_f.y, pause_w, pause_h};
			
			SDL_SetRenderDrawColor(rdn, 0, 0, 0, 128);
			SDL_SetRenderDrawBlendMode(rdn, SDL_BLENDMODE_BLEND);
			SDL_RenderFillRect(rdn, &screen_rect);
			SDL_RenderCopy(rdn, pause_tex, NULL, &message);
		}
		
		SDL_RenderPresent(rdn);
	}

	//Free section
	TTF_CloseFont(font_default);
	SDL_DestroyTexture(bot_tex);
	SDL_DestroyTexture(pause_tex);
	Mix_FreeChunk(click);
	Mix_FreeMusic(bgm);
	SDL_DestroyRenderer(rdn);
	SDL_DestroyWindow(win);
	TTF_Quit();
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
	return 0;
}