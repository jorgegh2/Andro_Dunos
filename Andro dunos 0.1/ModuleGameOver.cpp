#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleGameIntroduction.h"
#include "ModuleGameOver.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "Level01.h"
#include "ModuleStageClear.h"
#include "SDL\include\SDL.h"
#include "ModuleAudio.h"
#include "Animation.h"

ModuleGameOver::ModuleGameOver()
{

	// Game over screen

	//Animation
	gm_over.PushBack({ 2, 5, 12, 7 });        // 1st section   // modificar max
	gm_over.PushBack({ 2, 15, 12, 11 });
	gm_over.PushBack({ 2, 29, 14, 15 });
	gm_over.PushBack({ 2, 47, 18, 19 });
	gm_over.PushBack({ 2, 71, 21, 23 });
	gm_over.PushBack({ 2, 99, 25, 25 });
	gm_over.PushBack({ 2, 130, 29, 27 });
	gm_over.PushBack({ 2, 162, 35, 29 });
	gm_over.PushBack({ 2, 196, 41, 32 });
	gm_over.PushBack({ 2, 234, 47, 32 });
	gm_over.PushBack({ 2, 273, 53, 30 });
	gm_over.PushBack({ 2, 311, 59, 28 });
	gm_over.PushBack({ 2, 348, 64, 26 });
	gm_over.PushBack({ 2, 380, 70, 22 });
	gm_over.PushBack({ 2, 406, 74, 16 });
	gm_over.PushBack({ 2, 428, 80, 12 });
	gm_over.PushBack({ 2, 444, 84, 21 });
	gm_over.PushBack({ 2, 470, 88, 27 });
	gm_over.PushBack({ 2, 504, 90, 35 });
	gm_over.PushBack({ 2, 545, 90, 45 });
	gm_over.PushBack({ 106, 5, 92, 55 });     // 2nd section
	gm_over.PushBack({ 106, 67, 92, 65 });
	gm_over.PushBack({ 106, 141, 90, 75 });
	gm_over.PushBack({ 106, 224, 86, 83 });
	gm_over.PushBack({ 106, 315, 83, 96 });
	gm_over.PushBack({ 106, 422, 76, 106 });
	gm_over.PushBack({ 219, 3, 69, 114 });    // 3rd section
	gm_over.PushBack({ 219, 128, 61, 122 });
	gm_over.PushBack({ 219, 259, 53, 132 });
	gm_over.PushBack({ 219, 401, 44, 138 });
	gm_over.PushBack({ 295, 5, 34, 144 });    // 4th section
	gm_over.PushBack({ 295, 157, 24, 150 });
	gm_over.PushBack({ 295, 314, 30, 155 });
	gm_over.PushBack({ 337, 5, 44, 157 });    // 5th section
	gm_over.PushBack({ 337, 168, 58, 157 });
	gm_over.PushBack({ 337, 336, 72, 157 });
	gm_over.PushBack({ 413, 5, 87, 157 });    // 6th section
	gm_over.PushBack({ 413, 176, 103, 151 });
	gm_over.PushBack({ 413, 341, 117, 147 });
	gm_over.PushBack({ 536, 5, 131, 139 });   // 7th section
	gm_over.PushBack({ 536, 158, 147, 132 });
	gm_over.PushBack({ 536, 300, 159, 122 });
	gm_over.PushBack({ 536, 440, 171, 110 });
	gm_over.PushBack({ 717, 5, 192, 84 });   // 8th section
	gm_over.PushBack({ 717, 99, 202, 66 });
	gm_over.PushBack({ 717, 171, 208, 50 });
	gm_over.PushBack({ 717, 227, 214, 32 });
	gm_over.PushBack({ 717, 266, 169, 48 });
	gm_over.PushBack({ 717, 327, 220, 73 });
	gm_over.PushBack({ 717, 408, 216, 92 });
	gm_over.PushBack({ 946, 5, 211, 111 });   // 9th section
	gm_over.PushBack({ 946, 130, 205, 132 });
	gm_over.PushBack({ 946, 279, 205, 132 });
	gm_over.PushBack({ 946, 422, 196, 151 });
	gm_over.PushBack({ 2, 644, 185, 169 });   // 10th section
	gm_over.PushBack({ 2, 833, 174, 186 });
	gm_over.PushBack({ 2, 1034, 144, 208 });
	gm_over.PushBack({ 2, 1059, 125, 214 });
	gm_over.PushBack({ 198, 644, 106, 219 }); // 11th section
	gm_over.PushBack({ 198, 875, 87, 222 });
	gm_over.PushBack({ 198, 1112, 67, 224 });
	gm_over.PushBack({ 198, 1346, 46, 224 });
	gm_over.PushBack({ 312, 644, 37, 224 }); // 12th section
	gm_over.PushBack({ 312, 879, 68, 224 });
	gm_over.PushBack({ 295, 1112, 107, 219 });
	gm_over.PushBack({ 295, 1356, 126, 214 });
	gm_over.PushBack({ 434, 644, 145, 208 }); // 13th section
	gm_over.PushBack({ 434, 865, 161, 202 });
	gm_over.PushBack({ 434, 1078, 190, 173 });
	gm_over.PushBack({ 434, 1268, 202, 157 });
	gm_over.PushBack({ 434, 1447, 223, 119 });
	gm_over.PushBack({ 670, 644, 223, 119 }); // 14th section
	gm_over.PushBack({ 670, 780, 223, 119 });
	gm_over.PushBack({ 670, 912, 229, 100 });
	gm_over.PushBack({ 670, 1023, 235, 80 });
	gm_over.PushBack({ 670, 1119, 238, 59 });
	gm_over.PushBack({ 670, 1190, 240, 40 });
	gm_over.PushBack({ 670, 1246, 240, 40 }); // al
	gm_over.PushBack({ 670, 1296, 240, 40 });
	gm_over.PushBack({ 670, 1343, 240, 40 });
	gm_over.PushBack({ 670, 1389, 240, 40 });
	gm_over.PushBack({ 670, 1436, 240, 40 });
	gm_over.PushBack({ 670, 1483, 240, 40 });
	gm_over.PushBack({ 670, 1530, 240, 40 });
	gm_over.PushBack({ 923, 644, 240, 40 }); // 15th section
	gm_over.PushBack({ 923, 688, 240, 40 });
	gm_over.PushBack({ 923, 733, 240, 40 });
	gm_over.PushBack({ 923, 777, 240, 40 });
	gm_over.PushBack({ 923, 823, 240, 40 });
	gm_over.PushBack({ 923, 868, 240, 40 });
	gm_over.PushBack({ 923, 912, 240, 40 });
	gm_over.PushBack({ 923, 958, 240, 40 });
	gm_over.PushBack({ 923, 1003, 240, 40 });
	gm_over.PushBack({ 923, 1051, 240, 40 });
	gm_over.PushBack({ 923, 1099, 240, 40 });
	gm_over.PushBack({ 923, 1145, 240, 40 });
	gm_over.PushBack({ 923, 1190, 240, 40 });
	gm_over.PushBack({ 923, 1235, 240, 40 });
	gm_over.PushBack({ 923, 1279, 240, 40 });
	gm_over.PushBack({ 923, 1323, 240, 40 });
	gm_over.PushBack({ 923, 1366, 240, 40 });
	gm_over.PushBack({ 923, 1412, 240, 40 });
	gm_over.PushBack({ 923, 1456, 240, 40 });
	gm_over.PushBack({ 923, 1500, 240, 40 });
	gm_over.PushBack({ 923, 1546, 240, 40 });
	gm_over.PushBack({ 2, 1608, 240, 40 }); // 16th section
	gm_over.PushBack({ 2, 1653, 240, 40 });
	gm_over.PushBack({ 2, 1700, 240, 40 });
	gm_over.PushBack({ 2, 1745, 240, 40 });
	gm_over.PushBack({ 2, 1790, 240, 40 });
	gm_over.PushBack({ 2, 1834, 240, 40 });
	gm_over.PushBack({ 2, 1877, 240, 40 });
	gm_over.PushBack({ 2, 1923, 240, 40 });
	gm_over.PushBack({ 251, 1608, 240, 40 }); // 17th section
	gm_over.PushBack({ 251, 1653, 240, 40 });

	gm_over.loop = false;
	gm_over.speed = 0.4f;
}

