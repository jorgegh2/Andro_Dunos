#ifndef __ENEMY_33_H__
#define __ENEMY_33_H__

#include "Enemy.h"

class Enemy_33 : public Enemy
{
private:

	int original_y = 0;
	Animation fly;

public:

	Enemy_33(int x, int y);

	void Move();
};

#endif // __ENEMY_33_H__
