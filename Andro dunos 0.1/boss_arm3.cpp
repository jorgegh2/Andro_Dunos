#include "Application.h"
#include "boss_arm3.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include <cmath>

Arm_3::Arm_3(int x, int y) : Enemy(x, y)
{

	fly.PushBack({ 27, 53, 17, 18 });

	HP = 99999;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 17, 18 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemy);
	original_y = y;
	original_x = x;
}

void Arm_3::Move()
{
	if (i < 230) ++i;
	else {
		if (!value_taken) {
			val1 = original_y - App->player->position.y;
			val2 = original_x - App->player->position.x;
			vals = val1 / val2;
			if (vals > 1) {
				vals = 1;
				vals2 = val2 / val1;
			}
			else if (vals < -1) {
				vals = -1;
				vals2 = -(val2 / val1);
			}
			else {
				vals2 = 1;
			}
			if (val2 > 0) cases = true;
			else cases = false;
			value_taken = true;
		}
		if (sqrt(posx * posx + posy * posy) < 70 && !done) {
			if (val2 > 0) {
				posx += 4 * vals2;
				posy += 4 * vals;
			}
			else {
				posx -= 4 * vals2;
				posy -= 4 * vals;
			}
		}
		else if (aux < 35) ++aux;
		else if (sqrt(posx * posx + posy * posy) < 250 && !done) {
			if (val2 > 0) {
				posx += 6 * vals2;
				posy += 6 * vals;
			}
			else {
				posx -= 6 * vals2;
				posy -= 6 * vals;
			}
		}
		else if (aux < 80) {
			if (aux == 36) done = true;
			++aux;
		}
		else if (sqrt(posx * posx + posy * posy) >= 10) {
			if (val2 > 0) {
				posx -= 4 * vals2;
				posy -= 4 * vals;
			}
			else {
				posx += 4 * vals2;
				posy += 4 * vals;
			}
		}
		else {
			posx = 0;
			posy = 0;
			value_taken = false;
			i = 0;
			aux = 0;
			done = false;
		}


	}

	position.x = original_x - posx;
	position.y = original_y - posy;
}
