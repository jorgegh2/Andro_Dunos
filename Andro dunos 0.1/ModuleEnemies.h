#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
#include "Enemy_01.h"
#include "Enemy_3.h"
#include "Enemy15.h"
#include "Enemy.h"

#define MAX_ENEMIES 150

enum ENEMY_TYPES
{
	NO_TYPE,
	ENEMY_01,
	ENEMY_3,
	ENEMY_15,
	ENEMY_POWER_UP,
	ENEMY_20,
	ENEMY_23,
};

class Enemy;

struct EnemyInfo
{
	ENEMY_TYPES type = ENEMY_TYPES::NO_TYPE;
	int x, y;
};

class ModuleEnemies : public Module
{
public:

	ModuleEnemies();
	~ModuleEnemies();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	bool AddEnemy(ENEMY_TYPES type, int x, int y);

private:

	void SpawnEnemy(const EnemyInfo& info);

public:

	EnemyInfo queue[MAX_ENEMIES];
	Enemy* enemies[MAX_ENEMIES];
	SDL_Texture* sprites;
	SDL_Texture* enemy_3;
	SDL_Texture* enemy15;
	SDL_Texture* enemyPowerUp;
	SDL_Texture* enemy_20;
	SDL_Texture* enemy_23;
	float posXpowerUP;
	float posYpowerUP;

};

#endif // __ModuleEnemies_H__