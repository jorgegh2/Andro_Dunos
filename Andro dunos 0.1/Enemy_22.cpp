#include "Application.h"
#include "Enemy_22.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_22::Enemy_22(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 42, 9, 44, 43 });
	fly.PushBack({ 105, 24, 44, 43 });
	fly.PushBack({ 160, 25, 44, 43 });
	fly.PushBack({ 208, 26, 44, 43 });

	fly.loop = true;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 44, 43 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_22::Move()
{

	position.y = original_y;
	position.x -= 1;

}
