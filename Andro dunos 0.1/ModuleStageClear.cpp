#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleGameIntroduction.h"
#include "ModuleStageClear.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "Level01.h"
#include "Level03.h"
#include "ModuleGameOver.h"
#include "SDL\include\SDL.h"
#include "ModuleAudio.h"
#include "Animation.h"
#include "ModuleViscoGames.h"
#include "ModuleInsertCoin.h"
#include "ModulePlayersMenu.h"
#include "Module_Player_2.h"
#include "ModuleParticles.h"

ModuleStageClear::ModuleStageClear()
{
	// Stage clear screen

	//Animation
	stg_clear.PushBack({ 13, 19, 293, 47 });  // 1st column
	stg_clear.PushBack({ 13, 74, 293, 47 });
	stg_clear.PushBack({ 13, 129, 293, 42 });
	stg_clear.PushBack({ 13, 179, 293, 41 });
	stg_clear.PushBack({ 13, 228, 293, 38 });
	stg_clear.PushBack({ 13, 274, 293, 36 });
	stg_clear.PushBack({ 13, 318, 293, 32 });
	stg_clear.PushBack({ 13, 359, 293, 31 });
	stg_clear.PushBack({ 13, 399, 293, 28 });
	stg_clear.PushBack({ 13, 435, 293, 26 });
	stg_clear.PushBack({ 13, 469, 293, 22 });
	stg_clear.PushBack({ 13, 501, 293, 20 });
	stg_clear.PushBack({ 13, 529, 293, 17 });
	stg_clear.PushBack({ 317, 19, 294, 15 });  // 2nd column
	stg_clear.PushBack({ 317, 42, 294, 12 });
	stg_clear.PushBack({ 317, 61, 294, 9 });
	stg_clear.PushBack({ 317, 64, 294, 6 });
	stg_clear.PushBack({ 317, 88, 259, 2 });
	stg_clear.PushBack({ 320, 98, 256, 1 });
	stg_clear.PushBack({ 317, 107, 259, 5 });
	stg_clear.PushBack({ 315, 117, 261, 7 });
	stg_clear.PushBack({ 315, 129, 261, 9 });
	stg_clear.PushBack({ 316, 145, 261, 10 });
	stg_clear.PushBack({ 317, 159, 261, 12 });
	stg_clear.PushBack({ 316, 179, 261, 12 });
	stg_clear.PushBack({ 315, 200, 261, 14 });
	stg_clear.PushBack({ 315, 220, 261, 16 });
	stg_clear.PushBack({ 316, 238, 261, 18 });
	stg_clear.PushBack({ 315, 265, 261, 19 });
	stg_clear.PushBack({ 315, 292, 261, 21 });
	stg_clear.PushBack({ 315, 318, 261, 23 });
	stg_clear.PushBack({ 315, 347, 261, 25 });
	stg_clear.PushBack({ 316, 378, 261, 25 });
	stg_clear.PushBack({ 315, 408, 261, 27 });
	stg_clear.PushBack({ 315, 442, 261, 27 });
	stg_clear.loop = false;
	stg_clear.speed = 0.4f;
}

ModuleStageClear::~ModuleStageClear()
{}

// Load assets
bool ModuleStageClear::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	// We don't want the player in the screen
	/*if (App->player->IsEnabled() == true)
		App->player->Disable();*/

	App->player->god_mode = true;


	// Disable modules for debug mode
	if (App->game_intro->IsEnabled() == true)
		App->game_intro->Disable();

	App->player->c_player->SetPos(-100, -100);
	if (App->player2->IsEnabled() == true)
		App->player2->c_player2->SetPos(-100, -100);

	if (App->level03->IsEnabled() == true)
		App->level01->Disable();
	if (App->game_over->IsEnabled() == true)
		App->game_over->Disable();
	if (App->visco_games->IsEnabled() == true)
		App->visco_games->Disable();
	if (App->insert_coin->IsEnabled() == true)
		App->insert_coin->Disable();
	if (App->players_menu->IsEnabled() == true)
		App->players_menu->Disable();

	graphics = App->textures->Load("Images/stage_clear2.png");

	music_stage_clear = App->audio->LoadMusic("Music/Songs/06_Stage_Clear.ogg");

	App->audio->PlayMusic(music_stage_clear,-1,1);

	//App->render->camera.x = App->render->camera.y = 0;
	time_init = SDL_GetTicks();
	time_passed = 0;
	return ret;
}

// UnLoad assets
bool ModuleStageClear::CleanUp()
{
	LOG("Unloading stage clear scene");

	stg_clear.Reset();

	App->textures->Unload(graphics);
	App->audio->UnloadMusic(music_stage_clear);
	time_passed = 0;

	return true;
}

// PreUpdate: clear screen to black before every frame
update_status ModuleStageClear::PreUpdate()
{
	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);
	SDL_RenderClear(App->render->renderer);

	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleStageClear::Update()
{
	time_passed = SDL_GetTicks() - time_init;
	current_animation = &stg_clear;


	// Controller input
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_DPAD_DOWN) && y_pressed == false)
	{
		y_pressed = true;
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_DPAD_DOWN) == false)
	{
		y_pressed = false;
	}


	if ((App->input->keyboard[SDL_SCANCODE_F8] == KEY_DOWN || y_pressed == true) && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->game_intro);
	}

	/*if (time_passed > 5000 && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->game_intro);
	}*/

	App->render->Blit(graphics, 20, 30, &(current_animation->GetCurrentFrame()), false);

	return UPDATE_CONTINUE;
}
