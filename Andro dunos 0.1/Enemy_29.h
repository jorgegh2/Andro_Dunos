#ifndef __ENEMY_29_H__
#define __ENEMY_29_H__

#include "Enemy.h"

class Enemy_29 : public Enemy
{
private:

	float wave = -1.5f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_29(int x, int y);

	void Move();
};

#endif // __ENEMY_29_H__
