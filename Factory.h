#pragma once
#include <memory>
#include <map>
#include <string>
#include "Animal.h"
#include "Terrain.h"
#include "Grass.h"
#include "ConstructionItem.h"
#include "Building.h"
#include "Guest.h"

class Factory
{
public:
	//create animals
	static std::unique_ptr<Animal> createAnimal(const std::string& name);
	static bool registerAnimal(const std::string& name, std::unique_ptr<Animal>(*)());
	//create terrains
	static std::unique_ptr<Terrain> createTerrain(const std::string& name);
	static bool registerTerrain(const std::string& name, std::unique_ptr<Terrain>(*)());
	//create grass
	static std::unique_ptr<Grass> createGrass(const std::string& name);
	static bool registerGrass(const std::string& name, std::unique_ptr<Grass>(*)());
	//create constructions
	static std::unique_ptr<ConstructionItem> createConstruction(const std::string& name);
	static bool registerConstruction(const std::string& name, std::unique_ptr<ConstructionItem>(*)());
	//create buildings
	static std::unique_ptr<Building> createBuilding(const std::string& name);
	static bool registerBuilding(const std::string& name, std::unique_ptr<Building>(*)());
	//create people
	static std::unique_ptr<Guest> createGuest(const std::string& name);
	static bool registerGuest(const std::string& name, std::unique_ptr<Guest>(*)());


private:
	//animal map
	static std::map<std::string, std::unique_ptr<Animal>(*)()>& animalMap();
	//grass map
	static std::map<std::string, std::unique_ptr<Grass>(*)()>& grassMap();
	//terrain map
	static std::map<std::string, std::unique_ptr<Terrain>(*)()>& terrainMap();
	//construction map
	static std::map<std::string, std::unique_ptr<ConstructionItem>(*)()>& constructionMap();
	//building map
	static std::map<std::string, std::unique_ptr<Building>(*)()>& buildingMap();
	//people map
	static std::map<std::string, std::unique_ptr<Guest>(*)()>& GuestMap();
};

