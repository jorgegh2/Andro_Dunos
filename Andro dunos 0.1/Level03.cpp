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
#include <stdio.h>
#include "ModuleGameIntroduction.h"
#include "ModuleFonts.h"
#include "ModuleStageClear.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "Module_Player_2.h"
#include "UI.h"

Level03::Level03()
{

	//layout animation

	top_layout1.PushBack({ 0, 0, 1425, 70 });
	top_layout1.PushBack({ 0, 425, 1420, 70 });
	top_layout1.loop = true;
	top_layout1.speed = 0.1f;
	
	top_layout2.PushBack({ 0, 85, 1425, 70 });
	top_layout2.PushBack({ 0, 539, 1420, 68 });
	top_layout2.loop = true;
	top_layout2.speed = 0.1f;

	top_layout3.PushBack({ 0, 170, 1440, 104 });
	top_layout3.PushBack({ 0, 624, 1430, 55 });
	top_layout3.loop = true;
	top_layout3.speed = 0.1f;

	top_layout4.PushBack({ 0, 284, 1060, 117 });
	top_layout4.PushBack({ 0, 680, 1060, 116 });
	top_layout4.loop = true;
	top_layout4.speed = 0.1f;

	bot_layout1.PushBack({ 0, 425, 1430, 80 });
	bot_layout1.PushBack({ 0, -1, 1424, 80 });
	bot_layout1.loop = true;
	bot_layout1.speed = 0.1f;

	bot_layout2.PushBack({ 0, 538, 1430, 122 });
	bot_layout2.PushBack({ 0, 112, 1424, 122 });
	bot_layout2.loop = true;
	bot_layout2.speed = 0.1f;

	bot_layout3.PushBack({ 0, 708, 1401, 57 });
	bot_layout3.PushBack({ 0, 281, 1426, 60 });
	bot_layout3.loop = true;
	bot_layout3.speed = 0.1f;
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
	App->enemy->Enable();
	App->UI->Enable();
	App->level01->Disable();
	App->render->camera.x = 0;
	App->render->camera.y = 0;

	//Enemies Correct Coord.

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 490, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 498, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 506, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 512, 80);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 540, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 548, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 556, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 562, 80);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 800, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 808, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 816, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 822, 80);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 880, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 888, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 896, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_20, 902, 80);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_POWER_UP, 950, 120);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_21, 1000, 70);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_21, 1100, 110);
	
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_21, 1300, 70);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_21, 1400, 110);
	
	
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_22, 1600, 70);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_22, 1680, 110);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_22, 1780, 90);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 1900, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 1925, 130);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 1950, 70);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 1975, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2000, 90);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2025, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2050, 130);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2075, 70);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2100, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2125, 90);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2150, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2175, 90);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2200, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2225, 130);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2250, 70);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2275, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2300, 90);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2325, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2350, 130);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2375, 70);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2400, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2425, 90);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2450, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2475, 130);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2500, 70);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 2700, 55);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 2750, 85);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 2800, 55);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 2850, 85);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 2900, 55);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 2950, 85);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 3000, 55);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 3050, 85);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 3100, 55);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 3150, 85);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_25, 3250, 70);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_25, 3300, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_25, 3400, 90);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_25, 3450, 80);


	// here goes the big snake with collider in the head (enemy 26)


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_25, 3550, 70);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_25, 3600, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_25, 3650, 90);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_25, 3700, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_25, 3750, 100);


	// 14 en 27
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4100, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4125, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4150, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4175, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4200, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4225, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4250, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4275, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4300, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4325, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4350, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4375, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4400, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4425, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_27, 4450, 100);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_28, 4550, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_28, 4620, 90);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_28, 4690, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_28, 4740, 150);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 4800, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 4840, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 4880, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 4920, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 4960, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 5000, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 5040, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 5080, 120);






	/*

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 1600, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 1700, 130);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 1800, 150);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 1900, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2000, 130);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2100, 70);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2200, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2300, 90);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2400, 70);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2500, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 2600, 60);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 1200, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 1300, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 1400, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 1500, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 1600, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 1700, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 1800, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 1900, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 2000, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 2100, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 2200, 80);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6500, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6600, 130);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6700, 160);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6800, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6900, 130);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 7000, 160);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 7100, 100);
	*/
	


	// Colliders ---


	background1 = App->textures->Load("Images/Level03/Standard_background_Level 3.png");
	layout[1] = App->textures->Load("Images/Level03/layout4_5.png");
	layout[2] = App->textures->Load("Images/Level03/layout5.png");
	layout[0] = App->textures->Load("Images/Level03/top_layout1.png");
	layout[3] = App->textures->Load("Images/Level03/bot_layout1.png");
	finalbackground = App->textures->Load("Images/Level03/final_background.png");

	music_level03 = App->audio->LoadMusic("Music/Songs/09_Stage_3-Alien-Intro.ogg");
	music_level03v2 = App->audio->LoadMusic("Music/Songs/09_Stage_3-Alien-Loop.ogg");
	App->audio->PlayMusic(music_level03);

	i = 0;
	pos = 0;
	up = true;

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
	App->enemy->Disable();

	App->textures->Unload(background1);
	App->textures->Unload(layout[0]);
	App->textures->Unload(layout[1]);
	App->textures->Unload(layout[2]);
	App->textures->Unload(layout[3]);
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

	/*
	// Player 2 spawn in-level
	if (App->player2->IsEnabled() == false)
		if (App->input->keyboard[SDL_SCANCODE_BACKSPACE] == 1 || SDL_GameControllerGetButton(App->input->controller2, SDL_CONTROLLER_BUTTON_DPAD_LEFT))
		{
			App->players_menu->cr--;
			App->player2->Enable();
		}
		*/


	// Move camera forward -----------------------------
	if (App->render->camera.x <= 11000 * SCREEN_SIZE) {
		App->render->camera.x += 1 * SCREEN_SIZE; //speed in x axes
	}

	// Controllers input
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_LEFTSHOULDER) && l_shoulder_pressed == false)
	{
		l_shoulder_pressed = true;
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_LEFTSHOULDER) == false)
	{
		l_shoulder_pressed = false;
	}


	// Music
	if (App->render->camera.x >= 1055 * SCREEN_SIZE && mus_change == false) {
		App->audio->StopMusic();
		App->audio->PlayMusic(music_level03v2);
		mus_change = true;
	}
	if (pos >= 32 && up) up = false;
	else if (pos <= 0 && !up) up = true;
	if (up)
		pos += 0.125;
	else if (!up)
		pos -= 0.125;
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

	current = &top_layout1;
	if (!App->render->Blit(layout[0], SCREEN_WIDTH + 30, 0 - pos, &(current->GetCurrentFrame()), 0.74f)) return update_status::UPDATE_ERROR;
	current = &top_layout2;
	if (!App->render->Blit(layout[0], SCREEN_WIDTH + 30 + 1417, 0 - pos, &(current->GetCurrentFrame()), 0.74f)) return update_status::UPDATE_ERROR;
	current = &top_layout3;
	if (!App->render->Blit(layout[0], SCREEN_WIDTH + 30 + 2834, 0 - pos, &(current->GetCurrentFrame()), 0.74f)) return update_status::UPDATE_ERROR;
	current = &top_layout4;
	if (!App->render->Blit(layout[0], SCREEN_WIDTH + 30 + 4252, 0 - pos, &(current->GetCurrentFrame()), 0.74f)) return update_status::UPDATE_ERROR;
	current = &bot_layout1;
	if (!App->render->Blit(layout[3], SCREEN_WIDTH + 30, 150 + pos, &(current->GetCurrentFrame()), 0.74f)) return update_status::UPDATE_ERROR;
	current = &bot_layout2;
	if (!App->render->Blit(layout[3], SCREEN_WIDTH + 30 + 1417, 105 + pos, &(current->GetCurrentFrame()), 0.74f)) return update_status::UPDATE_ERROR;
	current = &bot_layout3;
	if (!App->render->Blit(layout[3], SCREEN_WIDTH + 30 + 2834, 179 + pos, &(current->GetCurrentFrame()), 0.74f)) return update_status::UPDATE_ERROR;

	if (!App->render->Blit(layout[1], 6080, 0, nullptr, 0.75f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[2], 6987, 0, nullptr, 0.75f)) return update_status::UPDATE_ERROR;
	//colliders
	if (App->input->keyboard[SDL_SCANCODE_4] == KEY_STATE::KEY_REPEAT)
	{
		App->render->camera.x += 20 * SCREEN_SIZE;
	}
	if (App->input->keyboard[SDL_SCANCODE_F8] == 1 || l_shoulder_pressed == true)
	{
		App->fade->FadeToBlack(this, (Module*)App->game_intro);
		
	}


	return UPDATE_CONTINUE;
}
