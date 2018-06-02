#include "Application.h"
#include "Enemy_33.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_33::Enemy_33(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 27, 31, 30, 25 });
	fly.PushBack({ 26, 72, 30, 25 });
	fly.PushBack({ 73, 72, 30, 25 });
	fly.loop = true;

	HP = 4;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 30, 25 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_33::Move()
{
	position.y = original_y;
	position.x -= 1;
}
