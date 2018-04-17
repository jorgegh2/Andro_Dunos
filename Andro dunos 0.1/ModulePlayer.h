#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

	void OnCollision(Collider*, Collider*);

public:

	SDL_Texture * graphics = nullptr;

	Animation* current_animation = nullptr;
	Animation idle;
	Animation up;
	Animation down;

	iPoint position;

	Collider* c_player = nullptr;

};

#endif