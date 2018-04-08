#ifndef __ModuleStage1_H__
#define __ModuleStage1_H__	

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class Level01 : public Module
{
public:
	Level01();
	~Level01();

	bool Start();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

public:
	
	SDL_Texture * tex;
	SDL_Texture* layout[6];
	float mov;
	float movy;
	int position[2];
	SDL_Rect camera;
	bool stop = false;
	bool xstop;
};

#endif