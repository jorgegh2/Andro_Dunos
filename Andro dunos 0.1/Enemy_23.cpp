#include "Application.h"
#include "Enemy_23.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_23::Enemy_23(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 56, 70, 29, 32 });
	fly.PushBack({ 15, 70, 29, 32 });
	fly.PushBack({ 88, 32, 29, 32 });
	fly.PushBack({ 51, 32, 29, 32 });
	fly.PushBack({ 14, 32, 29, 32 });
	fly.loop = false;

	HP = 4;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 29, 32 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_23::Move()
{

	position.y = original_y;
	position.x -= 1;

}
