#include "Application.h"
#include "Enemy.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

Enemy::Enemy(int x, int y) : position(x, y)
{
	enemy_death = App->audio->LoadSoundEffect("Music/Sounds_effects/Enemy_Medium_EXPLOSION.wav");
}

Enemy::~Enemy()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

const Collider* Enemy::GetCollider() const
{
	return collider;
}

void Enemy::Draw(SDL_Texture* sprites)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	if (animation != nullptr)
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

void Enemy::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->enemy_explosion1, position.x, position.y);
	App->particles->AddParticle(App->particles->enemy_explosion2, position.x + 10, position.y + 10);
	App->particles->AddParticle(App->particles->enemy_explosion3, position.x, position.y);
	App->audio->PlaySoundEffect(enemy_death);

}