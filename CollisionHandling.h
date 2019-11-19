#pragma once
#include "MapItem.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "Lion.h"
#include "Fence.h"
#include "Hippo.h"
#include "Giraffe.h"
#include "PollarBear.h"
#include "Elephant.h"
#include "HerbivorFood.h"
#include "Tree.h"
#include "Fence.h"
#include "PredatorFood.h"
#include "Rock.h"
#include "DrinkingStand.h"
#include "Restaurant.h"
#include "Bathroom.h"
#include "Rock.h"
#include "AnimalHappiness.h"
#include "Path.h"
#include "Water.h"
#include "Savannah.h"
#include "Dirt.h"
#include "Grass.h"
#include "Snow.h"
#include "Burger.h"
#include "CuttonCandy.h"
#include "ChickerNugets.h"
#include "WomanGuest.h"
#include "ManGuest.h"

/*this file handles collisions between each object on the map 
and each object that is put on the map*/
const double HIGHMEASURE = 0.009;
const double HIGHMEASUREPEOPLE = 0.4;
const double LOWMEASURE = 0.005;
const double VERYLOWMEASURE = 0.001;

struct UnknownCollision
{
	UnknownCollision(MapItem& a, MapItem& b) : first(a), second(b)
	{
		std::cout << "Unknown collision of " << typeid(a).name() << " and "
			<< typeid(b).name() << std::endl;
	}
	MapItem& first;
	MapItem& second;
};

namespace { // anonymous namespace — the standard way to make function "static"

