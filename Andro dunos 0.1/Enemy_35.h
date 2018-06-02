#ifndef __ENEMY_35_H__
#define __ENEMY_35_H__

#include "Enemy.h"

class Enemy_35 : public Enemy
{
private:

	//int original_y = 0;
	Animation fly;

public:

	Enemy_35(int x, int y);

	void Move();
};

#endif // __ENEMY_35_H__
