#include "Application.h"
#include "Enemy_29.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_29::Enemy_29(int x, int y) : Enemy(x, y)
{

	// sprite modified to wave version... (no time)
	fly.PushBack({ 53, 16, 30, 24 });
	fly.PushBack({ 54, 49, 30, 24 });
	fly.PushBack({ 52, 88, 30, 24 });
	fly.loop = true;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 30, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_29::Move()
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

	position.y = int(float(original_y) + (40.0 * sinf(wave)));
	position.x -= 1;
}
