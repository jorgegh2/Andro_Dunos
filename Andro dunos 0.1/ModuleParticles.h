#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleCollision.h"

#define MAX_ACTIVE_PARTICLES 150

struct SDL_Texture;
struct Collider;
enum COLLIDER_TYPE;

struct Particle
{
	Collider* collider = nullptr;
	Animation anim;
	uint fx = 0;
	iPoint position;
	iPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	~Particle();
	bool Update();
	enum TYPE_PARTICLE {
		SHOOT = 0,
		EXPLOSION,
		EXPLOSION_ENEMY,
		SHOOT_ENEMY
	} Type = TYPE_PARTICLE::SHOOT;
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

	void AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type = COLLIDER_NONE, Uint32 delay = 0);

private:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	SDL_Texture* graphics3 = nullptr;
	SDL_Texture* enemy15shotgraphics = nullptr;
	Particle* active[MAX_ACTIVE_PARTICLES];

public:

	Particle explosion;
	Particle explosion2;
	Particle enemy_explosion1;
	Particle enemy_explosion2;
	Particle enemy_explosion3;
	
	Particle basic_shoot_0_up;
	Particle basic_shoot_0_down;

	Particle basic_shoot_1;
	Particle basic_shoot_1_up;
	Particle basic_shoot_1_down;

	Particle basic_shoot_2;
	Particle basic_shoot_2_up;
	Particle basic_shoot_2_down;

	Particle laser_0;

	Particle laser_1;
	Particle laser_1_5;

	Particle laser_2;
	Particle laser_2_5;

	Particle back_shoot_0;
	Particle back_shoot_1;

	Particle enemy15shot;

};

#endif // __MODULEPARTICLES_H__