#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "Level01.h"
#include "ModuleGameOver.h"
#include "ModuleGameIntroduction.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"
#include "UI.h"
#include "Module_player_2.h"
#include "ModulePowerUp.h"
#include "Enemy.h"
#include "ModuleEnemies.h"
#include "Enemy_PowerUp.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePowerUp::ModulePowerUp()
{
	PowerUpText = NULL;

	// General Animation 
	idle.PushBack({ 2, 2, 16, 16 });
	idle.PushBack({ 21, 2, 16, 16 });
	idle.PushBack({ 39, 2, 16, 16 });//openclose
	idle.PushBack({ 111, 2, 16, 16 });//openclose
	idle.PushBack({ 57, 2, 16, 16 });//openclose
	idle.PushBack({ 75, 2, 16, 16 });
	idle.PushBack({ 93, 2, 16, 16 });

	idle.PushBack({ 2, 20, 16, 16 });
	idle.PushBack({ 21, 20, 16, 16 });
	idle.PushBack({ 39, 20, 16, 16 });//openclose
	idle.PushBack({ 111, 20, 16, 16 });//openclose
	idle.PushBack({ 57, 20, 16, 16 });//openclose
	idle.PushBack({ 75, 20, 16, 16 });
	idle.PushBack({ 93, 20, 16, 16 });

	idle.PushBack({ 2, 38, 16, 16 });
	idle.PushBack({ 21, 38, 16, 16 });
	idle.PushBack({ 39, 38, 16, 16 });//openclose
	idle.PushBack({ 111, 38, 16, 16 });//openclose
	idle.PushBack({ 57, 38, 16, 16 });//openclose
	idle.PushBack({ 75, 38, 16, 16 });
	idle.PushBack({ 93, 38, 16, 16 });

	idle.PushBack({ 2, 56, 16, 16 });
	idle.PushBack({ 21, 56, 16, 16 });
	idle.PushBack({ 39, 56, 16, 16 });//openclose
	idle.PushBack({ 111, 56, 16, 16 });//openclose
	idle.PushBack({ 57, 56, 16, 16 });//openclose
	idle.PushBack({ 75, 56, 16, 16 });
	idle.PushBack({ 93, 56, 16, 16 });

	idle.loop = false;
	idle.speed = 0.1f;

	



															/*// Up animation
															up.PushBack({ 94, 87, SHIP_WIDTH, SHIP_HEIGHT });
															up.PushBack({ 94, 66, SHIP_WIDTH, SHIP_HEIGHT });
															up.loop = false;
															up.speed = 0.1f;

															upback.PushBack({ 94, 87, SHIP_WIDTH, SHIP_HEIGHT });
															upback.PushBack({ 94, 108, SHIP_WIDTH, SHIP_HEIGHT });
															upback.loop = false;
															upback.speed = 0.1f;

															// Down animation
															down.PushBack({ 94, 131, SHIP_WIDTH, SHIP_HEIGHT });
															down.PushBack({ 94, 153, SHIP_WIDTH, SHIP_HEIGHT });
															down.loop = false;
															down.speed = 0.1f;

															downback.PushBack({ 94, 131, SHIP_WIDTH, SHIP_HEIGHT });
															downback.PushBack({ 94, 108, SHIP_WIDTH, SHIP_HEIGHT });
															downback.loop = false;
															downback.speed = 0.1f;*/

															// Turbo

															/*turbo_idle.PushBack({ 73, 116, 12, 5 });
															turbo_idle.PushBack({ 61, 116, 12, 5 });
															turbo_idle.PushBack({ 42, 116, 12, 5 });
															turbo_idle.loop = true;
															turbo_idle.speed = 0.8f;

															/*turbo_up.PushBack({ 73, 66, 12, 10 });
															turbo_up.PushBack({ 58, 66, 12, 10 });
															turbo_up.PushBack({ 42, 66, 12, 10 });
															turbo_down.loop = true;
															turbo_down.speed = 0.5f;

															/*
															turbo_up.PushBack({ 73, 91, 12, 8 });
															turbo_up.PushBack({ 59, 91, 12, 8 });
															turbo_up.PushBack({ 42, 91, 12, 8 });
															turbo_up.loop = true;
															turbo_up.speed = 0.8f;
															turbo_down.PushBack({});
															turbo_down.loop = true;
															turbo_down.speed = 0.8f;
															*/

}

ModulePowerUp::~ModulePowerUp()
{}

// Load assets
bool ModulePowerUp::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	PowerUpText = App->textures->Load("Images/power_ups.png");

	power_up_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Power_Up_Picked.wav");
	c_power_up = App->collision->AddCollider({ position.x, position.y, 16, 16 }, COLLIDER_POWER_UP, this); //Mirar esto

	


	/*laser_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-3_(Main_Ships).wav");
	basic_attack_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-1_(Main_Ships).wav");
	helix_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-4_(Main_Ships).wav");

	c_player = App->collision->AddCollider({ position.x, position.y, 27, 17 }, COLLIDER_PLAYER, this);

	player_death = App->audio->LoadSoundEffect("Music/Sounds_effects/Player_Death_Explosion.wav");
	change_weapon_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type_CHANGE.wav");

	PlayerSpawn();

	life = 3;*/
	return ret;
}

void ModulePowerUp::OnCollision(Collider* c1, Collider* c2) {

	if (c_power_up != nullptr && c_power_up == c1 && App->fade->IsFading() == false && c2 == App->player->c_player) {
			c_power_up->SetPos(-100, -100);
	}

}

// Unload assets
bool ModulePowerUp::CleanUp()
{

	LOG("Unloading player");

	App->audio->UnloadSoundEffect(power_up_sound);
	App->textures->Unload(PowerUpText);
	/*if(c_power_up !=nullptr)
		c_power_up->SetPos(App->player->position.x, App->player->position.y);*/
	/*App->audio->UnloadSoundEffect(player_death);
	App->audio->UnloadSoundEffect(laser_sound);
	App->audio->UnloadSoundEffect(basic_attack_sound);
	App->audio->UnloadSoundEffect(change_weapon_sound);
	App->textures->Unload(graphics);

	current_animation = &idle;*/

	return true;
}

// Update: draw background
update_status ModulePowerUp::Update()
{
	//power up conditions and movement
 	current_animation = &idle;
	
	App->render->Blit(PowerUpText, App->enemy->posXpowerUP, App->enemy->posYpowerUP, &(current_animation->GetCurrentFrame()));

	if (position.y < App->render->camera.y / SCREEN_SIZE || position.x < App->render->camera.x / SCREEN_SIZE || position.x > App->render->camera.x / SCREEN_SIZE + SCREEN_WIDTH - c_power_up->rect.w || position.y > App->render->camera.y / SCREEN_SIZE + SCREEN_WIDTH - c_power_up->rect.h) {

		if (condition == true) {
			App->render->Blit(PowerUpText, App->enemy->posXpowerUP += 0.6f, App->enemy->posYpowerUP -= 0.5f, &(current_animation->GetCurrentFrame()));
		}

		if (App->enemy->posYpowerUP == 0) {
			condition = false;
		}

		if (condition == false) {
			App->render->Blit(PowerUpText, App->enemy->posXpowerUP += 0.6f, App->enemy->posYpowerUP += 0.5f, &(current_animation->GetCurrentFrame()));
		}

		if (App->enemy->posYpowerUP == 208) {
			condition = true;
		}


	}

	c_power_up->SetPos(App->enemy->posXpowerUP, App->enemy->posYpowerUP);
	
	return UPDATE_CONTINUE;
}




