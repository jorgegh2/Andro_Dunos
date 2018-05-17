#ifndef __MODULELEVEL03_H__
#define __MODULELEVEL03_H__	

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"

struct SDL_Texture;
struct SDL_Rect;

class Level03 : public Module
{
public:
	Level03();
	~Level03();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* background1;
	SDL_Texture* layout[3];
	SDL_Texture* finalbackground;
	Mix_Music* music_level03 = nullptr;
	Mix_Music* music_level03v2 = nullptr;
	SDL_Rect lay1;
	SDL_Rect lay2;
	SDL_Rect lay3;
	SDL_Rect lay4;
	SDL_Rect lay5;
	SDL_Rect lay6;
	SDL_Rect lay7;
	bool mus_change = 0;
	// Controller input
	bool y_pressed = false;
	uint i;

};

#endif // __MODULELEVEL03_H__	