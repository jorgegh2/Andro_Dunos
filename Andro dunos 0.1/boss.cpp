#include "Application.h"
#include "boss.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Boss::Boss(int x, int y) : Enemy(x, y)
{

	//fly.PushBack({ 18, 7, 159, 162 });
	//fly.PushBack({ 179, 7, 159, 162 });
	//fly.PushBack({ 342, 7, 159, 162 });
	fly.PushBack({ 18, 176, 159, 162 });
	fly.PushBack({ 179, 176, 159, 162 });
	fly.PushBack({ 342, 176, 159, 162 });
	fly.PushBack({ 18, 338, 159, 162 });
	fly.PushBack({ 184, 338, 159, 162 });
	fly.PushBack({ 343, 176, 159, 162 });
	fly.speed = 0.1f;
	fly.loop = false;

	HP = 50;

	animation = &fly;

	collider = App->collision->AddCollider({ 4, 53, 53, 40 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);
	original_y = y;
	original_x = x;
}

void Boss::Move()
{
	position.x = original_x;
	position.y = original_y;
}
