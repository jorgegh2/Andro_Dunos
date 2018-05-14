#ifndef __UI_H__
#define __UI_H__

#include "Module.h"
//#include <iostream>

struct SDL_Texture;


class ModuleUI : public Module 
{
public:

	ModuleUI();

	// Destructor
	virtual ~ModuleUI();

	// Called before quitting
	bool Start();

	// Called before quitting
	bool CleanUp();

	update_status Update();

public:
	int font_score = -1;
	int Continue_Number = -1;
	char score_text[10];
	uint score = 0;
	uint Cuenta_atras_number = 0;
	char Cuenta_atras[10];
	uint time_dead_init = 0;
	uint time_dead = 0;
	

	SDL_Texture* UI = nullptr;
	SDL_Texture* Life_texture1 = nullptr;
	SDL_Texture* Continue = nullptr;
};


#endif
