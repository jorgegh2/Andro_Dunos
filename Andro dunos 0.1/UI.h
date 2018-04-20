#ifndef __UI_H__
#define __UI_H__

#include "Module.h"
//#include <iostream>

class ModuleUI : public Module 
{
public:

	ModuleUI();

	// Destructor
	virtual ~ModuleUI();

	// Called before quitting
	bool Start();

	// Called before quitting
	bool CleanUp();

	update_status Update();

public:
	int font_score = -1;
	char score_text[10];
	uint score = 0;
};


#endif
