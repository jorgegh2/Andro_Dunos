#include "Application.h"
#include "Enemy_28.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_28::Enemy_28(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 40, 94, 32, 23 });
	fly.PushBack({ 101, 95, 32, 23 });
	fly.PushBack({ 162, 95, 32, 23 });
	fly.PushBack({ 222, 95, 32, 23 });
	fly.PushBack({ 284, 96, 32, 23 });
	// tongue code here
	fly.PushBack({ 279, 357, 32, 23 });
	fly.PushBack({ 346, 355, 32, 23 });
	fly.PushBack({ 406, 357, 32, 23 });
	fly.loop = true;

	HP = 5;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 32, 23 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_28::Move()
{
	if (going_up)
	{
		if (wave > 1.5f)
			going_up = false;
		else
			wave += 0.1f;
	}
	else
	{
		if (wave < -1.5f)
			going_up = true;
		else
			wave -= 0.1f;
	}

	position.y = int(float(original_y) + (60.0 * sinf(wave)));
	position.x -= 1;
}
