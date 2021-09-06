/* @AuthorStudent Name:<Bilal Ak>
Student ID :<150190069>
Date:<24/05/2021>*/
#include "Elves.h"
#include "Faction.h"
#include <iostream>
using namespace std;

Elves::Elves(const string N,const int nou,const int ap,const int hp,const int urn) :Faction(N, nou, ap, hp, urn) {

}
//for this main.cpp it is not necessary but if we use a different main.cpp, we need to check if first enemy is dwarves or not
void Elves::PerformAttack() {
	if (firstEnemy->IsAlive() && !secondEnemy->IsAlive()) {
		if (firstEnemy->getName() == "Dwarves") {
			firstEnemy->ReceiveAttack(AP * numOfUnits*1.5, "elves");
		}
		else {
			firstEnemy->ReceiveAttack(AP * numOfUnits, "elves");
		}
	}
	else if (!firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
		if (secondEnemy->getName() == "Dwarves") {
			secondEnemy->ReceiveAttack(AP * numOfUnits * 150/100, "elves");
		}
		else {
			secondEnemy->ReceiveAttack(AP * numOfUnits, "elves");
		}
	}
	else if (firstEnemy->IsAlive() && secondEnemy->IsAlive()) {
		if (firstEnemy->getName() == "Dwarves") {
			firstEnemy->ReceiveAttack(AP * 150 / 100 * (numOfUnits -  (numOfUnits * 60/100)) , "elves");
			secondEnemy->ReceiveAttack(AP * (numOfUnits * 60 / 100), "elves");
		}
		else {
			firstEnemy->ReceiveAttack(AP * numOfUnits * 60 / 100, "elves");
			secondEnemy->ReceiveAttack(AP * 150 / 100 * (numOfUnits - (numOfUnits * 60 / 100)), "elves");
		}
	}
}

//we check which faction is attacking
void Elves::ReceiveAttack(int attack, string fact) {

	if (fact == "orcs") {
		attack = attack * 125/100;
	}
	else if (fact == "dwarves") {
		attack = attack * 75/100;
	}
	numOfUnits = numOfUnits - (attack / HP);

}

void Elves::Print() {
	cout << "\"You cannot reach our elegance.\"" << endl;
	Faction::Print();
}


int Elves::PurchaseWeapons(int wp) {
	AP = AP + 2 * wp;
	return wp * 15;
}

int Elves::PurchaseArmors(int ap) {
	HP = HP + 4 * ap;
	return ap * 5;
}
