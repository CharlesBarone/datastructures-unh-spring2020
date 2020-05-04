//
//  UnorderedArrayListReservation.hpp
//  program1
//
//  Created by Charles Barone on 3/5/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#ifndef UnorderedArrayListReservation_hpp
#define UnorderedArrayListReservation_hpp

#define MAX_ELEMS 100

#include <iostream>
#include <string>
#include "Reservation.hpp"

using namespace std;

class UnorderedArrayListReservation {
private:
    int currentPos;
    int length;
    Reservation data[MAX_ELEMS];
    
public:
    UnorderedArrayListReservation():currentPos{-1}, length{0}{};
    void MakeEmpty();
    void PutItem(Reservation reservation);
    Reservation GetItem(Reservation reservation);
    Reservation GetItem(string name);
    void DeleteItem(Reservation Reservation);
    void ResetList();
    Reservation GetNextItem();
    int GetLength();
    ~UnorderedArrayListReservation();
    
};
ostream& operator<<(ostream& os, UnorderedArrayListReservation& i);

#endif /* UnorderedArrayListReservation_hpp */
