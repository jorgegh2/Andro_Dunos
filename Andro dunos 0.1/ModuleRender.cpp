#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"

ModuleRender::ModuleRender() : Module()
{}

// Destructor
ModuleRender::~ModuleRender()
{}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if (REN_VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	if (renderer == NULL)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	// TODO 9: load a texture "test.png" to test is everything works well
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
	return ret;
}

// Called every draw update
update_status ModuleRender::PreUpdate()
{

	// TODO 7: Clear the screen to black before starting every frame
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(renderer);
	// TODO 10: Blit our test texture to check functionality

	for (int i = 0; i < 3; ++i) {
		if (i == 0) {
			if (mov + position[0] < 0 - TILE_WIDTH) position[0] += TILE_WIDTH * 3;
			if (!Blit(tex, mov + position[0], 120 + movy * 0.5, nullptr)) return update_status::UPDATE_ERROR;
		}
		else if (i == 1) {
			if (mov + position[1] + TILE_WIDTH < 0 - TILE_WIDTH) position[1] += TILE_WIDTH * 3;
			if (!Blit(tex, mov + TILE_WIDTH + position[1], 120 + movy * 0.5, nullptr)) return update_status::UPDATE_ERROR;
		}
		else {
			if (mov + position[2] + TILE_WIDTH * 2 < 0 - TILE_WIDTH) position[2] += TILE_WIDTH * 3;
			if (!Blit(tex, mov + TILE_WIDTH * 2 + position[2], 120 + movy * 0.5, nullptr)) return update_status::UPDATE_ERROR;
		}
	}

	if (xstop == false && mov >= -5149) {
		mov -= 0.45;
	}

	if ((mov <= -1684 && movy == 0) || (mov <= -4091 && movy <= -128)) xstop = true;
	else if ((mov <= -1684 && movy <= -128) || (mov <= -4091 && movy >= 0)) xstop = false;
	if ((mov <= -1684 && mov >= -1685 && movy >= -128)||(mov <= -2590 && mov >= -2660)||(mov <= -3468 && mov >= -3596)) {
		movy -= 0.45;
	}
	else if ((mov <= -2297 && mov >= -2368) || (mov <= -2918 && mov >= -3044) || (mov <= -4091 && mov >= -4092)) {
		movy += 0.45;
	}

	if (mov >= -950) if (!Blit(layout[0], mov * 1.75, -607 + movy * 1.75, nullptr)) return update_status::UPDATE_ERROR;
	if (mov <= -750 && mov >= -1950) if (!Blit(layout[1], mov * 1.75 + 1640, -607 + movy * 1.75, nullptr)) return update_status::UPDATE_ERROR;
	if (mov <= -1500 && mov >= -2950) if (!Blit(layout[2], mov * 1.75 + 3281, -607 + movy * 1.75, nullptr)) return update_status::UPDATE_ERROR;
	if (mov <= -2250 && mov >= -3950) if (!Blit(layout[3], mov * 1.75 + 4938, -607 + movy * 1.75, nullptr)) return update_status::UPDATE_ERROR;
	if (mov <= -3000 && mov >= -4950) if (!Blit(layout[4], mov * 1.75 + 6595, -607 + movy * 1.75, nullptr)) return update_status::UPDATE_ERROR;
	if (mov <= -3750) if (!Blit(layout[5], mov * 1.75 + 8235, -607 + movy * 1.75, nullptr)) return update_status::UPDATE_ERROR;
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{
	// TODO 8: Switch buffers so we actually render
	SDL_RenderPresent(renderer);
	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy window
	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section)
{
	bool ret = true;
	SDL_Rect rect;
	rect.x = x * SCREEN_SIZE;
	rect.y = y * SCREEN_SIZE;

	if (section != nullptr)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
	}

	rect.w *= SCREEN_SIZE;
	rect.h *= SCREEN_SIZE;

	if (SDL_RenderCopy(renderer, texture, section, &rect) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}