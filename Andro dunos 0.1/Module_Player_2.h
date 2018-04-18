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
	Animation idle;
	Animation up;
	Animation down;
	Animation upback;
	Animation downback;

	Mix_Chunk* laser_sound = nullptr;
	Mix_Chunk* basic_attack_sound = nullptr;

	iPoint position;

	Collider* c_player2 = nullptr;

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