#include "Application.h"
#include "Enemy.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "UI.h"

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

void Enemy::Draw(SDL_Texture* sprites, float speed, float col_speed)
{
	if (collider != nullptr)
		collider->SetPos(position.x + col_speed, position.y);

	if (animation != nullptr)
		App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()), speed);
}

void Enemy::OnCollision(Collider* collider, int type)
{
	if (type == 3) {
		App->particles->AddParticle(App->particles->enemy_explosion1, position.x + (App->render->camera.x / SCREEN_SIZE) * 0.2f, position.y);
		App->particles->AddParticle(App->particles->enemy_explosion2, position.x + 10 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, position.y + 10);
		App->particles->AddParticle(App->particles->enemy_explosion3, position.x + (App->render->camera.x / SCREEN_SIZE) * 0.2f, position.y);
		App->audio->PlaySoundEffect(enemy_death);
	}
	else {
  		App->particles->AddParticle(App->particles->enemy_explosion1, position.x, position.y);
		App->particles->AddParticle(App->particles->enemy_explosion2, position.x + 10, position.y + 10);
		App->particles->AddParticle(App->particles->enemy_explosion3, position.x, position.y);
		App->audio->PlaySoundEffect(enemy_death);
		if (collider->type == COLLIDER_PLAYER_SHOT)
			App->UI->score += 100;

		if (collider->type == COLLIDER_PLAYER_SHOT_2)
			App->UI->score2 += 100;

	}

}