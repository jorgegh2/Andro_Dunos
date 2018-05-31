#ifndef __ENEMY_27_H__
#define __ENEMY_27_H__

#include "Enemy.h"

class Enemy_27 : public Enemy
{
private:

	float wave = -1.5f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_27(int x, int y);

	void Move();
};

#endif // __ENEMY_27_H__
