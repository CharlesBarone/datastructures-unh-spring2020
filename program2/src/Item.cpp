//
//  Item.cpp
//  program2
//
//  Created by Charles Barone on 3/21/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "Item.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Item& i){
    os << "Item: [" << i.getValue() << "]";
    return os;
}

bool Item::operator< (const Item& other){
    return value < other.value;
}

bool Item::operator== (const Item& other){
    return value == other.value;
}
