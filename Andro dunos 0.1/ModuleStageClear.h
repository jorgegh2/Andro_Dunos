#ifndef __MODULESTAGECLEAR_H__
#define __MODULESTAGECLEAR_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"

struct SDL_Texture;

class ModuleStageClear : public Module
{
public:
	ModuleStageClear();
	~ModuleStageClear();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * graphics = nullptr;
	Mix_Music* music_stage_clear = nullptr;
	Animation* current_animation = nullptr;
	Animation stg_clear;

	// Controller input
	bool y_pressed = false;


	int time_init = 0;
	int time_passed = 0;
};

#endif // __MODULESTAGECLEAR_H__