#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "Level03.h"
#include "Level01.h"
#include "ModuleInput.h"
#include "ModuleGameIntroduction.h"
#include "ModuleStageClear.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "Module_Player_2.h"
#include "UI.h"

Level03::Level03()
{

}

Level03::~Level03()
{

}

// Load assets
bool Level03::Start()
{
	LOG("Loading background assets");

	if (App->player2->Two_Players == true)
		App->player2->Enable();
	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->UI->Enable();
	App->level01->Disable();

	//Enemies Correct Coord.


	// Colliders ---


	background1 = App->textures->Load("Images/Level03/Standard_background_Level 3.png");
	layout[0] = App->textures->Load("Images/Level03/layout1.png");
	layout[1] = App->textures->Load("Images/Level03/layout2.png");
	layout[2] = App->textures->Load("Images/Level03/layout3.png");
	layout[3] = App->textures->Load("Images/Level03/layout4.png");
	layout[4] = App->textures->Load("Images/Level03/layout5.png");
	finalbackground = App->textures->Load("Images/Level03/final_background.png");

	music_level03 = App->audio->LoadMusic("Music/Songs/09_Stage_3-Alien-Intro.ogg");
	music_level03v2 = App->audio->LoadMusic("Music/Songs/09_Stage_3-Alien-Loop.ogg");
	App->audio->PlayMusic(music_level03);

	return true;
}

// Unload assets
bool Level03::CleanUp()
{
	LOG("Unload Level03");

	App->player->Disable();
	App->player2->Disable();
	App->collision->Disable();
	App->particles->Disable();

	App->textures->Unload(background1);
	App->textures->Unload(layout[0]);
	App->textures->Unload(layout[1]);
	App->textures->Unload(layout[2]);
	App->textures->Unload(layout[3]);
	App->textures->Unload(layout[4]);
	App->textures->Unload(finalbackground);
	App->audio->UnloadMusic(music_level03);
	App->audio->UnloadMusic(music_level03v2);
	App->UI->Disable();

	return true;
}

update_status Level03::Update()
{
	// Move camera forward -----------------------------
	if (App->render->camera.x <= 11900 * SCREEN_SIZE) {
		App->render->camera.x += 1 * SCREEN_SIZE; //speed in x axes
	}

	// Controllers input
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_DPAD_DOWN) && y_pressed == false)
	{
		y_pressed = true;
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_DPAD_DOWN) == false)
	{
		y_pressed = false;
	}


	// Music
	if (App->render->camera.x >= 1150 * SCREEN_SIZE && mus_change == false) {
		App->audio->StopMusic();
		App->audio->PlayMusic(music_level03v2);
		mus_change = true;
	}

	// Draw everything --------------------------------------
	for (int i = 0; i < 10; ++i) if (!App->render->Blit(background1, 400 * i, 0, NULL, 0.38f)) return update_status::UPDATE_ERROR;
	for (int i = 0; i < 17; ++i) if (!App->render->Blit(finalbackground, 3470 + 80 * i, 0, NULL, 0.38f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[0], 0, 0, nullptr, 0.75f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[1], 1842, 0, nullptr, 0.75f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[2], 3684, 0, nullptr, 0.75f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[3], 5530, 0, nullptr, 0.75f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[4], 7678, 0, nullptr, 0.75f)) return update_status::UPDATE_ERROR;
	//colliders
	if (App->input->keyboard[SDL_SCANCODE_4] == KEY_STATE::KEY_REPEAT)
	{
		App->render->camera.x += 20;
	}
	if (App->input->keyboard[SDL_SCANCODE_F8] == 1 || y_pressed == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->game_intro);
		
	}

	return UPDATE_CONTINUE;
}
