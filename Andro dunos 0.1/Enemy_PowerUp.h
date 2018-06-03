#ifndef __ENEMY_POWER_UP_H__
#define __ENEMY_POWER_UP_H__

#include "Enemy.h"

class Enemy_Power_Up : public Enemy
{
private:
	float wave = -1.5f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;
	Animation giro1Abajo;
	Animation giro1Arriba;
	Animation Recula;
	uint time_final = 0;
	uint time_init = 0;
	bool short_time = true;
	uint loop = 0;
	/*Animation giro1Abajo;
	Animation giro1Arriba;
	Animation Recula;*/

public:

	Enemy_Power_Up(int x, int y);

	void Move();

	enum En_Power_Up_State {
		ST_Fly = 1,
		ST_giroAbajo,
		ST_giroArriba,
		ST_Recula
		
	}En_State = En_Power_Up_State::ST_Fly;

};

#endif // __ENEMY_POWER_UP_H__





//4444