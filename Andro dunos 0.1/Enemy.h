#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;
struct Mix_Chunk;



class Enemy
{
protected:
	Animation* animation = nullptr;
	Collider* collider = nullptr;
	

public:
	iPoint position;
	Mix_Chunk* enemy_death = nullptr;

	int Type;

public:
	Enemy(int x, int y);
	virtual ~Enemy();

	const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
	virtual void OnCollision(Collider* collider);
	
};

#endif // __ENEMY_H__