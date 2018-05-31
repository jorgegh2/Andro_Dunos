#include "Application.h"
#include "Enemy_25.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_25::Enemy_25(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 7, 55, 29, 9 });
	fly.PushBack({ 50, 55, 29, 9 });
	fly.PushBack({ 93, 55, 29, 9 });
	fly.loop = true;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 29, 9 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_25::Move()
{

	position.y = original_y;
	position.x -= 1;

}
