#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "Level01.h"
#include "ModuleInput.h"
#include "ModuleGameIntroduction.h"
#include "ModuleStageClear.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleEnemies.h"
#include "Module_Player_2.h"

Level01::Level01()
{
	
}

Level01::~Level01()
{

}

// Load assets
bool Level01::Start()
{
	LOG("Loading background assets");						

	if (App->player2->Two_Players == true)
		App->player2->Enable();
	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemy->Enable();

	//Enemies
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 320, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 332, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 344, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 356, 100);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 450, 80);
	//Original position
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1240, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1250, 50);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1250, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1400, 120);


	// Colliders ---
	//App->collision->AddCollider({ 0, 100, 100, 16 }, COLLIDER_WALL);

	xstop = false;
	background = App->textures->Load("Images/Background1.png");
	layout[0] = App->textures->Load("Images/layout1.png");
	layout[1] = App->textures->Load("Images/layout2.png");
	layout[2] = App->textures->Load("Images/layout3.png");
	layout[3] = App->textures->Load("Images/layout4.png");
	layout[4] = App->textures->Load("Images/layout5.png");
	layout[5] = App->textures->Load("Images/layout6.png");
	underground_tile = App->textures->Load("Images/under_tile.png");
	start_under = App->textures->Load("Images/start_under.png");
	end_under = App->textures->Load("Images/end_under.png");
	music_level01 = App->audio->LoadMusic("Music/04_Stage_1 -The Moon-Loop.ogg");
	App->audio->PlayMusic(music_level01);

	return true;
}

// Unload assets
bool Level01::CleanUp()
{
	LOG("Unload Level01");

	App->player->Disable();
	App->player2->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->enemy->Disable();

	App->textures->Unload(background);
	App->textures->Unload(layout[0]);
	App->textures->Unload(layout[1]);
	App->textures->Unload(layout[2]);
	App->textures->Unload(layout[3]);
	App->textures->Unload(layout[4]);
	App->textures->Unload(layout[5]);
	App->textures->Unload(underground_tile);
	App->textures->Unload(start_under);
	App->textures->Unload(end_under);

	return true;
}

update_status Level01::Update()
{
	// Move camera forward -----------------------------

	if (xstop == false && App->render->camera.x <= 11257 * SCREEN_SIZE) {
		App->render->camera.x += 1 * SCREEN_SIZE; //speed in x axes
	}

	if ((App->render->camera.x >= 3680 * SCREEN_SIZE && App->render->camera.x <= 3682 * SCREEN_SIZE && App->render->camera.y == 0)
		|| (App->render->camera.x >= 8945 * SCREEN_SIZE && App->render->camera.y >= 279)) xstop = true; // stop scrolling in x axes
	else if ((App->render->camera.x >= 3680 * SCREEN_SIZE && App->render->camera.x <= 3682 * SCREEN_SIZE && App->render->camera.y >= 279 * SCREEN_SIZE)
		|| (App->render->camera.x >= 8945 * SCREEN_SIZE && App->render->camera.x <= 8947 * SCREEN_SIZE && App->render->camera.y == 0)) xstop = false; // enable scroll in x axes

	if ((App->render->camera.x >= 3680 * SCREEN_SIZE && App->render->camera.x <= 3682 * SCREEN_SIZE  && App->render->camera.y <= 279 * SCREEN_SIZE)
		|| (App->render->camera.x >= 5658 * SCREEN_SIZE && App->render->camera.x <= 5814 * SCREEN_SIZE)
		|| (App->render->camera.x >= 7580 * SCREEN_SIZE && App->render->camera.x <= 7857 * SCREEN_SIZE)) {
		App->render->camera.y += 1 * SCREEN_SIZE; // speed in y axes
	}
	else if ((App->render->camera.x >= 5022 * SCREEN_SIZE && App->render->camera.x <= 5178 * SCREEN_SIZE)
		|| (App->render->camera.x >= 6370 * SCREEN_SIZE && App->render->camera.x <= 6647 * SCREEN_SIZE)
		|| (App->render->camera.x >= 8945 * SCREEN_SIZE && xstop == true)) {
		App->render->camera.y -= 1 * SCREEN_SIZE; // speed in y axes
	}
	


	// Draw everything --------------------------------------
	for (int i = 0; i < 29; ++i) if (!App->render->Blit(background, TILE_WIDTH * i, 120, NULL, 0.6f)) return update_status::UPDATE_ERROR;
	if (App->render->camera.x > 3681 * SCREEN_SIZE && App->render->camera.x <= 8943 * SCREEN_SIZE) {
		if (!App->render->Blit(start_under, 1435, -85, nullptr, 0.39f)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(underground_tile, 2015, -85, nullptr, 0.39f)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(underground_tile, 2014 + UNDER_TILE_WIDTH, -85, nullptr, 0.39f)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(underground_tile, 2013 + UNDER_TILE_WIDTH * 2, -85, nullptr, 0.39f)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(underground_tile, 2012 + UNDER_TILE_WIDTH * 3, -85, nullptr, 0.39f)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(end_under, 2011 + UNDER_TILE_WIDTH * 4 - 64 * 3, -85, nullptr, 0.39f)) return update_status::UPDATE_ERROR;//64 is the mesure of 1/6th of the under_tile_width here it's used to fit the end of the underground background into the previous tiles
	}
	if (!App->render->Blit(layout[0], 0, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[1], 1639, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[2], 3279, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[3], 4935, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[4], 6591, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;
	if (!App->render->Blit(layout[5], 8230, -607, nullptr, 0.8f)) return update_status::UPDATE_ERROR;

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 || App->render->camera.x > 11257 * SCREEN_SIZE)
	{
		App->fade->FadeToBlack(this, (Module*)App->stage_clear);
	}

	return UPDATE_CONTINUE;
}