#include "UI.h"
#include "Application.h"
#include "ModuleFonts.h"
#include <stdio.h>
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInsertCoin.h"
#include "Module_Player_2.h"
#include "ModulePlayersMenu.h"
#include "SDL\include\SDL.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleGameOver.h"
#include "Level01.h"

ModuleUI::ModuleUI()
{
	
	rc.PushBack({ 0, 0, 86, 11 });
	rc.PushBack({ 0, 11, 86, 11 });
	rc.speed = 0.01f;
	rc.loop = true;

	p2b.PushBack({ 0, 0, 124, 11 });
	p2b.PushBack({ 0, 11, 124, 11 });
	p2b.speed = 0.01f;
	p2b.loop = true;

	bar_1.x = 29;
	bar_1.y = 28;
	bar_1.w = 64;
	bar_1.h = 6;

}

ModuleUI::~ModuleUI() {}

bool ModuleUI::Start() {

	score = 0;
	score2 = 0;

	red_insert_coin = App->textures->Load("Images/HUD/insert_coin_red_p2.png");
	red_2p_button = App->textures->Load("Images/HUD/red_p2_button.png");
	font_score = App->fonts->Load("Images/Fonts/Font-score-white.png", "1234567890P", 1);
	font_credits = App->fonts->Load("Images/Fonts/credits_numbers.png", "0123456789", 1);
	font_high_score = App->fonts->Load("Images/Fonts/red_font_high_score_corrected.png", "0123456789", 1);
	graphics8 = App->textures->Load("Images/credit.png");

	high_score = App->textures->Load("Images/HUD/red_high_score.png");

	// Shots
	UI = App->textures->Load("Images/HUD/ui_elements_base.png");
	UI_laser = App->textures->Load("Images/HUD/ui_elements_laser.png");
	UI_backshoot = App->textures->Load("Images/HUD/ui_elements_backshoot.png");
	UI_helix = App->textures->Load("Images/HUD/ui_elements_helix.png");

	// Numbers
	font_power_up = App->fonts->Load("Images/HUD/numbers_powerup_corrected.png", "012345678", 1);

	// SA bar
	bar = App->textures->Load("Images/HUD/pritesheet-charge-beam.png");

	Life_texture1 = App->textures->Load("Images/HUD/Player_1_life.png");
	Continue = App->textures->Load("Images/continue-fonts.png");
	Continue_Number = App->fonts->Load("Images/continue-fonts-number.png", "0123456789", 1);

	return true;
}

