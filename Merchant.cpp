/* @AuthorStudent Name:<Bilal Ak>
Student ID :<150190069>
Date:<24/05/2021>*/
#include "Merchant.h"
#include "Faction.h"
#include "Orcs.h"
#include "Elves.h"
#include "Dwarves.h"
#include <iostream>
using namespace std;

Merchant::Merchant(const int sWP,const int sAP) {
	startingAP = sAP;
	startingWP = sWP;
	armorP = sAP;
	weaponP = sWP;
	revenue = 0;
}

void Merchant::AssignFactions(Faction* one, Faction* two, Faction* three) {
	firstfaction = one;
	secondfaction = two;
	thirdfaction = three;
}

bool Merchant::SellWeapons(string N, int wP) {
	if (N == "Orcs") {
		if (!firstfaction->IsAlive()) {
			cout << "The faction you want to sell weapons is dead!" << endl;
			return false;
		}
		else if (wP > weaponP) {
			cout << "You try to sell more weapons than you have in possession." << endl;
			return false;
		}
		else {
			revenue+=firstfaction->PurchaseWeapons(wP);
			cout << "Weapons sold!" << endl;
			weaponP = weaponP - wP;
			return true;
		}
	}
	else if (N == "Dwarves") {
		if (!secondfaction->IsAlive()) {
			cout << "The faction you want to sell weapons is dead!" << endl;
			return false;
		}
		else if (wP > weaponP) {
			cout << "You try to sell more weapons than you have in possession." << endl;
			return false;
		}
		else {
			revenue += secondfaction->PurchaseWeapons(wP);
			cout << "Weapons sold!" << endl;
			weaponP = weaponP - wP;
			return true;
		}
	}
	else if (N == "Elves") {
		if (!thirdfaction->IsAlive()) {
			cout << "The faction you want to sell weapons is dead!" << endl;
			return false;
		}
		else if (wP > weaponP) {
			cout << "You try to sell more weapons than you have in possession." << endl;
			return false;
		}
		else {
			revenue += thirdfaction->PurchaseWeapons(wP);
			cout << "Weapons sold!" << endl;
			weaponP = weaponP - wP;
			return true;
		}
	}
}

bool Merchant::SellArmors(string N, int aP) {
	if (N == "Orcs") {
		if (!firstfaction->IsAlive()) {
			cout << "The faction you want to sell armors is dead!" << endl;
			return false;
		}
		else if (aP > armorP) {
			cout << "You try to sell more armors than you have in possession." << endl;
			return false;
		}
		else {
			revenue += firstfaction->PurchaseArmors(aP);
			cout << "Armors sold!" << endl;
			armorP = armorP - aP;
			return true;
		}
	}
	else if (N == "Dwarves") {
		if (!secondfaction->IsAlive()) {
			cout << "The faction you want to sell armors is dead!" << endl;
			return false;
		}
		else if (aP > armorP) {
			cout << "You try to sell more armors than you have in possession." << endl;
			return false;
		}
		else {
			revenue += secondfaction->PurchaseArmors(aP);
			cout << "Armors sold!" << endl;
			armorP = armorP - aP;
			return true;
		}
	}
	else if (N == "Elves") {
		if (!thirdfaction->IsAlive()) {
			cout << "The faction you want to sell armors is dead!" << endl;
			return false;
		}
		else if (aP > armorP) {
			cout << "You try to sell more armors than you have in possession." << endl;
			return false;
		}
		else {
			revenue += thirdfaction->PurchaseArmors(aP);
			cout << "Armors sold!" << endl;
			armorP = armorP - aP;
			return true;
		}
	}
}

void Merchant::EndTurn() {
	armorP = startingAP;
	weaponP = startingWP;
}

//get and set methods

int Merchant::GetArmorPoints() {
	return armorP;
}

int Merchant::GetWeaponPoints() {
	return weaponP;
}

int Merchant::GetRevenue() {
	return revenue;
}
