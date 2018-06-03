#include "Application.h"
#include "Enemy_PowerUp.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "SDL\include\SDL_timer.h"

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
	fly.loop = false;
	fly.speed = 0.5f;

	giro1Abajo.PushBack({55, 0, 18, 25});
	giro1Abajo.PushBack({ 82, 0, 18, 25 }); //mover hacia adelante
	giro1Abajo.loop = false;
	giro1Abajo.speed = 0.5f;

	giro1Arriba.PushBack({134, 0, 18, 26});
	giro1Arriba.PushBack({ 160, 0, 18, 26 });
	giro1Arriba.PushBack({ 186, 0, 18, 26 });
	giro1Arriba.PushBack({ 212, 0, 18, 26 }); //movimiento diagonal
	giro1Arriba.loop = false;
	giro1Arriba.speed = 0.5f;
	
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
	Recula.loop = false;
	Recula.speed = 0.5f;



	

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 19, 26 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;

	time_init = SDL_GetTicks();
	time_final = 0;
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
	/*int move_position = 0;

	position.x -= 1;


	if (move_position > 3) {
		position.x -= -1;
		if (position.x -= 1) {
			move_position++;
		}
	}
	*/

	//if (time_animation_finished == true) {
		switch (En_State) {

		case ST_Fly:
			animation = &fly;
			position.x -= 0.2;
			time_final = SDL_GetTicks() - time_init;
			if (time_final >= 1500 && loop < 5) {
				En_State = ST_giroAbajo;
				time_final = 0;
				time_init = SDL_GetTicks();
				loop++;
			}
			break;

		case ST_giroAbajo:
			animation = &giro1Abajo;
			time_final = SDL_GetTicks() - time_init;
			if (short_time == true) {
				position.x -= 0; //cambiar por el movimiento por el de la camara para que parezca que esta quieto
				if (time_final >= 200)//timepo de giro {
					short_time = false;
			}
			else {
				position.x += 0.8;//cambiar por el movimiento diagonal
				position.y += 0.5;
			}

			if (time_final >= 1000) {
				En_State = ST_giroArriba;
				time_final = 0;
				time_init = SDL_GetTicks();
				short_time = true;
			}
			break;

		case ST_giroArriba:
			animation = &giro1Arriba;
			time_final = SDL_GetTicks() - time_init;
			if (short_time == true) {
				position.x -= 0; //cambiar por el movimiento por el de la camara para que parezca que esta quieto
				if (time_final >= 200)//timepo de giro {
					short_time = false;
			}
			else
			{
				position.x += 0.8; //cambiar por el movimiento diagonal
				position.y -= 0.5;
			}

				if (time_final >= 1000) {
					En_State = ST_Recula;
					time_final = 0;
					time_init = SDL_GetTicks();
				}
			break;

		case ST_Recula:
			animation = &Recula;
			position.x += 2;
			time_final = SDL_GetTicks() - time_init;
			if (time_final >= 2000) {
				En_State = ST_Fly;
				time_final = 0;
				time_init = SDL_GetTicks();
			}
			break;
		}
		//time_animation_finished = false;
	//}

	/*else {
		time_final = SDL_GetTicks() - time_init;
		if (short_time == true)
		{
			if (time_shine == true) {
				if (time_final >= 400) {
					time_animation_finished = true;
					time_init = SDL_GetTicks();
					time_final = 0;
					short_time = false;
					time_shine = false;
				}
			}
			else {
				if (time_final >= 100) {
					time_animation_finished = true;
					time_init = SDL_GetTicks();
					time_final = 0;
					short_time = false;
					time_shine = true;

				}
			}



		}
		else
		{
			if (time_final >= 2000) {
				time_animation_finished = true;
				time_final = 0;
				time_init = SDL_GetTicks();
				short_time = true;
			}
		}
	}*/

}
