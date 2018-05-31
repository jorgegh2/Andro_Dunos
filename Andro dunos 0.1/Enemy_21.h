#ifndef __ENEMY_21_H__
#define __ENEMY_21_H__

#include "Enemy.h"

class Enemy_21 : public Enemy
{
private:

	int original_y = 0;
	Animation fly;

public:

	Enemy_21(int x, int y);

	void Move();
};

#endif // __ENEMY_21_H__
