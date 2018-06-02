#include "Application.h"
#include "Enemy_32.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_32::Enemy_32(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 7, 29, 22, 21 });
	fly.loop = false;

	HP = 5;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 22, 21 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_32::Move()
{
	position.y = original_y;
	position.x -= 1;
}
