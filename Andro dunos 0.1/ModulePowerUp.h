#ifndef __ModulePowerUp_H__
#define __ModulePowerUp_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "ModuleCollision.h"

struct SDL_Texture;
struct Mix_Chunk;

class ModulePowerUp : public Module
{
public:
	ModulePowerUp();
	~ModulePowerUp();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider*, Collider*);
	


public:

	SDL_Texture * PowerUpText = nullptr;

	Animation idle;
	Animation* current_animation = nullptr;

	Mix_Chunk* power_up_sound = nullptr;

	Collider* c_power_up = nullptr;

	/*Animation* current_animation = nullptr;
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
	Mix_Chunk* change_weapon_sound = nullptr;*/

	iPoint position;
	fPoint location;

	uint life = 1;
	uint time_final = 0;
	uint time_init = 0;
	bool time_finished = true;

	bool powerup = false;
public:

};

#endif // __ModulePlayer_H__