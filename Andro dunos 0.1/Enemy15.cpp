#include "Application.h"
#include "Enemy15.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModulePlayer.h"

Enemy_15::Enemy_15(int x, int y) : Enemy(x, y)
{

	// original
	fly.PushBack({ 27, 10, 51, 29 });
	//disparando
	/*fly.PushBack({ 84, 10, 53, 29 });
	fly.PushBack({ 139, 10, 54, 29 });
	fly.PushBack({ 30, 44, 56, 29 });
	fly.PushBack({ 91, 44, 58, 29 });*/





	fly.speed = 0.02f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 51, 29 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);

	original_y = y;
}

void Enemy_15::Move()
{
	position.x -= 0;
}

void Enemy_15::Shot()
{

	if (position.y == App->player->position.y) {
		App->particles->AddParticle(App->particles->enemy15shot, position.x, position.y, COLLIDER_ENEMY_SHOT);
	}
}