update_status ModuleUI::Update()
{
	red_coin = &rc;
	p2_button = &p2b;

	if (App->player2->IsEnabled() == false && App->players_menu->cr == 0)
	{
		App->render->Blit(red_insert_coin, 188, 16, &(red_coin->GetCurrentFrame()), 0.0f, false);
	}
	if (App->player2->IsEnabled() == false && App->players_menu->cr > 0)
	{
		App->render->Blit(red_2p_button, 160, 16, &(p2_button->GetCurrentFrame()), 0.0f, false);
	}


	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) == true && r_shoulder_pressed == false)
	{
		r_shoulder_pressed = true;
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) == false)
	{
		r_shoulder_pressed = false;
	}


	// P1
	sprintf_s(score_text, 10, "%7d", score);
	App->fonts->BlitText(30, 7, font_score, score_text);
	App->fonts->BlitText(5, 7, font_score, "1P");

	// P2
	sprintf_s(score_text2, 10, "%7d", score2);
	App->fonts->BlitText(233, 7, font_score, score_text2);
	App->fonts->BlitText(210, 7, font_score, "2P");

	// SHOW CREDITS BOTTOM RIGHT
	sprintf_s(credits_text, 10, "%7d", App->players_menu->cr);
	App->fonts->BlitText(234, 208, font_credits, credits_text);
	App->render->Blit(graphics8, 230, 208, NULL, false);
	if (App->players_menu->cr < 10) {
		App->fonts->BlitText(280, 208, font_credits, "0");
	}

	// Highscore
	highscore = score + score2;
	App->render->Blit(high_score, 101, 7, NULL, 0.0f, false);
	sprintf_s(high_score_text, 10, "%7d", highscore);
	App->fonts->BlitText(122, 7, font_high_score, high_score_text);
	/*
	if (highscore < 10)
	{
		App->fonts->BlitText(132, 7, font_high_score, "0");  // + 8
		App->fonts->BlitText(140, 7, font_high_score, "0");
		App->fonts->BlitText(148, 7, font_high_score, "0");
		App->fonts->BlitText(156, 7, font_high_score, "0");
		App->fonts->BlitText(164, 7, font_high_score, "0");
		App->fonts->BlitText(172, 7, font_high_score, "0");
		App->fonts->BlitText(180, 7, font_high_score, "0");
	}
	// more conditions to add, for now it's ok because highscore is constant
	else if (highscore < 100 && highscore >= 10)
	{
		App->fonts->BlitText(132, 7, font_high_score, "0");  // + 8
		App->fonts->BlitText(140, 7, font_high_score, "0");
		App->fonts->BlitText(148, 7, font_high_score, "0");
		App->fonts->BlitText(156, 7, font_high_score, "0");
		App->fonts->BlitText(164, 7, font_high_score, "0");
		App->fonts->BlitText(172, 7, font_high_score, "0");
	}
	else if (highscore < 1000 && highscore >= 100)
	{
		App->fonts->BlitText(132, 7, font_high_score, "0");  // + 8
		App->fonts->BlitText(140, 7, font_high_score, "0");
		App->fonts->BlitText(148, 7, font_high_score, "0");
		App->fonts->BlitText(156, 7, font_high_score, "0");
		App->fonts->BlitText(164, 7, font_high_score, "0");
	}
	else if (highscore < 10000 && highscore >= 1000)
	{
		App->fonts->BlitText(132, 7, font_high_score, "0");  // + 8
		App->fonts->BlitText(140, 7, font_high_score, "0");
		App->fonts->BlitText(148, 7, font_high_score, "0");
		App->fonts->BlitText(156, 7, font_high_score, "0");
	}
	else if (highscore < 100000 && highscore >= 10000)
	{
		App->fonts->BlitText(132, 7, font_high_score, "0");  // + 8
		App->fonts->BlitText(140, 7, font_high_score, "0");
		App->fonts->BlitText(148, 7, font_high_score, "0");
	}
	else if (highscore < 1000000 && highscore >= 100000)
	{
		App->fonts->BlitText(132, 7, font_high_score, "0");  // + 8
		App->fonts->BlitText(140, 7, font_high_score, "0");
	}
	else if (highscore < 10000000 && highscore >= 1000000)
	{
		App->fonts->BlitText(132, 7, font_high_score, "0");  // + 8
	}*/

	/*HUD PLAYER 1*/
	// Weapons image
	if (App->player->change_weapon == 0)
		App->render->Blit(UI, 5, 16, NULL, 0.0f, false);
	else if (App->player->change_weapon == 1)
		App->render->Blit(UI_laser, 5, 16, NULL, 0.0f, false);
	else if (App->player->change_weapon == 2)
		App->render->Blit(UI_backshoot, 5, 16, NULL, 0.0f, false);
	else if (App->player->change_weapon == 3)
		App->render->Blit(UI_helix, 5, 16, NULL, 0.0f, false);

	// Numbers Player 1
	sprintf_s(powerup_text, 9, "%7d", n_powerup);
	App->fonts->BlitText(-7, 17, font_power_up, powerup_text);

	// Special attack bar p1
	App->render->Blit(bar, 68, 24, &bar_1, 0.0f, false);

	// Lifes
	if (App->player->life >= 2) App->render->Blit(Life_texture1, 10, 24, NULL, 0.0f, false);

	if (App->player->life == 3) App->render->Blit(Life_texture1, 19, 24, NULL, 0.0f, false);

	if (App->player->life <= 0)
	{

		time_dead = SDL_GetTicks() - time_dead_init;

		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || r_shoulder_pressed == true)
		{
			App->player->life = 3;
			App->player->Enable();

			App->player->PlayerSpawn();
		}

		else if (Cuenta_atras_number == 0)
		{
			App->fade->FadeToBlack(App->level01, App->game_over, 1);


		}

		if (time_dead >= 1000) {
			time_dead = 0;
			//para que cada segundo se reinicie y vuelva a contar un segundo
			time_dead_init = SDL_GetTicks();
			Cuenta_atras_number--;
			App->player->Disable();
		}

		sprintf_s(Cuenta_atras, 10, "%7d", Cuenta_atras_number);
		App->render->Blit(Continue, SCREEN_WIDTH / 10 - 2, SCREEN_HEIGHT / 4, NULL, 0.0f, false);
		App->fonts->BlitText(-146, SCREEN_HEIGHT / 4 + 60, Continue_Number, Cuenta_atras);

	}


	// Lifes player 2
	if (App->player2->IsEnabled())
	{
	
	if (App->player2->life >= 2) App->render->Blit(Life_texture1, 177, 24, NULL, 0.0f, false);

	if (App->player2->life == 3) App->render->Blit(Life_texture1, 186, 24, NULL, 0.0f, false);

	if (App->player2->life <= 0)
	{

		time_dead = SDL_GetTicks() - time_dead_init;

		if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || r_shoulder_pressed == true)
		{
			App->player2->life = 3;
			App->player2->Enable();

			App->player2->PlayerSpawn();
		}

		else if (Cuenta_atras_number == 0)
		{
			App->fade->FadeToBlack(App->level01, App->game_over, 1);


		}

		if (time_dead >= 1000) {
			time_dead = 0;
			//para que cada segundo se reinicie y vuelva a contar un segundo
			time_dead_init = SDL_GetTicks();
			Cuenta_atras_number--;
			App->player2->Disable();
		}

		sprintf_s(Cuenta_atras, 10, "%7d", Cuenta_atras_number);
		App->render->Blit(Continue, SCREEN_WIDTH / 10 - 2, SCREEN_HEIGHT / 4, NULL, 0.0f, false);
		App->fonts->BlitText(-146, SCREEN_HEIGHT / 4 + 60, Continue_Number, Cuenta_atras);

	}
	}

	/* HUD PLAYER 2*/
	if (App->player2->IsEnabled() == true) {
		if (App->player2->change_weapon == 0)
			App->render->Blit(UI, 171, 16, NULL, 0.0f, false);
		else if (App->player2->change_weapon == 1)
			App->render->Blit(UI_laser, 171, 16, NULL, 0.0f, false);
		else if (App->player2->change_weapon == 2)
			App->render->Blit(UI_backshoot, 171, 16, NULL, 0.0f, false);
		else if (App->player2->change_weapon == 3)
			App->render->Blit(UI_helix, 171, 16, NULL, 0.0f, false);

		// Numbers Player 2
		sprintf_s(powerup_text2, 9, "%7d", n_powerup2);
		App->fonts->BlitText(159, 17, font_power_up, powerup_text2);


		// Special attack bar p2
		App->render->Blit(bar, 234, 24, &bar_1, 0.0f, false);

	}

	return UPDATE_CONTINUE;
}

bool ModuleUI::CleanUp() {

	App->fonts->UnLoad(font_score);
	App->fonts->UnLoad(Continue_Number);
	App->fonts->UnLoad(font_credits);
	App->fonts->UnLoad(font_high_score);
	App->fonts->UnLoad(font_power_up);

	App->textures->Unload(high_score);

	App->textures->Unload(UI);
	App->textures->Unload(UI_laser);
	App->textures->Unload(UI_backshoot);
	App->textures->Unload(UI_helix);

	App->textures->Unload(bar);

	App->textures->Unload(red_insert_coin);
	App->textures->Unload(red_2p_button);
	

	App->textures->Unload(graphics8); // credits

	App->textures->Unload(Continue);
	App->textures->Unload(Life_texture1);

	return true;
}