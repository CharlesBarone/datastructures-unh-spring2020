//
//  MoveManager.hpp
//  program3
//
//  Created by Charles Barone on 4/22/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#pragma once
#include "Stack.hpp"
#include "BattleMove.hpp"

using namespace std;

class MoveManager {
private:
	Stack<BattleMove*> stack;
public:
	MoveManager():
		stack{Stack<BattleMove*>()}
	{}

	void ExecuteMove(BattleMove* cmd, Actor* self, Actor* other){
		cmd->Execute();
		stack.Push(cmd);
	}

	void UndoLastCommand(){
		if(stack.IsEmpty()){
			cout << "Nothing to undo." << endl;
			return;
		}
		BattleMove* cmd = stack.Top();
		cmd->Undo();
		delete stack.Top();
		stack.Pop();
	}

	~MoveManager(){
		while(!stack.IsEmpty()){
			delete stack.Top();
			stack.Pop();
		}
	}
};