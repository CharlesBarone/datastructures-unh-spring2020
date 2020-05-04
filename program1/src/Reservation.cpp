//
//  Reservation.cpp
//  program1
//
//  Created by Charles Barone on 3/5/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "Reservation.hpp"

using namespace std;

ostream& operator<<(ostream& os, const Reservation& i){
    os << "Reservation: [" << i.getName() << "]";
    return os;
}

bool Reservation::operator< (const Reservation& other){
    return name < other.name;
}

bool Reservation::operator== (const Reservation& other){
    return name == other.name;
}
