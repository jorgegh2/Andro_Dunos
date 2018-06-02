#ifndef __MODULELEVEL01_H__
#define __MODULELEVEL01_H__	

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"

struct SDL_Texture;
struct SDL_Rect;

class Level01 : public Module
{
public:
	Level01();
	~Level01();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* background;
	SDL_Texture* layout[6];
	SDL_Texture* underground_tile;
	SDL_Texture* start_under;
	SDL_Texture* end_under;
	SDL_Texture* mars;
	SDL_Texture* stars;
	Mix_Music* music_level01 = nullptr;
	Collider* c_wall[74];
	SDL_Rect moon;
	SDL_Rect star[8];
	uint i[8];
	bool xstop;

	// Controller input
	bool l_shoulder_pressed = false;
	
};

#endif // __MODULELEVEL01_H__	