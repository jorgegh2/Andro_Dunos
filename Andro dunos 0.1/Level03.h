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
	SDL_Texture* layout[4];
	SDL_Texture* finalbackground;
	SDL_Texture* wall;;
	Mix_Music* music_level03 = nullptr;
	Mix_Music* music_level03v2 = nullptr;
	Animation top_layout1;
	Animation top_layout2;
	Animation top_layout3;
	Animation top_layout4;
	Animation bot_layout1;;
	Animation bot_layout2;
	Animation bot_layout3;
	Animation* current = nullptr;
	Collider* c[74];

	bool mus_change = 0;
	// Controller input
	bool l_shoulder_pressed = false;
	uint i;
	float pos;
	bool up;

};

#endif // __MODULELEVEL03_H__	