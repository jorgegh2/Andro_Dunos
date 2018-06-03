#ifndef __boss_arm3_H__
#define __boss_arm3_H__

#include "Enemy.h"

class Arm_3 : public Enemy
{
private:

	int original_y = 0;
	int original_x = 0;
	Animation fly;
	int i = -150;
	float posx = 0, posy = 0;
	uint aux = 0;
	float vals, vals2, val1, val2;
	bool value_taken = false, done = false;
	bool cases;
public:

	Arm_3(int x, int y);

	void Move();
};

#endif // __boss_arm3_H__
