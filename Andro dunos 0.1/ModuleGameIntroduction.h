#ifndef __MODULESCENEKEN_H__
#define __MODULESCENEKEN_H__

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
	SDL_Rect title;
	Mix_Music* music_intro = nullptr;
	

	float foreground_pos;
	bool forward;
};

#endif // __MODULEGAMEINTRODUCTION_H__