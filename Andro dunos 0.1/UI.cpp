#include "UI.h"
#include "Application.h"
#include "ModuleFonts.h"
#include <stdio.h>

ModuleUI::ModuleUI(){}

ModuleUI::~ModuleUI() {}

bool ModuleUI::Start() {

	score = 0;

	font_score = App->fonts->Load("Images/Font-score-white.png", "1234567890P", 1);

	return true;
}

update_status ModuleUI::Update() {

	sprintf_s(score_text, 10, "%7d", score);

	App->fonts->BlitText(10, 10, font_score, score_text);
	App->fonts->BlitText(73, 10, font_score, "P");

	return UPDATE_CONTINUE;
}

bool ModuleUI::CleanUp() {

	App->fonts->UnLoad(font_score);

	return true;
}