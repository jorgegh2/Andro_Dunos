#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "SDL\include\SDL.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "Level01.h"
#include "ModuleGameOver.h"
#include "ModuleGameIntroduction.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"
#include "UI.h"
#include "Module_player_2.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	graphics = NULL;
	current_animation = NULL;

	// Idle animation
	idle.PushBack({ 94, 108, SHIP_WIDTH, SHIP_HEIGHT });

	// Up animation
	up.PushBack({ 94, 87, SHIP_WIDTH, SHIP_HEIGHT });
	up.PushBack({ 94, 66, SHIP_WIDTH, SHIP_HEIGHT });
	up.loop = false;
	up.speed = 0.1f;

	upback.PushBack({ 94, 87, SHIP_WIDTH, SHIP_HEIGHT });
	upback.PushBack({ 94, 108, SHIP_WIDTH, SHIP_HEIGHT });
	upback.loop = false;
	upback.speed = 0.1f;

	// Down animation
	down.PushBack({ 94, 131, SHIP_WIDTH, SHIP_HEIGHT });
	down.PushBack({ 94, 153, SHIP_WIDTH, SHIP_HEIGHT });
	down.loop = false;
	down.speed = 0.1f;

	downback.PushBack({ 94, 131, SHIP_WIDTH, SHIP_HEIGHT });
	downback.PushBack({ 94, 108, SHIP_WIDTH, SHIP_HEIGHT });
	downback.loop = false;
	downback.speed = 0.1f;

	// Turbo

	turbo_idle.PushBack({ 73, 116, 12, 5 });
	turbo_idle.PushBack({ 61, 116, 12, 5 });
	turbo_idle.PushBack({ 42, 116, 12, 5 });
	turbo_idle.loop = true;
	turbo_idle.speed = 0.8f;

	/*turbo_up.PushBack({ 73, 66, 12, 10 });
	turbo_up.PushBack({ 58, 66, 12, 10 });
	turbo_up.PushBack({ 42, 66, 12, 10 });
	turbo_down.loop = true;
	turbo_down.speed = 0.5f;*/

	/*
	turbo_up.PushBack({ 73, 91, 12, 8 });
	turbo_up.PushBack({ 59, 91, 12, 8 });
	turbo_up.PushBack({ 42, 91, 12, 8 });
	turbo_up.loop = true;
	turbo_up.speed = 0.8f;
	turbo_down.PushBack({});
	turbo_down.loop = true;
	turbo_down.speed = 0.8f;
	*/

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Images/Ship/ships.png"); // arcade version
	laser_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-3_(Main_Ships).wav");
	basic_attack_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-1_(Main_Ships).wav");
	helix_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-4_(Main_Ships).wav");
	
	c_player = App->collision->AddCollider({ position.x, position.y, 27, 17 }, COLLIDER_PLAYER, this);
	
	player_death = App->audio->LoadSoundEffect("Music/Sounds_effects/Player_Death_Explosion.wav");
	change_weapon_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type_CHANGE.wav");
	god_mode = false;

	position.x = 0;
	position.y = 0;
	location.x = 100;
	location.y = 100;
	life = 1;
	return ret;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");
	App->audio->UnloadSoundEffect(player_death);
	App->audio->UnloadSoundEffect(laser_sound);
	App->audio->UnloadSoundEffect(basic_attack_sound);
	App->audio->UnloadSoundEffect(change_weapon_sound);
	App->textures->Unload(graphics);

	current_animation = &idle;

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	
	anim_turbo = &turbo_idle;

	int speed = 2;


	if (SDL_GameControllerGetAxis(App->input->controller1, SDL_CONTROLLER_AXIS_LEFTY) > 5000 && player_down == false)
	{
		player_down = true;
	}
	if (SDL_GameControllerGetAxis(App->input->controller1, SDL_CONTROLLER_AXIS_LEFTY) > 5000 == false)
	{
		player_down = false;
	}

	if (SDL_GameControllerGetAxis(App->input->controller1, SDL_CONTROLLER_AXIS_LEFTY) < -5000 && player_up == false)
	{
		player_up = true;
	}
	if (SDL_GameControllerGetAxis(App->input->controller1, SDL_CONTROLLER_AXIS_LEFTY) < -5000 == false)
	{
		player_up = false;
	}

	if (SDL_GameControllerGetAxis(App->input->controller1, SDL_CONTROLLER_AXIS_LEFTY) > -5000 && SDL_GameControllerGetAxis(App->input->controller1, SDL_CONTROLLER_AXIS_LEFTY) < 5000 && player_up == false && player_down == false  && player_idle == false)
	{
		player_idle = true;
	}
	if (SDL_GameControllerGetAxis(App->input->controller1, SDL_CONTROLLER_AXIS_LEFTY) > -5000 && SDL_GameControllerGetAxis(App->input->controller1, SDL_CONTROLLER_AXIS_LEFTY) < 5000)
	{
		player_idle = false;
	}




	if ((App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT || (SDL_GameControllerGetAxis(App->input->controller1, SDL_CONTROLLER_AXIS_LEFTX) < -5000)) && position.x > App->render->camera.x / SCREEN_SIZE)
	{
		location.x -= speed;
	}

	if ((App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT || (SDL_GameControllerGetAxis(App->input->controller1, SDL_CONTROLLER_AXIS_LEFTX) > 5000)) && position.x < App->render->camera.x / SCREEN_SIZE + SCREEN_WIDTH - SHIP_WIDTH)
	{
		location.x += speed;
	}

	if ((App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT || player_down == true) && position.y < App->render->camera.y / SCREEN_SIZE + SCREEN_HEIGHT - SHIP_HEIGHT)
	{
		location.y += speed;
		if (current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
		
	}

	else if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP || (player_idle == true && player_down == false))
		if (current_animation != &downback)
		{
			downback.Reset();
			current_animation = &downback;

		}

	if ((App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT || player_up == true) && position.y > App->render->camera.y / SCREEN_SIZE)
	{
		location.y -= speed;
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
			anim_turbo = &turbo_up;
		}
	}

	else if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_UP || (player_idle == true && player_up == false))
		if (current_animation != &upback)
		{
			upback.Reset();
			current_animation = &upback;
			anim_turbo = &turbo_up;
		}


	// Player controls input

	/* pressed */
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_A) && a_pressed == false)
	{
		shoot = true;
		a_pressed = true;
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_X) && x_pressed == false)
	{
		powerup = true;
		x_pressed = true;
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_B) && b_pressed == false)
	{
		change = true;
		b_pressed = true;
	}

	/*not pressed*/

	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_A) == false)
	{
		a_pressed = false;
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_X) == false)
	{
		x_pressed = false;
	}
	if (SDL_GameControllerGetButton(App->input->controller1, SDL_CONTROLLER_BUTTON_B) == false)
	{
		b_pressed = false;
	}

	if (App->input->keyboard[SDL_SCANCODE_C] == KEY_STATE::KEY_DOWN || change == true)
	{
		change = false;
		switch (change_weapon) {

		case CHANGE_WEAPON::BASIC_ATTACK:
			change_weapon = CHANGE_WEAPON::LASER;
			App->audio->PlaySoundEffect(change_weapon_sound);

			break;

		case CHANGE_WEAPON::LASER:
			change_weapon = CHANGE_WEAPON::BACK_SHOOT;
			App->audio->PlaySoundEffect(change_weapon_sound);

			break;

		case CHANGE_WEAPON::BACK_SHOOT:
			change_weapon = CHANGE_WEAPON::HELIX;
			App->audio->PlaySoundEffect(change_weapon_sound);

			break;

		case CHANGE_WEAPON::HELIX:
			change_weapon = CHANGE_WEAPON::BASIC_ATTACK;
			App->audio->PlaySoundEffect(change_weapon_sound);

			break;
		}
	}


	// POWERUP
	if (App->input->keyboard[SDL_SCANCODE_X] == KEY_STATE::KEY_DOWN || powerup == true)
	{
		powerup = false;
		switch (power_up) {

		case POWER_UPS::POWER_UP_BASIC:
			power_up = POWER_UPS::POWER_UP_1;
			break;

		case POWER_UPS::POWER_UP_1:
			power_up = POWER_UPS::POWER_UP_2;
			break;

		case POWER_UPS::POWER_UP_2:
			power_up = POWER_UPS::POWER_UP_BASIC;
			break;
		}
	}
	//
	//////////

	// Shoot 
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN || shoot == true)
	{
		shoot = false;
		switch (power_up) {
		case POWER_UPS::POWER_UP_BASIC:
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				App->particles->AddParticle(App->particles->basic_shoot_0_down, position.x + 20, position.y + 11, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->basic_shoot_0_up, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(basic_attack_sound);
				//App->UI->score += 100;
				break;

			case CHANGE_WEAPON::LASER:
				App->particles->AddParticle(App->particles->laser_0, position.x + 20, position.y + 10, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::BACK_SHOOT:
				App->particles->AddParticle(App->particles->back_shoot_0, position.x + 20, position.y + 11, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::HELIX:
				App->particles->AddParticle(App->particles->helix_01_1, position.x + 20, position.y + 11, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->helix_01_2, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(helix_sound);
			
			}

			break;

		case POWER_UPS::POWER_UP_1:
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				App->particles->AddParticle(App->particles->basic_shoot_1_down, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->basic_shoot_1_up, position.x + 20, position.y + 4, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->basic_shoot_1, position.x + 26, position.y + 10, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(basic_attack_sound);
				break;

			case CHANGE_WEAPON::LASER:
				App->particles->AddParticle(App->particles->laser_1, position.x + 12, position.y - 2, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_1_5, position.x + 12, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			// case BACK_SHOOT
				
			case CHANGE_WEAPON::HELIX:
				App->particles->AddParticle(App->particles->helix_01_1, position.x + 20, position.y + 11, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->helix_01_2, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->helix_01_3, position.x + 20, position.y + 9, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(helix_sound);

			}

			


			break;

		case POWER_UPS::POWER_UP_2:
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				App->particles->AddParticle(App->particles->basic_shoot_2_down, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->basic_shoot_2_up, position.x + 20, position.y + 2, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->basic_shoot_2, position.x + 20, position.y + 9, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(basic_attack_sound);
				break;

			case CHANGE_WEAPON::LASER:
				App->particles->AddParticle(App->particles->laser_1, position.x + 12, position.y - 2, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_1_5, position.x + 12, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_2, position.x + 5, position.y - 2, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->laser_2_5, position.x + 5, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(laser_sound);
				break;

				// case BACK_SHOOT

			case CHANGE_WEAPON::HELIX:
				App->particles->AddParticle(App->particles->helix_02_1, position.x + 20, position.y + 11, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->helix_02_2, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->helix_02_3, position.x + 20, position.y + 9, COLLIDER_PLAYER_SHOT);
				App->audio->PlaySoundEffect(helix_sound);

			}

			break;

		}
	}

	//GOD MODE

	if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN) {
		if (god_mode)
			god_mode = false;
		else god_mode = true;
	}

	if (!god_mode)
	{
		if (App->player2->IsEnabled() == true)
			App->player2->c_player2->SetPos(App->player2->position.x, App->player2->position.y);

		c_player->SetPos(position.x, position.y);
	}
	else
	{
		c_player->SetPos(-100, -100);
		if (App->player2->IsEnabled() == true)
			App->player2->c_player2->SetPos(-100, -100);
	}


	if (time_finished == false)
	{
		time_final = SDL_GetTicks() - time_init;
		if (time_final <= 1000) {
			location.x +=1;
			position.x = App->render->camera.x / SCREEN_SIZE + location.x;
			position.y = App->render->camera.y / SCREEN_SIZE + location.y;
		}
		else {
			position.x = App->render->camera.x / SCREEN_SIZE + location.x;
			position.y = App->render->camera.y / SCREEN_SIZE + location.y;
		}
		
	
		if (time_final >= 4000)
		{
			time_finished = true;
			god_mode = false;
		}
		

	}
	
	
	else {
		position.x = App->render->camera.x / SCREEN_SIZE + location.x;
		position.y = App->render->camera.y / SCREEN_SIZE + location.y;
	}

	


	// Draw everything --------------------------------------
	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	App->render->Blit(graphics, position.x - 12, position.y + 8, &(anim_turbo->GetCurrentFrame()));
	if (App->input->keyboard[SDL_SCANCODE_BACKSPACE] == KEY_DOWN && App->fade->IsFading() == false)
	{
		App->player2->Enable();

	}



	return UPDATE_CONTINUE;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c_player != nullptr && c_player == c1 && App->fade->IsFading() == false)
	{
		//code
		App->audio->PlaySoundEffect(player_death);
		App->particles->AddParticle(App->particles->explosion, position.x, position.y);
		life--;
		time_init = SDL_GetTicks();
		time_final = 0;
		time_finished = false;
		god_mode = true;
		position.x = App->render->camera.x / SCREEN_SIZE;
		position.y = App->render->camera.y / SCREEN_SIZE;
		location.x = -SHIP_WIDTH;
		location.y = 100;
		if (life <= 0) {
			App->UI->time_dead = 0;
			App->UI->Cuenta_atras_number = 9;
			App->UI->time_dead_init = SDL_GetTicks();

			/*App->player->Disable();
			App->fade->FadeToBlack(App->level01, App->game_over, 1);*/
		


		}
	}
}