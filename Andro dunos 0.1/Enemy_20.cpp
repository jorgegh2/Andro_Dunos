#include "Application.h"
#include "Enemy_20.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_20::Enemy_20(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 55,55,20,20 });

	HP = 1;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 18, 18 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_20::Move()
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

	position.y = int(float(original_y) + (30.0f * sinf(wave)));
	position.x -= 1;
}
