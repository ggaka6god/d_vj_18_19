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
	SDL_Texture* texture;
	SDL_Rect source_elem_rect;
	GUI_TYPE type;
	iPoint pos_on_screen;
	const char* text = nullptr;
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

	// TODO 2: Create the factory methods
	// Gui creation functions

	GUI_elem* CreateGuiElem(GUI_TYPE _type, SDL_Rect _source_elem_rect, iPoint _pos_on_screen, SDL_Texture * _texture, const char * _text);

	p2List<GUI_elem*> GUI_elem_list;

	const SDL_Texture* GetAtlas() const;

private:

	SDL_Texture* atlas;
	p2SString atlas_file_name;
};

#endif // __j1GUI_H__