//
//  UnorderedArrayListCar.hpp
//  program1
//
//  Created by Charles Barone on 3/5/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#ifndef UnorderedArrayListCar_hpp
#define UnorderedArrayListCar_hpp

#define MAX_ELEMS 100

#include <iostream>
#include <string>
#include "Car.hpp"

using namespace std;

class UnorderedArrayListCar {
private:
    int currentPos;
    int length;
    Car data[MAX_ELEMS];
    
public:
    UnorderedArrayListCar():currentPos{-1}, length{0}{};
    void MakeEmpty();
    void PutItem(Car car);
    Car GetItem(Car car);
    Car GetItem(string plateNumber);
    void DeleteItem(Car Car);
    void ResetList();
    Car GetNextItem();
    int GetLength();
    ~UnorderedArrayListCar();
    void OutputAvailable();
    Car& GetItemAtIndex(int index);
    
    
};
ostream& operator<<(ostream& os, UnorderedArrayListCar& i);

#endif /* UnorderedArrayListCarCar_hpp */
