#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL/include/SDL_events.h"
#include "SDL/include/SDL_scancode.h"

#define MAX_KEYS 300

enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

class ModuleInput : public Module
{
public:
	
	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();

public:

	SDL_GameController * controller1 = nullptr;
	SDL_GameController* controller2 = nullptr;
	char *map1; // Char array where the controller buttons will be assigned
	char *map2;

	KEY_STATE keyboard[MAX_KEYS];
};

#endif // __ModuleInput_H__