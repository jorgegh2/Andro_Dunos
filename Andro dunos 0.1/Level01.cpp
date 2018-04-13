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
	underground_tile = App->textures->Load("under_tile.png");
	start_under = App->textures->Load("start_under.png");
	end_under = App->textures->Load("end_under.png");

	mov = -1600;
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

	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 255);

	SDL_RenderClear(App->render->renderer);

	//here we multiply mov and movy to a value to adapt into the original parallax speed
	//numbers like that are added to mov and movy are used to place the sprite at the x and y axes 

	if (App->level01->IsEnabled() == true) {

		for (int i = 0; i < 3; ++i) {
			if (mov + position[i] + TILE_WIDTH * i < 0 - TILE_WIDTH) position[i] += TILE_WIDTH * 3;//position is used to place the tile after the last tile when it's out of screen in left
			if (!App->render->Blit(tex, mov + TILE_WIDTH * i + position[i], 120 + movy * 0.5, nullptr)) return update_status::UPDATE_ERROR;
		}

		if (movy <= -60) if (!App->render->Blit(start_under, mov * 0.9 + 1510, 65 + movy * 0.5, nullptr)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(underground_tile, mov * 0.9 + 2091, -128 + movy * 0.5, nullptr)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(underground_tile, mov * 0.9 + 2091 + UNDER_TILE_WIDTH, -128 + movy * 0.5, nullptr)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(underground_tile, mov * 0.9 + 2091 + UNDER_TILE_WIDTH * 2, -128 + movy * 0.5, nullptr)) return update_status::UPDATE_ERROR;
		if (!App->render->Blit(underground_tile, mov * 0.9 + 2091 + UNDER_TILE_WIDTH * 3, -128 + movy * 0.5, nullptr)) return update_status::UPDATE_ERROR;

		if (movy <= -50) if (!App->render->Blit(end_under, mov * 0.9 + 2091 + UNDER_TILE_WIDTH * 4 - 64, 65 + movy * 0.5, nullptr)) return update_status::UPDATE_ERROR;//64 is the mesure of 1/6th of the under_tile_width here it's used to fit the end of the underground background into the previous tiles
		if (xstop == false && mov >= -5149) {
			mov -= 0.45; //speed in x axes
		}

		if ((mov <= -1684 && movy == 0) || (mov <= -4091 && movy <= -128)) xstop = true; // stop scrolling in x axes
		else if ((mov <= -1684 && movy <= -128) || (mov <= -4091 && movy >= 0)) xstop = false; // enable scroll in x axes
		if ((mov <= -1684 && mov >= -1685 && movy >= -128) || (mov <= -2590 && mov >= -2660) || (mov <= -3468 && mov >= -3595)) {
			movy -= 0.45; // speed in y axes
		}
		else if ((mov <= -2297 && mov >= -2368) || (mov <= -2918 && mov >= -3044) || (mov <= -4091 && mov >= -4092)) {
			movy += 0.45; // speed in y axes
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
			App->fade->FadeToBlack(App->level01, App->game_intro, 1);
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