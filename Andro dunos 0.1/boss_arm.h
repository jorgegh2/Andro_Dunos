#ifndef __boss_arm_H__
#define __boss_arm_H__

#include "Enemy.h"

class Boss_arm : public Enemy
{
private:

	int original_y = 0;
	int original_x = 0;
	Animation fly;
	int i = 0;
public:

	Boss_arm(int x, int y);

	void Move();
};

#endif // __boss_arm_H__
