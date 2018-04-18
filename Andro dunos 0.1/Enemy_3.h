#ifndef __ENEMY_3_H__
#define __ENEMY_3_H__

#include "Enemy.h"

class Enemy_3 : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_3(int x, int y);

	void Move();
};

#endif // __ENEMY_3_H__