#ifndef __ENEMY_22_H__
#define __ENEMY_22_H__

#include "Enemy.h"

class Enemy_22 : public Enemy
{
private:

	int original_y = 0;
	Animation fly;

public:

	Enemy_22(int x, int y);

	void Move();
};

#endif // __ENEMY_22_H__
