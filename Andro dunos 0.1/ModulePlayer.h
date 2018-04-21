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

public:

	SDL_Texture * graphics = nullptr;

	Animation* current_animation = nullptr;
	Animation idle;
	Animation up;
	Animation down;
	Animation upback;
	Animation downback;

	Mix_Chunk* laser_sound = nullptr;
	Mix_Chunk* basic_attack_sound = nullptr;

	iPoint position;
	iPoint location;

	bool god_mode = false;

	Collider* c_player = nullptr;

private:
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

#endif