#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"

j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	return true;
}

GUI_elem* j1Gui::CreateGuiElem(SDL_Texture * _texture, SDL_Rect _source_elem_rect, GUI_TYPE _type, iPoint _pos_on_screen, const char * _text)
{
	GUI_elem* ret = new GUI_elem;
	switch (_type)
	{
		case INTERACTIVE:
			ret->texture = _texture;
			ret->source_elem_rect = _source_elem_rect;

			break;
		case NON_INTERACTIVE:

			break;
		case TEXT:

			break;
		case NONE:

			break;
		default:
			break;
	}

	GUI_elem_list.add(ret);
	return ret;
}

// const getter for atlas
const SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

// class Gui ---------------------------------------------------

