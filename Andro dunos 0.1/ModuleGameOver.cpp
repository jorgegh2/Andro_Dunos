#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleGameIntroduction.h"
#include "ModuleGameOver.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "Level01.h"
#include "ModuleStageClear.h"
#include "SDL\include\SDL.h"
#include "ModuleAudio.h"
#include "Animation.h"
#include "ModuleViscoGames.h"
#include "ModuleInsertCoin.h"
#include "ModulePlayersMenu.h"

ModuleGameOver::ModuleGameOver()
{
	// A LOT better method to PushBack. All frames must have (and they have) the same size so we can just do a loop
	// Like so, there won't be so many pushbacks...

	for (x = 0; x < 11; x++)
	{
		for (y = 0; y < 11; y = y++)
		{
			gm_over.PushBack({x * ZONE_GO_SIZE, y * ZONE_GO_SIZE, ZONE_GO_SIZE, ZONE_GO_SIZE });	
		}
	}

	gm_over.loop = false;
	gm_over.speed = 0.4f;
}

ModuleGameOver::~ModuleGameOver()
{}

// Load assets
bool ModuleGameOver::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	// We don't want the player in the screen
	if (App->player->IsEnabled() == true)
		App->player->Disable();

	// Disable modules for debug mode
	if (App->game_intro->IsEnabled() == true)
		App->game_intro->Disable();
	if (App->level01->IsEnabled() == true)
		App->level01->Disable();
	if (App->stage_clear->IsEnabled() == true)
		App->stage_clear->Disable();
	if (App->visco_games->IsEnabled() == true)
		App->visco_games->Disable();
	if (App->insert_coin->IsEnabled() == true)
		App->insert_coin->Disable();
	if (App->players_menu->IsEnabled() == true)
		App->players_menu->Disable();

	graphics = App->textures->Load("Images/gameover.png");

	music_go = App->audio->LoadMusic("Music/Songs/18_Game_Over.ogg");

	App->audio->PlayMusic(music_go,-1,1);

	App->render->camera.x = App->render->camera.y = 0;

	return ret;
}

// UnLoad assets
bool ModuleGameOver::CleanUp()
{
	LOG("Unloading stage clear scene");

	gm_over.Reset();

	App->textures->Unload(graphics);
	App->audio->UnloadMusic(music_go);

	return true;
}

// PreUpdate: clear screen to black before every frame
update_status ModuleGameOver::PreUpdate()
{
	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);
	SDL_RenderClear(App->render->renderer);

	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleGameOver::Update()
{
	current_animation = &gm_over;

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

	App->render->Blit(graphics, 12, -10 /*pivot in the centre, so this number must be negative*/, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}
