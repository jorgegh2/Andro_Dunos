#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInsertCoin.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "Level01.h"
#include "Level03.h"
#include "SDL\include\SDL.h"
#include "ModuleAudio.h"
#include "Module_player_2.h"
#include "ModulePlayersMenu.h"

ModuleInsertCoin::ModuleInsertCoin()
{
	insert_coin1.PushBack({ 0, 0, 88, 8 });
	insert_coin1.PushBack({ 0, 88, 88, 8 });
	insert_coin1.loop = true;
	insert_coin1.speed = 0.02f;
}

ModuleInsertCoin::~ModuleInsertCoin()
{}

// Load assets
bool ModuleInsertCoin::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	graphics = App->textures->Load("Images/insert_coin.png");
	//graphics2 = App->textures->Load("Images/max_330.png");

	coin = App->audio->LoadSoundEffect("Music/Sounds_effects/COIN_inserted.wav");

	App->render->camera.x = App->render->camera.y = 0;

	return ret;
}

// UnLoad assets
bool ModuleInsertCoin::CleanUp()
{
	LOG("Unloading insert coin scene");

	App->textures->Unload(graphics);
	//App->textures->Unload(graphics2);
	App->audio->UnloadSoundEffect(coin);

	return true;
}

// PreUpdate: clear screen to black before every frame
update_status ModuleInsertCoin::PreUpdate()
{
	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 0);
	SDL_RenderClear(App->render->renderer);

	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleInsertCoin::Update()
{

	current_animation = &insert_coin1;
	i_coin = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, 104, 120, &i_coin);


	// Controller input
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_DPAD_DOWN) && dpad_down == false)
	{
		dpad_down = true;
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_DPAD_DOWN) == false)
	{
		dpad_down = false;
	}


	if ((App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN || dpad_down == true) && App->fade->IsFading() == false)
	{
		//Mix_VolumeChunk(coin, MIX_MAX_VOLUME);
		App->audio->PlaySoundEffect(coin);
		App->fade->FadeToBlack(this, (Module*)App->players_menu);
		App->players_menu->cr++;
	}

	return UPDATE_CONTINUE;
}
