#ifndef __Module_Player_2_H__
#define __Module_Player_2_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Mix_Chunk;

class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider*, Collider*);

public:

	SDL_Texture * graphics = nullptr;

	Animation* current_animation = nullptr;
	Animation* anim_turbo = nullptr;
	Animation idle;
	Animation up;
	Animation down;
	Animation upback;
	Animation downback;

	Animation turbo_idle;
	Animation turbo_up;
	Animation turbo_down;

	Mix_Chunk* helix_sound = nullptr;
	Mix_Chunk* laser_sound = nullptr;
	Mix_Chunk* basic_attack_sound = nullptr;
	Mix_Chunk* player_death = nullptr;
	Mix_Chunk* change_weapon_sound = nullptr;

	iPoint position;
	iPoint location;
	bool destroyed;



	bool reverse = false;

	Collider* c_player2 = nullptr;

	// Vars to check if the buttons are still pressed
	bool a_pressed = false;
	bool x_pressed = false;
	bool b_pressed = false;

	bool shoot = false; // so that the player does not shot forever
	bool change = false; // so that the player does not change weapons forever
	bool powerup = false;

	bool player_up = false;
	bool player_down = false;
	bool player_idle = false;

public:
	enum CHANGE_WEAPON
	{
		BASIC_ATTACK = 0,
		LASER,
		BACK_SHOOT,
		HELIX
	} change_weapon = CHANGE_WEAPON::BASIC_ATTACK;


	enum POWER_UPS
	{
		POWER_UP_BASIC = 0,
		POWER_UP_1,
		POWER_UP_2,
		POWER_UP_3,
		POWER_UP_4,
		POWER_UP_5,
		POWER_UP_6

	} power_up = POWER_UPS::POWER_UP_BASIC;
};

#endif