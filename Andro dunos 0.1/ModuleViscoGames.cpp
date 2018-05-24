#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleGameIntroduction.h"
#include "ModuleViscoGames.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "Level01.h"
#include "SDL\include\SDL.h"
#include "ModuleAudio.h"
#include "Module_player_2.h"

ModuleViscoGames::ModuleViscoGames()
{
	
}

ModuleViscoGames::~ModuleViscoGames()
{}

// Load assets
bool ModuleViscoGames::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	graphics = App->textures->Load("Images/Visco.png");
	graphics2 = App->textures->Load("Images/Games.png");

	//App->visco_games->Enable();

	if (App->game_intro->IsEnabled() == true)
		App->visco_games->Disable();

	time_passed = 0;
	time_init = SDL_GetTicks();

	App->render->camera.x = App->render->camera.y = 0;

	speedY = 4;
	speedX = 5;

	v.x = 57;
	v.y = 224;
	v.w = 189;
	v.h = 39;

	g.x = 40;
	g.y = -40;
	g.w = 223;
	g.h = 39;

	movX = false;
	return ret;
}

// UnLoad assets
bool ModuleViscoGames::CleanUp()
{
	LOG("Unloading game intro scene");

	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);

	time_passed = 0;


	return true;
}

// PreUpdate: clear screen to black before every frame
update_status ModuleViscoGames::PreUpdate()
{
	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);
	SDL_RenderClear(App->render->renderer);

	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleViscoGames::Update()
{
	time_passed = SDL_GetTicks() - time_init;

	// Controller input
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_Y) && y_pressed == false)
		y_pressed = true;
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_Y) == false)
		y_pressed = false;


	// problem with the camera maybe...

	if ((App->input->keyboard[SDL_SCANCODE_F8] == KEY_DOWN || y_pressed == true) && App->fade->IsFading() == false)
	{
	App->fade->FadeToBlack(this, (Module*)App->insert_coin);
	}

	if (movX == false) {
		v.y -= speedY;
		g.y += speedY;
	}

	if (v.y < 73)
	{
		speedY = 0;
		movX = true;
	}

	if (movX == true && time_passed > 2500)
	{
		v.x -= speedX;
		g.x += speedX;
	}

	if (v.x < -v.w - 20)   // 20 is used because the "games" sprite is widther than "visco", so we don't see a part of the letter 'g' of "games"
	{
		movX = false;
		speedX = 0;
		//animComplete = true;
		App->fade->FadeToBlack(this, (Module*)App->insert_coin, 1.5f);
	}

	//
	if (!App->render->Blit(graphics2, g.x, g.y, NULL)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(graphics, v.x, v.y, NULL)) return update_status::UPDATE_ERROR;
	//position.x -= 1;

	return UPDATE_CONTINUE;
}