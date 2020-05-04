//
//  Car.hpp
//  program1
//
//  Created by Charles Barone on 3/5/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#ifndef Car_hpp
#define Car_hpp

#include <iostream>
#include <string>
#include "enum.hpp"

using namespace std;

class Car{
    
private:
    string plateNumber;
    string make;
    string model;
    vehicleType type;
    double pricePerDay;
    bool isAvailable = true;
    
public:
    Car(){}
    Car(string plateNumber, string make, string model, vehicleType type, double pricePerDay, bool isAvailable):
        plateNumber{plateNumber},
        make{make},
        model{model},
        type{type},
        pricePerDay{pricePerDay},
        isAvailable{isAvailable}
    {}
    
    string getPlateNumber()const{ return plateNumber; }
    string getModel()const{ return model; }
    string getMake()const{ return make; }
    vehicleType getType()const{ return type; }
    double getPricePerDay()const{ return pricePerDay; }
    bool operator< (const Car& other);
    bool operator== (const Car& other);
    bool getAvailable(){ return isAvailable; }
    
    void setAvailable(bool available) {
        isAvailable = available;
    }
};
ostream& operator<<(ostream& os, const Car& i);

#endif /* Car_hpp */
