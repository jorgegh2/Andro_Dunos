#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleStageClear.h"
#include "ModuleGameOver.h"
#include "SDL/include/SDL.h"

#include "ModulePlayer.h"
#include "Level01.h"
ModuleInput::ModuleInput() : Module()
{
	for (uint i = 0; i < MAX_KEYS; ++i)
		keyboard[i] = KEY_IDLE;
}

// Destructor
ModuleInput::~ModuleInput()
{
}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	// Init controller subsystem
	if (SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER) < 0) {

		LOG("SDL_GAMECONTROLLER could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_Event e;
	SDL_PumpEvents();
	SDL_PollEvent(&e);

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keys[i] == 1)
		{
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}

	if (keyboard[SDL_SCANCODE_ESCAPE] || e.type == SDL_QUIT) return update_status::UPDATE_STOP;


	// Controllers

	if (controller1 == nullptr || controller2 == nullptr) {

		for (int i = 0; i < SDL_NumJoysticks(); ++i) {

			if (SDL_IsGameController(i)) {

				// Controller1
				controller1 = SDL_GameControllerOpen(i);

				if (controller1 != nullptr) {

					map1 = SDL_GameControllerMapping(controller1);
				}

				// maybe for controller2 put if i > 0 ?? must see
				// Controller2
				controller2 = SDL_GameControllerOpen(i);

				if (controller1 != nullptr) {

					map2 = SDL_GameControllerMapping(controller2);
				}
			}
		}
	}


	return update_status::UPDATE_CONTINUE;
}

update_status ModuleInput::Update()
{
	if (App->input->keyboard[SDL_SCANCODE_F4] == 1)
	{
		App->level01->Enable();
		App->player->Enable();
		App->stage_clear->Enable();
	}
	if (App->input->keyboard[SDL_SCANCODE_F5] == 1)
		App->game_over->Enable();

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	SDL_QuitSubSystem(SDL_INIT_GAMECONTROLLER); ////// new, remember
	return true;
}