ModuleGameOver::~ModuleGameOver()
{}

// Load assets
bool ModuleGameOver::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	// We don't want the player in the screen
	if (App->player->IsEnabled() == true)
		App->player->Disable();

	// Disable modules for debug mode
	if (App->game_intro->IsEnabled() == true)
		App->game_intro->Disable();
	if (App->level01->IsEnabled() == true)
		App->level01->Disable();
	if (App->stage_clear->IsEnabled() == true)
		App->stage_clear->Disable();

	graphics = App->textures->Load("Images/game_over.png");

	music_go = App->audio->LoadMusic("Music/18_Game_Over.ogg");

	App->audio->PlayMusic(music_go);

	App->render->camera.x = App->render->camera.y = 0;

	return ret;
}

// UnLoad assets
bool ModuleGameOver::CleanUp()
{
	LOG("Unloading stage clear scene");

	gm_over.Reset();

	App->textures->Unload(graphics);

	return true;
}

// PreUpdate: clear screen to black before every frame
update_status ModuleGameOver::PreUpdate()
{
	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);
	SDL_RenderClear(App->render->renderer);

	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleGameOver::Update()
{
	current_animation = &gm_over;

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->fade->FadeToBlack(this, (Module*)App->game_intro);
	}

	App->render->Blit(graphics, 30, 100, &(current_animation->GetCurrentFrame()));

	return UPDATE_CONTINUE;
}
