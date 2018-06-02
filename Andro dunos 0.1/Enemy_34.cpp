#include "Application.h"
#include "Enemy_34.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_34::Enemy_34(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 33, 31, 28, 24 });
	fly.PushBack({ 71, 30, 28, 24 });
	fly.PushBack({ 14, 66, 28, 24 });
	fly.PushBack({ 52, 66, 28, 24 });
	fly.PushBack({ 87, 66, 28, 24 });
	fly.speed = 0.3f;
	fly.loop = true;

	HP = 5;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 22, 21 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	//original_y = y;
}

void Enemy_34::Move()
{
	position.y -= 1;
	position.x -= 1;
}
