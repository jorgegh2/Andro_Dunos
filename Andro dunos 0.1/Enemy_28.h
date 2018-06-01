#ifndef __ENEMY_28_H__
#define __ENEMY_28_H__

#include "Enemy.h"

class Enemy_28 : public Enemy
{
private:

	float wave = -1.5f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_28(int x, int y);

	void Move();
};

#endif // __ENEMY_28_H__
