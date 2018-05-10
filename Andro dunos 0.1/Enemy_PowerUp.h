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

public:

	Enemy_Power_Up(int x, int y);

	void Move();
};

#endif // __ENEMY_POWER_UP_H__