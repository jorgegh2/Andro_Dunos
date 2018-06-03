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
#include "Enemy_28.h"
#include "Enemy_29.h"
#include "Enemy_30.h"
#include "Enemy_31.h"
#include "Enemy_33.h"
#include "Enemy_32.h"
#include "Enemy_34.h"
#include "Enemy_35.h"
#include "boss_arm.h"
#include "boss.h"
#include "boss_arm.h"
#include "boss_arm2.h"
#include "boss_arm3.h"
#include "Level01.h"
#include "ModuleStageClear.h"

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
	enemy_28 = App->textures->Load("Images/Enemies/en_28.png");
	enemy_29 = App->textures->Load("Images/Enemies/en_29_wave_version2.png"); // sprite modified for wave version
	enemy_30 = App->textures->Load("Images/Enemies/en_30.png");
	enemy_31 = App->textures->Load("Images/Enemies/en_31.png");
	enemy_33 = App->textures->Load("Images/Enemies/en_33.png");
	enemy_32 = App->textures->Load("Images/Enemies/en_32.png");
	enemy_34 = App->textures->Load("Images/Enemies/en_34.png");
	enemy_35 = App->textures->Load("Images/Enemies/en_35.png");
	boss = App->textures->Load("Images/Enemies/boss.png");
	boss_arm = App->textures->Load("Images/Enemies/boss_arm.png");

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
		if (enemies[i] != nullptr && enemies[i]->Type == 1 && App->level01->IsEnabled()) enemies[i]->Draw(sprites);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 2 && App->level01->IsEnabled()) enemies[i]->Draw(enemy_3);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 3 && App->level01->IsEnabled()) enemies[i]->Draw(enemy15, 0.8f, (App->render->camera.x / SCREEN_SIZE) * 0.2f);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 4 && App->level03->IsEnabled()) enemies[i]->Draw(enemyPowerUp);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 5 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_20);
	
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 6 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_23);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 7 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_24);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 8 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_21);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 9 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_22);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 10 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_25);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 11 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_27);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 12 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_28);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 13 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_29);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 14 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_30);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 15 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_31);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 16 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_33);
	
	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 17 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_32);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 18 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_34);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 19 && App->level03->IsEnabled()) enemies[i]->Draw(enemy_35);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 20 && App->level03->IsEnabled()) enemies[i]->Draw(boss_arm);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 21 && App->level03->IsEnabled()) enemies[i]->Draw(boss_arm);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 22 && App->level03->IsEnabled()) enemies[i]->Draw(boss_arm);

	for (uint i = 0; i < MAX_ENEMIES; ++i)
		if (enemies[i] != nullptr && enemies[i]->Type == 23 && App->level03->IsEnabled()) enemies[i]->Draw(boss);

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
			else if (enemies[i]->Type == 20 || enemies[i]->Type == 21 || enemies[i]->Type == 22);
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
	App->textures->Unload(enemy_28);
	App->textures->Unload(enemy_29);
	App->textures->Unload(enemy_30);
	App->textures->Unload(enemy_31);
	App->textures->Unload(enemy_33);
	App->textures->Unload(enemy_32);
	App->textures->Unload(enemy_34);
	App->textures->Unload(enemy_35);
	App->textures->Unload(boss);
	App->textures->Unload(boss_arm);


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
		case ENEMY_TYPES::ENEMY_28:
			enemies[i] = new Enemy_28(info.x, info.y);
			enemies[i]->Type = 12;
			break;
		case ENEMY_TYPES::ENEMY_29:
			enemies[i] = new Enemy_29(info.x, info.y);
			enemies[i]->Type = 13;
			break;
		case ENEMY_TYPES::ENEMY_30:
			enemies[i] = new Enemy_30(info.x, info.y);
			enemies[i]->Type = 14;
			break;
		case ENEMY_TYPES::ENEMY_31:
			enemies[i] = new Enemy_31(info.x, info.y);
			enemies[i]->Type = 15;
			break;
		case ENEMY_TYPES::ENEMY_33:
			enemies[i] = new Enemy_33(info.x, info.y);
			enemies[i]->Type = 16;
			break;
		case ENEMY_TYPES::ENEMY_32:
			enemies[i] = new Enemy_32(info.x, info.y);
			enemies[i]->Type = 17;
			break;
		case ENEMY_TYPES::ENEMY_34:
			enemies[i] = new Enemy_34(info.x, info.y);
			enemies[i]->Type = 18;
			break;
		case ENEMY_TYPES::ENEMY_35:
			enemies[i] = new Enemy_34(info.x, info.y);
			enemies[i]->Type = 19;
			break;
		case ENEMY_TYPES::BOSS_ARM:
			enemies[i] = new Boss_arm(info.x, info.y);
			enemies[i]->Type = 20;
			break;
		case ENEMY_TYPES::BOSS_ARM2:
			enemies[i] = new Boss_arm2(info.x, info.y);
			enemies[i]->Type = 21;
			break;
		case ENEMY_TYPES::BOSS_ARM_3:
			enemies[i] = new Arm_3(info.x, info.y);
			enemies[i]->Type = 22;
			break;
		case ENEMY_TYPES::BOSS:
			enemies[i] = new Boss(info.x, info.y);
			enemies[i]->Type = 23;
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
			
			if (enemies[i]->HP > 1)	
		    {
				enemies[i]->HP--;
				break;					
			}
			else if (enemies[i]->Type == 23) {
				App->stage_clear->Enable();
			}
			else	
			{
				enemies[i]->OnCollision(c2, enemies[i]->Type);
				delete enemies[i];
				enemies[i] = nullptr;
				break;
			}
			
		}
	}

/*
	if (c2->type == COLLIDER_PLAYER_SHOT)
		App->UI->score += 100;
	
	if (c2->type == COLLIDER_PLAYER_SHOT_2)
		App->UI->score2 += 100;
		*/
}
