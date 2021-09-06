/* @AuthorStudent Name:<Bilal Ak>
Student ID :<150190069>
Date:<24/05/2021>*/
#include "Orcs.h"
#include "Faction.h"
#include <iostream>
using namespace std;

Orcs::Orcs(const string N,const int nou,const int ap,const int hp,const int urn) :Faction(N, nou, ap, hp, urn) {

}

//for this main.cpp it is not necessary but if we use a different main.cpp, we need to check if first enemy is elves or not
void Orcs::PerformAttack() {
	if (firstEnemy->IsAlive() && !secondEnemy->IsAlive()) {
		firstEnemy->ReceiveAttack(AP*numOfUnits,"orcs");
	}
	else if (!firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
		secondEnemy->ReceiveAttack(AP * numOfUnits,"orcs");
	}
	else if (firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
		if (firstEnemy->getName() == "Elves") {
			firstEnemy->ReceiveAttack(AP * numOfUnits * 70 / 100, "orcs");
			secondEnemy->ReceiveAttack(AP * (numOfUnits- numOfUnits * 70 / 100), "orcs");
		}
		else {
			firstEnemy->ReceiveAttack(AP * (numOfUnits - numOfUnits * 70 / 100), "orcs");
			secondEnemy->ReceiveAttack(AP * numOfUnits * 70 / 100, "orcs");
		}
	}
}

//we check which faction is attacking
void Orcs::ReceiveAttack(int attack,string fact) {
	if (fact == "elves") {
		attack = attack * 75/100;
	}
	else if (fact == "dwarves") {
		attack = attack * 80/100;
	}
	numOfUnits = numOfUnits - (attack / HP);
}

void Orcs::Print() {
	cout << "\"Stop running, you'll only die tired!\"" << endl;
	Faction::Print();
}

int Orcs::PurchaseWeapons(int wp) {
	AP = AP + 2 * wp;
	return wp * 20;
}

int Orcs::PurchaseArmors(int ap) {
	HP = HP + 3 * ap;
	return ap * 1;
}
