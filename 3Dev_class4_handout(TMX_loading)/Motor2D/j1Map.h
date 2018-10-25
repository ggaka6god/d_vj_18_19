#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!
// ----------------------------------------------------

struct tileset_info
{
	uint firstgid = 1;
	p2SString name = "Desert";
	uint tilewidth = 32;
	uint tileheight = 32;
	uint spacing = 1;
	uint margin = 1;
};

// TODO 1: Create a struct needed to hold the information to Map node
	
	struct map_info
	{
		float map_version = 1.0;
		p2SString orientation = "orthogonal";
		p2SString renderorder = "right-down";
		uint width = 50;
		uint height = 15;
		uint tilewidth = 32;
		uint tileheight = 32;
		uint nextobjectid;
	};

// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

private:


public:

	// TODO 1: Add your struct for map info as public for now

	map_info map_info;    

private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__