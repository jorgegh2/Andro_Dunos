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
#include <time.h>


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePowerUp::ModulePowerUp()
{
	PowerUpText = NULL;





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
	//current_animation = &Red;
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
	c_power_up = App->collision->AddCollider({ position.x, position.y, 16, 16 }, COLLIDER_POWER_UP, this); 
	
	time_init = SDL_GetTicks();
	
	//Mirar esto




																										   /*laser_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-3_(Main_Ships).wav");
																										   basic_attack_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-1_(Main_Ships).wav");
																										   helix_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-4_(Main_Ships).wav");

																										   c_player = App->collision->AddCollider({ position.x, position.y, 27, 17 }, COLLIDER_PLAYER, this);

																										   player_death = App->audio->LoadSoundEffect("Music/Sounds_effects/Player_Death_Explosion.wav");
																										   change_weapon_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type_CHANGE.wav");

																										   PlayerSpawn();

																										   life = 3;*/

																										   // Correct Animation

																										   //RED

	Red.PushBack({ 2, 2, 16, 16 });

	RedShine.PushBack({ 21, 2, 16, 16 });
	RedShine.PushBack({ 39, 2, 16, 16 });
	RedShine.PushBack({ 57, 2, 16, 16 });
	RedShine.loop = false;
	RedShine.speed = 0.2;

	RedOpen.PushBack({ 111, 2, 16, 16 });
	RedOpen.PushBack({ 93, 2, 16, 16 });
	RedOpen.PushBack({ 75, 2, 16, 16 });
	RedOpen.loop = false;
	RedOpen.speed = 0.2;

	//BLUE

	Blue.PushBack({ 2, 20, 16, 16 });

	BlueShine.PushBack({ 21, 20, 16, 16 });
	BlueShine.PushBack({ 39, 20, 16, 16 });
	BlueShine.PushBack({ 57, 20, 16, 16 });
	BlueShine.loop = false;
	BlueShine.speed = 0.2;

	BlueOpen.PushBack({ 111, 20, 16, 16 });
	BlueOpen.PushBack({ 93, 20, 16, 16 });
	BlueOpen.PushBack({ 75, 20, 16, 16 });
	BlueOpen.loop = false;
	BlueOpen.speed = 0.2;

	//GREEN

	Green.PushBack({ 2, 38, 16, 16 });

	GreenShine.PushBack({ 21, 38, 16, 16 });
	GreenShine.PushBack({ 39, 38, 16, 16 });
	GreenShine.PushBack({ 57, 38, 16, 16 });
	GreenShine.loop = false;
	GreenShine.speed = 0.2;

	GreenOpen.PushBack({ 111, 38, 16, 16 });
	GreenOpen.PushBack({ 93, 38, 16, 16 });
	GreenOpen.PushBack({ 75, 38, 16, 16 });
	GreenOpen.loop = false;
	GreenOpen.speed = 0.2;

	//YELLOW

	Yellow.PushBack({ 2, 56, 16, 16 });

	YellowShine.PushBack({ 21, 56, 16, 16 });
	YellowShine.PushBack({ 39, 56, 16, 16 });
	YellowShine.PushBack({ 57, 56, 16, 16 });
	YellowShine.loop = false;
	YellowShine.speed = 0.2;

	YellowOpen.PushBack({ 111, 56, 16, 16 });
	YellowOpen.PushBack({ 93, 56, 16, 16 });
	YellowOpen.PushBack({ 75, 56, 16, 16 });
	YellowOpen.loop = false;
	YellowOpen.speed = 0.2;



	//CHANGES
	//Blue to red

	BlueToRed.PushBack({ 75, 20, 16, 16 });
	BlueToRed.PushBack({ 93, 20, 16, 16 });
	BlueToRed.PushBack({ 111, 20, 16, 16 });
	BlueToRed.PushBack({ 111, 2, 16, 16 });
	BlueToRed.PushBack({ 93, 2, 16, 16 });
	BlueToRed.PushBack({ 75, 2, 16, 16 });
	BlueToRed.loop = false;
	BlueToRed.speed = 0.2;

	//Red to yellow

	RedToYellow.PushBack({ 75, 2, 16, 16 });
	RedToYellow.PushBack({ 93, 2, 16, 16 });
	RedToYellow.PushBack({ 111, 2, 16, 16 });
	RedToYellow.PushBack({ 111, 56, 16, 16 });
	RedToYellow.PushBack({ 93, 56, 16, 16 });
	RedToYellow.PushBack({ 75, 56, 16, 16 });
	RedToYellow.loop = false;
	RedToYellow.speed = 0.2;

	//Yellow to green

	YellowToGreen.PushBack({ 75, 56, 16, 16 });
	YellowToGreen.PushBack({ 93, 56, 16, 16 });
	YellowToGreen.PushBack({ 111, 56, 16, 16 });
	YellowToGreen.PushBack({ 111, 38, 16, 16 });
	YellowToGreen.PushBack({ 93, 38, 16, 16 });
	YellowToGreen.PushBack({ 75, 38, 16, 16 });
	YellowToGreen.loop = false;
	YellowToGreen.speed = 0.2;

	//Green to blue

	GreenToBlue.PushBack({ 75, 38, 16, 16 });
	GreenToBlue.PushBack({ 93, 38, 16, 16 });
	GreenToBlue.PushBack({ 111, 38, 16, 16 });
	GreenToBlue.PushBack({ 111, 20, 16, 16 });
	GreenToBlue.PushBack({ 93, 20, 16, 16 });
	GreenToBlue.PushBack({ 75, 20, 16, 16 });
	GreenToBlue.loop = false;
	GreenToBlue.speed = 0.2;



	idle.loop = false;
	idle.speed = 0.1f;


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
	if (init == true) {
		switch (random_init) {
		case 1:
			current_animation = &BlueOpen;
			State = Power_Up_State::ST_BlueOpen;
			init = false;
			break;

		case 2:
			current_animation = &RedOpen;
			State = Power_Up_State::ST_RedOpen;
			init = false;
			break;

		case 3:
			current_animation = &YellowOpen;
			State = Power_Up_State::ST_YellowOpen;
			init = false;
			break;

		case 4:
			current_animation = &GreenOpen;
			State = Power_Up_State::ST_GreenOpen;
			init = false;
			break;

		}
	}
	

	

	if (time_animation_finished == true) {
		switch (State) {

		case ST_Blue:
			Blue.Reset();
			if (ToShine == false) {
				State = ST_BlueToRed;
				current_animation = &BlueToRed;
				ToShine = true;
			}
			else {
				State = ST_BlueShine;
				current_animation = &BlueShine;
				ToShine = false;
			}
			break;

		case ST_BlueShine:
			BlueShine.Reset();
			State = ST_Blue;
			current_animation = &Blue;
			break;

		case ST_BlueToRed:
			BlueToRed.Reset();
			State = ST_Red;
			current_animation = &Red;
			break;

		case ST_Red:
			Red.Reset();
			if (ToShine == false) {
				State = ST_RedToYellow;
				current_animation = &RedToYellow;
				ToShine = true;
			}
			else {
				State = ST_RedShine;
				current_animation = &RedShine;
				ToShine = false;
			}
			break;

		case ST_RedShine:
			RedShine.Reset();
			State = ST_Red;
			current_animation = &Red;
			break;

		case ST_RedToYellow:
			RedToYellow.Reset();
			State = ST_Yellow;
			current_animation = &Yellow;
			break;

		case ST_Yellow:
			Yellow.Reset();
			if (ToShine == false) {
				State = ST_YellowToGreen;
				current_animation = &YellowToGreen;
				ToShine = true;
			}
			else {
				State = ST_YellowShine;
				current_animation = &YellowShine;
				ToShine = false;
			}
			break;

		case ST_YellowShine:
			YellowShine.Reset();
			State = ST_Yellow;
			current_animation = &Yellow;
			break;

		case ST_YellowToGreen:
			YellowToGreen.Reset();
			State = ST_Green;
			current_animation = &Green;
			break;

		case ST_Green:
			Green.Reset();
			if (ToShine == false) {
				State = ST_GreenToBlue;
				current_animation = &GreenToBlue;
				ToShine = true;
			}
			else {
				State = ST_GreenShine;
				current_animation = &GreenShine;
				ToShine = false;
			}
			break;

		case ST_GreenShine:
			GreenShine.Reset();
			State = ST_Green;
			current_animation = &Green;
			break;

		case ST_GreenToBlue:
			GreenToBlue.Reset();
			State = ST_Blue;
			current_animation = &Blue;
			break;

		case ST_BlueOpen:
			BlueOpen.Reset();
			State = ST_Blue;
			current_animation = &Blue;
			break;

		case ST_RedOpen:
			RedOpen.Reset();
			State = ST_Red;
			current_animation = &Red;
			break;

		case ST_YellowOpen:
			YellowOpen.Reset();
			State = ST_Yellow;
			current_animation = &Yellow;
			break;

		case ST_GreenOpen:
			GreenOpen.Reset();
			State = ST_Green;
			current_animation = &Green;
			break;

		}
		time_animation_finished = false;
	}

	else {
		time_final = SDL_GetTicks() - time_init;
		if (short_time == true)
		{
			if (time_shine == true) {
				if (time_final >= 200) {
					time_animation_finished = true;
					time_init = SDL_GetTicks();
					time_final = 0;
					short_time = false;
					time_shine = false;
				}
			}
			else {
				if (time_final >= 100) {
					time_animation_finished = true;
					time_init = SDL_GetTicks();
					time_final = 0;
					short_time = false;
					time_shine = true;

				}
			}

			

		}
		else
		{
			if (time_final >= 2000) {
				time_animation_finished = true;
				time_final = 0;
				time_init = SDL_GetTicks();
				short_time = true;
			}
		}
	}





	 if (current_animation != nullptr) {

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
		App->render->Blit(PowerUpText, App->enemy->posXpowerUP, App->enemy->posYpowerUP, &(current_animation->GetCurrentFrame()));
		c_power_up->SetPos(App->enemy->posXpowerUP, App->enemy->posYpowerUP);
	}
	return UPDATE_CONTINUE;
}




