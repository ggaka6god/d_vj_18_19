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

	if (elements.count() > 0)
	{
		p2List_item<GUI_elem*>* g_item = elements.getFirst();
		while (g_item)
		{
			delete g_item->data;
			g_item = g_item->next;
		}
		elements.clear();
		LOG("GUI CLEAN UP OK!");
	}
	LOG("ERROR CLEANING UP GUI");
		return false;
}

void j1Gui::ManageFocus()
{
}

GUI_elem* j1Gui::AddUIElement(GUI_TYPE _type, iPoint _pos_on_screen)
{
	
	GUI_elem* ret = new GUI_elem;

	ret->type = _type;
	ret->pos_on_screen = _pos_on_screen;

	switch (_type)
	{
		case INTERACTIVE:
		


			break;

		case NON_INTERACTIVE:
	
			ret->source_elem_rect = SDL_Rect({ 485, 829, 328, 103 });

			break;

		case TEXT:
		


			break;

		case NONE:
			break;

		default:
			break;
	}

	elements.add(ret);
	return ret;
}

// const getter for atlas
const SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

// class Gui ---------------------------------------------------

