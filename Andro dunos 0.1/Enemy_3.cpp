#include "Application.h"
#include "ModuleEnemies.h"
#include "Enemy_3.h"
#include "ModuleCollision.h"

Enemy_3::Enemy_3(int x, int y) : Enemy(x, y)
{

	/*fly.PushBack({ 0,0,20,20 });
	fly.PushBack({ 21,0,21,20 });
	fly.PushBack({ 43,0,20,20 });
	fly.PushBack({ 64,0,20,21 });
	fly.PushBack({ 85,0,20,20 });
	fly.PushBack({ 106,0,20,21 });
	fly.PushBack({ 0,27,20,20 });
	fly.PushBack({ 21,27,21,20 });
	fly.PushBack({ 43,27,20,20 });*/

	fly.PushBack({ 90, 0, 29, 14 });
	fly.PushBack({ 0, 1, 29, 13 });
	fly.PushBack({ 30, 0, 29, 16 });
	fly.PushBack({ 59, 1, 29, 17 });
	fly.PushBack({ 30, 0, 29, 16 });
	fly.PushBack({ 0, 1, 29, 13 });


	fly.speed = 0.08f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 29, 17 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_3::Move()
{
	if (going_up)
	{
		if (wave > 1.0f)
			going_up = false;
		else
			wave += 0.15f;
	}
	else
	{
		if (wave < -1.0f)
			going_up = true;
		else
			wave -= 0.15f;
	}

	position.y = int(float(original_y) + (5.0f * sinf(wave)));
	position.x -= 1;

}

