#include "Application.h"
#include "Enemy_21.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_21::Enemy_21(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 48, 51, 44, 26 });
	fly.PushBack({ 106, 51, 44, 26 });
	fly.PushBack({ 164, 51, 44, 26 });
	fly.PushBack({ 48, 111, 44, 26 });
	fly.PushBack({ 106, 111, 44, 26 });
	fly.PushBack({ 164, 111, 44, 26 });
	fly.PushBack({ 56, 171, 44, 26 });
	fly.PushBack({ 110, 111, 44, 26 });
	fly.PushBack({ 164, 111, 44, 26 });
	fly.loop = true;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 44, 26 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_21::Move()
{

	position.y = original_y;
	position.x -= 1;

}
