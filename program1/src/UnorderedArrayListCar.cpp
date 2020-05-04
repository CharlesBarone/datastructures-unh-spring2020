//
//  UnorderedArrayListCar.cpp
//  program1
//
//  Created by Charles Barone on 3/5/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "UnorderedArrayListCar.hpp"

using namespace std;

void UnorderedArrayListCar::OutputAvailable(){
    int i = 0;
    for(; i < length; i++) {
        if(data[i].getAvailable() == 1) {
            cout << i+1 << ". " << data[i].getMake() << " " << data[i].getModel();
            
            switch(data[i].getType()) {
                case 0:
                    cout << " (sedan) $";
                    break;
                case 1:
                    cout << " (suv) $";
                    break;
                case 2:
                    cout << " (exotic) $";
                    break;
            }
            
            cout << data[i].getPricePerDay() << "/day" << endl;
            
        } else {
            cout << i+1 << ". Unavailable." << endl;
        }
    }
    
    cout << i+1 << ". Press enter to cancel." << endl;
}

void UnorderedArrayListCar::MakeEmpty(){
    length = 0;
}

void UnorderedArrayListCar::PutItem(Car car){
    data[length++] = car;
}

Car UnorderedArrayListCar::GetItem(Car car){
    for(int i = 0; i < length; ++i){
        if (data[i] == car) {
            return data[i];
        }
    }
    throw "Item not found";
}

Car UnorderedArrayListCar::GetItem(string plateNumber){
    for(int i = 0; i < length; ++i) {
        if(data[i].getPlateNumber() == plateNumber) {
            return data[i];
        }
    }
    throw "Not plateNumber Found!";
}

void UnorderedArrayListCar::DeleteItem(Car car){
    for(int i = 0; i < length; ++i){
        if (data[i] == car){
            data[i] = data[--length];
        }
    }
}

void UnorderedArrayListCar::ResetList(){
    currentPos = 0;
}

Car UnorderedArrayListCar::GetNextItem(){
    if(currentPos < length)
        return data[currentPos++];
    
    throw "Out of Range";
}

int UnorderedArrayListCar::GetLength(){
    return length;
}

UnorderedArrayListCar::~UnorderedArrayListCar(){
    
}

Car& UnorderedArrayListCar::GetItemAtIndex(int index){
    return data[index];
}

ostream& operator<<(ostream& os, UnorderedArrayListCar& o){
    o.ResetList();
    os << "Cars: [";
    for(int i = 0; i < o.GetLength(); ++i){
        os << "(" << o.GetNextItem() << ")";
        if (i < o.GetLength() - 1) os << ", ";
    }
    os << "]";
    return os;
}
