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

	//

	//visco_games_animation.PushBack({32, 88, 189, 39}); //VISCO
	//visco_games_animation.PushBack({ 15, 128, 223, 39 }); //GAMES

//	visco_games_animation.loop = false;

	//

	graphics = App->textures->Load("Images/Visco.png");	
	graphics2 = App->textures->Load("Images/Games.png");

	App->visco_games->Enable();

	if (App->game_intro->IsEnabled() == true)
		App->visco_games->Disable();

	App->render->camera.x = App->render->camera.y = 0;

	return ret;
}

// UnLoad assets
bool ModuleViscoGames::CleanUp()
{
	LOG("Unloading game intro scene");

	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);

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

	

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->level01);
	}

	//
	if (!App->render->Blit(graphics, (SCREEN_WIDTH / 2) - 94, ((SCREEN_HEIGHT / 2) - 39), nullptr, 0.39f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(graphics2, (SCREEN_WIDTH / 2) - 111, ((SCREEN_HEIGHT / 2) + 1), nullptr, 0.39f)) return update_status::UPDATE_ERROR;
	//position.x -= 1;


	return UPDATE_CONTINUE;
}