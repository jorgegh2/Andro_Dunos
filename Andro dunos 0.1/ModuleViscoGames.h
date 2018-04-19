#ifndef __MODULEVISCOGAMES_H__
#define __MODULEVISCOGAMES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"

struct SDL_Texture;

class ModuleViscoGames : public Module
{
public:
	ModuleViscoGames();
	~ModuleViscoGames();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * graphics = nullptr;
	SDL_Texture * graphics2 = nullptr;
	Mix_Music* music_intro = nullptr;

};

#endif // __MODULEGAMEINTRODUCTION_H__