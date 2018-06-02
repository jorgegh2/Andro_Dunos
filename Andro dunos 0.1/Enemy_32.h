#ifndef __ENEMY_32_H__
#define __ENEMY_32_H__

#include "Enemy.h"

class Enemy_32 : public Enemy
{
private:

	int original_y = 0;
	Animation fly;

public:

	Enemy_32(int x, int y);

	void Move();
};

#endif // __ENEMY_32_H__
