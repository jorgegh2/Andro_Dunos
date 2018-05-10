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


#define SPAWN_MARGIN 50

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
		if (enemies[i] != nullptr && enemies[i]->Type == 3) enemies[i]->Draw(enemy15);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 4) enemies[i]->Draw(enemyPowerUp);

	return UPDATE_CONTINUE;
}

update_status ModuleEnemies::PostUpdate()
{
	// check camera position to decide what to spawn
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr)
		{
			if (enemies[i]->position.x * SCREEN_SIZE < (App->render->camera.x) - SPAWN_MARGIN)
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
		}
	}
}

void ModuleEnemies::OnCollision(Collider* c1, Collider* c2)
{
	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (enemies[i] != nullptr && enemies[i]->GetCollider() == c1)
		{
			enemies[i]->OnCollision(c2);
			delete enemies[i];
			enemies[i] = nullptr;
			break;
		}
	}
	if (c2->type == COLLIDER_PLAYER_SHOT)
		App->UI->score += 100;
}