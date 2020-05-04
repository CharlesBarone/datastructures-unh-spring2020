//
//  Actor.cpp
//  program3
//
//  Created by Charles Barone on 4/22/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "Actor.hpp"
#include <iostream>

using namespace std;

void Actor::DoMove(MoveManager& mgr, MoveType moveType, Actor* other){
	string MoveTypeStrings[3] = { "AttackOne", "AttackTwo", "Heal" };
	cout << this->getName() << " used: " << MoveTypeStrings[static_cast<int>(moveType)] << endl;
	mgr.ExecuteMove(MoveFactory::BuildMove(moveType, this, other), this, other);
}

void Actor::Hit(int damage) {
	cout << this->getName() << ", (" << this->getHealth() << ") is hit with " << damage << " damage.\n";
	this->iHealth -= damage;
}

void Actor::Heal(int amount) {
	cout << this->getName() << ", (" << this->getHealth() << ") is healed by " << amount << " hp.\n";
	this->iHealth += amount;
}

vector<MoveType> Actor::GetMoves() {
	return this->moves;
}

bool Actor::IsDead() {
	return this->iHealth <= 0;
}