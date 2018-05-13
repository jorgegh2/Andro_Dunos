#include "UI.h"
#include "Application.h"
#include "ModuleFonts.h"
#include <stdio.h>
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL.h"

ModuleUI::ModuleUI(){}

ModuleUI::~ModuleUI() {}

bool ModuleUI::Start() {

	score = 0;
	Cuenta_atras_number = 9;

	font_score = App->fonts->Load("Images/Fonts/Font-score-white.png", "1234567890P", 1);
	UI = App->textures->Load("Images/HUD/ui_elements_base.png");
	Life_texture1 = App->textures->Load("Images/HUD/Player_1_life.png");
	Continue = App->textures->Load("Images/continue-fonts.png");
	Continue_Number = App->fonts->Load("Images/continue-fonts-number.png", "0123456789", 1);

	return true;
}

update_status ModuleUI::Update() 
{

	sprintf_s(score_text, 10, "%7d", score);
	
	App->fonts->BlitText(30, 7, font_score, score_text);
	App->fonts->BlitText(5, 7, font_score, "1P");
	//HUD
	App->render->Blit(UI, 5, 16, NULL, 0.0f, false);
	//lifes
	if(App->player->life >= 2) App->render->Blit(Life_texture1, 10, 24, NULL, 0.0f, false);
	
	if (App->player->life == 3) App->render->Blit(Life_texture1, 19, 24, NULL, 0.0f, false);
	
	if (App->player->life <= 0)
	{
		time_dead_init = SDL_GetTicks();
		time_dead = SDL_GetTicks() - time_dead_init;
		if (time_dead >= 13000)
		{
			App->player->life = 3;
		}
		
		Cuenta_atras_number = 5;
		
		sprintf_s(Cuenta_atras, 10, "%7d", Cuenta_atras_number);
		App->render->Blit(Continue, SCREEN_WIDTH / 10, SCREEN_HEIGHT / 4, NULL, 0.0f, false);
		App->fonts->BlitText(10, SCREEN_HEIGHT / 4, Continue_Number, Cuenta_atras);

	}

	return UPDATE_CONTINUE;
}

bool ModuleUI::CleanUp() {

	App->fonts->UnLoad(font_score);

	return true;
}