/* @AuthorStudent Name:<Bilal Ak>
Student ID :<150190069>
Date:<24/05/2021>*/
#pragma once
#include "Faction.h"
#include <iostream>
using namespace std;

class Elves :public Faction {
public:
	Elves(const string = "default",const int = 0,const int = 0,const int = 0,const int = 0);
	void PerformAttack();
	void ReceiveAttack(int attack, string fact);
	void Print();
	int PurchaseWeapons(int);
	int PurchaseArmors(int);
};
