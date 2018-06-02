#include "Application.h"
#include "Enemy_30.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_30::Enemy_30(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 90, 51, 29, 27 });
	fly.loop = true;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 29, 27 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_30::Move()
{
	position.y = original_y;
	position.x -= 1;
}
