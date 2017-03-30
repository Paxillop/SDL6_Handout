
#ifndef __MODULEINTRO_H__
#define __MODULEINTRO_H__

#include "Module.h"

struct SDL_Texture;

class ModuleIntro : public Module
{
public:
	ModuleIntro();
	~ModuleIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* intro_back = nullptr;
	SDL_Rect background;
	bool fading;
	int background_x;
	int background_y;
};

#endif // __MODULEINTROE_H__


