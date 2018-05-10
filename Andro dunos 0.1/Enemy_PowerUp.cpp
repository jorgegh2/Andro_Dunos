#include "Application.h"
#include "Enemy_PowerUp.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Enemy_Power_Up::Enemy_Power_Up(int x, int y) : Enemy(x, y)
{

	/*fly.PushBack({ 65,27,18,12 });
	fly.PushBack({ 41,26,19,13 });
	fly.PushBack({ 20,24,18,18 });
	fly.PushBack({ 0,22,18,20 });
	fly.PushBack({ 101,0,19,22 });
	fly.PushBack({ 79,1,18,20 });
	fly.PushBack({ 59,3,18,17 });
	fly.PushBack({ 39,5,18,13 });
	fly.PushBack({ 19,5,18,12 });
	fly.PushBack({ 0,5,18,12 });*/

	fly.PushBack({ 4,0,18,26 }); //initial




	fly.speed = 0.1f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 19, 26 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_Power_Up::Move()
{
	/*if (going_up)
	{
	if (wave > 1.5f)
	going_up = false;
	else
	wave += 0.05f;
	}
	else
	{
	if (wave < -1.5f)
	going_up = true;
	else
	wave -= 0.05f;
	}

	position.y = int(float(original_y) + (25.0f * sinf(wave)));*/
	int move_position = 0;

	position.x -= 1;


	if (move_position > 3) {
		position.x -= -1;
		if (position.x -= 1) {
			move_position++;
		}
	}

}