	void LionLion(MapItem& Lion1, MapItem& Lion2)
	{

		Lion& lion = static_cast <Lion&> (Lion1);
		lion.specialAnimation();
		lion.increaseHappiness(LOWMEASURE);
	}
	void ElephantElephant(MapItem& Elephant1, MapItem& Elephant2)
	{
		Elephant& elephant = static_cast <Elephant&> (Elephant1);
		elephant.specialAnimation();
		elephant.increaseHappiness(LOWMEASURE);
	}
	void HippoHippo(MapItem& Hippo1, MapItem& Hippo2)
	{
		Hippo& hippo = static_cast <Hippo&> (Hippo1);
		hippo.specialAnimation();
		hippo.increaseHappiness(LOWMEASURE);
	}
	void GiraffeGiraffe(MapItem& Giraffe1, MapItem& Giraffe2)
	{
		Giraffe& giraffe = static_cast <Giraffe&> (Giraffe1);
		giraffe.specialAnimation();
		giraffe.increaseHappiness(LOWMEASURE);
	}
	void PollarBearPollarBear(MapItem& PollarBear1, MapItem& PollarBear2)
	{
		PollarBear& pollar = static_cast <PollarBear&> (PollarBear1);
		pollar.specialAnimation();
		pollar.increaseHappiness(LOWMEASURE);
	}
	void LionHippo(MapItem& lion,MapItem& hippo)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.walkAnimation();
		Hippo& h = static_cast <Hippo&> (hippo);
		h.runAnimation();
	}

	void LionGiraffe(MapItem& lion,MapItem& giraffe)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.walkAnimation();
		l.decreaseHappiness(HIGHMEASURE);
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.runAnimation();
		
	}

	void LionPollar(MapItem& lion,MapItem& pollar)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.walkAnimation();
		l.decreaseHappiness(HIGHMEASURE);
		PollarBear& p = static_cast <PollarBear&> (pollar);
		p.runAnimation();
		
	}

	void LionElephant(MapItem& lion,MapItem& elephant)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.walkAnimation();
		l.decreaseHappiness(HIGHMEASURE);
		Elephant& e = static_cast <Elephant&> (elephant);
		e.runAnimation();
		
	}

	void ElephantGiraffe(MapItem& elephant, MapItem& giraffe)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.runAnimation();
		Elephant& e = static_cast <Elephant&> (elephant);
		e.walkAnimation();
		e.decreaseHappiness(HIGHMEASURE);
	}
	
	void ElephantPollarBear(MapItem& elephant, MapItem& pollarBear)
	{
		Elephant& e = static_cast <Elephant&> (elephant);
		e.runAnimation();
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.specialAnimation();
		e.decreaseHappiness(HIGHMEASURE);
	}
	
	void ElephantHippo(MapItem& elephant, MapItem& hippo)
	{
		Elephant& e = static_cast <Elephant&> (elephant);
		e.runAnimation();
		e.decreaseHappiness(HIGHMEASURE);
		Hippo& h = static_cast <Hippo&> (hippo);
		h.specialAnimation();
		
	}
	void GiraffeHippo(MapItem& giraffe, MapItem& hippo)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.runAnimation();
		g.decreaseHappiness(HIGHMEASURE);
		Hippo& h = static_cast <Hippo&> (hippo);
		h.runAnimation();
		
	}

	void GiraffePollarBear(MapItem& giraffe, MapItem& pollarBear)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.runAnimation();
		g.decreaseHappiness(HIGHMEASURE);
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.runAnimation();
		
	}
	void HippoPollarBear(MapItem& hippo, MapItem& pollarBear)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.runAnimation();
		h.decreaseHappiness(HIGHMEASURE);
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.runAnimation();
	
	}
	void LionBurger(MapItem& lion, MapItem& Burger)
	{
		Lion& l= static_cast <Lion&> (lion);
		
		l.decreaseHappiness(HIGHMEASURE);
	}
	void LionBathroom(MapItem& lion, MapItem& bathroom)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.decreaseHappiness(HIGHMEASURE);
	}
	void LionDrinkingStand(MapItem& lion, MapItem& drinkingstand)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.decreaseHappiness(HIGHMEASURE);
	}
	void ElephantBurger(MapItem& elephant, MapItem& Burger)
	{
		Elephant& e = static_cast <Elephant&> (elephant);
		e.decreaseHappiness(HIGHMEASURE);
	}
	void ElephantBathroom(MapItem& elephant, MapItem& bathroom)
	{
		Elephant& e = static_cast <Elephant&> (elephant);
		e.decreaseHappiness(HIGHMEASURE);
	}
	void ElephantDrinkingStand(MapItem& elephant, MapItem& drinkingstand)
	{
		Elephant& e = static_cast <Elephant&> (elephant);
		e.decreaseHappiness(HIGHMEASURE);
	}
	void GiraffeBurger(MapItem& giraffe, MapItem& Burger)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.decreaseHappiness(HIGHMEASURE);
	}
	void GiraffeBathroom(MapItem& giraffe, MapItem& bathroom)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.decreaseHappiness(HIGHMEASURE);
	}
	void GiraffeDrinkingStand(MapItem& giraffe, MapItem& drinkingstand)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.decreaseHappiness(HIGHMEASURE);
	}
	void HippoBurger(MapItem& hippo, MapItem& Burger)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.decreaseHappiness(HIGHMEASURE);
	}
	void HippoBathroom(MapItem& hippo, MapItem& bathroom)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.decreaseHappiness(HIGHMEASURE);
	}
	void HippoDrinkingStand(MapItem& hippo, MapItem& drinkingstand)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.decreaseHappiness(HIGHMEASURE);
	}
	void PollarBearBurger(MapItem& pollarBear, MapItem& Burger)
	{
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.decreaseHappiness(HIGHMEASURE);
	}
	void PollarBearBathroom(MapItem&  pollarBear, MapItem& bathroom)
	{
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.decreaseHappiness(HIGHMEASURE);
	}
	void PollarBearDrinkingStand(MapItem& pollarBear, MapItem& drinkingstand)
	{
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.decreaseHappiness(HIGHMEASURE);
	}
	void LionHerbivorFood(MapItem& lion, MapItem& HerbivorFood)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.decreaseHappiness(HIGHMEASURE);
	}
	void LionTree(MapItem& lion, MapItem& tree)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.increaseHappiness(HIGHMEASURE);
	}
	void LionFence(MapItem& lion, MapItem& fance)
	{
		;
	}
	void LionPredatorFood(MapItem& lion, MapItem& PredatorFood)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.eatAnimation();
		l.increaseHappiness(HIGHMEASURE);
	}
	void LionRock(MapItem& lion, MapItem& rock)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.specialAnimation();
		l.increaseHappiness(LOWMEASURE);
	}
	void ElephantHerbivorFood(MapItem& elephant, MapItem& HerbivorFood)
	{
		Elephant& e= static_cast <Elephant&> (elephant);
		e.eatAnimation();
		e.increaseHappiness(HIGHMEASURE);
	}
	void ElephantTree(MapItem& elephant, MapItem& tree)
	{
		Elephant& e = static_cast <Elephant&> (elephant);
		e.increaseHappiness(HIGHMEASURE);
	}
	void ElephantFence(MapItem& elephant, MapItem& fance)
	{
		;
	}
	void ElephantPredatorFood(MapItem& elephant, MapItem& PredatorFood)
	{
		;
	}
	void ElephantRock(MapItem& elephant, MapItem& rock)
	{
		Elephant& e = static_cast <Elephant&> (elephant);
		e.increaseHappiness(LOWMEASURE);
	}
	void GiraffeHerbivorFood(MapItem& giraffe, MapItem& HerbivorFood)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.eatAnimation();
		g.increaseHappiness(HIGHMEASURE);
	}
	void GiraffeTree(MapItem& giraffe, MapItem& tree)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.decreaseHappiness(LOWMEASURE);
	}
	void GiraffeFence(MapItem& Giraffe, MapItem& fance)
	{
		;
	}
	void GiraffePredatorFood(MapItem& giraffe, MapItem& PredatorFood)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.decreaseHappiness(VERYLOWMEASURE);
	}
	void GiraffeRock(MapItem& giraffe, MapItem& rock)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.decreaseHappiness(HIGHMEASURE);
	}
	void HippoHerbivorFood(MapItem& hippo, MapItem& HerbivorFood)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.eatAnimation();
		h.increaseHappiness(HIGHMEASURE);
	}
	void HippoTree(MapItem& hippo, MapItem& tree)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.decreaseHappiness(HIGHMEASURE);
	}
	void HippoFence(MapItem& Hippo, MapItem& fance)
	{
		;
	}
	void HippoPredatorFood(MapItem& hippo, MapItem& PredatorFood)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.decreaseHappiness(HIGHMEASURE);
	}
	void HippoRock(MapItem& hippo, MapItem& rock)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.decreaseHappiness(LOWMEASURE);
	}

	void PollarBearHerbivorFood(MapItem&  pollarBear, MapItem& HerbivorFood)
	{
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.decreaseHappiness(HIGHMEASURE);
	}
	void  PollarBearTree(MapItem&  pollarBear, MapItem& tree)
	{
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.decreaseHappiness(HIGHMEASURE);
	}
	void PollarBearFence(MapItem&  PollarBear, MapItem& fance)
	{
		;
	}
	void  PollarBearPredatorFood(MapItem&  pollarBear, MapItem& PredatorFood)
	{
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.increaseHappiness(HIGHMEASURE);
	}
	void  PollarBearRock(MapItem&  pollarBear, MapItem& rock)
	{
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.increaseHappiness(HIGHMEASURE);
	}
	void LionCuttonCandy(MapItem&  lion, MapItem& CuttonCandy)
	{
		Lion& l= static_cast <Lion&> (lion);
		l.decreaseHappiness(LOWMEASURE);
	}
	void LionChickerNugets(MapItem&  lion, MapItem& ChickerNugets)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.decreaseHappiness(LOWMEASURE);
	}
	void ElephantCuttonCandy(MapItem&  elephant, MapItem& CuttonCandy)
	{
		Elephant& e = static_cast <Elephant&> (elephant);
		e.decreaseHappiness(LOWMEASURE);
	}
	void ElephantChickerNugets(MapItem&  elephant, MapItem& ChickerNugets)
	{
		Elephant& e = static_cast <Elephant&> (elephant);
		e.decreaseHappiness(LOWMEASURE);
	}
	void GiraffeCuttonCandy(MapItem&  giraffe, MapItem& CuttonCandy)
	{
		Giraffe& g= static_cast <Giraffe&> (giraffe);
		g.decreaseHappiness(LOWMEASURE);
	}
	void GiraffeChickerNugets(MapItem&  giraffe, MapItem& ChickerNugets)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.decreaseHappiness(LOWMEASURE);
	}
	void HippoCuttonCandy(MapItem&  hippo, MapItem& CuttonCandy)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.decreaseHappiness(LOWMEASURE);
	}
	void HippoChickerNugets(MapItem&  hippo, MapItem& ChickerNugets)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.decreaseHappiness(LOWMEASURE);
	}
	void PollarBearCuttonCandy(MapItem&  pollarBear, MapItem& CuttonCandy)
	{
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.decreaseHappiness(LOWMEASURE);
	}
	void PollarBearChickerNugets(MapItem&  pollarBear, MapItem& ChickerNugets)
	{
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.decreaseHappiness(LOWMEASURE);
	}
	//--------------------------lion and terrain-------------------------
	void LionPath(MapItem&  lion, MapItem& path)
	{
		;
	}
	void LionWater(MapItem&  lion, MapItem& water)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.increaseHappiness(VERYLOWMEASURE);
	}
	void LionSnow(MapItem&  lion, MapItem& snow)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.decreaseHappiness(VERYLOWMEASURE);
	}
	void LionSavannah(MapItem&  lion, MapItem& savanna)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.increaseHappiness(VERYLOWMEASURE);
	}
	void LionGrass(MapItem&  lion, MapItem& Grass)
	{
		;
	}
	void LionDirt(MapItem&  lion, MapItem& Dirt)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.increaseHappiness(VERYLOWMEASURE);
	}
	//------------------elephant with terrain----------------------
	void ElephantPath(MapItem&  Elephant, MapItem& path)
	{
		;
	}
	void ElephantWater(MapItem&  elephant, MapItem& water)
	{

		Elephant& e = static_cast <Elephant&> (elephant);
		e.increaseHappiness(VERYLOWMEASURE);
		
	}
	void ElephantSnow(MapItem&  elephant, MapItem& snow)
	{
		Elephant& e = static_cast <Elephant&> (elephant);
		e.decreaseHappiness(VERYLOWMEASURE);
	}
	void ElephantSavannah(MapItem&  elephant, MapItem& savanna)
	{
		Elephant& e = static_cast <Elephant&> (elephant);
		e.increaseHappiness(VERYLOWMEASURE);
	}
	void ElephantGrass(MapItem&  Elephant, MapItem& Grass)
	{
		;
	}
	void ElephantDirt(MapItem&  elephant, MapItem& Dirt)
	{
		Elephant& e = static_cast <Elephant&> (elephant);
		e.increaseHappiness(VERYLOWMEASURE);

	}
	//------------------Giraffe with terrain----------------------
	void GiraffePath(MapItem&  Giraffe, MapItem& path)
	{
		;
	}
	void GiraffeWater(MapItem&  giraffe, MapItem& water)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.increaseHappiness(VERYLOWMEASURE);
	}
	void GiraffeSnow(MapItem&  giraffe, MapItem& snow)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.decreaseHappiness(LOWMEASURE);
	}
	void GiraffeSavannah(MapItem&  giraffe, MapItem& savanna)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.increaseHappiness(VERYLOWMEASURE);
	}
	void GiraffeGrass(MapItem&  Giraffe, MapItem& Grass)
	{
		;
	}
	void GiraffeDirt(MapItem&  giraffe, MapItem& Dirt)
	{
		Giraffe& g = static_cast <Giraffe&> (giraffe);
		g.increaseHappiness(VERYLOWMEASURE);
	}
	//------------------Hippo with terrain----------------------
	void HippoPath(MapItem&  Hippo, MapItem& path)
	{
		;
	}
	void HippoWater(MapItem&  hippo, MapItem& water)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.waterAnimation();//add swim annimation
		h.increaseHappiness(LOWMEASURE);
	}
	void HippoSnow(MapItem&  hippo, MapItem& snow)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.decreaseHappiness(LOWMEASURE);
	}
	void HippoSavannah(MapItem&  hippo, MapItem& savanna)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.decreaseHappiness(LOWMEASURE);
	}
	void HippoGrass(MapItem&  Hippo, MapItem& Grass)
	{
		;
	}
	void HippoDirt(MapItem&  hippo, MapItem& Dirt)
	{
		Hippo& h = static_cast <Hippo&> (hippo);
		h.increaseHappiness(VERYLOWMEASURE);
	}
	//------------------PollarBear with terrain----------------------
	void PollarBearPath(MapItem&  PollarBear, MapItem& path)
	{
		;
	}
	void PollarBearWater(MapItem&  pollarBear, MapItem& water)
	{
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.increaseHappiness(VERYLOWMEASURE);
	}
	void PollarBearSnow(MapItem&  pollarBear, MapItem& snow)
	{
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.increaseHappiness(VERYLOWMEASURE);
	}
	void PollarBearSavannah(MapItem&  pollarBear, MapItem& savanna)
	{
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.decreaseHappiness(LOWMEASURE);
	}
	void PollarBearGrass(MapItem&  PollarBear, MapItem& Grass)
	{
		;
	}
	void PollarBearDirt(MapItem&  pollarBear, MapItem& Dirt)
	{
		PollarBear& p = static_cast <PollarBear&> (pollarBear);
		p.decreaseHappiness(LOWMEASURE);
	}
	//-----------------guest and building--------------------------------------
	void ManGuestBathroom(MapItem&  manGuest, MapItem& bathroom)
	{

		Bathroom& b = static_cast <Bathroom&> (bathroom);
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.increaseHappiness(LOWMEASURE);
		b.increaseZooMoney(1);
	}
	void WomanGuestBathroom(MapItem&  womanGuest, MapItem& bathroom)
	{
		Bathroom& b = static_cast <Bathroom&> (bathroom);
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.increaseHappiness(LOWMEASURE);
		b.increaseZooMoney(1);
	}
	void ManGuestDrinkingStand(MapItem&  manGuest, MapItem& drink)
	{
		Bathroom& d = static_cast <Bathroom&> (drink);
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.increaseHappiness(LOWMEASURE);
		d.increaseZooMoney(5);
	}
	void WomanGuestDrinkingStand(MapItem&  womanGuest, MapItem& drink)
	{
		Bathroom& d = static_cast <Bathroom&> (drink);
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.increaseHappiness(LOWMEASURE);
		d.increaseZooMoney(5);
	}
	void ManGuestBurger(MapItem&  manGuest, MapItem& burger)
	{
		Burger& b = static_cast <Burger&> (burger);
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.increaseHappiness(LOWMEASURE);
		b.increaseZooMoney(35);
	}
	void WomanGuestBurger(MapItem&  womanGuest, MapItem& burger)
	{
		Burger& b = static_cast <Burger&> (burger);
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.increaseHappiness(LOWMEASURE);
		b.increaseZooMoney(20);
	}
	void ManGuestCuttonCandy(MapItem&  manGuest, MapItem& cuttonCandy)
	{
		CuttonCandy& c = static_cast <CuttonCandy&> (cuttonCandy);
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.increaseHappiness(LOWMEASURE);
		c.increaseZooMoney(5);
	}
	void WomanGuestCuttonCandy(MapItem&  womanGuest, MapItem& cuttonCandy)
	{
		CuttonCandy& c = static_cast <CuttonCandy&> (cuttonCandy);
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.increaseHappiness(LOWMEASURE);
		c.increaseZooMoney(5);
	}
	void ManGuestChickerNugets(MapItem&  manGuest, MapItem& chicken)
	{
		ChickerNugets& c = static_cast <ChickerNugets&> (chicken);
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.increaseHappiness(LOWMEASURE);
		c.increaseZooMoney(20);
	}
	void WomanGuestChickerNugets(MapItem&  womanGuest, MapItem& chicken)
	{
		ChickerNugets& c = static_cast <ChickerNugets&> (chicken);
		WomanGuest& m = static_cast <WomanGuest&> (womanGuest);
		m.increaseHappiness(LOWMEASURE);
		c.increaseZooMoney(20);
		
	}
	//--------------------guest with construction----------------------------
	void ManGuestHerbivorFood(MapItem&  manGuest, MapItem& HerbivorFood)
	{
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.decreaseHappiness(LOWMEASURE);
	}
	void ManGuestTree(MapItem&  manGuest, MapItem& Tree)
	{
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.increaseHappiness(LOWMEASURE);
	}
	void ManGuestFence(MapItem&  manGuest, MapItem& Fence)
	{
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.increaseHappiness(HIGHMEASURE);
	}
	void ManGuestPredatorFood(MapItem&  manGuest, MapItem& PredatorFood)
	{
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.decreaseHappiness(LOWMEASURE);
	}
	void ManGuestRock(MapItem&  manGuest, MapItem& Rock)
	{
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.decreaseHappiness(HIGHMEASURE);
	}
	void WomanGuestHerbivorFood(MapItem&  womanGuest, MapItem& HerbivorFood)
	{
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.decreaseHappiness(HIGHMEASURE);
	}
	void WomanGuestTree(MapItem&  womanGuest, MapItem& Tree)
	{
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.increaseHappiness(LOWMEASURE);
	}
	void WomanGuestFence(MapItem&  womanGuest, MapItem& Fence)
	{
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.increaseHappiness(HIGHMEASURE);
	}
	void WomanGuestPredatorFood(MapItem&  womanGuest, MapItem& PredatorFood)
	{
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.decreaseHappiness(LOWMEASURE);
	}
	void WomanGuestRock(MapItem&  womanGuest, MapItem& Rock)
	{
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.decreaseHappiness(LOWMEASURE);
	}
	//------------------guest with animal-------------------------------------------
	void ManGuestLion(MapItem&  manGuest, MapItem& lion)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.specialAnimation();
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.decreaseHappiness(HIGHMEASUREPEOPLE);
	}
	void ManGuestElephant(MapItem&  manGuest, MapItem& Elephant)
	{
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.decreaseHappiness(HIGHMEASUREPEOPLE);
	}
	void ManGuestGiraffe(MapItem&  manGuest, MapItem& Giraffe)
	{
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.decreaseHappiness(HIGHMEASUREPEOPLE);
	}
	void ManGuestHippo(MapItem&  manGuest, MapItem& Hippo)
	{
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.decreaseHappiness(HIGHMEASUREPEOPLE);
	}
	void ManGuestPollarBear(MapItem&  manGuest, MapItem& PollarBear)
	{
		ManGuest& m = static_cast <ManGuest&> (manGuest);
		m.decreaseHappiness(HIGHMEASUREPEOPLE);
	}

	void WomanGuestLion(MapItem&  womanGuest, MapItem& lion)
	{
		Lion& l = static_cast <Lion&> (lion);
		l.specialAnimation();
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.decreaseHappiness(HIGHMEASUREPEOPLE);
	}
	void WomanGuestElephant(MapItem&  womanGuest, MapItem& Elephant)
	{
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.decreaseHappiness(HIGHMEASUREPEOPLE);
	}
	void WomanGuestGiraffe(MapItem&  womanGuest, MapItem& Giraffe)
	{
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.decreaseHappiness(HIGHMEASUREPEOPLE);
	}
	void WomanGuestHippo(MapItem&  womanGuest, MapItem& Hippo)
	{
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.decreaseHappiness(HIGHMEASUREPEOPLE);
	}
	void WomanGuestPollarBear(MapItem&  womanGuest, MapItem& PollarBear)
	{
		WomanGuest& w = static_cast <WomanGuest&> (womanGuest);
		w.decreaseHappiness(HIGHMEASUREPEOPLE);
	}
	//--------------------------------------------------------------------------
	void DoNothing(MapItem&  item1, MapItem& item2)
	{
		;
	}
	//---------------------------------------------------------------------------
	void HippoLion(MapItem& hippo, MapItem& lion)
	{
		LionHippo(lion, hippo);
	}
	void GiraffeLion(MapItem& giraffe, MapItem& lion)
	{
		LionGiraffe(lion, giraffe);
	}
	void PollarLion(MapItem& pollar, MapItem& lion)
	{
		LionPollar(lion, pollar);
	}
	void ElephantLion(MapItem& elephant, MapItem& lion)
	{
		LionElephant(lion, elephant);
	}
	void GiraffeElephant(MapItem& Giraffe, MapItem& Elephant)
	{
		ElephantGiraffe(Elephant, Giraffe);
	}
	void PollarBearElephant(MapItem& PollarBear, MapItem& Elephant)
	{
		ElephantPollarBear(Elephant, PollarBear);
	}
	void HippoElephant(MapItem& hippo, MapItem& Elephant)
	{
		ElephantHippo(Elephant, hippo);
	}
	void HippoGiraffe(MapItem& hippo, MapItem& Giraffe)
	{
		GiraffeHippo(Giraffe, hippo);
	}
	void PollarBearGiraffe(MapItem& PollarBear, MapItem& Giraffe)
	{
		GiraffePollarBear(Giraffe, PollarBear);
	}
	void PollarBearHippo(MapItem& PollarBear, MapItem& hippo)
	{
		HippoPollarBear(hippo, PollarBear);
	}
	void BurgerLion(MapItem& Burger, MapItem& lion)
	{
		LionBurger(lion, Burger);
	}
	void BathroomLion(MapItem& bathroom, MapItem& lion)
	{
		LionBathroom(lion, bathroom);
	}
	void DrinkingStandLion(MapItem& drinkingstand, MapItem& lion)
	{
		LionDrinkingStand(lion, drinkingstand);
	}
	void BurgerElephant(MapItem& Burger, MapItem& elephant)
	{
		ElephantBurger(elephant, Burger);
	}
	void BathroomElephant(MapItem& bathroom, MapItem& elephant)
	{
		ElephantBathroom(elephant, bathroom);
	}
	void DrinkingStandElephant(MapItem& drinkingstand, MapItem& elephant)
	{
		ElephantDrinkingStand(elephant, drinkingstand);
	}
	void BurgerGiraffe(MapItem& Burger, MapItem& giraffe)
	{
		GiraffeBurger(giraffe, Burger);
	}
	void BathroomGiraffe(MapItem& bathroom, MapItem& giraffe)
	{
		GiraffeBathroom(giraffe, bathroom);
	}
	void DrinkingStandGiraffe(MapItem& drinkingstand, MapItem& giraffe)
	{
		GiraffeDrinkingStand(giraffe, drinkingstand);
	}
	void BurgerHippo(MapItem& Burger, MapItem& hippo)
	{
		HippoBurger(hippo, Burger);
	}
	void BathroomHippo(MapItem& bathroom, MapItem& hippo)
	{
		HippoBathroom(hippo, bathroom);
	}
	void DrinkingStandHippo(MapItem& drinkingstand, MapItem& hippo)
	{
		HippoDrinkingStand(hippo, drinkingstand);
	}
	void BurgerPollarBear(MapItem& Burger, MapItem& PollarBear)
	{
		PollarBearBurger(PollarBear, Burger);
	}
	void BathroomPollarBear(MapItem& bathroom, MapItem& PollarBear)
	{
		PollarBearBathroom(PollarBear, bathroom);
	}
	void DrinkingStandPollarBear(MapItem& drinkingstand, MapItem& PollarBear)
	{
		PollarBearDrinkingStand(PollarBear, drinkingstand);
	}
	//-----------------------------newwwww-----------------------------
	void HerbivorFoodLion(MapItem&  HerbivorFood, MapItem& Lion)
	{
		LionHerbivorFood(Lion, HerbivorFood);
	}
	void TreeLion(MapItem&  tree, MapItem& Lion)
	{
		LionTree(Lion, tree);
	}
	void FenceLion(MapItem&  fance, MapItem& Lion)
	{
		LionFence(Lion, fance);
	}
	void PredatorFoodLion(MapItem&  PredatorFood, MapItem& Lion)
	{
		LionPredatorFood(Lion, PredatorFood);
	}
	void RockLion(MapItem&  rock, MapItem& Lion)
	{
		LionRock(Lion, rock);
	}
	void HerbivorFoodElephant(MapItem&  HerbivorFood, MapItem& Elephant)
	{
		ElephantHerbivorFood(Elephant, HerbivorFood);
	}
	void TreeElephant(MapItem&  tree, MapItem& Elephant)
	{
		ElephantTree(Elephant, tree);
	}
	void FenceElephant(MapItem&  fance, MapItem& Elephant)
	{
		ElephantFence(Elephant, fance);
	}
	void PredatorFoodElephant(MapItem&  PredatorFood, MapItem& Elephant)
	{
		ElephantPredatorFood(Elephant, PredatorFood);
	}
	void RockElephant(MapItem&  rock, MapItem& Elephant)
	{
		ElephantRock(Elephant, rock);
	}
	void HerbivorFoodGiraffe(MapItem&  HerbivorFood, MapItem& Giraffe)
	{
		GiraffeHerbivorFood(Giraffe, HerbivorFood);
	}
	void TreeGiraffe(MapItem&  tree, MapItem& Giraffe)
	{
		GiraffeTree(Giraffe, tree);
	}
	void FenceGiraffe(MapItem&  fance, MapItem& Giraffe)
	{
		GiraffeFence(Giraffe, fance);
	}
	void PredatorFoodGiraffe(MapItem&  PredatorFood, MapItem& Giraffe)
	{
		GiraffePredatorFood(Giraffe, PredatorFood);
	}
	void RockGiraffe(MapItem&  rock, MapItem& Giraffe)
	{
		GiraffeRock(Giraffe, rock);
	}
	void HerbivorFoodHippo(MapItem&  HerbivorFood, MapItem& Hippo)
	{
		HippoHerbivorFood(Hippo, HerbivorFood);
	}
	void TreeHippo(MapItem&  tree, MapItem& Hippo)
	{
		HippoTree(Hippo, tree);
	}
	void FenceHippo(MapItem&  fance, MapItem& Hippo)
	{
		HippoFence(Hippo, fance);
	}
	void PredatorFoodHippo(MapItem&  PredatorFood, MapItem& Hippo)
	{
		HippoPredatorFood(Hippo, PredatorFood);
	}
	void RockHippo(MapItem&  rock, MapItem& Hippo)
	{
		HippoRock(Hippo, rock);
	}
	void HerbivorFoodPollarBear(MapItem&  HerbivorFood, MapItem& PollarBear)
	{
		PollarBearHerbivorFood(PollarBear, HerbivorFood);
	}
	void TreePollarBear(MapItem&  tree, MapItem& PollarBear)
	{
		PollarBearTree(PollarBear, tree);
	}
	void FencePollarBear(MapItem&  fance, MapItem& PollarBear)
	{
		PollarBearFence(PollarBear, fance);
	}
	void PredatorFoodPollarBear(MapItem&  PredatorFood, MapItem& PollarBear)
	{
		PollarBearPredatorFood(PollarBear, PredatorFood);
	}
	void RockPollarBear(MapItem&  rock, MapItem& PollarBear)
	{
		PollarBearRock(PollarBear, rock);
	}
	void CuttonCandyLion(MapItem&  CuttonCandy, MapItem& lion)
	{
		LionCuttonCandy(lion, CuttonCandy);
	}
	void ChickerNugetsLion(MapItem&  ChickerNugets, MapItem& lion)
	{
		LionChickerNugets(lion, ChickerNugets);
	}
	void CuttonCandyElephant(MapItem&  CuttonCandy, MapItem& Elephant)
	{
		ElephantCuttonCandy(Elephant, CuttonCandy);
	}
	void ChickerNugetsElephant(MapItem&  ChickerNugets, MapItem& Elephant)
	{
		ElephantChickerNugets(Elephant, ChickerNugets);
	}
	void CuttonCandyGiraffe(MapItem&  CuttonCandy, MapItem& Giraffe)
	{
		GiraffeCuttonCandy(Giraffe, CuttonCandy);
	}
	void ChickerNugetsGiraffe(MapItem&  ChickerNugets, MapItem& Giraffe)
	{
		GiraffeChickerNugets(Giraffe, ChickerNugets);
	}
	void CuttonCandyHippo(MapItem&  CuttonCandy, MapItem& Hippo)
	{
		HippoCuttonCandy(Hippo, CuttonCandy);
	}
	void ChickerNugetsHippo(MapItem&  ChickerNugets, MapItem& Hippo)
	{
		HippoChickerNugets(Hippo, ChickerNugets);
	}
	void CuttonCandyPollarBear(MapItem&  CuttonCandy, MapItem& PollarBear)
	{
		PollarBearCuttonCandy(PollarBear, CuttonCandy);
	}
	void ChickerNugetsPollarBear(MapItem&  ChickerNugets, MapItem& PollarBear)
	{
		PollarBearChickerNugets(PollarBear, ChickerNugets);
	}
	//-------------------water with animals--------------------------------
	void WaterLion(MapItem&  Water, MapItem& Lion)
	{
		LionWater(Lion, Water);
	}
	void WaterElephant(MapItem&  Water, MapItem& Elephant)
	{
		ElephantWater(Elephant, Water);
	}
	void WaterGiraffe(MapItem&  Water, MapItem& Giraffe)
	{
		GiraffeWater(Giraffe, Water);
	}
	void WaterHippo(MapItem&  Water, MapItem& Hippo)
	{
		HippoWater(Hippo, Water);
	}
	void WaterPollarBear(MapItem&  Water, MapItem& PollarBear)
	{
		PollarBearWater(PollarBear, Water);
	}
	//-------------------Snow with animals--------------------------------
	void SnowLion(MapItem&  Snow, MapItem& Lion)
	{
		LionSnow(Lion, Snow);
	}
	void SnowElephant(MapItem&  Snow, MapItem& Elephant)
	{
		ElephantSnow(Elephant, Snow);
	}
	void SnowGiraffe(MapItem&  Snow, MapItem& Giraffe)
	{
		GiraffeSnow(Giraffe, Snow);
	}
	void SnowHippo(MapItem&  Snow, MapItem& Hippo)
	{
		HippoSnow(Hippo, Snow);
	}
	void SnowPollarBear(MapItem&  Snow, MapItem& PollarBear)
	{
		PollarBearSnow(PollarBear, Snow);
	}
	//-------------------Savannah with animals--------------------------------
	void SavannahLion(MapItem&  Savannah, MapItem& Lion)
	{
		LionSavannah(Lion, Savannah);
	}
	void SavannahElephant(MapItem&  Savannah, MapItem& Elephant)
	{
		ElephantSavannah(Elephant, Savannah);
	}
	void SavannahGiraffe(MapItem&  Savannah, MapItem& Giraffe)
	{
		GiraffeSavannah(Giraffe, Savannah);
	}
	void SavannahHippo(MapItem&  Savannah, MapItem& Hippo)
	{
		HippoSavannah(Hippo, Savannah);
	}
	void SavannahPollarBear(MapItem&  Savannah, MapItem& PollarBear)
	{
		PollarBearSavannah(PollarBear, Savannah);
	}
	//-------------------Path with animals--------------------------------
	void PathLion(MapItem&  Path, MapItem& Lion)
	{
		LionPath(Path, Path);
	}
	void PathElephant(MapItem&  Path, MapItem& Elephant)
	{
		ElephantPath(Elephant, Path);
	}
	void PathGiraffe(MapItem&  Path, MapItem& Giraffe)
	{
		GiraffePath(Giraffe, Path);
	}
	void PathHippo(MapItem&  Path, MapItem& Hippo)
	{
		HippoPath(Hippo, Path);
	}
	void PathPollarBear(MapItem&  Path, MapItem& PollarBear)
	{
		PollarBearPath(PollarBear, Path);
	}
	//-------------------Grass with animals--------------------------------
	void GrassLion(MapItem&  Grass, MapItem& Lion)
	{
		LionGrass(Lion, Grass);
	}
	void GrassElephant(MapItem&  Grass, MapItem& Elephant)
	{
		ElephantGrass(Elephant, Grass);
	}
	void GrassGiraffe(MapItem&  Grass, MapItem& Giraffe)
	{
		GiraffeGrass(Giraffe, Grass);
	}
	void GrassHippo(MapItem&  Grass, MapItem& Hippo)
	{
		HippoGrass(Hippo, Grass);
	}
	void GrassPollarBear(MapItem&  Grass, MapItem& PollarBear)
	{
		PollarBearGrass(PollarBear, Grass);
	}
	//-------------------Dirt with animals--------------------------------
	void DirtLion(MapItem&  Dirt, MapItem& Lion)
	{
		LionGrass(Lion, Dirt);
	}
	void DirtElephant(MapItem&  Dirt, MapItem& Elephant)
	{
		ElephantDirt(Elephant, Dirt);
	}
	void DirtGiraffe(MapItem&  Dirt, MapItem& Giraffe)
	{
		GiraffeDirt(Giraffe, Dirt);
	}
	void DirtHippo(MapItem&  Dirt, MapItem& Hippo)
	{
		HippoDirt(Hippo, Dirt);
	}
	void DirtPollarBear(MapItem&  Dirt, MapItem& PollarBear)
	{
		PollarBearDirt(PollarBear, Dirt);
	}
	//-------------------building with Guest--------------------------------
	void BathroomManGuest(MapItem&  Bathroom, MapItem& ManGuest)
	{
		ManGuestBathroom(ManGuest, Bathroom);
	}
	void BathroomWomanGuest(MapItem&  Bathroom, MapItem& WomanGuest)
	{
		WomanGuestBathroom(WomanGuest, Bathroom);
	}
	void DrinkingStandManGuest(MapItem&  DrinkingStand, MapItem& ManGuest)
	{
		ManGuestDrinkingStand(ManGuest, DrinkingStand);
	}
	void DrinkingStandWomanGuest(MapItem&  DrinkingStand, MapItem& WomanGuest)
	{
		WomanGuestDrinkingStand(WomanGuest, DrinkingStand);
	}
	void BurgerManGuest(MapItem&  Burger, MapItem& ManGuest)
	{
		ManGuestBurger(ManGuest, Burger);
	}
	void BurgerWomanGuest(MapItem&  Burger, MapItem& WomanGuest)
	{
		WomanGuestBurger(WomanGuest, Burger);
	}
	void CuttonCandyManGuest(MapItem&  CuttonCandy, MapItem& ManGuest)
	{
		ManGuestCuttonCandy(ManGuest, CuttonCandy);
	}
	void CuttonCandyWomanGuest(MapItem&  CuttonCandy, MapItem& WomanGuest)
	{
		WomanGuestCuttonCandy(WomanGuest, CuttonCandy);
	}
	void ChickerNugetsManGuest(MapItem&  ChickerNugets, MapItem& ManGuest)
	{
		ManGuestChickerNugets(ManGuest, ChickerNugets);
	}
	void ChickerNugetsWomanGuest(MapItem&  ChickerNugets, MapItem& WomanGuest)
	{
		WomanGuestChickerNugets(WomanGuest, ChickerNugets);
	}
	void HerbivorFoodManGuest(MapItem&  HerbivorFood, MapItem& ManGuest)
	{
		ManGuestHerbivorFood(ManGuest, HerbivorFood);
	}
	void HerbivorFoodWomanGuest(MapItem&  HerbivorFood, MapItem& WomanGuest)
	{
		WomanGuestHerbivorFood(WomanGuest, HerbivorFood);
	}
	void TreeManGuest(MapItem&  Tree, MapItem& ManGuest)
	{
		ManGuestTree(ManGuest, Tree);
	}
	void TreeWomanGuest(MapItem&  Tree, MapItem& WomanGuest)
	{
		WomanGuestTree(WomanGuest, Tree);
	}
	void FenceManGuest(MapItem&  Fence, MapItem& ManGuest)
	{
		ManGuestFence(ManGuest, Fence);
	}
	void FenceWomanGuest(MapItem&  Fence, MapItem& WomanGuest)
	{
		WomanGuestFence(WomanGuest, Fence);
	}
	void PredatorFoodManGuest(MapItem&  PredatorFood, MapItem& ManGuest)
	{
		ManGuestPredatorFood(ManGuest, PredatorFood);
	}
	void PredatorFoodWomanGuest(MapItem&  PredatorFood, MapItem& WomanGuest)
	{
		WomanGuestPredatorFood(WomanGuest, PredatorFood);
	}

	void RockManGuest(MapItem&  Rock, MapItem& ManGuest)
	{
		ManGuestRock(ManGuest, Rock);
	}
	void RockWomanGuest(MapItem&  Rock, MapItem& WomanGuest)
	{
		WomanGuestRock(WomanGuest, Rock);
	}
	void LionManGuest(MapItem&  Lion, MapItem& ManGuest)
	{
		ManGuestLion(ManGuest, Lion);
	}
	void LionWomanGuest(MapItem&  Lion, MapItem& WomanGuest)
	{
		WomanGuestLion(WomanGuest, Lion);
	}
	void ElephantManGuest(MapItem&  Elephant, MapItem& ManGuest)
	{
		ManGuestElephant(ManGuest, Elephant);
	}
	void ElephantWomanGuest(MapItem&  Elephant, MapItem& WomanGuest)
	{
		WomanGuestElephant(WomanGuest, Elephant);
	}
	void GiraffeManGuest(MapItem&  Giraffe, MapItem& ManGuest)
	{
		ManGuestGiraffe(ManGuest, Giraffe);
	}
	void GiraffeWomanGuest(MapItem&  Giraffe, MapItem& WomanGuest)
	{
		WomanGuestGiraffe(WomanGuest, Giraffe);
	}
	void HippoManGuest(MapItem&  Hippo, MapItem& ManGuest)
	{
		ManGuestHippo(ManGuest, Hippo);
	}
	void HippoWomanGuest(MapItem&  Hippo, MapItem& WomanGuest)
	{
		WomanGuestHippo(WomanGuest, Hippo);
	}
	void PollarBearManGuest(MapItem&  PollarBear, MapItem& ManGuest)
	{
		ManGuestPollarBear(ManGuest, PollarBear);
	}
	void PollarBearWomanGuest(MapItem&  PollarBear, MapItem& WomanGuest)
	{
		WomanGuestPollarBear(WomanGuest, PollarBear);
	}
	
	
	//-------------------------------------------------------------

	using HitFunctionPtr = void(*)(MapItem&, MapItem&);
	using Key = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Key, HitFunctionPtr>;

	HitMap initializeCollisionMap()
	{
		HitMap phm;
		//lion collistion
		phm[Key(typeid(Lion), typeid(Lion))] = &LionLion;
		phm[Key(typeid(Lion), typeid(Hippo))] = &LionHippo;
		phm[Key(typeid(Hippo), typeid(Lion))] = &HippoLion;
		phm[Key(typeid(Lion), typeid(Giraffe))] = &LionGiraffe;
		phm[Key(typeid(Giraffe), typeid(Lion))] = &GiraffeLion;
		phm[Key(typeid(Lion), typeid(PollarBear))] = &LionPollar;
		phm[Key(typeid(PollarBear), typeid(Lion))] = &PollarLion;
		phm[Key(typeid(Lion), typeid(Elephant))] = &LionElephant;
		phm[Key(typeid(Elephant), typeid(Lion))] = &ElephantLion;
		//lion and buildings collision
		phm[Key(typeid(Lion), typeid(Burger))] = &LionBurger;
		phm[Key(typeid(Burger), typeid(Lion))] = &BurgerLion;
		phm[Key(typeid(Lion), typeid(Bathroom))] = &LionBathroom;
		phm[Key(typeid(Bathroom), typeid(Lion))] = &BathroomLion;
		phm[Key(typeid(Lion), typeid(DrinkingStand))] = &LionDrinkingStand;
		phm[Key(typeid(DrinkingStand), typeid(Lion))] = &DrinkingStandLion;
		phm[Key(typeid(Lion), typeid(CuttonCandy))] = &LionCuttonCandy;
		phm[Key(typeid(CuttonCandy), typeid(Lion))] = &CuttonCandyLion;
		phm[Key(typeid(Lion), typeid(ChickerNugets))] = &LionChickerNugets;
		phm[Key(typeid(ChickerNugets), typeid(Lion))] = &ChickerNugetsLion;
		//lion and construction collision
		phm[Key(typeid(Lion), typeid(HerbivorFood))] = &LionHerbivorFood;
		phm[Key(typeid(HerbivorFood), typeid(Lion))] = &HerbivorFoodLion;
		phm[Key(typeid(Lion), typeid(Tree))] = &LionTree;
		phm[Key(typeid(Tree), typeid(Lion))] = &TreeLion;
		phm[Key(typeid(Lion), typeid(Fence))] = &LionFence;
		phm[Key(typeid(Fence), typeid(Lion))] = &FenceLion;
		phm[Key(typeid(Lion), typeid(PredatorFood))] = &LionPredatorFood;
		phm[Key(typeid(PredatorFood), typeid(Lion))] = &PredatorFoodLion;
		phm[Key(typeid(Lion), typeid(Rock))] = &LionRock;
		phm[Key(typeid(Rock), typeid(Lion))] = &RockLion;
		//lion and terrain collision
		phm[Key(typeid(Lion), typeid(Path))] = &LionPath;
		phm[Key(typeid(Lion), typeid(Water))] = &LionWater;
		phm[Key(typeid(Lion), typeid(Savannah))] = &LionSavannah;
		phm[Key(typeid(Lion), typeid(Dirt))] = &LionDirt;
		phm[Key(typeid(Lion), typeid(Grass))] = &LionGrass;
		phm[Key(typeid(Lion), typeid(Snow))] = &LionSnow;
		
		//lion with guest
		phm[Key(typeid(Lion), typeid(ManGuest))] = &LionManGuest;
		phm[Key(typeid(Lion), typeid(WomanGuest))] = &LionWomanGuest;
		
		//elephant collision
		phm[Key(typeid(Elephant), typeid(Elephant))] = &ElephantElephant;
		phm[Key(typeid(Elephant), typeid(Giraffe))] = &ElephantGiraffe;
		phm[Key(typeid(Giraffe), typeid(Elephant))] = &GiraffeElephant;
		phm[Key(typeid(Elephant), typeid(PollarBear))] = &ElephantPollarBear;
		phm[Key(typeid(PollarBear), typeid(Elephant))] = &PollarBearElephant;
		phm[Key(typeid(Elephant), typeid(Hippo))] = &ElephantHippo;
		phm[Key(typeid(Hippo), typeid(Elephant))] = &HippoElephant;
		//elephant and buildings collision
		phm[Key(typeid(Elephant), typeid(Burger))] = &ElephantBurger;
		phm[Key(typeid(Burger), typeid(Elephant))] = &BurgerElephant;
		phm[Key(typeid(Elephant), typeid(Bathroom))] = &ElephantBathroom;
		phm[Key(typeid(Bathroom), typeid(Elephant))] = &BathroomElephant;
		phm[Key(typeid(Elephant), typeid(DrinkingStand))] = &ElephantDrinkingStand;
		phm[Key(typeid(DrinkingStand), typeid(Elephant))] = &DrinkingStandElephant;
		phm[Key(typeid(Elephant), typeid(CuttonCandy))] = &ElephantCuttonCandy;
		phm[Key(typeid(CuttonCandy), typeid(Elephant))] = &CuttonCandyElephant;
		phm[Key(typeid(Elephant), typeid(ChickerNugets))] = &ElephantChickerNugets;
		phm[Key(typeid(ChickerNugets), typeid(Elephant))] = &ChickerNugetsElephant;
		//Elephant and construction collision
		phm[Key(typeid(Elephant), typeid(HerbivorFood))] = &ElephantHerbivorFood;
		phm[Key(typeid(HerbivorFood), typeid(Elephant))] = &HerbivorFoodElephant;
		phm[Key(typeid(Elephant), typeid(Tree))] = &ElephantTree;
		phm[Key(typeid(Tree), typeid(Elephant))] = &TreeElephant;
		phm[Key(typeid(Elephant), typeid(Fence))] = &ElephantFence;
		phm[Key(typeid(Fence), typeid(Elephant))] = &FenceElephant;
		phm[Key(typeid(Elephant), typeid(PredatorFood))] = &ElephantPredatorFood;
		phm[Key(typeid(PredatorFood), typeid(Elephant))] = &PredatorFoodElephant;
		phm[Key(typeid(Elephant), typeid(Rock))] = &ElephantRock;
		phm[Key(typeid(Rock), typeid(Elephant))] = &RockElephant;
		//elephant and terrain collision
		phm[Key(typeid(Elephant), typeid(Path))] = &ElephantPath;
		phm[Key(typeid(Elephant), typeid(Water))] = &ElephantWater;
		phm[Key(typeid(Elephant), typeid(Savannah))] = &ElephantSavannah;
		phm[Key(typeid(Elephant), typeid(Dirt))] = &ElephantDirt;
		phm[Key(typeid(Elephant), typeid(Grass))] = &ElephantGrass;
		phm[Key(typeid(Elephant), typeid(Snow))] = &ElephantSnow;
		//Elephant with guest
		phm[Key(typeid(Elephant), typeid(ManGuest))] = &ElephantManGuest;
		phm[Key(typeid(Elephant), typeid(WomanGuest))] = &ElephantWomanGuest;


		//giraffe collision
		phm[Key(typeid(Giraffe), typeid(Giraffe))] = &GiraffeGiraffe;
		phm[Key(typeid(Giraffe), typeid(Hippo))] = &GiraffeHippo;
		phm[Key(typeid(Giraffe), typeid(PollarBear))] = &GiraffePollarBear;
		phm[Key(typeid(Hippo), typeid(Giraffe))] = &HippoGiraffe;
		phm[Key(typeid(PollarBear), typeid(Giraffe))] = &PollarBearGiraffe;
		//Giraffe and buildings collision
		phm[Key(typeid(Giraffe), typeid(Burger))] = &GiraffeBurger;
		phm[Key(typeid(Burger), typeid(Giraffe))] = &BurgerGiraffe;
		phm[Key(typeid(Giraffe), typeid(Bathroom))] = &GiraffeBathroom;
		phm[Key(typeid(Bathroom), typeid(Giraffe))] = &BathroomGiraffe;
		phm[Key(typeid(Giraffe), typeid(DrinkingStand))] = &GiraffeDrinkingStand;
		phm[Key(typeid(DrinkingStand), typeid(Giraffe))] = &DrinkingStandGiraffe;
		phm[Key(typeid(Giraffe), typeid(CuttonCandy))] = &GiraffeCuttonCandy;
		phm[Key(typeid(CuttonCandy), typeid(Giraffe))] = &CuttonCandyGiraffe;
		phm[Key(typeid(Giraffe), typeid(ChickerNugets))] = &GiraffeChickerNugets;
		phm[Key(typeid(ChickerNugets), typeid(Giraffe))] = &ChickerNugetsGiraffe;
		//Giraffe and construction collision
		phm[Key(typeid(Giraffe), typeid(HerbivorFood))] = &GiraffeHerbivorFood;
		phm[Key(typeid(HerbivorFood), typeid(Giraffe))] = &HerbivorFoodGiraffe;
		phm[Key(typeid(Giraffe), typeid(Tree))] = &GiraffeTree;
		phm[Key(typeid(Tree), typeid(Giraffe))] = &TreeGiraffe;
		phm[Key(typeid(Giraffe), typeid(Fence))] = &GiraffeFence;
		phm[Key(typeid(Fence), typeid(Giraffe))] = &FenceGiraffe;
		phm[Key(typeid(Giraffe), typeid(PredatorFood))] = &GiraffePredatorFood;
		phm[Key(typeid(PredatorFood), typeid(Giraffe))] = &PredatorFoodGiraffe;
		phm[Key(typeid(Giraffe), typeid(Rock))] = &GiraffeRock;
		phm[Key(typeid(Rock), typeid(Giraffe))] = &RockGiraffe;
		//Giraffe and terrain collision
		phm[Key(typeid(Giraffe), typeid(Path))] = &GiraffePath;
		phm[Key(typeid(Giraffe), typeid(Water))] = &GiraffeWater;
		phm[Key(typeid(Giraffe), typeid(Savannah))] = &GiraffeSavannah;
		phm[Key(typeid(Giraffe), typeid(Dirt))] = &GiraffeDirt;
		phm[Key(typeid(Giraffe), typeid(Grass))] = &GiraffeGrass;
		phm[Key(typeid(Giraffe), typeid(Snow))] = &GiraffeSnow;
		//Giraffe with guest
		phm[Key(typeid(Giraffe), typeid(ManGuest))] = &GiraffeManGuest;
		phm[Key(typeid(Giraffe), typeid(WomanGuest))] = &GiraffeWomanGuest;
	
		
		//hippo collision
		phm[Key(typeid(Hippo), typeid(Hippo))] = &HippoHippo;
		phm[Key(typeid(Hippo), typeid(PollarBear))] = &HippoPollarBear;
		phm[Key(typeid(PollarBear), typeid(Hippo))] = &PollarBearHippo;
		//hippo and buildings collision
		phm[Key(typeid(Hippo), typeid(Burger))] = &HippoBurger;
		phm[Key(typeid(Burger), typeid(Hippo))] = &BurgerHippo;
		phm[Key(typeid(Hippo), typeid(Bathroom))] = &HippoBathroom;
		phm[Key(typeid(Bathroom), typeid(Hippo))] = &BathroomHippo;
		phm[Key(typeid(Hippo), typeid(DrinkingStand))] = &HippoDrinkingStand;
		phm[Key(typeid(DrinkingStand), typeid(Hippo))] = &DrinkingStandHippo;
		phm[Key(typeid(Hippo), typeid(CuttonCandy))] = &HippoCuttonCandy;
		phm[Key(typeid(CuttonCandy), typeid(Hippo))] = &CuttonCandyHippo;
		phm[Key(typeid(Hippo), typeid(ChickerNugets))] = &HippoChickerNugets;
		phm[Key(typeid(ChickerNugets), typeid(Hippo))] = &ChickerNugetsHippo;
		//hippo and construction collision
		phm[Key(typeid(Hippo), typeid(HerbivorFood))] = &HippoHerbivorFood;
		phm[Key(typeid(HerbivorFood), typeid(Hippo))] = &HerbivorFoodHippo;
		phm[Key(typeid(Hippo), typeid(Tree))] = &HippoTree;
		phm[Key(typeid(Tree), typeid(Hippo))] = &TreeHippo;
		phm[Key(typeid(Hippo), typeid(Fence))] = &HippoFence;
		phm[Key(typeid(Fence), typeid(Hippo))] = &FenceHippo;
		phm[Key(typeid(Hippo), typeid(PredatorFood))] = &HippoPredatorFood;
		phm[Key(typeid(PredatorFood), typeid(Hippo))] = &PredatorFoodHippo;
		phm[Key(typeid(Hippo), typeid(Rock))] = &HippoRock;
		phm[Key(typeid(Rock), typeid(Hippo))] = &RockHippo;
		//Hippo and terrain collision
		phm[Key(typeid(Hippo), typeid(Path))] = &HippoPath;
		phm[Key(typeid(Hippo), typeid(Water))] = &HippoWater;
		phm[Key(typeid(Hippo), typeid(Savannah))] = &HippoSavannah;
		phm[Key(typeid(Hippo), typeid(Dirt))] = &HippoDirt;
		phm[Key(typeid(Hippo), typeid(Grass))] = &HippoGrass;
		phm[Key(typeid(Hippo), typeid(Snow))] = &HippoSnow;
		//Hippo with guest
		phm[Key(typeid(Hippo), typeid(ManGuest))] = &HippoManGuest;
		phm[Key(typeid(Hippo), typeid(WomanGuest))] = &HippoWomanGuest;

		//pollar collision
		phm[Key(typeid(PollarBear), typeid(PollarBear))] = &PollarBearPollarBear;
		//pollar and buildings collision
		phm[Key(typeid(PollarBear), typeid(Burger))] = &PollarBearBurger;
		phm[Key(typeid(Burger), typeid(PollarBear))] = &BurgerPollarBear;
		phm[Key(typeid(PollarBear), typeid(Bathroom))] = &PollarBearBathroom;
		phm[Key(typeid(Bathroom), typeid(PollarBear))] = &BathroomPollarBear;
		phm[Key(typeid(PollarBear), typeid(DrinkingStand))] = &PollarBearDrinkingStand;
		phm[Key(typeid(DrinkingStand), typeid(PollarBear))] = &DrinkingStandPollarBear;
		phm[Key(typeid(PollarBear), typeid(CuttonCandy))] = &PollarBearCuttonCandy;
		phm[Key(typeid(CuttonCandy), typeid(PollarBear))] = &CuttonCandyPollarBear;
		phm[Key(typeid(PollarBear), typeid(ChickerNugets))] = &PollarBearChickerNugets;
		phm[Key(typeid(ChickerNugets), typeid(PollarBear))] = &ChickerNugetsPollarBear;
		//PollarBear and construction collision
		phm[Key(typeid(PollarBear), typeid(HerbivorFood))] = &PollarBearHerbivorFood;
		phm[Key(typeid(HerbivorFood), typeid(PollarBear))] = &HerbivorFoodPollarBear;
		phm[Key(typeid(PollarBear), typeid(Tree))] = &PollarBearTree;
		phm[Key(typeid(Tree), typeid(PollarBear))] = &TreePollarBear;
		phm[Key(typeid(PollarBear), typeid(Fence))] = &PollarBearFence;
		phm[Key(typeid(Fence), typeid(PollarBear))] = &FencePollarBear;
		phm[Key(typeid(PollarBear), typeid(PredatorFood))] = &PollarBearPredatorFood;
		phm[Key(typeid(PredatorFood), typeid(PollarBear))] = &PredatorFoodPollarBear;
		phm[Key(typeid(PollarBear), typeid(Rock))] = &PollarBearRock;
		phm[Key(typeid(Rock), typeid(PollarBear))] = &RockPollarBear;
		//PollarBear and terrain collision
		phm[Key(typeid(PollarBear), typeid(Path))] = &PollarBearPath;
		phm[Key(typeid(PollarBear), typeid(Water))] = &PollarBearWater;
		phm[Key(typeid(PollarBear), typeid(Savannah))] = &PollarBearSavannah;
		phm[Key(typeid(PollarBear), typeid(Dirt))] = &PollarBearDirt;
		phm[Key(typeid(PollarBear), typeid(Grass))] = &PollarBearGrass;
		phm[Key(typeid(PollarBear), typeid(Snow))] = &PollarBearSnow;
		//PollarBear with guest
		phm[Key(typeid(PollarBear), typeid(ManGuest))] = &PollarBearManGuest;
		phm[Key(typeid(PollarBear), typeid(WomanGuest))] = &PollarBearWomanGuest;

		//buildings with buildings
		phm[Key(typeid(DrinkingStand), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(DrinkingStand), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(DrinkingStand), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(DrinkingStand), typeid(ChickerNugets))] = &DoNothing;
		phm[Key(typeid(DrinkingStand), typeid(CuttonCandy))] = &DoNothing;
		
		phm[Key(typeid(Burger), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(Burger), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(Burger), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(Burger), typeid(ChickerNugets))] = &DoNothing;
		phm[Key(typeid(Burger), typeid(CuttonCandy))] = &DoNothing;
		
		phm[Key(typeid(Bathroom), typeid(ChickerNugets))] = &DoNothing;
		phm[Key(typeid(Bathroom), typeid(CuttonCandy))] = &DoNothing;
		phm[Key(typeid(Bathroom), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(Bathroom), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(Bathroom), typeid(Bathroom))] = &DoNothing;

		phm[Key(typeid(ChickerNugets), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(ChickerNugets), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(ChickerNugets), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(ChickerNugets), typeid(ChickerNugets))] = &DoNothing;
		phm[Key(typeid(ChickerNugets), typeid(CuttonCandy))] = &DoNothing;

		phm[Key(typeid(CuttonCandy), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(CuttonCandy), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(CuttonCandy), typeid(ChickerNugets))] = &DoNothing;
		phm[Key(typeid(CuttonCandy), typeid(CuttonCandy))] = &DoNothing;
		phm[Key(typeid(CuttonCandy), typeid(Bathroom))] = &DoNothing;

		//construction with constraction
		phm[Key(typeid(HerbivorFood), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(HerbivorFood), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(HerbivorFood), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(HerbivorFood), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(HerbivorFood), typeid(Rock))] = &DoNothing;

		phm[Key(typeid(Tree), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(Tree), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(Tree), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(Tree), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(Tree), typeid(Rock))] = &DoNothing;

		phm[Key(typeid(Fence), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(Fence), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(Fence), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(Fence), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(Fence), typeid(Rock))] = &DoNothing;

		phm[Key(typeid(PredatorFood), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(PredatorFood), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(PredatorFood), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(PredatorFood), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(PredatorFood), typeid(Rock))] = &DoNothing;

		phm[Key(typeid(Rock), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(Rock), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(Rock), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(Rock), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(Rock), typeid(Rock))] = &DoNothing;

		//building with terrain
		phm[Key(typeid(Bathroom), typeid(Water))] = &DoNothing;
		phm[Key(typeid(Bathroom), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(Bathroom), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(Bathroom), typeid(Path))] = &DoNothing;
		phm[Key(typeid(Bathroom), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(Bathroom), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(DrinkingStand), typeid(Water))] = &DoNothing;
		phm[Key(typeid(DrinkingStand), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(DrinkingStand), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(DrinkingStand), typeid(Path))] = &DoNothing;
		phm[Key(typeid(DrinkingStand), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(DrinkingStand), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(Burger), typeid(Water))] = &DoNothing;
		phm[Key(typeid(Burger), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(Burger), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(Burger), typeid(Path))] = &DoNothing;
		phm[Key(typeid(Burger), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(Burger), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(CuttonCandy), typeid(Water))] = &DoNothing;
		phm[Key(typeid(CuttonCandy), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(CuttonCandy), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(CuttonCandy), typeid(Path))] = &DoNothing;
		phm[Key(typeid(CuttonCandy), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(CuttonCandy), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(ChickerNugets), typeid(Water))] = &DoNothing;
		phm[Key(typeid(ChickerNugets), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(ChickerNugets), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(ChickerNugets), typeid(Path))] = &DoNothing;
		phm[Key(typeid(ChickerNugets), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(ChickerNugets), typeid(Dirt))] = &DoNothing;


		//buildings with constructions
		phm[Key(typeid(Bathroom), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(Bathroom), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(Bathroom), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(Bathroom), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(Bathroom), typeid(Rock))] = &DoNothing;

		phm[Key(typeid(DrinkingStand), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(DrinkingStand), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(DrinkingStand), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(DrinkingStand), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(DrinkingStand), typeid(Rock))] = &DoNothing;

		phm[Key(typeid(Burger), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(Burger), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(Burger), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(Burger), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(Burger), typeid(Rock))] = &DoNothing;

		phm[Key(typeid(CuttonCandy), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(CuttonCandy), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(CuttonCandy), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(CuttonCandy), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(CuttonCandy), typeid(Rock))] = &DoNothing;

		phm[Key(typeid(ChickerNugets), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(ChickerNugets), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(ChickerNugets), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(ChickerNugets), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(ChickerNugets), typeid(Rock))] = &DoNothing;

		//building with guest
		phm[Key(typeid(Bathroom), typeid(ManGuest))] = &BathroomManGuest;
		phm[Key(typeid(Bathroom), typeid(WomanGuest))] = &BathroomWomanGuest;

		phm[Key(typeid(DrinkingStand), typeid(ManGuest))] = &DrinkingStandManGuest;
		phm[Key(typeid(DrinkingStand), typeid(WomanGuest))] = &DrinkingStandWomanGuest;

		phm[Key(typeid(Burger), typeid(ManGuest))] = &BurgerManGuest;
		phm[Key(typeid(Burger), typeid(WomanGuest))] = &BurgerWomanGuest;

		phm[Key(typeid(CuttonCandy), typeid(ManGuest))] = &CuttonCandyManGuest;
		phm[Key(typeid(CuttonCandy), typeid(WomanGuest))] = &CuttonCandyWomanGuest;

		phm[Key(typeid(ChickerNugets), typeid(ManGuest))] = &ChickerNugetsManGuest;
		phm[Key(typeid(ChickerNugets), typeid(WomanGuest))] = &ChickerNugetsWomanGuest;


		//construction with building
		phm[Key(typeid(HerbivorFood), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(HerbivorFood), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(HerbivorFood), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(HerbivorFood), typeid(ChickerNugets))] = &DoNothing;
		phm[Key(typeid(HerbivorFood), typeid(CuttonCandy))] = &DoNothing;
		
		phm[Key(typeid(Tree), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(Tree), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(Tree), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(Tree), typeid(ChickerNugets))] = &DoNothing;
		phm[Key(typeid(Tree), typeid(CuttonCandy))] = &DoNothing;

		phm[Key(typeid(Fence), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(Fence), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(Fence), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(Fence), typeid(ChickerNugets))] = &DoNothing;
		phm[Key(typeid(Fence), typeid(CuttonCandy))] = &DoNothing;

		phm[Key(typeid(PredatorFood), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(PredatorFood), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(PredatorFood), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(PredatorFood), typeid(ChickerNugets))] = &DoNothing;
		phm[Key(typeid(PredatorFood), typeid(CuttonCandy))] = &DoNothing;

		phm[Key(typeid(Rock), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(Rock), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(Rock), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(Rock), typeid(ChickerNugets))] = &DoNothing;
		phm[Key(typeid(Rock), typeid(CuttonCandy))] = &DoNothing;

		//construction with terrain
		phm[Key(typeid(HerbivorFood), typeid(Water))] = &DoNothing;
		phm[Key(typeid(HerbivorFood), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(HerbivorFood), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(HerbivorFood), typeid(Path))] = &DoNothing;
		phm[Key(typeid(HerbivorFood), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(HerbivorFood), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(Tree), typeid(Water))] = &DoNothing;
		phm[Key(typeid(Tree), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(Tree), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(Tree), typeid(Path))] = &DoNothing;
		phm[Key(typeid(Tree), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(Tree), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(Fence), typeid(Water))] = &DoNothing;
		phm[Key(typeid(Fence), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(Fence), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(Fence), typeid(Path))] = &DoNothing;
		phm[Key(typeid(Fence), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(Fence), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(PredatorFood), typeid(Water))] = &DoNothing;
		phm[Key(typeid(PredatorFood), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(PredatorFood), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(PredatorFood), typeid(Path))] = &DoNothing;
		phm[Key(typeid(PredatorFood), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(PredatorFood), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(Rock), typeid(Water))] = &DoNothing;
		phm[Key(typeid(Rock), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(Rock), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(Rock), typeid(Path))] = &DoNothing;
		phm[Key(typeid(Rock), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(Rock), typeid(Dirt))] = &DoNothing;

		//construction with guest
		phm[Key(typeid(HerbivorFood), typeid(ManGuest))] = &HerbivorFoodManGuest;
		phm[Key(typeid(HerbivorFood), typeid(WomanGuest))] = &HerbivorFoodWomanGuest;

		phm[Key(typeid(Tree), typeid(ManGuest))] = &TreeManGuest;
		phm[Key(typeid(Tree), typeid(WomanGuest))] = &TreeWomanGuest;

		phm[Key(typeid(Fence), typeid(ManGuest))] = &FenceManGuest;
		phm[Key(typeid(Fence), typeid(WomanGuest))] = &FenceWomanGuest;

		phm[Key(typeid(PredatorFood), typeid(ManGuest))] = &PredatorFoodManGuest;
		phm[Key(typeid(PredatorFood), typeid(WomanGuest))] = &PredatorFoodWomanGuest;

		phm[Key(typeid(Rock), typeid(ManGuest))] = &RockManGuest;
		phm[Key(typeid(Rock), typeid(WomanGuest))] = &RockWomanGuest;

		//terrain with terrain
		phm[Key(typeid(Water), typeid(Water))] = &DoNothing;
		phm[Key(typeid(Water), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(Water), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(Water), typeid(Path))] = &DoNothing;
		phm[Key(typeid(Water), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(Water), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(Snow), typeid(Water))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(Path))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(Savannah), typeid(Water))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(Path))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(Path), typeid(Water))] = &DoNothing;
		phm[Key(typeid(Path), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(Path), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(Path), typeid(Path))] = &DoNothing;
		phm[Key(typeid(Path), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(Path), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(Grass), typeid(Water))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(Path))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(Dirt), typeid(Water))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(Path))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(Dirt))] = &DoNothing;

		//terrain with building
		phm[Key(typeid(Water), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(Water), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(Water), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(Water), typeid(CuttonCandy))] = &DoNothing;
		phm[Key(typeid(Water), typeid(ChickerNugets))] = &DoNothing;

		phm[Key(typeid(Snow), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(CuttonCandy))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(ChickerNugets))] = &DoNothing;

		phm[Key(typeid(Savannah), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(CuttonCandy))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(ChickerNugets))] = &DoNothing;

		phm[Key(typeid(Path), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(Path), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(Path), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(Path), typeid(CuttonCandy))] = &DoNothing;
		phm[Key(typeid(Path), typeid(ChickerNugets))] = &DoNothing;

		phm[Key(typeid(Grass), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(CuttonCandy))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(ChickerNugets))] = &DoNothing;

		phm[Key(typeid(Dirt), typeid(Bathroom))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(DrinkingStand))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(Burger))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(CuttonCandy))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(ChickerNugets))] = &DoNothing;

		//terrian with animal
		phm[Key(typeid(Water), typeid(Lion))] = &WaterLion;
		phm[Key(typeid(Water), typeid(Elephant))] = &WaterElephant;
		phm[Key(typeid(Water), typeid(Giraffe))] = &WaterGiraffe;
		phm[Key(typeid(Water), typeid(Hippo))] = &WaterHippo;
		phm[Key(typeid(Water), typeid(PollarBear))] = &WaterPollarBear;

		phm[Key(typeid(Snow), typeid(Lion))] = &SnowLion;
		phm[Key(typeid(Snow), typeid(Elephant))] = &SnowElephant;
		phm[Key(typeid(Snow), typeid(Giraffe))] = &SnowGiraffe;
		phm[Key(typeid(Snow), typeid(Hippo))] = &SnowHippo;
		phm[Key(typeid(Snow), typeid(PollarBear))] = &SnowPollarBear;

		phm[Key(typeid(Savannah), typeid(Lion))] = &SavannahLion;
		phm[Key(typeid(Savannah), typeid(Elephant))] = &SavannahElephant;
		phm[Key(typeid(Savannah), typeid(Giraffe))] = &SavannahGiraffe;
		phm[Key(typeid(Savannah), typeid(Hippo))] = &SavannahHippo;
		phm[Key(typeid(Savannah), typeid(PollarBear))] = &SavannahPollarBear;

		phm[Key(typeid(Path), typeid(Lion))] = &PathLion;
		phm[Key(typeid(Path), typeid(Elephant))] = &PathElephant;
		phm[Key(typeid(Path), typeid(Giraffe))] = &PathGiraffe;
		phm[Key(typeid(Path), typeid(Hippo))] = &PathHippo;
		phm[Key(typeid(Path), typeid(PollarBear))] = &PathPollarBear;

		phm[Key(typeid(Grass), typeid(Lion))] = &GrassLion;
		phm[Key(typeid(Grass), typeid(Elephant))] = &GrassElephant;
		phm[Key(typeid(Grass), typeid(Giraffe))] = &GrassGiraffe;
		phm[Key(typeid(Grass), typeid(Hippo))] = &GrassHippo;
		phm[Key(typeid(Grass), typeid(PollarBear))] = &GrassPollarBear;

		phm[Key(typeid(Dirt), typeid(Lion))] = &DirtLion;
		phm[Key(typeid(Dirt), typeid(Elephant))] = &DirtElephant;
		phm[Key(typeid(Dirt), typeid(Giraffe))] = &DirtGiraffe;
		phm[Key(typeid(Dirt), typeid(Hippo))] = &DirtHippo;
		phm[Key(typeid(Dirt), typeid(PollarBear))] = &DirtPollarBear;

		//terrain with construction
		phm[Key(typeid(Water), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(Water), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(Water), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(Water), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(Water), typeid(Rock))] = &DoNothing;

		phm[Key(typeid(Snow), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(Rock))] = &DoNothing;

		phm[Key(typeid(Savannah), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(Rock))] = &DoNothing;

		phm[Key(typeid(Path), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(Path), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(Path), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(Path), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(Path), typeid(Rock))] = &DoNothing;

		phm[Key(typeid(Grass), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(Rock))] = &DoNothing;

		phm[Key(typeid(Dirt), typeid(HerbivorFood))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(Tree))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(Fence))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(PredatorFood))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(Rock))] = &DoNothing;

		//terrain with guest
		phm[Key(typeid(Water), typeid(ManGuest))] = &DoNothing;
		phm[Key(typeid(Water), typeid(WomanGuest))] = &DoNothing;

		phm[Key(typeid(Snow), typeid(ManGuest))] = &DoNothing;
		phm[Key(typeid(Snow), typeid(WomanGuest))] = &DoNothing;

		phm[Key(typeid(Savannah), typeid(ManGuest))] = &DoNothing;
		phm[Key(typeid(Savannah), typeid(WomanGuest))] = &DoNothing;

		phm[Key(typeid(Path), typeid(ManGuest))] = &DoNothing;
		phm[Key(typeid(Path), typeid(WomanGuest))] = &DoNothing;

		phm[Key(typeid(Grass), typeid(ManGuest))] = &DoNothing;
		phm[Key(typeid(Grass), typeid(WomanGuest))] = &DoNothing;

		phm[Key(typeid(Dirt), typeid(ManGuest))] = &DoNothing;
		phm[Key(typeid(Dirt), typeid(WomanGuest))] = &DoNothing;


	
		//guest with guest
		phm[Key(typeid(ManGuest), typeid(ManGuest))] = &DoNothing;
		phm[Key(typeid(ManGuest), typeid(WomanGuest))] = &DoNothing;
		phm[Key(typeid(WomanGuest), typeid(WomanGuest))] = &DoNothing;
		phm[Key(typeid(WomanGuest), typeid(ManGuest))] = &DoNothing;

		//guest with building
		phm[Key(typeid(ManGuest), typeid(Bathroom))] = &ManGuestBathroom;
		phm[Key(typeid(ManGuest), typeid(DrinkingStand))] = &ManGuestDrinkingStand;
		phm[Key(typeid(ManGuest), typeid(Burger))] = &ManGuestBurger;
		phm[Key(typeid(ManGuest), typeid(CuttonCandy))] = &ManGuestCuttonCandy;
		phm[Key(typeid(ManGuest), typeid(ChickerNugets))] = &ManGuestChickerNugets;

		phm[Key(typeid(WomanGuest), typeid(Bathroom))] = &WomanGuestBathroom;
		phm[Key(typeid(WomanGuest), typeid(DrinkingStand))] = &WomanGuestDrinkingStand;
		phm[Key(typeid(WomanGuest), typeid(Burger))] = &WomanGuestBurger;
		phm[Key(typeid(WomanGuest), typeid(CuttonCandy))] = &WomanGuestCuttonCandy;
		phm[Key(typeid(WomanGuest), typeid(ChickerNugets))] = &WomanGuestChickerNugets;

		//guest with construction
		phm[Key(typeid(ManGuest), typeid(HerbivorFood))] = &ManGuestHerbivorFood;
		phm[Key(typeid(ManGuest), typeid(Tree))] = &ManGuestTree;
		phm[Key(typeid(ManGuest), typeid(Fence))] = &ManGuestFence;
		phm[Key(typeid(ManGuest), typeid(PredatorFood))] = &ManGuestPredatorFood;
		phm[Key(typeid(ManGuest), typeid(Rock))] = &ManGuestRock;

		phm[Key(typeid(WomanGuest), typeid(HerbivorFood))] = &WomanGuestHerbivorFood;
		phm[Key(typeid(WomanGuest), typeid(Tree))] = &WomanGuestTree;
		phm[Key(typeid(WomanGuest), typeid(Fence))] = &WomanGuestFence;
		phm[Key(typeid(WomanGuest), typeid(PredatorFood))] = &WomanGuestPredatorFood;
		phm[Key(typeid(WomanGuest), typeid(Rock))] = &WomanGuestRock;

		//guest with animal
		phm[Key(typeid(ManGuest), typeid(Lion))] = &ManGuestLion;
		phm[Key(typeid(ManGuest), typeid(Elephant))] = &ManGuestElephant;
		phm[Key(typeid(ManGuest), typeid(Giraffe))] = &ManGuestGiraffe;
		phm[Key(typeid(ManGuest), typeid(Hippo))] = &ManGuestHippo;
		phm[Key(typeid(ManGuest), typeid(PollarBear))] = &ManGuestPollarBear;

		phm[Key(typeid(WomanGuest), typeid(Lion))] = &WomanGuestLion;
		phm[Key(typeid(WomanGuest), typeid(Elephant))] = &WomanGuestElephant;
		phm[Key(typeid(WomanGuest), typeid(Giraffe))] = &WomanGuestGiraffe;
		phm[Key(typeid(WomanGuest), typeid(Hippo))] = &WomanGuestHippo;
		phm[Key(typeid(WomanGuest), typeid(PollarBear))] = &WomanGuestPollarBear;

		//guest with terrain
		phm[Key(typeid(ManGuest), typeid(Water))] = &DoNothing;
		phm[Key(typeid(ManGuest), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(ManGuest), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(ManGuest), typeid(Path))] = &DoNothing;
		phm[Key(typeid(ManGuest), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(ManGuest), typeid(Dirt))] = &DoNothing;

		phm[Key(typeid(WomanGuest), typeid(Water))] = &DoNothing;
		phm[Key(typeid(WomanGuest), typeid(Snow))] = &DoNothing;
		phm[Key(typeid(WomanGuest), typeid(Savannah))] = &DoNothing;
		phm[Key(typeid(WomanGuest), typeid(Path))] = &DoNothing;
		phm[Key(typeid(WomanGuest), typeid(Grass))] = &DoNothing;
		phm[Key(typeid(WomanGuest), typeid(Dirt))] = &DoNothing;


		return phm;
	}

	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
	{
		static HitMap collisionMap = initializeCollisionMap();
		auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
		if (mapEntry == collisionMap.end())
		{
			return nullptr;
		}
		return mapEntry->second;
	}

} // end namespace

void processCollision(MapItem& object1, MapItem& object2)
{
	auto phf = lookup(typeid(object1), typeid(object2));
	if (!phf)
	{
		throw UnknownCollision(object1, object2);
	}
	phf(object1, object2);
}
