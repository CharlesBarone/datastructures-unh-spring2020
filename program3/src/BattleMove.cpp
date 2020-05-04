//
//  BattleMove.cpp
//  program3
//
//  Created by Charles Barone on 4/22/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "Actor.hpp"

AttackOneCommand::AttackOneCommand(Actor* self,  Actor* other) {
	this->self = self;
	this->other = other;
}

void AttackOneCommand::Execute() {
	srand(time(NULL));
	int damage = rand() % 15 + 10;
	this->actualDamage = damage;
	this->other->Hit(damage);
}
void AttackOneCommand::Undo() {
	this->other->Heal(actualDamage);
}

AttackTwoCommand::AttackTwoCommand(Actor* self,  Actor* other) {
	this->self = self;
	this->other = other;
}

void AttackTwoCommand::Execute() {
	srand(time(NULL));
	int damage = rand() % 25 + 0;
	this->actualDamage = damage;
	this->other->Hit(damage);
}
void AttackTwoCommand::Undo() {
	this->other->Heal(actualDamage);
}

HealCommand::HealCommand(Actor* self,  Actor* other) {
	this->self = self;
	this->other = other;
}

void HealCommand::Execute() {
	srand(time(NULL));
	int healAmount = rand() % 15 + 10;
	this->actualHealAmount = healAmount;
	this->self->Heal(healAmount);
}

void HealCommand::Undo() {
	this->self->Hit(actualHealAmount);
}