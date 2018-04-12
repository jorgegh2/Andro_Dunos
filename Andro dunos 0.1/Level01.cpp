#include "Globals.h"
#include "SDL\include\SDL.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"
#include "Level01.h"
#include "ModuleGameIntroduction.h"
#include "ModuleStageClear.h"
#include "ModuleAudio.h"

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
	bool ret = true;					

	if (App->player->IsEnabled() == false)
		App->player->Enable();

	tex = App->textures->Load("Background1.png");
	layout[0] = App->textures->Load("layout1.png");
	layout[1] = App->textures->Load("layout2.png");
	layout[2] = App->textures->Load("layout3.png");
	layout[3] = App->textures->Load("layout4.png");
	layout[4] = App->textures->Load("layout5.png");
	layout[5] = App->textures->Load("layout6.png");

	mov = 0;
	movy = 0;
	xstop = false;
	position[0] = position[1] = position[2] = 0;

	music_level01 = App->audio->LoadMusic("Music/04_Stage_1 -The Moon-Loop.ogg");

	App->audio->PlayMusic(music_level01);

	return ret;
}

// Unload assets
bool Level01::CleanUp()
{
	if(App->player->IsEnabled() == true)
		App->player->Disable();

	if (App->level01->IsEnabled() == true)
		App->level01->Disable();

	LOG("Unload Level01");
	App->textures->Unload(tex);

	// TODO: loop
	App->textures->Unload(layout[0]);
	App->textures->Unload(layout[1]);
	App->textures->Unload(layout[2]);
	App->textures->Unload(layout[3]);
	App->textures->Unload(layout[4]);
	App->textures->Unload(layout[5]);

	return true;
}

update_status Level01::Update()
{
	// Draw everything -------------------------------------- Andro Dunos
	// TODO 7: Clear the screen to black before starting every frame
	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);

	SDL_RenderClear(App->render->renderer);
	// TODO 10: Blit our test texture to check functionality
	if (App->level01->IsEnabled() == true) {
		for (int i = 0; i < 3; ++i) {
			if (i == 0) {
				if (mov + position[0] < 0 - TILE_WIDTH) position[0] += TILE_WIDTH * 3;
				if (!App->render->Blit(tex, mov + position[0], 120 + movy * 0.5, nullptr)) return update_status::UPDATE_ERROR;
			}
			else if (i == 1) {
				if (mov + position[1] + TILE_WIDTH < 0 - TILE_WIDTH) position[1] += TILE_WIDTH * 3;
				if (!App->render->Blit(tex, mov + TILE_WIDTH + position[1], 120 + movy * 0.5, nullptr)) return update_status::UPDATE_ERROR;
			}
			else {
				if (mov + position[2] + TILE_WIDTH * 2 < 0 - TILE_WIDTH) position[2] += TILE_WIDTH * 3;
				if (!App->render->Blit(tex, mov + TILE_WIDTH * 2 + position[2], 120 + movy * 0.5, nullptr)) return update_status::UPDATE_ERROR;
			}
		}

		if (xstop == false && mov >= -5149) {
			mov -= 0.45;
		}

		if ((mov <= -1684 && movy == 0) || (mov <= -4091 && movy <= -128)) xstop = true;
		else if ((mov <= -1684 && movy <= -128) || (mov <= -4091 && movy >= 0)) xstop = false;
		if ((mov <= -1684 && mov >= -1685 && movy >= -128) || (mov <= -2590 && mov >= -2660) || (mov <= -3468 && mov >= -3596)) {
			movy -= 0.45;
		}
		else if ((mov <= -2297 && mov >= -2368) || (mov <= -2918 && mov >= -3044) || (mov <= -4091 && mov >= -4092)) {
			movy += 0.45;
		}

		if (mov >= -950) if (!App->render->Blit(layout[0], mov * 1.75, -607 + movy * 1.75, nullptr)) return update_status::UPDATE_ERROR;
		if (mov <= -750 && mov >= -1950) if (!App->render->Blit(layout[1], mov * 1.75 + 1640, -607 + movy * 1.75, nullptr)) return update_status::UPDATE_ERROR;
		if (mov <= -1500 && mov >= -2950) if (!App->render->Blit(layout[2], mov * 1.75 + 3281, -607 + movy * 1.75, nullptr)) return update_status::UPDATE_ERROR;
		if (mov <= -2250 && mov >= -3950) if (!App->render->Blit(layout[3], mov * 1.75 + 4938, -607 + movy * 1.75, nullptr)) return update_status::UPDATE_ERROR;
		if (mov <= -3000 && mov >= -4950) if (!App->render->Blit(layout[4], mov * 1.75 + 6595, -607 + movy * 1.75, nullptr)) return update_status::UPDATE_ERROR;
		if (mov <= -3750) if (!App->render->Blit(layout[5], mov * 1.75 + 8235, -607 + movy * 1.75, nullptr)) return update_status::UPDATE_ERROR;


		//make so pressing SPACE the other stage is loaded
		if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
		{
			App->fade->FadeToBlack(App->level01, App->stage_clear, 1);
		}
	}

	return UPDATE_CONTINUE;
}

update_status Level01::PostUpdate()
{
	//Switch buffers so we actually render
	SDL_RenderPresent(App->render->renderer);

	return UPDATE_CONTINUE;
}