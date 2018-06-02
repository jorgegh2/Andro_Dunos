#ifndef __ENEMY_31_H__
#define __ENEMY_31_H__

#include "Enemy.h"

class Enemy_31 : public Enemy
{
private:

	int original_y = 0;
	Animation fly;

public:

	Enemy_31(int x, int y);

	void Move();
};

#endif // __ENEMY_31_H__
