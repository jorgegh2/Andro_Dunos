#ifndef __ModuleAudio_H__
#define __ModuleAudio_H__

#include "Module.h"
#include "Globals.h"
#include "SDL_mixer/include/SDL_mixer.h"

#pragma comment ( lib, "SDL_mixer/libx86/SDL2_mixer.lib")

#define MAX_MUSIC 25
#define MAX_FX 25

class ModuleAudio :public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Init();

	bool CleanUp();

	void PlayMusic(Mix_Music* music_to_play, int repetitions = -1);
	void PlaySoundEffect(Mix_Chunk* effect_to_play);

	Mix_Music* LoadMusic(char* path);
	Mix_Chunk* LoadSoundEffect(char* path);

	void UnloadMusic(Mix_Music*music);
	void UnloadSoundEffect(Mix_Chunk* effect);

public:

	Mix_Music* songs[MAX_MUSIC];
	//last_song contador
	//uint no conta els negatius, mes eficient
	uint last_song = 0;

	//last_effect contador
	Mix_Chunk* sound_effects[MAX_FX];
	uint last_effect = 0;
};

#endif

