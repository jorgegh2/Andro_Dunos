#ifndef __ENEMY_24_H__
#define __ENEMY_24_H__

#include "Enemy.h"

class Enemy_24 : public Enemy
{
private:

	int original_y = 0;
	Animation fly;

public:

	Enemy_24(int x, int y);

	void Move();
};

#endif // __ENEMY_24_H__
