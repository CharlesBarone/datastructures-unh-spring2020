//
//  Car.cpp
//  program1
//
//  Created by Charles Barone on 3/5/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "Car.hpp"

using namespace std;

ostream& operator<<(ostream& os, const Car& i){
    os << "Car: [" << i.getPlateNumber() << "]";
    return os;
}

bool Car::operator< (const Car& other){
    return plateNumber < other.plateNumber;
}

bool Car::operator== (const Car& other){
    return plateNumber == other.plateNumber;
}
