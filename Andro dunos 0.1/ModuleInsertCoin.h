#ifndef __MODULEINSERTCOIN_H__
#define __MODULEINSERTCOIN_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"

struct SDL_Texture;
struct SDL_Rect;

class ModuleInsertCoin : public Module
{
public:
	ModuleInsertCoin();
	~ModuleInsertCoin();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture * graphics = nullptr;
	//SDL_Texture* graphics2 = nullptr;
	Mix_Chunk* coin = nullptr;
	Animation* current_animation = nullptr;
	Animation insert_coin1;
	SDL_Rect i_coin;

	// Controller input
	bool dpad_down = false;  // insert coin


	int time_passed = 0;
	bool change_bg = false;
};

#endif // __MODULEINSERTCOIN_H__