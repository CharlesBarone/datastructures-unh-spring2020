//
//  BattleMoveFactory.hpp
//  program3
//
//  Created by Charles Barone on 4/22/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#pragma once

#include "enums.hpp"
#include "Actor.hpp"
#include "BattleMove.hpp"

using namespace std;

class MoveFactory{
	public:
		static BattleMove* BuildMove(MoveType type, Actor* self, Actor* other){
			BattleMove* m; 
			switch(type){
				case MoveType::AttackOne:
					m = new AttackOneCommand(self, other);
					break;
				case MoveType::AttackTwo:
					m = new AttackTwoCommand(self, other);
					break; 
				case MoveType::Heal:
					m =  new HealCommand(self, other);
					break;
				default: 
					cerr << "Unexistent: " << (int)type;
					throw "Non-existent move";
			}
			return m; 
		}
};