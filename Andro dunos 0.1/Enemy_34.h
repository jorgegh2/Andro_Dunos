#ifndef __ENEMY_34_H__
#define __ENEMY_34_H__

#include "Enemy.h"

class Enemy_34 : public Enemy
{
private:

	//int original_y = 0;
	Animation fly;

public:

	Enemy_34(int x, int y);

	void Move();
};

#endif // __ENEMY_34_H__
