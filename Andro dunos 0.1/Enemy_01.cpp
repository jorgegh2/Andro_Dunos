#include "Application.h"
#include "Enemy_01.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_01::Enemy_01(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 65,27,18,12 });
	fly.PushBack({ 41,26,19,13 });
	fly.PushBack({ 20,24,18,18 });
	fly.PushBack({ 0,22,18,20 });
	fly.PushBack({ 101,0,19,22 });
	fly.PushBack({ 79,1,18,20 });
	fly.PushBack({ 59,3,18,17 });
	fly.PushBack({ 39,5,18,13 });
	fly.PushBack({ 19,5,18,12 });
	fly.PushBack({ 0,5,18,12 });

	

	fly.speed = 0.4f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 1, 19, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_01::Move()
{
	if (going_up)
	{
		if (wave > 1.0f)
			going_up = false;
		else
			wave += 0.15f;
	}
	else
	{
		if (wave < -1.0f)
			going_up = true;
		else
			wave -= 0.15f;
	}

	position.y = int(float(original_y) + (30.0f * sinf(wave)));
	position.x -= 1;
}
