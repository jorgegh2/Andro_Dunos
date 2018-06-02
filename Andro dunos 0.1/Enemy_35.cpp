#include "Application.h"
#include "Enemy_35.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_35::Enemy_35(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 34, 17, 14, 14 });
	fly.PushBack({ 84, 19, 12, 12 });
	fly.PushBack({ 35, 40, 12, 12 });
	fly.PushBack({ 83, 39, 13, 13 });
	fly.PushBack({ 34, 63, 15, 15 });
	fly.PushBack({ 85, 64, 15, 15 });
	fly.PushBack({ 34, 93, 12, 12 });
	fly.PushBack({ 82, 91, 14, 14 });
	fly.speed = 0.3f;
	fly.loop = true;

	HP = 5;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 14, 14 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	//original_y = y;
}

void Enemy_35::Move()
{
	position.y -= 1;
	position.x -= 1;
}
