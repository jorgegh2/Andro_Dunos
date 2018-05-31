#ifndef __ENEMY_25_H__
#define __ENEMY_25_H__

#include "Enemy.h"

class Enemy_25 : public Enemy
{
private:

	int original_y = 0;
	Animation fly;

public:

	Enemy_25(int x, int y);

	void Move();
};

#endif // __ENEMY_25_H__
