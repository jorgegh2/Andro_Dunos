#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;
struct Mix_Chunk;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider*, Collider*);

	void PlayerSpawn();

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
	fPoint location;
	bool destroyed = true;
	bool god_mode = false;

	uint life = 1;
	uint time_final = 0;
	uint time_init = 0;
	bool time_finished = true;
	

	Collider* c_player = nullptr;

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

public: // so we can access from UI module and blit the HUD textures or images
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
	} power_up = POWER_UPS::POWER_UP_BASIC;
};

#endif // __ModulePlayer_H__