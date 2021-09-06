/* @AuthorStudent Name:<Bilal Ak>
Student ID :<150190069>
Date:<24/05/2021>*/
#include "Dwarves.h"
#include "Faction.h"
#include <iostream>
using namespace std;

Dwarves::Dwarves(const string N,const int nou,const int ap,const int hp,const int urn) :Faction(N, nou, ap, hp, urn) {

}

void Dwarves::PerformAttack() {
	if (firstEnemy->IsAlive() && !secondEnemy->IsAlive()) {
		firstEnemy->ReceiveAttack(AP * numOfUnits, "dwarves");
	}
	else if (!firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
		secondEnemy->ReceiveAttack(AP * numOfUnits, "dwarves");
	}
	else if (firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
		firstEnemy->ReceiveAttack(AP * (numOfUnits * 50 / 100), "dwarves");
		secondEnemy->ReceiveAttack(AP * (numOfUnits * 50 / 100), "dwarves");
	}
}

void Dwarves::ReceiveAttack(int attack, string fact) {
	numOfUnits = numOfUnits - (attack / HP);
}

void Dwarves::Print() {
	cout << "\"Taste the power of our axes!\"" << endl;
	Faction::Print();
}

int Dwarves::PurchaseWeapons(int wp) {
	AP = AP + wp;
	return wp * 10;
}

int Dwarves::PurchaseArmors(int ap) {
	HP = HP + 2 * ap;
	return ap * 3;
}
