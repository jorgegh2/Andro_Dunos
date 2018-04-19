#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 17

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModulePlayer;
class ModuleFadeToBlack;
class ModuleGameIntroduction;
class ModuleStageClear;
class ModuleGameOver;
class Level01;
class Module;
class ModuleAudio;
class ModuleParticles;
class ModuleCollision;
class ModuleEnemies;
class ModulePlayer2;
class ModuleViscoGames;
class ModuleFonts;

class Application
{
public:

	Module * modules[NUM_MODULES]; // = { nullptr }; ? see effect
	ModuleWindow* window = nullptr;
	ModuleRender* render = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModulePlayer* player = nullptr;
	ModuleFadeToBlack* fade = nullptr;
	Level01* level01 = nullptr;
	ModuleGameIntroduction* game_intro = nullptr;
	ModuleViscoGames* visco_games = nullptr;
	ModuleGameOver* game_over = nullptr;
	ModuleAudio* audio = nullptr;
	ModuleStageClear* stage_clear = nullptr;
	ModuleParticles* particles = nullptr;
	ModuleCollision* collision = nullptr;
	ModuleEnemies* enemy = nullptr;
	ModulePlayer2* player2 = nullptr;
	ModuleFonts* fonts = nullptr;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__