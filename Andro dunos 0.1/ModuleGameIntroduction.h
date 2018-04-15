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
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * graphics = nullptr;
	Mix_Music* music_intro = nullptr;

};

#endif // __MODULEGAMEINTRODUCTION_H__