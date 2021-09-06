/* @AuthorStudent Name:<Bilal Ak>
Student ID :<150190069>
Date:<24/05/2021>*/
#pragma once
#include <iostream>
using namespace std;

class Faction {
protected:
	string Name;
	Faction* firstEnemy;
	Faction* secondEnemy;
	int numOfUnits;
	int AP;
	int HP;
	int URN;
	int totalHealth;
	bool isAlive;
public:
	Faction (const string="default",const  int=0,const  int=0,const  int=0,const  int=0);
	void AssignEnemies(Faction*, Faction*);
	virtual void PerformAttack()=0;
	virtual void ReceiveAttack(int, string)=0;
	virtual int PurchaseWeapons(int)=0;
	virtual int PurchaseArmors(int)=0;
	virtual void Print();
	void EndTurn();
	//get and set methods
	bool IsAlive();
	string getName();
};
