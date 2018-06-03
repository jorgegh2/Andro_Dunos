#ifndef __boss_H__
#define __boss_H__

#include "Enemy.h"

class Boss : public Enemy
{
private:

	int original_y = 0;
	int original_x = 0;
	Animation fly;
	int i = 0;
	bool start = false;
	bool down = true;
	float mov = 0;
public:

	Boss(int x, int y);

	void Move();
};

#endif // __boss_H__
