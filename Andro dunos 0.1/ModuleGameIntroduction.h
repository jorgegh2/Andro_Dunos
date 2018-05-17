#ifndef __MODULEGAMEINTRODUCTION_H__
#define __MODULEGAMEINTRODUCTION_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"

struct SDL_Texture;

class ModuleGameIntroduction : public Module
{
public:
	ModuleGameIntroduction();
	~ModuleGameIntroduction();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr; // neo geo
	SDL_Texture* graphics2 = nullptr; // text 
	SDL_Texture* graphics3 = nullptr; // snk
	SDL_Texture* graphics4 = nullptr; // copyright
	Mix_Music* music_intro = nullptr;
	
	Animation* current_animation = nullptr; // neo geo
	Animation* current_animation2 = nullptr; // snk
	Animation* current_animation3 = nullptr; // text 1
	bool change_text = false;
	Animation* current_animation4 = nullptr; // text 2
	
	Animation neo_geo;
	Animation snk;
	Animation t1;
	Animation t2;

	// Controller input
	bool y_pressed = false;


	int time_init = 0;
	int time_passed = 0;
	bool change_bg = false;
};

#endif // __MODULEGAMEINTRODUCTION_H__