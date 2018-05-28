#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "Module_Player_2.h"
#include "SDL\include\SDL.h"
#include "ModuleParticles.h"
#include "UI.h"
#include "ModuleGameOver.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "Level01.h"
#include "ModuleGameIntroduction.h"
#include "ModuleAudio.h"
#include "ModulePowerUp.h"
#include "ModulePlayer.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer2::ModulePlayer2()
{
	graphics = NULL;
	current_animation = &idle;

	// Idle animation
	idle.PushBack({ 154, 108, SHIP_WIDTH, SHIP_HEIGHT });

	// Up animation
	up.PushBack({ 154, 87, SHIP_WIDTH, SHIP_HEIGHT });
	up.PushBack({ 154, 66, SHIP_WIDTH, SHIP_HEIGHT });
	up.loop = false;
	up.speed = 0.1f;

	upback.PushBack({ 154, 87, SHIP_WIDTH, SHIP_HEIGHT });
	upback.PushBack({ 154, 108, SHIP_WIDTH, SHIP_HEIGHT });
	upback.loop = false;
	upback.speed = 0.1f;

	// Down animation
	down.PushBack({ 154, 131, SHIP_WIDTH, SHIP_HEIGHT });
	down.PushBack({ 154, 153, SHIP_WIDTH, SHIP_HEIGHT });
	down.loop = false;
	down.speed = 0.1f;

	downback.PushBack({ 154, 131, SHIP_WIDTH, SHIP_HEIGHT });
	downback.PushBack({ 154, 108, SHIP_WIDTH, SHIP_HEIGHT });
	downback.loop = false;
	downback.speed = 0.1f;

	// Turbo

	turbo_idle.PushBack({ 73, 116, 12, 5 });
	turbo_idle.PushBack({ 61, 116, 12, 5 });
	turbo_idle.PushBack({ 42, 116, 12, 5 });
	turbo_idle.loop = true;
	turbo_idle.speed = 0.8f;
}

ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Images/Ship/ships.png"); // arcade version
	c_player2 = App->collision->AddCollider({ position.x, position.y, 27, 17 }, COLLIDER_PLAYER, this);

	laser_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-3_(Main_Ships).wav");
	basic_attack_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-1_(Main_Ships).wav");
	helix_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type-4_(Main_Ships).wav");

	player_death = App->audio->LoadSoundEffect("Music/Sounds_effects/Player_Death_Explosion.wav");
	change_weapon_sound = App->audio->LoadSoundEffect("Music/Sounds_effects/Laser_Shot_Type_CHANGE.wav");

	PlayerSpawn();

	life = 3;

	//destroyed = false;

	return ret;
}

