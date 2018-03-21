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
	tex[0] = App->textures->Load("1.png");
	tex[1] = App->textures->Load("2.png");
	tex[2] = App->textures->Load("3.png");
	tex[3] = App->textures->Load("4.png");
	tex[4] = App->textures->Load("5.png");
	tex[5] = App->textures->Load("6.png");
	tex[6] = App->textures->Load("7.png");
	tex[7] = App->textures->Load("8.png");
	tex[8] = App->textures->Load("9.png");
	tex[9] = App->textures->Load("10.png");
	tex[10] = App->textures->Load("11.png");
	tex[11] = App->textures->Load("12.png");
	tex[12] = App->textures->Load("13.png");
	tex[13] = App->textures->Load("14.png");
	tex[14] = App->textures->Load("15.png");
	tex[15] = App->textures->Load("16.png");

	mov = 0;
	return ret;
}

// Called every draw update
update_status ModuleRender::PreUpdate()
{
	
	// TODO 7: Clear the screen to black before starting every frame
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(renderer);
	// TODO 10: Blit our test texture to check functionality
	for (int i = 0; i < 16; ++i) {
		if (i >= 8) {
			if (!Blit(tex[i], mov + i*TILE_WITH - 5, SCREEN_HEIGHT/2, nullptr)) return update_status::UPDATE_ERROR;
		}
		else{
			if (!Blit(tex[i], mov + i*TILE_WITH, SCREEN_HEIGHT/2, nullptr)) return update_status::UPDATE_ERROR;
		}
	}
	--mov;
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
