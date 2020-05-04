//
//  Actor.hpp
//  program3
//
//  Created by Charles Barone on 4/22/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "enums.hpp"
#include "MoveManager.hpp"
#include "BattleMoveFactory.hpp"

using namespace std;

class Actor {
public:
	Actor(string name, int health)
		: sName(name), iHealth(health)
	{ }
	void Hit(int damage);	//public method to hit THIS actor with damage
	void Heal(int amount);	//public method to heal this actor with an amount
	vector<MoveType> GetMoves();	//vector of MoveTypes
	bool IsDead();
	auto getName() const -> string { return this->sName; }
	auto getHealth() const -> int { return this->iHealth; }
	void DoMove(MoveManager& mgr, MoveType, Actor* other);

private:
	string sName;
	int iHealth;
	vector<MoveType> moves;

protected:
	void addMove(MoveType move) { moves.push_back(move); }
};

class Knight: public Actor{
public:
	Knight(string name, int health)
		: Actor(name, health)
	{
		addMove(MoveType::AttackTwo);
		addMove(MoveType::Heal);
	}
};

class Ghost: public Actor{
public:
	Ghost(string name, int health)
		: Actor(name, health)
	{
		addMove(MoveType::AttackOne);
		addMove(MoveType::Heal);
	}
};

class Warrior: public Actor{
public:
	Warrior(string name, int health)
		: Actor(name, health)
	{
		addMove(MoveType::AttackTwo);
		addMove(MoveType::AttackTwo);
	}
};