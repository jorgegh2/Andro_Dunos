#include "Application.h"
#include "boss_arm.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Boss_arm::Boss_arm(int x, int y) : Enemy(x, y)
{

	//fly.PushBack({ 18, 7, 159, 162 });

	fly.speed = 0.14f;
	fly.loop = true;

	HP = 50;

	animation = &fly;

	collider = App->collision->AddCollider({ 4, 53, 70, 100 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);
	original_y = y;
	original_x = x;
}

void Boss_arm::Move()
{
	if (i < 280) ++i;
	else {

	}

	position.x = original_x;
	position.y = original_y;
}
