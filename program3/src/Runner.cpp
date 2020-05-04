//
//  Runner.cpp
//  program3
//
//  Created by Charles Barone on 4/22/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "Runner.hpp"

using namespace std;

void Runner::Begin() {
	vector<Actor*> actors;
	MoveManager mgr;

	while(actors.size() != 2) {
		if(actors.size() == 1)
			cout << "Select a player:\n1) Ghost\n2) Knight\n3) Warrior\n";
		else
			cout <<"Select an opponent:\n1) Ghost\n2) Knight\n3) Warrior\n";
		
		int choice;
		cin >> choice;
		cout << "You selected: " << choice << endl;
		switch((ActorType)choice) {
			case ActorType::Ghost1:
				actors.push_back(new Ghost("Ghost", 100));
				break;
			case ActorType::Knight1:
				actors.push_back(new Knight("Knight", 100));
				break;
			case ActorType::Warrior1:
				actors.push_back(new Warrior("Warrior", 100));
				break;
			default:
				cout << "\nPlease enter a valid selection!\n";
				break;
		}
	}

	cout << "Beginning match!\n";
	cout << actors[0]->getName() << ", (" << actors[0]->getHealth() << ")\n";
	cout << actors[1]->getName() << ", (" << actors[1]->getHealth() << ")\n-----------------------------------\n";

	while(!actors[0]->IsDead() && !actors[1]->IsDead()) {
		cout << "Choose move:\n1) P1 -> P2\n2) P2 -> P1\n3) Undo\n";
		int choice;
		cin >> choice;

		srand(time(NULL));
		int random = rand() % 2 + 1;

		switch(choice) {
			case 1: // P1 -> P2
				actors[0]->DoMove(mgr, actors[0]->GetMoves()[random], actors[1]);
				break;
			case 2: // P2 -> P1
				actors[1]->DoMove(mgr, actors[1]->GetMoves()[random], actors[0]);
				break;
			case 3:
				mgr.UndoLastCommand();
				break;
			default:
				cout << "\nPlease enter a valid selection!\n";
				break;
		}

		cout << "[Player: " << actors[0]->getName() << ", (" << actors[0]->getHealth() << ")][Opponent: " << actors[1]->getName() << ", (" << actors[1]->getHealth() << ")]\n";
	}

	cout << "Winner is: " << (actors[0]->IsDead()? "Opponent" : "Player") << endl;
}