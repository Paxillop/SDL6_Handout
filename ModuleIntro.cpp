
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleIntro.h"
#include "ModuleSceneSpace.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleIntro::ModuleIntro()
{
	background.w = SCREEN_WIDTH;
	background.h = SCREEN_HEIGHT + 50;
	background_x = 0;
	background_y = -34;
}

ModuleIntro::~ModuleIntro()
{}

// Load assets
bool ModuleIntro::Start()
{
	LOG("Loading intro scene");
	bool ret = true;
	intro_back = App->textures->Load("rtype/intro.png");

	App->player->Disable();

	fading = false;

	return ret;
}

// UnLoad assets
bool ModuleIntro::CleanUp()
{
	LOG("Unloading intro scene");

	App->textures->Unload(intro_back);
	App->player->Disable();

	return true;
}

// Update: draw background
update_status ModuleIntro::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(intro_back, background_x, background_y, &background, 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] && fading == false)
	{
		App->fade->FadeToBlack(this, App->scene_space);
		fading = true;
	}

	return UPDATE_CONTINUE;
}

