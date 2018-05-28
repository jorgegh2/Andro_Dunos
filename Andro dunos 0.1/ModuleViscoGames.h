#ifndef __MODULEVISCOGAMES_H__
#define __MODULEVISCOGAMES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"

struct SDL_Texture;
struct SDL_Rect;

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

	SDL_Rect v;
	SDL_Rect g;

	int speedX = 2;
	int speedY = 2;
	bool movX = false;
	bool animComplete = false;

	// Controller input
	bool l_shoulder_pressed = false;


	int time_passed = 0;
	int time_init = 0;

};

#endif // __MODULEGAMEINTRODUCTION_H__