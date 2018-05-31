#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleTextures.h"
#include "Enemy.h"
#include "Enemy_01.h"
#include "Enemy_3.h"
#include "Enemy15.h"
#include "Enemy_PowerUp.h"
#include "UI.h"
#include "ModulePowerUp.h"
#include "Level03.h"
#include "Enemy_20.h"
#include "Enemy_23.h"
#include "Enemy_24.h"
#include "Enemy_21.h"
#include "Enemy_22.h"
#include "Enemy_25.h"
#include "Enemy_27.h"

#define SPAWN_MARGIN (60 * SCREEN_SIZE)

ModuleEnemies::ModuleEnemies()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		enemies[i] = nullptr;
}

// Destructor
ModuleEnemies::~ModuleEnemies()
{
}

bool ModuleEnemies::Start()
{
	// Create a prototype for each enemy available so we can copy them around
	sprites = App->textures->Load("Images/Enemies/1.png");
	enemy_3 = App->textures->Load("Images/Enemies/3.png");
	enemy15 = App->textures->Load("Images/Enemies/15.png");
	enemyPowerUp = App->textures->Load("Images/Enemies/POWER_UP.png");
	enemy_20 = App->textures->Load("Images/Enemies/en_20.png");
	enemy_23 = App->textures->Load("Images/Enemies/en_23.png");
	enemy_24 = App->textures->Load("Images/Enemies/en_24.png");
	enemy_21 = App->textures->Load("Images/Enemies/en_21.png");
	enemy_22 = App->textures->Load("Images/Enemies/en_22.png");
	enemy_25 = App->textures->Load("Images/Enemies/en_25.png");
	enemy_27 = App->textures->Load("Images/Enemies/en_27.png");

	return true;
}

update_status ModuleEnemies::PreUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type != ENEMY_TYPES::NO_TYPE)
		{
			if (queue[i].x * SCREEN_SIZE < App->render->camera.x + (App->render->camera.w * SCREEN_SIZE) + SPAWN_MARGIN)
			{
				SpawnEnemy(queue[i]);
				queue[i].type = ENEMY_TYPES::NO_TYPE;
				LOG("Spawning enemy at %d", queue[i].x * SCREEN_SIZE);
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleEnemies::Update()
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr) enemies[i]->Move();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 1) enemies[i]->Draw(sprites);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 2) enemies[i]->Draw(enemy_3);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 3) enemies[i]->Draw(enemy15, 0.8f, (App->render->camera.x / SCREEN_SIZE) * 0.2f);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 4) enemies[i]->Draw(enemyPowerUp);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 5) enemies[i]->Draw(enemy_20);
	
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 6) enemies[i]->Draw(enemy_23);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 7) enemies[i]->Draw(enemy_24);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 8) enemies[i]->Draw(enemy_21);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 9) enemies[i]->Draw(enemy_22);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 10) enemies[i]->Draw(enemy_25);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 11) enemies[i]->Draw(enemy_27);


	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (enemies[i]->Type == 3) {
 				if (enemies[i]->position.x * SCREEN_SIZE + (App->render->camera.x) * 0.2f < (App->render->camera.x) - SPAWN_MARGIN)
				{
					LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);
					delete enemies[i];
					enemies[i] = nullptr;
				}
			}
			else if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
			{
				LOG("DeSpawning enemy at %d", enemies[i]->position.x * SCREEN_SIZE);
				delete enemies[i];
				enemies[i] = nullptr;
			}
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemies::CleanUp()
{
	LOG("Freeing all enemies");

	App->textures->Unload(enemy15);
	App->textures->Unload(enemy_3);
	App->textures->Unload(sprites);
	App->textures->Unload(enemyPowerUp);
	App->textures->Unload(enemy_20);
	App->textures->Unload(enemy_23);
	App->textures->Unload(enemy_24);
	App->textures->Unload(enemy_21);
	App->textures->Unload(enemy_22);
	App->textures->Unload(enemy_25);
	App->textures->Unload(enemy_27);


	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			delete enemies[i];
			enemies[i] = nullptr;
		}
	}

	return true;
}

bool ModuleEnemies::AddEnemy(ENEMY_TYPES type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (queue[i].type == ENEMY_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;
			ret = true;
			break;
		}
	}

	return ret;
}

void ModuleEnemies::SpawnEnemy(const EnemyInfo& info)
{
	uint i = 0;
	for (; enemies[i] != nullptr && i < MAX_ENEMIES; ++i);

	if (i != MAX_ENEMIES)
	{
		switch (info.type)
		{
		case ENEMY_TYPES::ENEMY_01:
			enemies[i] = new Enemy_01(info.x, info.y);
			enemies[i]->Type = 1;
			break;
		case ENEMY_TYPES::ENEMY_3:
			enemies[i] = new Enemy_3(info.x, info.y);
			enemies[i]->Type = 2;
			break;
		case ENEMY_TYPES::ENEMY_15:
			enemies[i] = new Enemy_15(info.x, info.y);
			enemies[i]->Type = 3;
			break;
		case ENEMY_TYPES::ENEMY_POWER_UP:
			enemies[i] = new Enemy_Power_Up(info.x, info.y);
			enemies[i]->Type = 4;
			break;
		case ENEMY_TYPES::ENEMY_20:
			enemies[i] = new Enemy_20(info.x, info.y);
			enemies[i]->Type = 5;
			break;
		case ENEMY_TYPES::ENEMY_23:
			enemies[i] = new Enemy_23(info.x, info.y);
			enemies[i]->Type = 6;
			break;
		case ENEMY_TYPES::ENEMY_24:
			enemies[i] = new Enemy_24(info.x, info.y);
			enemies[i]->Type = 7;
			break;
		case ENEMY_TYPES::ENEMY_21:
			enemies[i] = new Enemy_21(info.x, info.y);
			enemies[i]->Type = 8;
			break;
		case ENEMY_TYPES::ENEMY_22:
			enemies[i] = new Enemy_22(info.x, info.y);
			enemies[i]->Type = 9;
			break;
		case ENEMY_TYPES::ENEMY_25:
			enemies[i] = new Enemy_25(info.x, info.y);
			enemies[i]->Type = 10;
			break;
		case ENEMY_TYPES::ENEMY_27:
			enemies[i] = new Enemy_27(info.x, info.y);
			enemies[i]->Type = 11;
			break;
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			if (enemies[i]->Type == 4) {
				App->power_up->Enable();
				posXpowerUP = enemies[i]->position.x;
				posYpowerUP = enemies[i]->position.y;
				
				//if () {
					//que cuando choque el jugador desaparezca TOTALMENTE power up
				//}
			}
			enemies[i]->OnCollision(c2, enemies[i]->Type);
			delete enemies[i];
			enemies[i] = nullptr;
			break;
		}
	}


	if (c2->type == COLLIDER_PLAYER_SHOT)
		App->UI->score += 100;
	
	if (c2->type == COLLIDER_PLAYER_SHOT_2)
		App->UI->score2 += 100;

}
