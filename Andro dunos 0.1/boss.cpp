#include "Application.h"
#include "boss.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Boss::Boss(int x, int y) : Enemy(x, y)
{

	//fly.PushBack({ 18, 7, 159, 162 });
	//fly.PushBack({ 180, 7, 159, 162 });
	//fly.PushBack({ 344, 7, 159, 162 });
	fly.PushBack({ 18, 176, 159, 162 });
	fly.PushBack({ 180, 176, 159, 162 });
	fly.PushBack({ 344, 176, 159, 162 });
	fly.PushBack({ 18, 176, 159, 162 });
	fly.PushBack({ 180, 176, 159, 162 });
	fly.PushBack({ 344, 176, 159, 162 });
	fly.PushBack({ 18, 176, 159, 162 });
	fly.PushBack({ 180, 176, 159, 162 });
	fly.PushBack({ 344, 176, 159, 162 });
	fly.PushBack({ 18, 176, 159, 162 });
	fly.PushBack({ 180, 176, 159, 162 });
	fly.PushBack({ 344, 176, 159, 162 });
	fly.PushBack({ 18, 176, 159, 162 });
	fly.PushBack({ 180, 176, 159, 162 });
	fly.PushBack({ 344, 176, 159, 162 });
	fly.PushBack({ 18, 176, 159, 162 });
	fly.PushBack({ 180, 176, 159, 162 });
	fly.PushBack({ 344, 176, 159, 162 });
	fly.PushBack({ 18, 176, 159, 162 });
	fly.PushBack({ 180, 176, 159, 162 });
	fly.PushBack({ 344, 176, 159, 162 });
	fly.PushBack({ 18, 176, 159, 162 });
	fly.PushBack({ 180, 176, 159, 162 });
	fly.PushBack({ 344, 176, 159, 162 });
	fly.PushBack({ 18, 176, 159, 162 });
	fly.PushBack({ 180, 176, 159, 162 });
	fly.PushBack({ 344, 176, 159, 162 });
	fly.PushBack({ 18, 510, 159, 162 });
	fly.PushBack({ 180, 510, 159, 162 });
	fly.PushBack({ 344, 510, 159, 162 });
	fly.PushBack({ 18, 339, 159, 162 });
	fly.PushBack({ 180, 339, 159, 162 });
	fly.PushBack({ 344, 339, 159, 162 });
	fly.PushBack({ 180, 339, 159, 162 });
	fly.PushBack({ 18, 339, 159, 162 });
	fly.PushBack({ 344, 510, 159, 162 });
	fly.PushBack({ 180, 510, 159, 162 });
	fly.PushBack({ 18, 510, 159, 162 });
	fly.PushBack({ 344, 176, 159, 162 });
	fly.PushBack({ 180, 176, 159, 162 });
	fly.speed = 0.14f;
	fly.loop = true;

	HP = 50;

	animation = &fly;

	collider = App->collision->AddCollider({ 4, 53, 70, 100 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);
	original_y = y;
	original_x = x;
}

void Boss::Move()
{
	if (i < 280) ++i;
	else {
		if (mov >= 10 && down) down = false;
		else if (mov <= 0 && !down) down = true;
		if (down)
			mov += 0.3;
		else if (!down) {
			mov -= 0.3;
			if (mov <= 0) i = 0;
		}
	}

	position.x = original_x;
	position.y = original_y + mov;
}
