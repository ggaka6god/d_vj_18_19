#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"

#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes

enum GUI_TYPE
{
	INTERACTIVE,
	NON_INTERACTIVE,
	TEXT,
	NONE
};

struct GUI_elem
{
	SDL_Rect source_elem_rect;
	GUI_TYPE type;
	iPoint pos_on_screen;
};

// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	void ManageFocus();

	// TODO 2: Create the factory methods
	// Gui creation functions

	GUI_elem* AddUIElement(GUI_TYPE _type, iPoint _pos_on_screen);

	const SDL_Texture* GetAtlas() const;

public:
	bool debug_draw = false;

private:

	SDL_Texture* atlas;
	p2SString atlas_file_name;

	p2List<GUI_elem*> elements;
	GUI_elem* curr_element;

	uint curr_tab = 0;
};

#endif // __j1GUI_H__