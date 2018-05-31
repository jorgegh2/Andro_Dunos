#include "Application.h"
#include "Enemy_27.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_27::Enemy_27(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 34, 53, 24, 28 });
	fly.PushBack({ 69, 53, 24, 28 });
	fly.loop = true;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 18, 18 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_27::Move()
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

	position.y = int(float(original_y) + (100.0 * sinf(wave)));
	position.x -= 1;
}
