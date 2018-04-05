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

	if(REN_VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);
	
	if(renderer == NULL)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	// TODO 9: load a texture "test.png" to test is everything works well
	tex = App->textures->Load("Background1.png");
	layout = App->textures->Load("Background_all.png");
	
	mov = -1680;
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
			if (!Blit(tex, mov + position[0], 120 + movy*0.5, nullptr)) return update_status::UPDATE_ERROR;
		}
		else if (i == 1) {
			if (mov + position[1] + TILE_WIDTH < 0 - TILE_WIDTH) position[1] += TILE_WIDTH * 3;
			if (!Blit(tex, mov + TILE_WIDTH + position[1], 120 + movy*0.5, nullptr)) return update_status::UPDATE_ERROR;
		}
		else {
			if (mov + position[2] + TILE_WIDTH * 2 < 0 - TILE_WIDTH) position[2] += TILE_WIDTH * 3;
			if (!Blit(tex, mov + TILE_WIDTH * 2 + position[2], 120 + movy*0.5, nullptr)) return update_status::UPDATE_ERROR;
		}
	}
	
	if (mov > -1683 || movy <=-128) {		
		mov -= 0.45;
	}

	else if(mov <= -1683 && movy>=-128 && stop == false) {
		movy -= 0.45;
	}

	if (mov < -1900) {
		if(movy == 127) stop = true;
		movy += 0.45;
		
	}



	if (!Blit(layout, mov * 1.75, -607 + movy*1.75, nullptr)) return update_status::UPDATE_ERROR;
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
	if(renderer != nullptr)
		SDL_DestroyRenderer(renderer);

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section)
{
	bool ret = true;
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;

	if(section != nullptr)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
	}


	if(SDL_RenderCopy(renderer, texture, section, &rect) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		system("pause");
		ret = false;
	}

	return ret;
}
