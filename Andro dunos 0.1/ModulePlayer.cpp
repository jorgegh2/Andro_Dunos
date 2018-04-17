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
#include "ModuleGameIntroduction.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	graphics = NULL;
	current_animation = NULL;

	position.x = 100;
	position.y = 100;

	// Idle animation
	idle.PushBack({ 94, 108, SHIP_WIDTH, SHIP_HEIGHT });

	// Up animation
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
	downback.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Images/ships.png"); // arcade version
	c_player = App->collision->AddCollider({ position.x, position.y, 27, 17 }, COLLIDER_PLAYER);

	return ret;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	current_animation = &idle;
	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	if (App->player->IsEnabled() == true)
	{

		int speed = 1;
		
		if ((App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) && position.x > 0)
		{
			position.x -= speed;
		}


		if ((App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) && position.x < SCREEN_WIDTH - SHIP_WIDTH)
		{
			position.x += speed;
		}

		if ((App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT) && position.y < SCREEN_HEIGHT - SHIP_HEIGHT)
		{
			position.y += speed;
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


		if ((App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT) && position.y > 0)
		{
			position.y -= speed;
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

		//to change weapon
		if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN)
		{
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				change_weapon = CHANGE_WEAPON::LASER;
				break;

			case CHANGE_WEAPON::LASER:
				change_weapon = CHANGE_WEAPON::BASIC_ATTACK;
				break;
			}
		}
		//////////
		// Shoot 
		if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_DOWN) 
		{
			switch (power_up) {
			case POWER_UPS::POWER_UP_BASIC:
				switch (change_weapon) {

				case CHANGE_WEAPON::BASIC_ATTACK:
					App->particles->AddParticle(App->particles->basic_shoot_0, position.x + 20, position.y, COLLIDER_PLAYER_SHOT);
					break;

				case CHANGE_WEAPON::LASER:
					App->particles->AddParticle(App->particles->laser_0, position.x + 20, position.y, COLLIDER_PLAYER_SHOT);
					break;
				}

			break;

			case POWER_UPS::POWER_UP_1:
				switch (change_weapon) {

				case CHANGE_WEAPON::BASIC_ATTACK:
					App->particles->AddParticle(App->particles->basic_shoot_1, position.x + 20, position.y, COLLIDER_PLAYER_SHOT);
					break;

				case CHANGE_WEAPON::LASER:
					App->particles->AddParticle(App->particles->laser_1, position.x + 20, position.y, COLLIDER_PLAYER_SHOT);
					break;
				}

			break;

			}
		}
		/////////////
		c_player->SetPos(position.x, position.y);
		
		// Draw everything --------------------------------------
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));

	}

	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c_player != nullptr && c_player == c1)
	{
		//code
		App->player->Disable();
		App->fade->FadeToBlack(App->level01, App->game_intro, 1);
	}
}