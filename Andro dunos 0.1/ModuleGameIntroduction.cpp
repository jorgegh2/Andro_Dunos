#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleGameIntroduction.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "Level01.h"
#include "SDL\include\SDL.h"
#include "ModuleAudio.h"
#include "Module_player_2.h"

ModuleGameIntroduction::ModuleGameIntroduction()
{

}

ModuleGameIntroduction::~ModuleGameIntroduction()
{}

// Load assets
bool ModuleGameIntroduction::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	graphics = App->textures->Load("Images/Title.png");

	music_intro = App->audio->LoadMusic("Music/01_Neo_Geo_Logo.ogg");

	App->audio->PlayMusic(music_intro);

	App->render->camera.x = App->render->camera.y = 0;

	return ret;
}

// UnLoad assets
bool ModuleGameIntroduction::CleanUp()
{
	LOG("Unloading game intro scene");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModuleGameIntroduction::Update()
{
	App->render->Blit(graphics, 0, 0, NULL);
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->visco_games);
	}

	return UPDATE_CONTINUE;
}
