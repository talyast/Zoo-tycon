#include "Factory.h"


std::unique_ptr<Animal> Factory::createAnimal(const std::string& name) {
	auto it = animalMap().find(name);
	if (it == animalMap().end())
		return nullptr;
	return it->second();
}

bool Factory::registerAnimal(const std::string& name, std::unique_ptr<Animal>(*f)()) {
	animalMap().emplace(name, f);
	return true;
}

std::unique_ptr<Terrain> Factory::createTerrain(const std::string & name)
{
	auto it = terrainMap().find(name);
	if (it == terrainMap().end())
		return nullptr;
	return it->second();
}


bool Factory::registerTerrain(const std::string & name, std::unique_ptr<Terrain>(*f)())
{
	terrainMap().emplace(name, f);
	return true;
}

std::unique_ptr<Grass> Factory::createGrass(const std::string& name)
{
	auto it = grassMap().find(name);
	if (it == grassMap().end())
		return nullptr;
	return it->second();
}

bool Factory::registerGrass(const std::string& name, std::unique_ptr<Grass>(*f)())
{
	grassMap().emplace(name, f);
	return true;
}
std::unique_ptr<ConstructionItem> Factory::createConstruction(const std::string & name)
{
	auto it = constructionMap().find(name);
	if (it == constructionMap().end())
		return nullptr;
	return it->second();
}

bool Factory::registerConstruction(const std::string & name, std::unique_ptr<ConstructionItem>(*f)())
{
	constructionMap().emplace(name, f);
	return true;
}

std::unique_ptr<Building> Factory::createBuilding(const std::string & name)
{
	auto it = buildingMap().find(name);
	if (it == buildingMap().end())
		return nullptr;
	return it->second();
}

bool Factory::registerBuilding(const std::string & name, std::unique_ptr<Building>(*f)())
{
	buildingMap().emplace(name, f);
	return true;
}


std::unique_ptr<Guest> Factory::createGuest(const std::string & name)
{
	auto it = GuestMap().find(name);
	if (it == GuestMap().end())
		return nullptr;
	return it->second();
}

bool Factory::registerGuest(const std::string & name, std::unique_ptr<Guest>(*f)())
{
	GuestMap().emplace(name, f);
	return true;
}

std::map<std::string, std::unique_ptr<Animal>(*)()>& Factory::animalMap()
{
	static std::map<std::string, std::unique_ptr<Animal>(*)()> map;
	return map;
}

std::map<std::string, std::unique_ptr<Grass>(*)()>& Factory::grassMap()
{
	static std::map<std::string, std::unique_ptr<Grass>(*)()> map;
	return map;
}

std::map<std::string, std::unique_ptr<Terrain>(*)()>& Factory::terrainMap()
{
	static std::map<std::string, std::unique_ptr<Terrain>(*)()> map;
	return map;
}

std::map<std::string, std::unique_ptr<ConstructionItem>(*)()>& Factory::constructionMap()
{
	static std::map<std::string, std::unique_ptr<ConstructionItem>(*)()> map;
	return map;
}

std::map<std::string, std::unique_ptr<Building>(*)()>& Factory::buildingMap()
{
	static std::map<std::string, std::unique_ptr<Building>(*)()> map;
	return map;
}

std::map<std::string, std::unique_ptr<Guest>(*)()>& Factory::GuestMap()
{
	static std::map<std::string, std::unique_ptr<Guest>(*)()> map;
	return map;
}