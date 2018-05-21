#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 22

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
class ModuleInsertCoin;
class ModulePlayersMenu;
class ModuleUI;
class Level03;
class ModulePowerUp;

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
	ModuleInsertCoin* insert_coin = nullptr;
	ModulePlayersMenu* players_menu = nullptr;
	ModuleUI* UI = nullptr;
	Level03* level03 = nullptr;
	ModulePowerUp* power_up = nullptr;

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