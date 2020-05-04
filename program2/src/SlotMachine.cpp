//
//  SlotMachine.cpp
//  program2
//
//  Created by Charles Barone on 3/21/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "SlotMachine.hpp"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

SlotMachine::SlotMachine() {
    srand((int)time(NULL));
    
    char arr[10] = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', '7'};
    
    random_shuffle(&arr[0], &arr[10]);
    for(int i = 0; i < 10; i++) {
        string s;
        s += arr[i];
        reel1.PutItem(Item(s));
    }
    
    random_shuffle(&arr[0], &arr[10]);
    for(int i = 0; i < 10; i++) {
        string s;
        s += arr[i];
        reel2.PutItem(Item(s));
    }
    
    random_shuffle(&arr[0], &arr[10]);
    for(int i = 0; i < 10; i++) {
        string s;
        s += arr[i];
        reel3.PutItem(Item(s));
    }
}

vector<char> SlotMachine::Spin() {
    srand((int)time(NULL));
    int random1 = (int)(rand() % 100 + 1);
    int random2 = (int)(rand() % 100 + 1);
    int random3 = (int)(rand() % 100 + 1);
    
    reel1.ResetList();
    reel2.ResetList();
    reel3.ResetList();
    
    Item item1;
    for(int i = 0; i < random1-1; i++) {
        item1 = reel1.GetNextItem();
    }
    
    Item item2;
    for(int i = 0; i < random2-1; i++) {
        item2 = reel2.GetNextItem();
    }
    
    Item item3;
    for(int i = 0; i < random3-1; i++) {
        item3 = reel3.GetNextItem();
    }
    
    cout <<  " --------------\n| Slot Machine |\n -------------- \n|    ";
    
    cout << item1.getValue() << " " << item2.getValue() << " " << item3.getValue() << "     |\n|    ";
    
    vector<char> vec;
    
    item1 = reel1.GetNextItem();
    item2 = reel2.GetNextItem();
    item3 = reel3.GetNextItem();
    
    vec.push_back(item1.getValue()[0]);
    vec.push_back(item2.getValue()[0]);
    vec.push_back(item3.getValue()[0]);
    
    cout << item1.getValue() << " " << item2.getValue() << " " << item3.getValue() << "     |\n|    ";
    
    cout << reel1.GetNextItem().getValue() << " " << reel2.GetNextItem().getValue() << " " << reel3.GetNextItem().getValue() << "     |\n -------------- " << endl;
    
    return vec;
}
