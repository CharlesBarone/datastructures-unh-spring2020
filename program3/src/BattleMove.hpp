//
//  BattleMove.hpp
//  program3
//
//  Created by Charles Barone on 4/22/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#pragma once

#include "IMove.hpp"

class Actor;

class BattleMove: public IMove {
public:
	BattleMove() {}
	void Execute() {}
	void Undo() {}
protected:
	Actor* self;
	Actor* other;
};

class AttackOneCommand: public BattleMove {
public:
	AttackOneCommand(Actor* self,  Actor* other);
	void Execute();
	void Undo();
private:
	int actualDamage;
};

class AttackTwoCommand: public BattleMove {
public:
	AttackTwoCommand(Actor* self,  Actor* other);
	void Execute();
	void Undo();
private:
	int actualDamage;
};

class HealCommand: public BattleMove {
public:
	HealCommand(Actor* self,  Actor* other);
	void Execute();
	void Undo();
private:
	int actualHealAmount;
};