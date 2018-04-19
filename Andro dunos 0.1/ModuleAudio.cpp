#include "ModuleAudio.h"
#include "SDL_mixer\include\SDL_mixer.h"

ModuleAudio::ModuleAudio()
{
	for (uint i = 0; i < MAX_MUSIC; ++i)
	{
		songs[i] = nullptr;
	}



	for (uint i = 0; i < MAX_FX; ++i)
	{
		sound_effects[i] = nullptr;
	}
}

ModuleAudio::~ModuleAudio()
{
}

bool ModuleAudio::Init()
{
	bool ret = true;

	LOG("Init Audio Module.......");

	if (Mix_Init(MIX_INIT_OGG) < 0)
	{
		LOG("Audio Module can't be initialitzed: %s\n", Mix_GetError());
		return false;
	}
	else
	{
		if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024) < 0)
		{
			LOG("Audio Module can't open: %s\n", Mix_GetError());
		}
	}

	return ret;
}

bool ModuleAudio::CleanUp()
{
	for (uint i = 0; i < MAX_MUSIC; ++i)
	{
		if (songs[i] != nullptr){
			Mix_FreeMusic(songs[i]);
		sound_effects[i] = nullptr;
		}
	}

	for (uint i = 0; i < MAX_FX; ++i)
	{
		if (sound_effects[i] != nullptr) {
			Mix_FreeChunk(sound_effects[i]);
			sound_effects[i] = nullptr;
		}
	}

	Mix_CloseAudio();
	Mix_Quit();

	return true;
}

Mix_Music* ModuleAudio::LoadMusic(char* path)
{


	Mix_Music* music = nullptr;
	if (last_song < MAX_MUSIC) {
		music = Mix_LoadMUS(path);

		if (music == nullptr)
		{
			LOG("Couldn't load song with path: %s")
		}
		else
		{
			songs[last_song++] = music;
		}
	}
	return music;
}

Mix_Chunk* ModuleAudio::LoadSoundEffect(char* path)
{
	Mix_Chunk* effect = nullptr;

	if (last_song < MAX_FX)
	{
		effect = Mix_LoadWAV(path);

		if (effect == nullptr)
		{
			LOG("error");
		}
		else
		{
			sound_effects[last_effect++] = effect;
		}
	}
	return effect;
}

void ModuleAudio::UnloadMusic(Mix_Music* music)
{
	for (uint i = 0; i < last_song; ++i)
	{
		if (songs[i] == music)
		{
			Mix_FreeMusic(music);
			songs[i] = nullptr;
		
			break;
		}
	}
}

void ModuleAudio::UnloadSoundEffect(Mix_Chunk* effect)
{
	for (uint i = 0; i < last_song; ++i)
	{
		if (sound_effects[i] == effect)
		{
			Mix_FreeChunk(effect);
			sound_effects[i] = nullptr;
		
			break;
		}
	}
}


void ModuleAudio::PlayMusic(Mix_Music* music_to_play, int milisec, int  repetitions) {
	Mix_FadeInMusic(music_to_play, repetitions, milisec);
	Mix_VolumeMusic(MIX_MAX_VOLUME / 3);
}

void ModuleAudio::PlaySoundEffect(Mix_Chunk* effect_to_play)
{
	Mix_PlayChannel(-1, effect_to_play, 0);
}

void ModuleAudio::StopMusic(int  milisec) {
	Mix_FadeOutMusic(milisec);
}

void ModuleAudio::StopSoundEffect(int channel_stopped) {
	Mix_HaltChannel(channel_stopped);
}
