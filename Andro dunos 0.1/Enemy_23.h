#ifndef __ENEMY_23_H__
#define __ENEMY_23_H__

#include "Enemy.h"

class Enemy_23 : public Enemy
{
private:

	int original_y = 0;
	Animation fly;

public:

	Enemy_23(int x, int y);

	void Move();
};

#endif // __ENEMY_23_H__
