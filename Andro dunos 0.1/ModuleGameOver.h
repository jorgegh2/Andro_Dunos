#ifndef __MODULEGAMEOVER_H__
#define __MODULEGAMEOVER_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"

#define ZONE_GO_SIZE 256

struct SDL_Texture;

class ModuleGameOver : public Module
{
public:
	ModuleGameOver();
	~ModuleGameOver();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * graphics = nullptr;
	Mix_Music* music_go = nullptr;
	Animation* current_animation = nullptr;
	Animation gm_over;

	int x;
	int y;
	bool loop = true;

};

#endif // __MODULEGAMEOVER_H__