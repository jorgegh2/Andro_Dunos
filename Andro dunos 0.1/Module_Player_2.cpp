#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "Module_Player_2.h"
#include "SDL\include\SDL.h"
#include "ModuleParticles.h"
#include "ModuleGameOver.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "Level01.h"
#include "ModuleGameIntroduction.h"
#include "ModuleAudio.h"
#include "ModulePlayer.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer2::ModulePlayer2()
{
	graphics = NULL;
	current_animation = &idle;

	// Idle animation
	idle.PushBack({ 154, 108, SHIP_WIDTH, SHIP_HEIGHT });

	// Up animation
	up.PushBack({ 154, 87, SHIP_WIDTH, SHIP_HEIGHT });
	up.PushBack({ 154, 66, SHIP_WIDTH, SHIP_HEIGHT });
	up.loop = false;
	up.speed = 0.1f;

	upback.PushBack({ 154, 87, SHIP_WIDTH, SHIP_HEIGHT });
	upback.PushBack({ 154, 108, SHIP_WIDTH, SHIP_HEIGHT });
	upback.loop = false;
	upback.speed = 0.1f;

	// Down animation
	down.PushBack({ 154, 131, SHIP_WIDTH, SHIP_HEIGHT });
	down.PushBack({ 154, 153, SHIP_WIDTH, SHIP_HEIGHT });
	down.loop = false;
	down.speed = 0.1f;

	downback.PushBack({ 154, 131, SHIP_WIDTH, SHIP_HEIGHT });
	downback.PushBack({ 154, 108, SHIP_WIDTH, SHIP_HEIGHT });
	downback.loop = false;
	downback.speed = 0.1f;
}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Images/Ship/ships.png"); // arcade version
	c_player2 = App->collision->AddCollider({ position.x, position.y, 27, 17 }, COLLIDER_PLAYER, this);

	laser_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-3_(Main_Ships).wav");
	basic_attack_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-1_(Main_Ships).wav");

	player_death = App->audio->LoadSoundEffect("Music/Sounds_effects/Player_Death_Explosion.wav");
	change_weapon_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type_CHANGE.wav");

	destroyed = false;
	position.x = 0;
	position.y = 0;
	location.x = 150;
	location.y = 100;

	return ret;
}

// Unload assets
bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player");

	App->audio->UnloadSoundEffect(player_death);
	App->audio->UnloadSoundEffect(laser_sound);
	App->audio->UnloadSoundEffect(basic_attack_sound);
	App->audio->UnloadSoundEffect(change_weapon_sound);
	App->textures->Unload(graphics);
	current_animation = &idle;

	return true;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	position.x = App->render->camera.x / SCREEN_SIZE + location.x;
	position.y = App->render->camera.y / SCREEN_SIZE + location.y;

	int speed = 2;

	if ((App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) && position.x > App->render->camera.x / SCREEN_SIZE)
	{
		location.x -= speed;
	}

	if ((App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) && position.x < App->render->camera.x / SCREEN_SIZE + SCREEN_WIDTH - SHIP_WIDTH)
	{
		location.x += speed;
	}

	if ((App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT) && position.y < App->render->camera.y / SCREEN_SIZE + SCREEN_HEIGHT - SHIP_HEIGHT)
	{
		location.y += speed;
		if (current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
	}

	else if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_UP)
		if (current_animation != &downback)
		{
			downback.Reset();
			current_animation = &downback;
		}

	if ((App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT) && position.y > App->render->camera.y / SCREEN_SIZE)
	{
		location.y -= speed;
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
	}

	else if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_UP)
		if (current_animation != &upback)
		{
			upback.Reset();
			current_animation = &upback;
		}


	if (App->input->keyboard[SDL_SCANCODE_O] == KEY_STATE::KEY_DOWN)
	{
		switch (change_weapon) {

		case CHANGE_WEAPON::BASIC_ATTACK:
			change_weapon = CHANGE_WEAPON::LASER;
			App->audio->PlaySoundEffect(change_weapon_sound);

			break;

		case CHANGE_WEAPON::LASER:
			change_weapon = CHANGE_WEAPON::BASIC_ATTACK;
			App->audio->PlaySoundEffect(change_weapon_sound);

			break;
		}
	}


	// POWERUP
	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_DOWN)
	{
		switch (power_up) {

		case POWER_UPS::POWER_UP_BASIC:
			power_up = POWER_UPS::POWER_UP_1;
			break;

		case POWER_UPS::POWER_UP_1:
			power_up = POWER_UPS::POWER_UP_2;
			break;

		case POWER_UPS::POWER_UP_2:
			power_up = POWER_UPS::POWER_UP_BASIC;
			break;
		}
	}
	//
	//////////
	// Shoot 
	if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN)
	{
		switch (power_up) {
		case POWER_UPS::POWER_UP_BASIC:
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				App->particles->AddParticle(App->particles->basic_shoot_0_down, position.x + 20, position.y + 11, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->basic_shoot_0_up, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(basic_attack_sound);
				break;

			case CHANGE_WEAPON::LASER:
				App->particles->AddParticle(App->particles->laser_0, position.x + 20, position.y + 10, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(laser_sound);
				break;
			}

			break;

		case POWER_UPS::POWER_UP_1:
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				App->particles->AddParticle(App->particles->basic_shoot_1_down, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->basic_shoot_1_up, position.x + 20, position.y + 4, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->basic_shoot_1, position.x + 26, position.y + 10, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(basic_attack_sound);
				break;

			case CHANGE_WEAPON::LASER:
				App->particles->AddParticle(App->particles->laser_1, position.x + 12, position.y - 2, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_1_5, position.x + 12, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(laser_sound);
				break;
			}

			break;

		case POWER_UPS::POWER_UP_2:
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				App->particles->AddParticle(App->particles->basic_shoot_2_down, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->basic_shoot_2_up, position.x + 20, position.y + 2, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->basic_shoot_2, position.x + 20, position.y + 9, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(basic_attack_sound);
				break;

			case CHANGE_WEAPON::LASER:
				App->particles->AddParticle(App->particles->laser_1, position.x + 12, position.y - 2, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_1_5, position.x + 12, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_2, position.x + 5, position.y - 2, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_2_5, position.x + 5, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(laser_sound);
				break;
			}

			break;


			
		}
	}


	if (!App->player->god_mode)
	{
		c_player2->SetPos(position.x, position.y);
	}
	// Draw everything --------------------------------------
	if (destroyed == false) {
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	}
	return UPDATE_CONTINUE;
}

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2)
{
	if (c_player2 != nullptr && c_player2 == c1 && App->fade->IsFading() == false)
	{
		//code
		App->audio->PlaySoundEffect(player_death);
		App->particles->AddParticle(App->particles->explosion2, position.x, position.y);
		App->player2->Disable();
		App->fade->FadeToBlack(App->level01, App->game_over, 1);
		destroyed == true;
	}
}