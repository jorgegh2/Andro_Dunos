#ifndef __ENEMY15_H__
#define __ENEMY15_H__

#include "Enemy.h"

class Enemy_15 : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_15(int x, int y);

	void Move();
	void Shot();
};

#endif // __ENEMY15_H__