// Unload assets
bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player 2");

	App->audio->UnloadSoundEffect(player_death);
	App->audio->UnloadSoundEffect(laser_sound);
	App->audio->UnloadSoundEffect(basic_attack_sound);
	App->audio->UnloadSoundEffect(change_weapon_sound);
	App->audio->UnloadSoundEffect(helix_sound);

	App->textures->Unload(graphics);

	current_animation = &idle;

	return true;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	anim_turbo = &turbo_idle;

	position.x = App->render->camera.x / SCREEN_SIZE + location.x;
	position.y = App->render->camera.y / SCREEN_SIZE + location.y;

	int speed = 2;


	if (SDL_GameControllerGetAxis(App->input->controller2, SDL_CONTROLLER_AXIS_LEFTY) > 5000 && player_down == false)
	{
		player_down = true;
	}
	if (SDL_GameControllerGetAxis(App->input->controller2, SDL_CONTROLLER_AXIS_LEFTY) > 5000 == false)
	{
		player_down = false;
	}

	if (SDL_GameControllerGetAxis(App->input->controller2, SDL_CONTROLLER_AXIS_LEFTY) < -5000 && player_up == false)
	{
		player_up = true;
	}
	if (SDL_GameControllerGetAxis(App->input->controller2, SDL_CONTROLLER_AXIS_LEFTY) < -5000 == false)
	{
		player_up = false;
	}

	if (SDL_GameControllerGetAxis(App->input->controller2, SDL_CONTROLLER_AXIS_LEFTY) > -5000 && SDL_GameControllerGetAxis(App->input->controller2, SDL_CONTROLLER_AXIS_LEFTY) < 5000 && player_up == false && player_down == false && player_idle == false)
	{
		player_idle = true;
	}
	if (SDL_GameControllerGetAxis(App->input->controller2, SDL_CONTROLLER_AXIS_LEFTY) > -5000 && SDL_GameControllerGetAxis(App->input->controller2, SDL_CONTROLLER_AXIS_LEFTY) < 5000)
	{
		player_idle = false;
	}




	if ((App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT || (SDL_GameControllerGetAxis(App->input->controller2, SDL_CONTROLLER_AXIS_LEFTX) < -5000)) && position.x > App->render->camera.x / SCREEN_SIZE)
	{
		location.x -= speed;
	}

	if ((App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT || (SDL_GameControllerGetAxis(App->input->controller2, SDL_CONTROLLER_AXIS_LEFTX) > 5000)) && position.x < App->render->camera.x / SCREEN_SIZE + SCREEN_WIDTH - SHIP_WIDTH)
	{
		location.x += speed;
	}

	if ((App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT || player_down == true) && position.y < App->render->camera.y / SCREEN_SIZE + SCREEN_HEIGHT - SHIP_HEIGHT)
	{
		location.y += speed;
		player_idle = true;
		reverse = false;
		if (current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
	}

	else if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_UP || (player_idle == true && player_down == false && reverse == false))
		if (current_animation != &downback)
		{
			downback.Reset();
			current_animation = &downback;
			player_idle = false;
		}

	if ((App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT || player_up == true) && position.y > App->render->camera.y / SCREEN_SIZE)
	{
		location.y -= speed;
		player_idle = true;
		reverse = true;
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
	}

	else if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_UP || (player_idle == true && player_up == false))
		if (current_animation != &upback)
		{
			upback.Reset();
			current_animation = &upback;
			player_idle = false;
		}

	// Player 2 controls input

	/* pressed */
	if (SDL_GameControllerGetButton(App->input->controller2, SDL_CONTROLLER_BUTTON_A) && a_pressed == false)
	{
		shoot = true;
		a_pressed = true;
	}
	if (SDL_GameControllerGetButton(App->input->controller2, SDL_CONTROLLER_BUTTON_X) && x_pressed == false)
	{
		powerup = true;
		x_pressed = true;
	}
	if (SDL_GameControllerGetButton(App->input->controller2, SDL_CONTROLLER_BUTTON_B) && b_pressed == false)
	{
		change = true;
		b_pressed = true;
	}

	/*not pressed*/

	if (SDL_GameControllerGetButton(App->input->controller2, SDL_CONTROLLER_BUTTON_A) == false)
	{
		a_pressed = false;
	}
	if (SDL_GameControllerGetButton(App->input->controller2, SDL_CONTROLLER_BUTTON_X) == false)
	{
		x_pressed = false;
	}
	if (SDL_GameControllerGetButton(App->input->controller2, SDL_CONTROLLER_BUTTON_B) == false)
	{
		b_pressed = false;
	}

	// Change player 2 weapon

	if (App->input->keyboard[SDL_SCANCODE_O] == KEY_STATE::KEY_DOWN || change == true)
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
	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_DOWN || powerup == true)
	{
		powerup = false;
		switch (power_up) {

		case POWER_UPS::POWER_UP_BASIC:
			power_up = POWER_UPS::POWER_UP_1;
			App->UI->n_powerup2 = 2;
			break;

		case POWER_UPS::POWER_UP_1:
			power_up = POWER_UPS::POWER_UP_2;
			App->UI->n_powerup2 = 3;
			break;

		case POWER_UPS::POWER_UP_2:
			power_up = POWER_UPS::POWER_UP_3;
			App->UI->n_powerup2 = 4;
			break;

		case POWER_UPS::POWER_UP_3:
			power_up = POWER_UPS::POWER_UP_4;
			App->UI->n_powerup2 = 5;
			break;

		case POWER_UPS::POWER_UP_4:
			power_up = POWER_UPS::POWER_UP_5;
			App->UI->n_powerup2 = 6;
			break;

		case POWER_UPS::POWER_UP_5:
			power_up = POWER_UPS::POWER_UP_6;
			App->UI->n_powerup2 = 7;
			break;

		case POWER_UPS::POWER_UP_6:
			power_up = POWER_UPS::POWER_UP_BASIC;
			App->UI->n_powerup2 = 1;
			break;
		}
	}
	//
	//////////
	// Shoot 
	if (App->input->keyboard[SDL_SCANCODE_RCTRL] == KEY_STATE::KEY_DOWN || shoot == true)
	{
		shoot = false;
		switch (power_up) {
		case POWER_UPS::POWER_UP_BASIC:
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				App->particles->AddParticle(App->particles->basic_shoot_0_down, position.x + 15, position.y + 11, COLLIDER_PLAYER_SHOT);
				App->particles->AddParticle(App->particles->basic_shoot_0_up, position.x + 15, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(basic_attack_sound);
				//App->UI->score += 100;
				break;

			case CHANGE_WEAPON::LASER:
				App->particles->AddParticle(App->particles->laser_0, position.x + 20, position.y + 10, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::BACK_SHOOT:
				App->particles->AddParticle(App->particles->back_shoot_0, position.x + 20, position.y + 10, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_0_back, position.x + 15, position.y + 10, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::HELIX:
				App->particles->AddParticle(App->particles->helix_01_1, position.x + 20, position.y + 11, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_01_2, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(helix_sound);
				break;
			}

			break;

		case POWER_UPS::POWER_UP_1:
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				App->particles->AddParticle(App->particles->basic_shoot_1_down, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_1_up, position.x + 20, position.y + 4, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_1, position.x + 26, position.y + 10, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(basic_attack_sound);
				break;

			case CHANGE_WEAPON::LASER:
				App->particles->AddParticle(App->particles->laser_1, position.x + 12, position.y - 2, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_1_5, position.x + 12, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::BACK_SHOOT:
				App->particles->AddParticle(App->particles->back_shoot_0, position.x + 20, position.y + 10, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_0_back, position.x + 15, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_0_back, position.x + 15, position.y + 13, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::HELIX:
				App->particles->AddParticle(App->particles->helix_01_1, position.x + 13, position.y + 11, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_01_2, position.x + 13, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_01_3, position.x + 26, position.y + 9, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(helix_sound);
				break;
			}




			break;

		case POWER_UPS::POWER_UP_2:
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				App->particles->AddParticle(App->particles->basic_shoot_2_down, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_2_up, position.x + 20, position.y + 0, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_2, position.x + 22, position.y + 9, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(basic_attack_sound);
				break;

			case CHANGE_WEAPON::LASER:
				App->particles->AddParticle(App->particles->laser_1, position.x + 12, position.y - 2, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_1_5, position.x + 12, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_2, position.x + 5, position.y - 2, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_2_5, position.x + 5, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::BACK_SHOOT:
				App->particles->AddParticle(App->particles->back_shoot_0, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_0, position.x + 20, position.y + 13, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_2_diagonal_up, position.x + 10, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_2_diagonal_down, position.x + 10, position.y + 8, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::HELIX:
				App->particles->AddParticle(App->particles->helix_02_1, position.x + 13, position.y + 11, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_02_2, position.x + 13, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_02_3, position.x + 26, position.y + 9, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(helix_sound);
				break;
			}

			break;
		case POWER_UPS::POWER_UP_3:
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				App->particles->AddParticle(App->particles->basic_shoot_3_down, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_3_up, position.x + 20, position.y - 2, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_2, position.x + 24, position.y + 9, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(basic_attack_sound);
				break;

			case CHANGE_WEAPON::LASER:
				App->particles->AddParticle(App->particles->laser_3_up, position.x + 12, position.y - 2, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_3_down, position.x + 12, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_3_up_back, position.x + 5, position.y - 2, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_3_down_back, position.x + 5, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::BACK_SHOOT:
				App->particles->AddParticle(App->particles->back_shoot_0, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_0, position.x + 20, position.y + 13, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_2_diagonal_up, position.x + 10, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_2_diagonal_down, position.x + 10, position.y + 8, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_3_back, position.x, position.y + 8, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::HELIX:
				App->particles->AddParticle(App->particles->helix_03_1, position.x + 10, position.y + 13, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_03_2, position.x + 10, position.y + 5, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_02_1, position.x + 23, position.y + 13, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_02_2, position.x + 23, position.y + 5, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(helix_sound);
				break;
			}
			break;

		case POWER_UPS::POWER_UP_4:
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				App->particles->AddParticle(App->particles->basic_shoot_3_down, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_3_up, position.x + 20, position.y - 3, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_4_down, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_4_up, position.x + 20, position.y + 4, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(basic_attack_sound);
				break;

			case CHANGE_WEAPON::LASER:
				App->particles->AddParticle(App->particles->laser_4_up, position.x + 5, position.y - 10, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_4_down, position.x + 5, position.y + 4, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_4_up_back, position.x - 10, position.y - 10, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_4_down_back, position.x - 10, position.y + 4, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::BACK_SHOOT:
				App->particles->AddParticle(App->particles->back_shoot_0, position.x + 20, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_0, position.x + 20, position.y + 13, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_3_diagonal_up, position.x + 10, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_3_diagonal_down, position.x + 10, position.y + 8, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_3_back, position.x, position.y + 8, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::HELIX:
				App->particles->AddParticle(App->particles->helix_04_1, position.x + 23, position.y + 13, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_04_2, position.x + 23, position.y + 5, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_03_1, position.x + 10, position.y + 13, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_03_2, position.x + 10, position.y + 5, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(helix_sound);
				break;
			}
			break;

		case POWER_UPS::POWER_UP_5:
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				App->particles->AddParticle(App->particles->basic_shoot_3_down, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_3_up, position.x + 20, position.y - 5, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_5_down, position.x + 20, position.y + 10, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_5_up, position.x + 20, position.y, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(basic_attack_sound);
				break;

			case CHANGE_WEAPON::LASER:
				App->particles->AddParticle(App->particles->laser_5_up, position.x + 5, position.y - 10, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_5_down, position.x + 5, position.y + 4, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_5_up_back, position.x - 10, position.y - 10, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_5_down_back, position.x - 10, position.y + 4, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::BACK_SHOOT:
				App->particles->AddParticle(App->particles->back_shoot_0_5, position.x + 17, position.y + 11, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_0_up, position.x + 14, position.y + 1, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_0_down, position.x + 14, position.y + 12, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_3_diagonal_up, position.x + 10, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_3_diagonal_down, position.x + 10, position.y + 8, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_3_back, position.x, position.y + 8, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;


			case CHANGE_WEAPON::HELIX:
				App->particles->AddParticle(App->particles->helix_05_3, position.x + 26, position.y + 9, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_05_1, position.x + 23, position.y + 13, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_05_2, position.x + 23, position.y + 5, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_03_1, position.x + 10, position.y + 13, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_03_2, position.x + 10, position.y + 5, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(helix_sound);
				break;
			}
			break;

		case POWER_UPS::POWER_UP_6:
			switch (change_weapon) {

			case CHANGE_WEAPON::BASIC_ATTACK:
				App->particles->AddParticle(App->particles->basic_shoot_6_down, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_6_up, position.x + 20, position.y - 11, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_5_down, position.x + 20, position.y + 12, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->basic_shoot_5_up, position.x + 20, position.y - 1, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(basic_attack_sound);
				break;

			case CHANGE_WEAPON::LASER:
				App->particles->AddParticle(App->particles->laser_6_up, position.x + 5, position.y - 30, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_6_down, position.x + 5, position.y, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_6_up_back, position.x - 25, position.y - 30, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->laser_6_down_back, position.x - 25, position.y, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::BACK_SHOOT:
				App->particles->AddParticle(App->particles->back_shoot_1_5, position.x + 20, position.y + 9, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_0_up, position.x + 14, position.y + 1, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_0_down, position.x + 14, position.y + 12, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_3_diagonal_up, position.x + 10, position.y + 7, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_3_diagonal_down, position.x + 10, position.y + 8, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->back_shoot_3_back, position.x, position.y + 8, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(laser_sound);
				break;

			case CHANGE_WEAPON::HELIX:
				App->particles->AddParticle(App->particles->helix_05_3, position.x + 26, position.y + 9, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_05_1, position.x + 23, position.y + 13, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_05_2, position.x + 23, position.y + 5, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_06_1, position.x + 10, position.y + 13, COLLIDER_PLAYER_SHOT_2);
				App->particles->AddParticle(App->particles->helix_06_2, position.x + 10, position.y + 5, COLLIDER_PLAYER_SHOT_2);
				App->audio->PlaySoundEffect(helix_sound);
				break;

			}
		}
	}

	if (time_finished == false)
	{
		time_final = SDL_GetTicks() - time_init;
		if (time_final <= 2000 && time_final >= 1000) {
			location.x += 1;
			position.x = App->render->camera.x / SCREEN_SIZE + location.x;
			position.y = App->render->camera.y / SCREEN_SIZE + location.y;

		}

		else {
			position.x = App->render->camera.x / SCREEN_SIZE + location.x;
			position.y = App->render->camera.y / SCREEN_SIZE + location.y;


		}

		if (time_final > 2000) destroyed = false;
		if (time_final >= 4000)
		{
			time_finished = true;
			god_mode = false;

		}

		// Draw everything -------------------------------------- parpadeo
		if (time_final % 100 <= 50) {
			App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
			App->render->Blit(graphics, position.x - 12, position.y + 8, &(anim_turbo->GetCurrentFrame()));
		}
	}


	else {


		// Draw everything --------------------------------------
		App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
		App->render->Blit(graphics, position.x - 12, position.y + 8, &(anim_turbo->GetCurrentFrame()));

		position.x = App->render->camera.x / SCREEN_SIZE + location.x;
		position.y = App->render->camera.y / SCREEN_SIZE + location.y;

	}



	if (!App->player->god_mode)
	{
		c_player2->SetPos(position.x, position.y);
	}

	return UPDATE_CONTINUE;
}

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2)
{
	if (c_player2 != nullptr && c_player2 == c1 && App->fade->IsFading() == false && c2 != App->power_up->c_power_up)
	{
		//code
		if (!god_mode) {
			App->audio->PlaySoundEffect(player_death);
			App->particles->AddParticle(App->particles->explosion, position.x, position.y);
			life--;
			destroyed = true;
			PlayerSpawn();
			if (life <= 0) {
				App->UI->time_dead = 0;
				App->UI->Cuenta_atras_number = 9;
				App->UI->time_dead_init = SDL_GetTicks();

				/*App->player->Disable();
				App->fade->FadeToBlack(App->level01, App->game_over, 1);*/
			}
		}
	}
	if (c_player2 != nullptr && c_player2 == c1 && App->fade->IsFading() == false && c2 == App->power_up->c_power_up)
	{
		App->power_up->Disable();
	}
}

void ModulePlayer2::PlayerSpawn() {
	time_init = SDL_GetTicks();
	time_final = 0;
	time_finished = false;
	god_mode = true;
	/*	position.x = App->render->camera.x / SCREEN_SIZE;
	position.y = App->render->camera.y / SCREEN_SIZE;*/
	location.x = -SHIP_WIDTH;
	location.y = 50;
	current_animation = &idle;

}