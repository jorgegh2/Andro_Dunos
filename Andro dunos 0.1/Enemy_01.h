#ifndef __ENEMY_01_H__
#define __ENEMY_01_H__

#include "Enemy.h"

class Enemy_01 : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_01(int x, int y);

	void Move();
};

#endif // __ENEMY_01_H__