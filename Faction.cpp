/* @AuthorStudent Name:<Bilal Ak>
Student ID :<150190069>
Date:<24/05/2021>*/
#include "Faction.h"
#include <iostream>
using namespace std;
//constructor
Faction::Faction(const string N,const int nou,const int ap,const int hp,const int urn) {
	Name = N;
	numOfUnits = nou;
	AP = ap;
	HP = hp;
	URN = urn;
	totalHealth = hp * nou;
	isAlive = true;
}
void Faction::AssignEnemies(Faction *one, Faction *two) {
	firstEnemy = one;
	secondEnemy = two;
}

void Faction::Print() {
	cout << "Faction Name:         " << Name << endl;
	if (isAlive) {
		cout << "Status:               Alive" << endl;
	}
	else {
		cout << "Status:               Defeated" << endl;
	}
	cout << "Number of Units:      " << numOfUnits << endl;
	cout << "Attack Point:         " << AP << endl;
	cout << "Health Point:         " << HP << endl;
	cout << "Unit Regen Number:    " << URN << endl;
	cout << "Total Faction Health: " << totalHealth << endl;
}

void Faction::EndTurn() {

	if (numOfUnits < 0) {
		numOfUnits = 0;
	}
	if (numOfUnits == 0) {
		isAlive=false;
	}
	if (numOfUnits != 0) {
		numOfUnits += URN;
	}
	totalHealth = HP * numOfUnits;
}

bool Faction::IsAlive() {
	return isAlive;
}

string Faction::getName() {
	return Name;
}
