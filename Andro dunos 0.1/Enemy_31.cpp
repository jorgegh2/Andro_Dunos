#include "Application.h"
#include "Enemy_31.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_31::Enemy_31(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 13, 36, 27, 20 });
	fly.PushBack({ 51, 37, 27, 20 });
	fly.PushBack({ 89, 36, 27, 21 });
	fly.PushBack({ 30, 74, 27, 21 });
	fly.PushBack({ 72, 74, 27, 13 });
	fly.loop = true;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 27, 20 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_31::Move()
{
	position.y = original_y;
	position.x -= 1;
}
