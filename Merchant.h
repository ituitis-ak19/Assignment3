/* @AuthorStudent Name:<Bilal Ak>
Student ID :<150190069>
Date:<24/05/2021>*/
#pragma once
#include "Faction.h"
#include "Orcs.h"
#include "Elves.h"
#include "Dwarves.h"
#include <iostream>
using namespace std;
class Merchant {
private:
	Faction* firstfaction;
	Faction* secondfaction;
	Faction* thirdfaction;
	int startingWP;
	int startingAP;
	int revenue;
	int armorP;
	int weaponP;
public:
	Merchant(const int=0,const int=0);
	void AssignFactions(Faction*, Faction*, Faction*);
	bool SellWeapons(string, int);
	bool SellArmors(string, int);
	void EndTurn();
	//get and set methods
	int GetArmorPoints();
	int GetWeaponPoints();
	int GetRevenue();
};
