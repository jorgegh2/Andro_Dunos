#ifndef __ENEMY_30_H__
#define __ENEMY_30_H__

#include "Enemy.h"

class Enemy_30 : public Enemy
{
private:

	int original_y = 0;
	Animation fly;

public:

	Enemy_30(int x, int y);

	void Move();
};

#endif // __ENEMY_30_H__
