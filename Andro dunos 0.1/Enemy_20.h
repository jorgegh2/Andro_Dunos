#ifndef __ENEMY_20_H__
#define __ENEMY_20_H__

#include "Enemy.h"

class Enemy_20 : public Enemy
{
private:
	float wave = -1.5f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_20(int x, int y);

	void Move();
};

#endif // __ENEMY_20_H__
