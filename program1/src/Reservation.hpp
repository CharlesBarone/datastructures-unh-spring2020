//
//  Reservation.hpp
//  program1
//
//  Created by Charles Barone on 3/5/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#ifndef Reservation_hpp
#define Reservation_hpp

#include <iostream>
#include <string>
using namespace std;

class Reservation{
    
private:
    string name; //key
    string vehicleRented;
    
public:
    Reservation(){}
    Reservation(string name, string vehicleRented):
        name{name},
        vehicleRented{vehicleRented}
    {}
    
    string getName()const{ return name; }
    string getVehicleRented() { return vehicleRented; }
    bool operator< (const Reservation& other);
    bool operator== (const Reservation& other);
};
ostream& operator<<(ostream& os, const Reservation& i);

#endif /* Reservation_hpp */
