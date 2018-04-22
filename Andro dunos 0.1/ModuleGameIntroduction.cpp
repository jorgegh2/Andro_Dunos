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
#include "ModulePlayersMenu.h"

ModuleGameIntroduction::ModuleGameIntroduction()
{
	// neo geo anim
	neo_geo.PushBack({ 142, 7, 218, 38 });
	neo_geo.PushBack({ 142, 50, 218, 36 });
	neo_geo.PushBack({ 142, 94, 218, 36 });
	neo_geo.PushBack({ 142, 138, 218, 36 });
	neo_geo.PushBack({ 142, 182, 218, 38 });
	neo_geo.PushBack({ 142, 224, 218, 38 });
	neo_geo.PushBack({ 142, 265, 218, 38 });
	neo_geo.PushBack({ 142, 305, 218, 38 });
	neo_geo.PushBack({ 142, 345, 218, 38 });
	neo_geo.PushBack({ 142, 384, 218, 38 });
	neo_geo.PushBack({ 142, 425, 218, 38 });
	neo_geo.PushBack({ 142, 466, 218, 38 });
	neo_geo.PushBack({ 142, 507, 218, 38 });
	neo_geo.PushBack({ 142, 548, 218, 38 });
	neo_geo.PushBack({ 142, 588, 218, 38 });
	neo_geo.PushBack({ 142, 629, 218, 38 });
	neo_geo.PushBack({ 142, 668, 218, 38 });  // animation starts getting shorter on y-axis
	neo_geo.PushBack({ 142, 711, 218, 38 });
	neo_geo.PushBack({ 142, 752, 218, 38 });
	neo_geo.PushBack({ 142, 799, 218, 38 });
	neo_geo.PushBack({ 142, 851, 218, 38 });
	neo_geo.PushBack({ 142, 900, 218, 38 });
	neo_geo.PushBack({ 142, 946, 218, 38 });
	neo_geo.PushBack({ 142, 991, 218, 38 });
	neo_geo.PushBack({ 142, 1039, 218, 38 });
	neo_geo.PushBack({ 142, 1097, 218, 38 });
	neo_geo.PushBack({ 142, 1160, 218, 38 });
	neo_geo.PushBack({ 142, 1227, 218, 38 });
	neo_geo.PushBack({ 142, 1294, 218, 38 });
	neo_geo.PushBack({ 142, 1368, 218, 38 });
	neo_geo.PushBack({ 142, 1432, 218, 38 });
	neo_geo.PushBack({ 142, 1503, 218, 38 });
	neo_geo.PushBack({ 142, 1566, 218, 38 });
	neo_geo.PushBack({ 142, 1630, 218, 38 });
	neo_geo.PushBack({ 142, 1692, 218, 38 });
	neo_geo.PushBack({ 142, 1760, 218, 38 });
	neo_geo.PushBack({ 142, 1831, 218, 38 });
	neo_geo.PushBack({ 142, 1906, 218, 38 });
	neo_geo.PushBack({ 142, 1974, 218, 38 });
	neo_geo.PushBack({ 142, 2049, 218, 38 });
	neo_geo.PushBack({ 142, 2126, 218, 38 });
	neo_geo.PushBack({ 142, 2204, 218, 38 });
	neo_geo.PushBack({ 142, 2273, 218, 38 });
	neo_geo.PushBack({ 142, 2338, 218, 38 });
	neo_geo.PushBack({ 142, 2395, 218, 38 });
	neo_geo.PushBack({ 142, 2450, 218, 38 });
	neo_geo.PushBack({ 142, 2506, 218, 38 });

	neo_geo.loop = false;
	neo_geo.speed = 0.4f;

	// snk anim
	snk.PushBack({ 17, 35, 72, 19 });
	snk.PushBack({ 94, 35, 72, 19 });
	snk.PushBack({ 169, 35, 72, 19 });
	snk.PushBack({ 18, 64, 72, 19 });
	snk.PushBack({ 94, 64, 72, 19 });
	snk.PushBack({ 170, 64, 72, 19 });
	snk.PushBack({ 18, 90, 72, 19 });
	snk.PushBack({ 94, 90, 72, 19 });
	snk.PushBack({ 170, 90, 72, 19 });
	snk.PushBack({ 18, 114, 72, 19 });
	snk.PushBack({ 94, 114, 72, 19 });
	snk.PushBack({ 169, 114, 72, 19 });
	snk.PushBack({ 17, 140, 72, 19 });
	snk.PushBack({ 94, 140, 72, 19 });
	snk.PushBack({ 170, 140, 72, 19 });
	snk.PushBack({ 17, 164, 72, 19 });
	snk.PushBack({ 94, 164, 72, 19 });
	snk.PushBack({ 171, 164, 72, 19 });
	snk.loop = false;
	snk.speed = 0.4f;
}

ModuleGameIntroduction::~ModuleGameIntroduction()
{}

// Load assets
bool ModuleGameIntroduction::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	if (App->level01->IsEnabled() == true)
		App->level01->Disable();

	graphics = App->textures->Load("Images/ng_anim.png");
	graphics2 = App->textures->Load("Images/max_330.png");
	graphics3 = App->textures->Load("Images/snk_animation.png");

	music_intro = App->audio->LoadMusic("Music/01_Neo_Geo_Logo.ogg");

	App->audio->PlayMusic(music_intro,-1,1);

	App->render->camera.x = App->render->camera.y = 0;
	time_passed = 0;

	// time code
	time_init = SDL_GetTicks();
	time_passed = 0;

	
	return ret;
}

// UnLoad assets
bool ModuleGameIntroduction::CleanUp()
{
	LOG("Unloading game intro scene");

	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->textures->Unload(graphics3);

	App->audio->UnloadMusic(music_intro);

	change_bg = false;

	// Reset time counter
	time_passed = 0;

	return true;
}

// PreUpdate: clear screen to black before every frame
update_status ModuleGameIntroduction::PreUpdate()
{
	time_passed = SDL_GetTicks() - time_init;

	if (time_passed > 1500) change_bg = true;

	if (!change_bg) {
		
		SDL_SetRenderDrawColor(App->render->renderer, 255, 255, 255, 0);
	}
	else {
		
		SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 0);
	}
	
	SDL_RenderClear(App->render->renderer);

	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleGameIntroduction::Update()
{
	time_passed = SDL_GetTicks() - time_init;

	current_animation = &neo_geo;
	current_animation2 = &snk;

	App->render->Blit(graphics, 40, 50, &(current_animation->GetCurrentFrame()));


	if (time_passed > 1700)
		App->render->Blit(graphics2, 83, 120, NULL);

	if (time_passed > 2500)
		App->render->Blit(graphics3, 112, 170, &(current_animation2->GetCurrentFrame()));

	if ((time_passed > 5000 || App->input->keyboard[SDL_SCANCODE_F8] == KEY_STATE::KEY_DOWN) && App->fade->IsFading() == false)
	{
		App->render->camera.x = App->render->camera.y = 0;
		App->fade->FadeToBlack(this, (Module*)App->visco_games);
	}
	/*
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN) {
		//App->fade->FadeToBlack(this, (Module*)App->players_menu);
		Disable();
		App->players_menu->Enable();
		App->audio->StopMusic();
	}*/

	return UPDATE_CONTINUE;
}
