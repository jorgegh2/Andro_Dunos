#include "UI.h"
#include "Application.h"
#include "ModuleFonts.h"
#include <stdio.h>
#include "ModuleTextures.h"
#include "ModuleRender.h"


ModuleUI::ModuleUI(){}

ModuleUI::~ModuleUI() {}

bool ModuleUI::Start() {

	score = 0;

	font_score = App->fonts->Load("Images/Font-score-white.png", "1234567890P", 1);
	UI = App->textures->Load("Images/ui_elements_base.png");
	Life_texture1 = App->textures->Load("Images/Player_1_life.png");
	

	return true;
}

update_status ModuleUI::Update() 
{

	sprintf_s(score_text, 10, "%7d", score);
	
	App->fonts->BlitText(5, 7, font_score, score_text);
	App->fonts->BlitText(5, 7, font_score, "1P");
	//HUD
	App->render->Blit(UI, 5, 15, NULL, 0.0f, false);
	//lifes
	App->render->Blit(Life_texture1, 10, 23, NULL, 0.0f, false);
	App->render->Blit(Life_texture1, 19, 23, NULL, 0.0f, false);
	

	return UPDATE_CONTINUE;
}

bool ModuleUI::CleanUp() {

	App->fonts->UnLoad(font_score);

	return true;
}