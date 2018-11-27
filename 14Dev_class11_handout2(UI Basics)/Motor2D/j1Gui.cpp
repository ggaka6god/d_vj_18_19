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

	if (GUI_elem_list.count() > 0)
	{
		p2List_item<GUI_elem*>* g_item = GUI_elem_list.getFirst();
		while (g_item)
		{
			delete g_item->data;
			g_item = g_item->next;
		}
		GUI_elem_list.clear();
		LOG("GUI CLEAN UP OK!");
	}
	LOG("ERROR CLEANING UP GUI");
		return false;
}

GUI_elem* j1Gui::CreateGuiElem(GUI_TYPE _type, SDL_Rect _source_elem_rect, iPoint _pos_on_screen, SDL_Texture * _texture, const char * _text)
{
	
	GUI_elem* ret = new GUI_elem;
	switch (_type)
	{
		case INTERACTIVE:
			ret->type = _type;
			ret->source_elem_rect = _source_elem_rect;
			ret->pos_on_screen = _pos_on_screen;
			ret->texture = _texture;

			break;
		case NON_INTERACTIVE:
			ret->type = _type;
			ret->source_elem_rect = _source_elem_rect;
			ret->pos_on_screen = _pos_on_screen;
			ret->texture = _texture;

			break;
		case TEXT:
			ret->type = _type;
			ret->source_elem_rect = _source_elem_rect;
			ret->pos_on_screen = _pos_on_screen;
			ret->text = _text;

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

