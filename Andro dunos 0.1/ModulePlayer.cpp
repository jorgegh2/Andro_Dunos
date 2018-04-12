#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL.h"
#include "ModuleParticles.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	graphics = NULL;
	current_animation = NULL;

	position.x = 100;
	position.y = 100;

	// Idle animation
	idle.PushBack({94, 108, 27, 17});

	// Up animation
	up.PushBack({94, 87, 27, 15});
	up.PushBack({94, 66, 27, 15});
	up.loop = false;
	up.speed = 0.1f;

	// Down animation
	down.PushBack({94, 131, 27, 16});
	down.PushBack({94, 153, 27, 17});
	up.loop = false;
	down.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("ships.png"); // arcade version
	
	return ret;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	if (App->player->IsEnabled() == true)
	{
		Animation* current_animation = &idle;

		int speed = 1;

		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		{
			position.x -= speed;
		}

		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		{
			position.x += speed;
		}

		if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
		{
			position.y += speed;
			if (current_animation != &down)
			{
				down.Reset();
				current_animation = &down;
			}
		}

		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
		{
			position.y -= speed;
			if (current_animation != &up)
			{
				up.Reset();
				current_animation = &up;
			}
		}

			// Shoot laser
			if (App->input->keyboard[SDL_SCANCODE_Q] == KEY_STATE::KEY_DOWN) {

				App->particles->AddParticle(App->particles->laser, position.x + 20 , position.y - 14);
			}

			// TODO: Control the ship doesn't get out of the screen


			// Draw everything --------------------------------------
			SDL_Rect r = current_animation->GetCurrentFrame();

			App->render->Blit(graphics, position.x, position.y - r.h, &r);
	}
	
	return UPDATE_CONTINUE;
}