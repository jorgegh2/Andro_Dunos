#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 100;

	// Idle animation
	idle.PushBack({ 94, 108, 27, 17 });

	// Up animation
	up.PushBack({ 94, 87, 27, 15 });
	up.PushBack({ 94, 66, 27, 15 });
	up.loop = false;
	up.speed = 0.1f;

	// Down animation
	down.PushBack({ 94, 131, 27, 16 });
	down.PushBack({ 94, 153, 27, 17 });
	down.loop = false;
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

// Update: draw background
update_status ModulePlayer::Update()
{

	Animation* current_animation = &idle;


	int speed = 1;
	//if (App->player->IsEnabled() == true) {
	/*if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
	position.y -= speed;
	if (current_animation != &up)
	{
	up.Reset();
	current_animation = &up;
	}
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
	position.y += speed;
	if (current_animation != &down)
	{
	down.Reset();
	current_animation = &down;
	}
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == 1)
	{
	if (App->input->keyboard[SDL_SCANCODE_UP] == 1) {
	current_animation = &up;
	position.x += speed;
	}
	else if (App->input->keyboard[SDL_SCANCODE_DOWN] == 1) {
	current_animation = &down;
	position.x += speed;
	}
	else {
	current_animation = &idle;
	position.x += speed;
	}
	}

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == 1)
	{
	if (App->input->keyboard[SDL_SCANCODE_UP] == 1) {
	current_animation = &up;
	position.x -= speed;
	}
	else if (App->input->keyboard[SDL_SCANCODE_DOWN] == 1) {
	current_animation = &down;
	position.x -= speed;
	}
	else {
	current_animation = &idle;
	position.x -= speed;
	}
	}*/

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
	}

	// TODO: Control the ship doesn't get out of the screen


	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &(current_animation->GetCurrentFrame()));
	/*if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
		current_animation = &idle;*/
	//}

	return UPDATE_CONTINUE;
}

bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}