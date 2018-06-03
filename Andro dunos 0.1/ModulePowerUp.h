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

	Animation Red;
	Animation RedShine;
	Animation RedOpen;

	Animation Blue;
	Animation BlueShine;
	Animation BlueOpen;

	Animation Green;
	Animation GreenShine;
	Animation GreenOpen;

	Animation Yellow;
	Animation YellowShine;
	Animation YellowOpen;

	Animation BlueToRed;
	Animation RedToYellow;
	Animation YellowToGreen;
	Animation GreenToBlue;

	int random_init = -1;
	bool ToShine = false;
	

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
	bool time_animation_finished = false;
	bool short_time = true;
	bool time_shine = false;
	bool init = true;

	int bordeY;
	int varX;
	int varY;

	bool loop = true;

	bool conditionY = true;
	bool conditionX = false;

	float SpeedX = 0.2;
	float SpeedY = 1;

	bool powerup = false;
public:
	enum Power_Up_State {
		None = 0,
		ST_Red,
		ST_RedShine,
		ST_RedOpen,
		ST_Blue,
		ST_BlueShine,
		ST_BlueOpen,
		ST_Green,
		ST_GreenShine,
		ST_GreenOpen,
		ST_Yellow,
		ST_YellowShine,
		ST_YellowOpen,

		//changes
		ST_BlueToRed,
		ST_RedToYellow,
		ST_YellowToGreen,
		ST_GreenToBlue
	}State = Power_Up_State::None;
};

#endif // __ModulePlayer_H__