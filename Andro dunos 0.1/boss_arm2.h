#ifndef __boss_arm2_H__
#define __boss_arm2_H__

#include "Enemy.h"

class Boss_arm2 : public Enemy
{
private:

	int original_y = 0;
	int original_x = 0;
	Animation fly;
	int i = -100;
	float posx = 0, posy = 0;
	uint aux = 0;
	float vals, vals2, val1, val2;
	bool value_taken = false, done = false;
	bool cases;
public:

	Boss_arm2(int x, int y);

	void Move();
};

#endif // __boss_arm2_H__
