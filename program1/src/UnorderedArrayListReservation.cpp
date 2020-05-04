//
//  UnorderedArrayListReservation.cpp
//  program1
//
//  Created by Charles Barone on 3/5/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "UnorderedArrayListReservation.hpp"

using namespace std;

void UnorderedArrayListReservation::MakeEmpty(){
    length = 0;
}

void UnorderedArrayListReservation::PutItem(Reservation reservation){
    data[length++] = reservation;
}

Reservation UnorderedArrayListReservation::GetItem(Reservation reservation){
    for(int i = 0; i < length; ++i){
        if (data[i] == reservation) {
            return data[i];
        }
    }
    throw "Item not found";
}

Reservation UnorderedArrayListReservation::GetItem(string name){
    for(int i = 0; i < length; ++i) {
        if(data[i].getName() == name) {
            return data[i];
        }
    }
    throw "Not plateNumber Found!";
}

void UnorderedArrayListReservation::DeleteItem(Reservation reservation){
    for(int i = 0; i < length; ++i){
        if (data[i] == reservation){
            data[i] = data[--length];
        }
    }
}

void UnorderedArrayListReservation::ResetList(){
    currentPos = 0;
}

Reservation UnorderedArrayListReservation::GetNextItem(){
    if(currentPos < length)
        return data[currentPos++];
    
    throw "Out of Range";
}

int UnorderedArrayListReservation::GetLength(){
    return length;
}

UnorderedArrayListReservation::~UnorderedArrayListReservation(){
    
}

ostream& operator<<(ostream& os, UnorderedArrayListReservation& o){
    o.ResetList();
    os << "Reservations: [";
    for(int i = 0; i < o.GetLength(); ++i){
        Reservation r = o.GetNextItem();
        os << "(Reservation: [" << r.getName() << "], Car: [" << r.getVehicleRented() << "])";
        if (i < o.GetLength() - 1) os << ", ";
    }
    os << "]";
    return os;
}
