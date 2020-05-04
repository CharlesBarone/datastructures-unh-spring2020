//
//  Game.cpp
//  program2
//
//  Created by Charles Barone on 3/21/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "Game.hpp"

using namespace std;

void Game::begin() {
    
    SlotMachine* slotMachine = new SlotMachine();
    PayoutTable* payoutTable = new PayoutTable();
    
    vector<char> vec;
    short balance = 100;
    bool run = true;
    
    while(run) {
        if(balance < 1) {
            cout << "\n\n\nOh no! It looks like you ran out of money! Come back again later!";
            run = false;
        } else {
            cout << "Welcome to the Slot Machine!\nCurrent Balance: $" << balance << "\nReminder, each spin costs $1!\nType 1 to spin or 0 to quit: ";
            int input;
            cin >> input;
            if(input == 1) {
                vec = slotMachine->Spin();
                balance -= 1;
                
                if(vec[0] == vec[1] && vec[0] == vec[2]) {
                    if(vec[0] == '7') {
                        cout << "JACKPOT!" << endl;
                    }
                    
                    short payout = payoutTable->GetPayout(vec[0]);
                    balance += payout;
                    cout << "$" << payout << " was added to your balance! Your new balance is $" << balance << "." << endl;
                }
            } else if(input == 0) {
                run = false;
            } else {
                cout << "Invalid input.\n" << endl;
            }
        }
    }
}
