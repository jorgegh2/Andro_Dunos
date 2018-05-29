#include "Application.h"
#include "Enemy_24.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_24::Enemy_24(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 30, 8, 31, 31 });
	fly.PushBack({ 67, 9, 31, 31 });
	fly.PushBack({ 13, 48, 31, 31 });
	fly.PushBack({ 47, 49, 31, 31 });
	fly.PushBack({ 83, 49, 31, 31 });
	fly.PushBack({ 9, 92, 31, 31 });
	fly.PushBack({ 47, 92, 31, 31 });
	fly.PushBack({ 86, 92, 31, 31 });
	fly.loop = true;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 30, 30 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_24::Move()
{

	position.y = original_y;
	position.x -= 1;

}
