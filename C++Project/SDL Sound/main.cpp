#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <cmath>
using namespace std;

int main(int argv, char* args[])
{
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, AUDIO_S8, 2, 2048);

	int channel_num = 5;
	int channel_count = 0;
	int len = 3;
	double freq;
	Mix_AllocateChannels(channel_num);
	Mix_Chunk* tracks[channel_num];
	unsigned char* samples[channel_num];
	while(1)
	{
		if(channel_count>channel_num)
		{
			cout<<"max channel number reached"<<endl;
			Mix_FadeOutChannel(-1, 500);
			SDL_Delay(3000);
			cout<<"break"<<endl;
			break;
		}

		cout<<"enter"<<endl;
		cin>>freq;
		cout<<"play"<<endl;

		samples[channel_count] = new unsigned char[44100*len];
		for (int i = 0; i < 44100*len; ++i)
		{
			*(samples[channel_count]+i) = round(31*sin(freq*M_PI*double(i)/44100.0));
		}
		tracks[channel_count] = new Mix_Chunk {1, samples[channel_count], 44100*3, 128};
		Mix_PlayChannel(channel_count, (tracks[channel_count]), -1);
		
		channel_count++;	
	}

	for (int i = 0; i < channel_num; ++i)
	{
		Mix_FreeChunk(tracks[i]);
	}
	Mix_CloseAudio();
	SDL_Quit();
	return 0;
}