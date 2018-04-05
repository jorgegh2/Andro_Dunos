#ifndef __ModuleRenderer_H__
#define __ModuleRenderer_H__

#include "SDL\include\SDL_rect.h"
#include "Module.h"

struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Rect;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PostUpdate();
	update_status PreUpdate();
	bool CleanUp();

	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section);

public:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* tex;
	SDL_Texture* layout;
	float mov;
	float movy;
	int position[2];
	SDL_Rect camera;
	bool stop = false;
};

#endif //__ModuleRenderer_H__