#ifndef __UI_H__
#define __UI_H__

#include "Module.h"
#include "Animation.h"
//#include <iostream>

struct SDL_Texture;
#include "SDL\include\SDL.h" // I don't know why I can't put struct SDL_Rect; like so the program doesn't compile

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
	int font_high_score = -1;
	//int font_score2 = -1;
	int Continue_Number = -1;
	char score_text[10];
	char score_text2[10];
	char high_score_text[10]; // highscore text
	uint score = 0;
	uint score2 = 0;
	uint highscore = 0;
	uint Cuenta_atras_number = 0;
	char Cuenta_atras[10];
	uint time_dead_init = 0;
	uint time_dead = 0;

	SDL_Texture* high_score = nullptr;

	SDL_Texture* UI = nullptr; // normal shot
	SDL_Texture* UI_laser = nullptr;
	SDL_Texture* UI_backshoot = nullptr;
	SDL_Texture* UI_helix = nullptr; // way

	SDL_Texture* red_insert_coin = nullptr;
	SDL_Texture* red_2p_button = nullptr;
	Animation* red_coin = nullptr;
	Animation rc;
	Animation* p2_button = nullptr;
	Animation p2b;


	// Power-up numbers
	int font_power_up = -1;
	// player 1
	char powerup_text[9];
	uint n_powerup = 1;
	//player 2
	char powerup_text2[9];
	uint n_powerup2 = 1;


	// etc

	SDL_Texture* Life_texture1 = nullptr;
	SDL_Texture* Continue = nullptr;

	//var for continue with gamepad
	bool r_shoulder_pressed = false;

	// Credits
	int font_credits = -1;
	char credits_text[10];
	SDL_Texture* graphics8 = nullptr; // credits text
};


#endif
