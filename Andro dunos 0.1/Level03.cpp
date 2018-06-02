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


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_21, 5100, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_21, 5130, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_21, 5160, 60);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 5250, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 5290, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 5330, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 5370, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 5410, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_29, 5450, 120);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_POWER_UP, 5550, 100);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_30, 5600, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_30, 5650, 90);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_30, 5700, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_30, 5750, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_30, 5800, 130);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_30, 5900, 70);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_30, 5950, 120);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_POWER_UP, 6000, 100);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 6200, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_24, 6400, 120);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_31, 6400, 160);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_31, 6500, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_31, 6600, 100);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_POWER_UP, 6810, 115);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6700, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6725, 160);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6750, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6775, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6700, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6725, 160);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6750, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6775, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6800, 80);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6825, 160);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6850, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_23, 6875, 120);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_31, 7000, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_31, 7100, 100);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_POWER_UP, 7200, 100);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_33, 7300, 100);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_33, 7400, 140);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_32, 7500, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_32, 7525, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_32, 7550, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_32, 7575, 60);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_32, 7600, 60);

	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_32, 7550, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_32, 7575, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_32, 7600, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_32, 7625, 120);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_32, 7650, 120);


	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_33, 7750, 140);
	App->enemy->AddEnemy(ENEMY_TYPES::ENEMY_33, 7850, 100);


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
	//bot moving
	c[0] = App->collision->AddCollider({ 377, 210, 50, 45 }, COLLIDER_WALL, nullptr);
	c[1] = App->collision->AddCollider({ 412, 194, 50, 45 }, COLLIDER_WALL, nullptr);
	c[2] = App->collision->AddCollider({ 436, 187, 150, 45 }, COLLIDER_WALL, nullptr);
	c[3] = App->collision->AddCollider({ 575, 176, 40, 20 }, COLLIDER_WALL, nullptr);
	c[4] = App->collision->AddCollider({ 600, 173, 264, 20 }, COLLIDER_WALL, nullptr);
	c[5] = App->collision->AddCollider({ 860, 188, 300, 20 }, COLLIDER_WALL, nullptr);
	c[6] = App->collision->AddCollider({ 1157, 200, 23, 20 }, COLLIDER_WALL, nullptr);
	c[7] = App->collision->AddCollider({ 1172, 220, 100, 20 }, COLLIDER_WALL, nullptr);
	c[8] = App->collision->AddCollider({ 1255, 210, 20, 20 }, COLLIDER_WALL, nullptr);
	c[9] = App->collision->AddCollider({ 1275, 190, 300, 20 }, COLLIDER_WALL, nullptr);
	c[10] = App->collision->AddCollider({ 1550, 177, 30, 20 }, COLLIDER_WALL, nullptr);
	c[11] = App->collision->AddCollider({ 1575, 170, 180, 20 }, COLLIDER_WALL, nullptr);
	c[12] = App->collision->AddCollider({ 1720, 157, 180, 20 }, COLLIDER_WALL, nullptr);
	c[13] = App->collision->AddCollider({ 1875, 145, 40, 20 }, COLLIDER_WALL, nullptr);
	c[14] = App->collision->AddCollider({ 1900, 140, 140, 20 }, COLLIDER_WALL, nullptr);
	c[15] = App->collision->AddCollider({ 2040, 130, 40, 20 }, COLLIDER_WALL, nullptr);
	c[16] = App->collision->AddCollider({ 2060, 122, 140, 20 }, COLLIDER_WALL, nullptr);
	c[17] = App->collision->AddCollider({ 2200, 112, 32, 20 }, COLLIDER_WALL, nullptr);
	c[18] = App->collision->AddCollider({ 2230, 120, 20, 20 }, COLLIDER_WALL, nullptr);
	c[19] = App->collision->AddCollider({ 2250, 137, 80, 20 }, COLLIDER_WALL, nullptr);
	c[20] = App->collision->AddCollider({ 2330, 127, 30, 20 }, COLLIDER_WALL, nullptr);
	c[21] = App->collision->AddCollider({ 2347, 107, 5, 20 }, COLLIDER_WALL, nullptr);
	c[22] = App->collision->AddCollider({ 2350, 125, 170, 20 }, COLLIDER_WALL, nullptr);
	c[23] = App->collision->AddCollider({ 2500, 140, 170, 20 }, COLLIDER_WALL, nullptr);
	c[24] = App->collision->AddCollider({ 2670, 154, 170, 20 }, COLLIDER_WALL, nullptr);
	c[25] = App->collision->AddCollider({ 2830, 173, 300, 20 }, COLLIDER_WALL, nullptr);
	c[26] = App->collision->AddCollider({ 3130, 190, 1470, 20 }, COLLIDER_WALL, nullptr);
	c[27] = App->collision->AddCollider({ 4600, 200, 20, 20 }, COLLIDER_WALL, nullptr);
	c[28] = App->collision->AddCollider({ 4620, 220, 20, 20 }, COLLIDER_WALL, nullptr);
	c[29] = App->collision->AddCollider({ 344, 0, 40, 28 }, COLLIDER_WALL, nullptr);
	//top moving
	c[30] = App->collision->AddCollider({ 375, 0, 40, 40 }, COLLIDER_WALL, nullptr);
	c[31] = App->collision->AddCollider({ 397, 0, 400, 50 }, COLLIDER_WALL, nullptr);
	c[32] = App->collision->AddCollider({ 790, 0, 955, 35 }, COLLIDER_WALL, nullptr);
	c[33] = App->collision->AddCollider({ 1740, 0, 20, 25 }, COLLIDER_WALL, nullptr);
	c[34] = App->collision->AddCollider({ 1760, 0, 18, 15 }, COLLIDER_WALL, nullptr);
	c[35] = App->collision->AddCollider({ 1778, 0, 70, 05 }, COLLIDER_WALL, nullptr);
	c[36] = App->collision->AddCollider({ 1840, 0, 30, 20 }, COLLIDER_WALL, nullptr);
	c[37] = App->collision->AddCollider({ 1860, 0, 300, 38 }, COLLIDER_WALL, nullptr);
	c[38] = App->collision->AddCollider({ 2140, 0, 160, 50 }, COLLIDER_WALL, nullptr);
	c[39] = App->collision->AddCollider({ 2300, 0, 155, 37 }, COLLIDER_WALL, nullptr);
	c[40] = App->collision->AddCollider({ 2455, 0, 2010, 20 }, COLLIDER_WALL, nullptr);
	c[41] = App->collision->AddCollider({ 4460, 0, 150, 36 }, COLLIDER_WALL, nullptr);
	c[42] = App->collision->AddCollider({ 4600, 0, 20, 26 }, COLLIDER_WALL, nullptr);
	c[43] = App->collision->AddCollider({ 4620, 0, 65, 18 }, COLLIDER_WALL, nullptr);
	c[44] = App->collision->AddCollider({ 4673, 0, 20, 70 }, COLLIDER_WALL, nullptr);
	c[45] = App->collision->AddCollider({ 4660, 65, 60, 33 }, COLLIDER_WALL, nullptr);
	c[46] = App->collision->AddCollider({ 4648, 78, 12, 18 }, COLLIDER_WALL, nullptr);
	c[47] = App->collision->AddCollider({ 4720, 65, 165, 20 }, COLLIDER_WALL, nullptr);
	c[48] = App->collision->AddCollider({ 4885, 52, 157, 16 }, COLLIDER_WALL, nullptr);
	c[49] = App->collision->AddCollider({ 5042, 40, 40, 14 }, COLLIDER_WALL, nullptr);
	c[50] = App->collision->AddCollider({ 5080, 27, 22, 14 }, COLLIDER_WALL, nullptr);
	c[51] = App->collision->AddCollider({ 5100, 10, 25, 18 }, COLLIDER_WALL, nullptr);
	c[52] = App->collision->AddCollider({ 5124, 0, 60, 22 }, COLLIDER_WALL, nullptr);
	c[53] = App->collision->AddCollider({ 5180, 0, 25, 30 }, COLLIDER_WALL, nullptr);
	c[54] = App->collision->AddCollider({ 5200, 0, 8, 50 }, COLLIDER_WALL, nullptr);
	c[55] = App->collision->AddCollider({ 5208, 0, 294, 36 }, COLLIDER_WALL, nullptr);
	c[56] = App->collision->AddCollider({ 5500, 0, 167, 21 }, COLLIDER_WALL, nullptr);
	c[57] = App->collision->AddCollider({ 5663, 0, 22, 9 }, COLLIDER_WALL, nullptr);
	//bot not moving
	c[58] = App->collision->AddCollider({ 6087, 198, 20, 30 }, COLLIDER_WALL, nullptr);
	c[59] = App->collision->AddCollider({ 6098, 191, 1560, 30 }, COLLIDER_WALL, nullptr);
	c[60] = App->collision->AddCollider({ 6249, 160, 42, 40 }, COLLIDER_WALL, nullptr);
	c[61] = App->collision->AddCollider({ 6263, 149, 10, 11 }, COLLIDER_WALL, nullptr);
	c[62] = App->collision->AddCollider({ 6377, 160, 42, 40 }, COLLIDER_WALL, nullptr);
	c[63] = App->collision->AddCollider({ 6391, 149, 10, 11 }, COLLIDER_WALL, nullptr);
	c[64] = App->collision->AddCollider({ 6762, 160, 42, 40 }, COLLIDER_WALL, nullptr);
	c[65] = App->collision->AddCollider({ 6775, 149, 10, 11 }, COLLIDER_WALL, nullptr);
	c[66] = App->collision->AddCollider({ 7272, 160, 42, 40 }, COLLIDER_WALL, nullptr);
	c[67] = App->collision->AddCollider({ 7285, 149, 10, 11 }, COLLIDER_WALL, nullptr);
	c[68] = App->collision->AddCollider({ 7658, 215, 50, 11 }, COLLIDER_WALL, nullptr);
	c[69] = App->collision->AddCollider({ 7694, 199, 620, 20 }, COLLIDER_WALL, nullptr);
	//top not moving
	c[70] = App->collision->AddCollider({ 6247, 0, 20, 8 }, COLLIDER_WALL, nullptr);
	c[71] = App->collision->AddCollider({ 6265, 0, 780, 18 }, COLLIDER_WALL, nullptr);
	c[72] = App->collision->AddCollider({ 6407, 0, 45, 45 }, COLLIDER_WALL, nullptr);
	c[73] = App->collision->AddCollider({ 6423, 0, 10, 58 }, COLLIDER_WALL, nullptr);



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
	//bot moving
	c[0]->SetPos(377 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 210 + pos);
	c[1]->SetPos(412 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 194 + pos);
	c[2]->SetPos(436 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 187 + pos);
	c[3]->SetPos(575 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 176 + pos);
	c[4]->SetPos(600 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 173 + pos);
	c[5]->SetPos(860 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 188 + pos);
	c[6]->SetPos(1157 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 200 + pos);
	c[7]->SetPos(1172 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 220 + pos);
	c[8]->SetPos(1255 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 210 + pos);
	c[9]->SetPos(1275 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 190 + pos);
	c[10]->SetPos(1550 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 177 + pos);
	c[11]->SetPos(1575 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 170 + pos);
	c[12]->SetPos(1720 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 157 + pos);
	c[13]->SetPos(1875 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 145 + pos);
	c[14]->SetPos(1900 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 140 + pos);
	c[15]->SetPos(2040 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 130 + pos);
	c[16]->SetPos(2060 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 122 + pos);
	c[17]->SetPos(2200 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 112 + pos);
	c[18]->SetPos(2230 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 120 + pos);
	c[19]->SetPos(2250 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 137 + pos);
	c[20]->SetPos(2330 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 127 + pos);
	c[21]->SetPos(2347 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 107 + pos);
	c[22]->SetPos(2350 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 125 + pos);
	c[23]->SetPos(2500 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 140 + pos);
	c[24]->SetPos(2670 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 154 + pos);
	c[25]->SetPos(2830 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 173 + pos);
	c[26]->SetPos(3130 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 190 + pos);
	c[27]->SetPos(4600 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 200 + pos);
	c[28]->SetPos(4620 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 220 + pos);
	//top moving
	c[29]->SetPos(344 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[30]->SetPos(375 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[31]->SetPos(397 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[32]->SetPos(790 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[33]->SetPos(1740 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[34]->SetPos(1760 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[35]->SetPos(1778 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[36]->SetPos(1840 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[37]->SetPos(1860 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[38]->SetPos(2140 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[39]->SetPos(2300 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[40]->SetPos(2455 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[41]->SetPos(4460 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[42]->SetPos(4600 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[43]->SetPos(4620 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[44]->SetPos(4673 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[45]->SetPos(4660 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 65 - pos);
	c[46]->SetPos(4648 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 78 - pos);
	c[47]->SetPos(4720 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 65 - pos);
	c[48]->SetPos(4885 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 52 - pos);
	c[49]->SetPos(5042 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 40 - pos);
	c[50]->SetPos(5080 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 27 - pos);
	c[51]->SetPos(5100 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 10 - pos);
	c[52]->SetPos(5124 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[53]->SetPos(5180 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[54]->SetPos(5200 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[55]->SetPos(5208 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[56]->SetPos(5500 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	c[57]->SetPos(5663 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0 - pos);
	//bot not moving
	c[58]->SetPos(6087 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 198);
	c[59]->SetPos(6098 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 191);
	c[60]->SetPos(6249 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 160);
	c[61]->SetPos(6263 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 149);
	c[62]->SetPos(6377 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 160);
	c[63]->SetPos(6391 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 149);
	c[64]->SetPos(6762 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 160);
	c[65]->SetPos(6776 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 149);
	c[66]->SetPos(7272 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 160);
	c[67]->SetPos(7286 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 149);
	c[68]->SetPos(7658 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 215);
	c[69]->SetPos(7694 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 199);
	//top not moving
	c[70]->SetPos(6247 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0);
	c[71]->SetPos(6265 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0);
	c[72]->SetPos(6407 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0);
	c[73]->SetPos(6423 + (App->render->camera.x / SCREEN_SIZE) * 0.25f, 0);


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
