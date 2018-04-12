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
	// Stage clear logo
	title.x = 0;
	title.y = 0;
	title.w = 304;
	title.h = 224;

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
	App->level01->Disable();

	music_intro = App->audio->LoadMusic("Music/01_Neo_Geo_Logo.ogg");

	App->audio->PlayMusic(music_intro);

	graphics = App->textures->Load("Stageclear.png");

	return ret;
}

// UnLoad assets
bool ModuleStageClear::CleanUp()
{

	if (App->game_intro->IsEnabled() == true)
		App->game_intro->Disable();

	App->textures->Unload(graphics);

	//no cal
	//App->audio->StopMusic();

	return true;
}

// Update: draw background
update_status ModuleStageClear::Update()
{
	App->render->Blit(graphics, 0, 0, &title);


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		App->fade->FadeToBlack(App->stage_clear, App->game_intro, 1);
	}


	return UPDATE_CONTINUE;
}
