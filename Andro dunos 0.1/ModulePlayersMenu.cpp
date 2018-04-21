#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "Animation.h"
#include "ModuleRender.h"
#include "ModulePlayersMenu.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "Level01.h"
#include "ModuleFadeToBlack.h"
#include "SDL\include\SDL.h"
#include "ModuleAudio.h"
#include "Module_player_2.h"
#include "ModuleFonts.h"
#include <stdio.h>

ModulePlayersMenu::ModulePlayersMenu()
{
	// Background
	bg.x = 0;
	bg.y = 0;
	bg.w = 304;
	bg.h = 224;

	// Timer animation
	timer.PushBack({ 36, 81, 17, 8 }); // 3rd column
	timer.PushBack({ 36, 72, 17, 8 });
	timer.PushBack({ 36, 63, 17, 8 });
	timer.PushBack({ 36, 54, 17, 8 });
	timer.PushBack({ 36, 45, 17, 8 });
	timer.PushBack({ 36, 36, 17, 8 });
	timer.PushBack({ 36, 27, 17, 8 });
	timer.PushBack({ 36, 18, 17, 8 });
	timer.PushBack({ 36, 9, 17, 8 });
	timer.PushBack({ 36, 0, 17, 8 });
	timer.PushBack({ 18, 81, 17, 8 }); // 2nd column
	timer.PushBack({ 18, 72, 15, 8 });
	timer.PushBack({ 18, 63, 15, 8 });
	timer.PushBack({ 18, 54, 15, 8 });
	timer.PushBack({ 18, 45, 15, 8 });
	timer.PushBack({ 18, 36, 15, 8 });
	timer.PushBack({ 18, 27, 15, 8 });
	timer.PushBack({ 18, 18, 15, 8 });
	timer.PushBack({ 18, 9, 15, 8 });
	timer.PushBack({ 18, 0, 15, 8 });
	timer.PushBack({ 0, 81, 15, 8 }); // 1st column
	timer.PushBack({ 0, 72, 17, 8 });
	timer.PushBack({ 0, 63, 17, 8 });
	timer.PushBack({ 0, 54, 17, 8 });
	timer.PushBack({ 0, 45, 17, 8 });
	timer.PushBack({ 0, 36, 17, 8 });
	timer.PushBack({ 0, 27, 17, 8 });
	timer.PushBack({ 0, 18, 17, 8 });
	timer.PushBack({ 0, 9, 17, 8 });
	timer.PushBack({ 0, 0, 17, 8 });
	timer.PushBack({ 0, 0, 17, 8 });
	timer.loop = false;
	timer.speed = 0.01f;

	// p1 animation
	p1.PushBack({ 0, 0, 112, 8 });
	p1.PushBack({ 112, 0, 112, 8 });
	p1.loop = true;
	p1.speed = 0.02f;

	// p2 animation
	p2.PushBack({ 0, 0, 160, 8 });
	p2.PushBack({ 0, 160, 160, 8 });
	p2.loop = true;
	p2.speed = 0.02f;

}

ModulePlayersMenu::~ModulePlayersMenu()
{}

// Load assets
bool ModulePlayersMenu::Start()
{
	LOG("Loading background assets");
	bool ret = true;

	graphics = App->textures->Load("Images/logo-background.png");
	graphics2 = App->textures->Load("Images/logo_solo.png");
	graphics3 = App->textures->Load("Images/press_1p_start.png");
	graphics4 = App->textures->Load("Images/press_2p_start.png");
	graphics5 = App->textures->Load("Images/visco_games.png");
	graphics6 = App->textures->Load("Images/text.png");
	graphics7 = App->textures->Load("Images/timer.png");
	graphics8 = App->textures->Load("Images/credit.png");
	font_credits = App->fonts->Load("Images/credits_numbers.png", "0123456789", 1);
	coin = App->audio->LoadSoundEffect("Music/COIN_inserted.wav");

	App->render->camera.x = App->render->camera.y = 0;

	return ret;
}

// UnLoad assets
bool ModulePlayersMenu::CleanUp()
{
	LOG("Unloading game intro scene");

	timer.Reset();
	p1.Reset();
	p2.Reset();

	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->textures->Unload(graphics3);
	App->textures->Unload(graphics4);
	App->textures->Unload(graphics5);
	App->textures->Unload(graphics6);
	App->textures->Unload(graphics7);
	App->textures->Unload(graphics8);
	App->fonts->UnLoad(font_credits);
	App->audio->UnloadSoundEffect(coin);

	return true;
}

// PreUpdate: clear screen to black before every frame
update_status ModulePlayersMenu::PreUpdate()
{
	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, 0);
	SDL_RenderClear(App->render->renderer);

	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModulePlayersMenu::Update()
{

	if (App->input->keyboard[SDL_SCANCODE_1] == KEY_DOWN) 
	{
		Mix_VolumeChunk(coin, MIX_MAX_VOLUME);
		App->audio->PlaySoundEffect(coin);
		cr++;
	}
	sprintf_s(credits_text, 10, "%7d", cr);
	App->fonts->BlitText(5, 7, font_credits, credits_text);

	current_animation = &timer;
	current_animation2 = &p1;
	current_animation3 = &p2;

	App->render->Blit(graphics, 0, 0, &bg);
	App->render->Blit(graphics2, 33, 40, NULL);
	App->render->Blit(graphics8, 230, 208, NULL);

	// pi
	if (cr < 2)
		App->render->Blit(graphics3, 97, 142, &(current_animation2->GetCurrentFrame()));

	// p2
	if (cr > 1)
		App->render->Blit(graphics4, 73, 142, &(current_animation3->GetCurrentFrame()));

	App->render->Blit(graphics5, 68, 159, NULL);
	App->render->Blit(graphics6, 56, 185, NULL);
	App->render->Blit(graphics7, 168, 201, &(current_animation->GetCurrentFrame()));

	if (timer.current_frame >= timer.last_frame - 1)
	{
		App->fade->FadeToBlack(this, (Module*)App->level01, 1);
		App->player2->Two_Players = false;
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->fade->IsFading() == false && cr >= 1)
	{
		App->fade->FadeToBlack(this, (Module*)App->level01);
		App->player2->Two_Players = false;
		cr--;
	}

	if (App->input->keyboard[SDL_SCANCODE_BACKSPACE] == KEY_DOWN && App->fade->IsFading() == false && cr > 1)
	{
		App->fade->FadeToBlack(this, (Module*)App->level01);
		App->player2->Two_Players = true;
		cr -= 2;
	}

	return UPDATE_CONTINUE;
}
