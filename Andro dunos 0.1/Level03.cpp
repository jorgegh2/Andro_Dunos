#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "Level03.h"
#include "ModulePlayersMenu.h"
#include "Level01.h"
#include "ModuleInput.h"
#include "ModuleInsertCoin.h"
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
	lay1.x = 0;
	lay1.y = 0;
	lay1.w = 1416;
	lay1.h = 69;

	lay2.x = 0;
	lay2.y = 85;
	lay2.w = 1425;
	lay2.h = 70;

	lay3.x = 0;
	lay3.y = 170;
	lay3.w = 1437;
	lay3.h = 104;

	lay4.x = 0;
	lay4.y = 284;
	lay4.w = 1054;
	lay4.h = 117;

	lay5.x = 0;
	lay5.y = 422;
	lay5.w = 1432;
	lay5.h = 110;

	lay6.x = 0;
	lay6.y = 533;
	lay6.w = 1425;
	lay6.h = 141;

	lay7.x = 0;
	lay7.y = 691;
	lay7.w = 1489;
	lay7.h = 85;

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
	App->render->camera.x = 0;
	App->render->camera.y = 0;

	//Enemies Correct Coord.


	// Colliders ---


	background1 = App->textures->Load("Images/Level03/Standard_background_Level 3.png");
	layout[1] = App->textures->Load("Images/Level03/layout4_5.png");
	layout[2] = App->textures->Load("Images/Level03/layout5.png");
	layout[0] = App->textures->Load("Images/Level03/layout_v1.png");
	finalbackground = App->textures->Load("Images/Level03/final_background.png");

	music_level03 = App->audio->LoadMusic("Music/Songs/09_Stage_3-Alien-Intro.ogg");
	music_level03v2 = App->audio->LoadMusic("Music/Songs/09_Stage_3-Alien-Loop.ogg");
	App->audio->PlayMusic(music_level03);

	i = 0;

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
	App->textures->Unload(finalbackground);
	App->audio->UnloadMusic(music_level03);
	App->audio->UnloadMusic(music_level03v2);
	App->UI->Disable();

	return true;
}

update_status Level03::Update()
{

	if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN || App->players_menu->coin_inserted == true)
	{
		App->players_menu->coin_inserted = false;
		//Mix_VolumeChunk(coin, MIX_MAX_VOLUME);
		App->audio->PlaySoundEffect(App->players_menu->coin);
		App->players_menu->cr++;
	}


	// Player 2 spawn in-level
	if (App->player2->IsEnabled() == false)
		if (App->input->keyboard[SDL_SCANCODE_BACKSPACE] == 1 || SDL_GameControllerGetButton(App->input->controller2, SDL_CONTROLLER_BUTTON_DPAD_LEFT))
		{
			App->players_menu->cr--;
			App->player2->Enable();
		}


	// Move camera forward -----------------------------
	if (App->render->camera.x <= 11000 * SCREEN_SIZE) {
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
	for (int i = 0; i < 18; ++i) if (!App->render->Blit(finalbackground, 3005 + 80 * i, 0, NULL, 0.38f)) return update_status::UPDATE_ERROR;
	if (App->render->camera.x >= 7100 * SCREEN_SIZE && App->render->camera.x <= 7910 * SCREEN_SIZE) {
		if (i < 255) i += 3;
		App->render->DrawQuad({ App->render->camera.x / SCREEN_SIZE, 0, SCREEN_WIDTH, SCREEN_HEIGHT }, 0, 0, 0, i);
	}
	if (App->render->camera.x >= 7910 * SCREEN_SIZE && App->render->camera.x <= 8010 * SCREEN_SIZE) {
		if (i > 0) i -= 5;
		App->render->DrawQuad({ App->render->camera.x / SCREEN_SIZE, 0, SCREEN_WIDTH, SCREEN_HEIGHT }, 0, 0, 0, i);
	}


	if (!App->render->Blit(layout[0], SCREEN_WIDTH + 50, 0, &lay1, 0.75f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[0], SCREEN_WIDTH + 50 + 1416, 0, &lay2, 0.75f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[0], SCREEN_WIDTH + 50 + 2833, 0, &lay3, 0.75f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[0], SCREEN_WIDTH + 50 + 4251, 0, &lay4, 0.75f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[0], SCREEN_WIDTH + 50, 147, &lay5, 0.75f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[0], SCREEN_WIDTH + 50 + 1416, 100, &lay6, 0.75f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[0], SCREEN_WIDTH + 50 + 2834, 162, &lay7, 0.75f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[1], 6080, 0, nullptr, 0.75f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[2], 6987, 0, nullptr, 0.75f)) return update_status::UPDATE_ERROR;
	//colliders
	if (App->input->keyboard[SDL_SCANCODE_4] == KEY_STATE::KEY_REPEAT)
	{
		App->render->camera.x += 20 * SCREEN_SIZE;
	}
	if (App->input->keyboard[SDL_SCANCODE_F8] == 1 || y_pressed == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->game_intro);
		
	}

	return UPDATE_CONTINUE;
}
