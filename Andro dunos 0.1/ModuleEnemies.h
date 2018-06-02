#ifndef __ModuleEnemies_H__
#define __ModuleEnemies_H__

#include "Module.h"
#include "Enemy_01.h"
#include "Enemy_3.h"
#include "Enemy15.h"
#include "Enemy.h"

#define MAX_ENEMIES 350

enum ENEMY_TYPES
{
	NO_TYPE,
	ENEMY_01,
	ENEMY_3,
	ENEMY_15,
	ENEMY_POWER_UP,
	ENEMY_20,
	ENEMY_23,
	ENEMY_24,
	ENEMY_21,
	ENEMY_22,
	ENEMY_25,
	ENEMY_27,
	ENEMY_28,
	ENEMY_29,
	ENEMY_30,
	ENEMY_31, // actually is the ENEMY_32...
	ENEMY_33,
	ENEMY_32, // actually is the ENEMY_31...
	ENEMY_34,
	ENEMY_35,
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
	SDL_Texture* enemy_24;
	SDL_Texture* enemy_21;
	SDL_Texture* enemy_22;
	SDL_Texture* enemy_25;
	SDL_Texture* enemy_27;
	SDL_Texture* enemy_28;
	SDL_Texture* enemy_29;
	SDL_Texture* enemy_30;
	SDL_Texture* enemy_31;
	SDL_Texture* enemy_33;
	SDL_Texture* enemy_32;
	SDL_Texture* enemy_34;
	SDL_Texture* enemy_35;
	
	float posXpowerUP;
	float posYpowerUP;

};

#endif // __ModuleEnemies_H__