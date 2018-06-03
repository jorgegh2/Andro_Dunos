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
	
	/*giro1Abajo.PushBack({55, 0, 18, 25});
	giro1Abajo.PushBack({ 82, 0, 18, 25 }); //mover hacia adelante

	giro1Arriba.PushBack({134, 0, 18, 26});
	giro1Arriba.PushBack({ 160, 0, 18, 26 });
	giro1Arriba.PushBack({ 186, 0, 18, 26 });
	giro1Arriba.PushBack({ 212, 0, 18, 26 }); //movimiento diagonal
	
	Recula.PushBack({ 212, 0, 18, 26 });
	Recula.PushBack({ 263, 2, 21, 21 });
	Recula.PushBack({ 1, 30, 25, 18 });
	Recula.PushBack({ 26, 31, 26, 18 });
	Recula.PushBack({ 53, 31, 25, 18 });
	Recula.PushBack({ 79, 31, 25, 18 });
	Recula.PushBack({ 107, 31, 21, 21 });
	Recula.PushBack({ 132, 31, 21, 21 });
	Recula.PushBack({ 161, 27, 18, 25 });
	Recula.PushBack({ 185, 27, 18, 25 });
	Recula.PushBack({ 212, 26, 18, 26 });
	Recula.PushBack({ 263, 26, 19, 26 });
	Recula.PushBack({ 4, 52, 18, 26 });
	Recula.PushBack({ 30, 52, 18, 26 });
	Recula.PushBack({ 56, 52, 18, 26 }); //movimiento hacia la derecha*/




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
