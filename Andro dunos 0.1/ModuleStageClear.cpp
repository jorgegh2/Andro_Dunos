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
#include "SDL\include\SDL.h"
#include "ModuleAudio.h"

ModuleStageClear::ModuleStageClear()
{
	
}

ModuleStageClear::~ModuleStageClear()
{}

// Load assets
bool ModuleStageClear::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	// We don't want the player in the screen
	if (App->player->IsEnabled() == true)
		App->player->Disable();

	graphics = App->textures->Load("Images/Stageclear.png");

	music_intro = App->audio->LoadMusic("Music/01_Neo_Geo_Logo.ogg");

	App->audio->PlayMusic(music_intro);

	App->render->camera.x = App->render->camera.y = 0;

	return ret;
}

// UnLoad assets
bool ModuleStageClear::CleanUp()
{
	LOG("Unloading stage clear scene");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModuleStageClear::Update()
{
	App->render->Blit(graphics, 0, 0, NULL);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->game_intro);
	}

	return UPDATE_CONTINUE;
}
