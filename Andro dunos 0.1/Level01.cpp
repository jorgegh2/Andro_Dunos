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
#include "UI.h"

Level01::Level01()
{
	//moon
	moon.x = 91;
	moon.y = 215;
	moon.w = 137;
	moon.h = 138;
	
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
	App->UI->Enable();

	//Enemies Correct Coord.
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 450, 50);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 465, 50);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 480, 50);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 495, 50);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 555, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 570, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 585, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 600, 140);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 660, 50);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 675, 50);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 690, 50);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 705, 50);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 765, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 780, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 795, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_01, 810, 140);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1240, 65);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1250, 40);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1250, 90);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1340, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1350, 95);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1350, 145);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1440, 65);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1450, 40);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1450, 90);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1540, 95);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1550, 70);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1550, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1530, 90);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1560, 55);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1560, 145);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1660, 90);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1670, 65);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1680, 45);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1760, 110);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1770, 135);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_3, 1780, 155);


	// Colliders ---
	c_wall[0] = App->collision->AddCollider({ 0, 200, 3000, 35 }, COLLIDER_WALL, nullptr);
	c_wall[1] = App->collision->AddCollider({ 900, 176, 110, 30 }, COLLIDER_WALL, nullptr);
	c_wall[2] = App->collision->AddCollider({ 1563, 184, 110, 30 }, COLLIDER_WALL, nullptr);
	c_wall[3] = App->collision->AddCollider({ 2364, 176, 110, 30 }, COLLIDER_WALL, nullptr);
	c_wall[4] = App->collision->AddCollider({ 2602, 184, 110, 30 }, COLLIDER_WALL, nullptr);
	c_wall[5] = App->collision->AddCollider({ 2974, 170, 34, 40 }, COLLIDER_WALL, nullptr);
	c_wall[6] = App->collision->AddCollider({ 3005, 195, 15, 12 }, COLLIDER_WALL, nullptr);
	c_wall[7] = App->collision->AddCollider({ 2970, 195, 35, 250 }, COLLIDER_WALL, nullptr);
	c_wall[8] = App->collision->AddCollider({ 2970, 300, 40, 100 }, COLLIDER_WALL, nullptr);
	c_wall[9] = App->collision->AddCollider({ 2977, 328, 40, 100 }, COLLIDER_WALL, nullptr);
	c_wall[10] = App->collision->AddCollider({ 2982, 400, 70, 50 }, COLLIDER_WALL, nullptr);
	c_wall[11] = App->collision->AddCollider({ 3000, 430, 1200, 20 }, COLLIDER_WALL, nullptr);
	c_wall[12] = App->collision->AddCollider({ 3204, 170, 46, 89 }, COLLIDER_WALL, nullptr);
	c_wall[13] = App->collision->AddCollider({ 3214, 259, 26, 45 }, COLLIDER_WALL, nullptr);
	c_wall[14] = App->collision->AddCollider({ 3240, 259, 26, 25 }, COLLIDER_WALL, nullptr);
	c_wall[15] = App->collision->AddCollider({ 3245, 215, 90, 53 }, COLLIDER_WALL, nullptr);
	c_wall[16] = App->collision->AddCollider({ 3335, 215, 95, 40 }, COLLIDER_WALL, nullptr);
	c_wall[17] = App->collision->AddCollider({ 3430, 215, 200, 25 }, COLLIDER_WALL, nullptr);
	c_wall[18] = App->collision->AddCollider({ 3630, 215, 120, 20 }, COLLIDER_WALL, nullptr);
	c_wall[19] = App->collision->AddCollider({ 3742, 215, 320, 25 }, COLLIDER_WALL, nullptr);
	c_wall[20] = App->collision->AddCollider({ 3890, 415, 78, 35 }, COLLIDER_WALL, nullptr);
	c_wall[21] = App->collision->AddCollider({ 4085, 420, 50, 25 }, COLLIDER_WALL, nullptr);
	c_wall[22] = App->collision->AddCollider({ 4115, 385, 50, 45 }, COLLIDER_WALL, nullptr);
	c_wall[23] = App->collision->AddCollider({ 4142, 355, 50, 45 }, COLLIDER_WALL, nullptr);
	c_wall[24] = App->collision->AddCollider({ 4192, 327, 50, 45 }, COLLIDER_WALL, nullptr);
	c_wall[25] = App->collision->AddCollider({ 4205, 310, 405, 45 }, COLLIDER_WALL, nullptr);
	c_wall[26] = App->collision->AddCollider({ 4055, 190, 25, 34 }, COLLIDER_WALL, nullptr);
	c_wall[27] = App->collision->AddCollider({ 4075, 138, 55, 55 }, COLLIDER_WALL, nullptr);
	c_wall[28] = App->collision->AddCollider({ 4101, 122, 55, 40 }, COLLIDER_WALL, nullptr);
	c_wall[29] = App->collision->AddCollider({ 4132, 105, 55, 25 }, COLLIDER_WALL, nullptr);
	c_wall[30] = App->collision->AddCollider({ 4150, 93, 750, 20 }, COLLIDER_WALL, nullptr);
	c_wall[31] = App->collision->AddCollider({ 4573, 328, 50, 45 }, COLLIDER_WALL, nullptr);
	c_wall[32] = App->collision->AddCollider({ 4622, 357, 50, 60 }, COLLIDER_WALL, nullptr);
	c_wall[33] = App->collision->AddCollider({ 4650, 388, 50, 60 }, COLLIDER_WALL, nullptr);
	c_wall[34] = App->collision->AddCollider({ 4695, 417, 35, 30 }, COLLIDER_WALL, nullptr);
	c_wall[35] = App->collision->AddCollider({ 4720, 430, 510, 20 }, COLLIDER_WALL, nullptr);
	c_wall[36] = App->collision->AddCollider({ 5222, 419, 40, 20 }, COLLIDER_WALL, nullptr);
	c_wall[37] = App->collision->AddCollider({ 5252, 387, 40, 40 }, COLLIDER_WALL, nullptr);
	c_wall[38] = App->collision->AddCollider({ 5282, 357, 50, 40 }, COLLIDER_WALL, nullptr);
	c_wall[39] = App->collision->AddCollider({ 5330, 305, 40, 60 }, COLLIDER_WALL, nullptr);
	c_wall[40] = App->collision->AddCollider({ 5364, 275, 40, 60 }, COLLIDER_WALL, nullptr);
	c_wall[41] = App->collision->AddCollider({ 5394, 245, 50, 60 }, COLLIDER_WALL, nullptr);
	c_wall[42] = App->collision->AddCollider({ 5443, 213, 775, 35 }, COLLIDER_WALL, nullptr);
	c_wall[43] = App->collision->AddCollider({ 6210, 242, 60, 35 }, COLLIDER_WALL, nullptr);
	c_wall[44] = App->collision->AddCollider({ 6268, 275, 35, 44 }, COLLIDER_WALL, nullptr);
	c_wall[45] = App->collision->AddCollider({ 6295, 307, 41, 59 }, COLLIDER_WALL, nullptr);
	c_wall[46] = App->collision->AddCollider({ 6330, 355, 52, 40 }, COLLIDER_WALL, nullptr);
	c_wall[47] = App->collision->AddCollider({ 6380, 387, 33, 40 }, COLLIDER_WALL, nullptr);
	c_wall[48] = App->collision->AddCollider({ 6405, 420, 40, 25 }, COLLIDER_WALL, nullptr);
	c_wall[49] = App->collision->AddCollider({ 6435, 440, 849, 15 }, COLLIDER_WALL, nullptr);
	c_wall[50] = App->collision->AddCollider({ 6515, 208, 687, 30 }, COLLIDER_WALL, nullptr);
	c_wall[51] = App->collision->AddCollider({ 6465, 177, 54, 31 }, COLLIDER_WALL, nullptr);
	c_wall[52] = App->collision->AddCollider({ 6437, 140, 35, 37 }, COLLIDER_WALL, nullptr);
	c_wall[53] = App->collision->AddCollider({ 6404, 90, 32, 53 }, COLLIDER_WALL, nullptr);
	c_wall[54] = App->collision->AddCollider({ 6354, 69, 59, 28 }, COLLIDER_WALL, nullptr);
	c_wall[55] = App->collision->AddCollider({ 6325, 30, 28, 35 }, COLLIDER_WALL, nullptr);
	c_wall[56] = App->collision->AddCollider({ 6290, -15, 33, 47 }, COLLIDER_WALL, nullptr);
	c_wall[57] = App->collision->AddCollider({ 7010, 233, 65, 21 }, COLLIDER_WALL, nullptr);
	c_wall[58] = App->collision->AddCollider({ 7060, 242, 100, 21 }, COLLIDER_WALL, nullptr);
	c_wall[59] = App->collision->AddCollider({ 7150, 252, 40, 30 }, COLLIDER_WALL, nullptr);
	c_wall[60] = App->collision->AddCollider({ 7168, 180, 38, 118 }, COLLIDER_WALL, nullptr);
	c_wall[61] = App->collision->AddCollider({ 7205, 196, 14, 12 }, COLLIDER_WALL, nullptr);
	c_wall[62] = App->collision->AddCollider({ 7283, 428, 60, 11 }, COLLIDER_WALL, nullptr);
	c_wall[63] = App->collision->AddCollider({ 7341, 416, 38, 11 }, COLLIDER_WALL, nullptr);
	c_wall[64] = App->collision->AddCollider({ 7365, 397, 32, 17 }, COLLIDER_WALL, nullptr);
	c_wall[65] = App->collision->AddCollider({ 7395, 367, 27, 30 }, COLLIDER_WALL, nullptr);
	c_wall[66] = App->collision->AddCollider({ 7405, 300, 16, 71 }, COLLIDER_WALL, nullptr);
	c_wall[67] = App->collision->AddCollider({ 7413, 257, 16, 45 }, COLLIDER_WALL, nullptr);
	c_wall[68] = App->collision->AddCollider({ 7405, 175, 35, 88 }, COLLIDER_WALL, nullptr);
	c_wall[69] = App->collision->AddCollider({ 7395, 199, 10, 10 }, COLLIDER_WALL, nullptr);
	c_wall[70] = App->collision->AddCollider({ 7420, 200, 1895, 35 }, COLLIDER_WALL, nullptr);
	c_wall[71] = App->collision->AddCollider({ 7788, 184, 100, 30 }, COLLIDER_WALL, nullptr);
	c_wall[72] = App->collision->AddCollider({ 8415, 184, 100, 30 }, COLLIDER_WALL, nullptr);
	c_wall[73] = App->collision->AddCollider({ 8655, 179, 100, 30 }, COLLIDER_WALL, nullptr);

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

	App->audio->UnloadMusic(music_level01);
	App->UI->Disable();

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
	if (!App->render->Blit(layout[5], 790, 0 , &moon, 0.25f)) return update_status::UPDATE_ERROR;
	
	//colliders
	c_wall[0]->SetPos(0 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 200 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[1]->SetPos(900 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 176);
	c_wall[2]->SetPos(1560 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 184);
	c_wall[3]->SetPos(2362 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 184);
	c_wall[4]->SetPos(2600 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 176);
	c_wall[5]->SetPos(2974 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 170 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[6]->SetPos(3005 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 200 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[7]->SetPos(2970 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 195 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[8]->SetPos(2970 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 300 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[9]->SetPos(2977 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 328 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[10]->SetPos(2982 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 400 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[11]->SetPos(3000 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 430 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[12]->SetPos(3204 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 170 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[13]->SetPos(3214 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 259 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[14]->SetPos(3240 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 259 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[15]->SetPos(3245 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 215 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[16]->SetPos(3335 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 215 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[17]->SetPos(3430 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 215 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[18]->SetPos(3630 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 215 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[19]->SetPos(3742 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 215 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[20]->SetPos(3890 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 415 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[21]->SetPos(4085 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 420 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[22]->SetPos(4115 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 385 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[23]->SetPos(4142 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 355 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[24]->SetPos(4192 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 327 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[25]->SetPos(4205 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 310 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[26]->SetPos(4055 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 190 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[27]->SetPos(4075 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 138 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[28]->SetPos(4101 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 122 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[29]->SetPos(4132 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 105 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[30]->SetPos(4150 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 93 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[31]->SetPos(4573 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 328 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[32]->SetPos(4622 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 357 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[33]->SetPos(4650 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 388 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[34]->SetPos(4695 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 417 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[35]->SetPos(4720 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 430 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[36]->SetPos(5222 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 419 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[37]->SetPos(5252 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 387 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[38]->SetPos(5282 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 357 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[39]->SetPos(5330 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 305 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[40]->SetPos(5364 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 275 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[41]->SetPos(5394 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 245 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[42]->SetPos(5443 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 213 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[43]->SetPos(6210 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 242 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[44]->SetPos(6268 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 275 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[45]->SetPos(6295 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 307 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[46]->SetPos(6330 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 355 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[47]->SetPos(6380 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 387 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[48]->SetPos(6405 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 420 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[49]->SetPos(6435 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 440 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[50]->SetPos(6515 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 208 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[51]->SetPos(6465 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 177 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[52]->SetPos(6437 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 140 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[53]->SetPos(6404 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 90 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[54]->SetPos(6354 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 69 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[55]->SetPos(6325 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 30 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[56]->SetPos(6290 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, -15 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[57]->SetPos(7010 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 233 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[58]->SetPos(7060 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 242 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[59]->SetPos(7150 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 252 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[60]->SetPos(7168 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 180 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[61]->SetPos(7205 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 196 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[62]->SetPos(7283 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 428 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[63]->SetPos(7341 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 416 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[64]->SetPos(7365 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 397 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[65]->SetPos(7395 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 367 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[66]->SetPos(7405 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 300 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[67]->SetPos(7413 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 257 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[68]->SetPos(7405 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 175 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[69]->SetPos(7395 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 199 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[70]->SetPos(7420 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 200 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[71]->SetPos(7788 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 184 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[72]->SetPos(8415 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 184 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);
	c_wall[73]->SetPos(8655 + (App->render->camera.x / SCREEN_SIZE) * 0.2f, 179 + (App->render->camera.y / SCREEN_SIZE) * 0.2f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1 || App->render->camera.x > 11257 * SCREEN_SIZE)
	{
		App->fade->FadeToBlack(this, (Module*)App->stage_clear);
	}

	return UPDATE_CONTINUE;
}
