//
//  Item.cpp
//  Unordered Linked List
//  Used for generating comparison timings for program4
//
//  Created by Charles Barone on 5/03/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "Item.hpp"

std::ostream& operator<<(std::ostream& os, const Item& i){
	os << "Item[" << i.getKey() << "] = " << i.getValue();
	return os;
}

bool Item::operator< (const Item& other){
	return key < other.key;
}

bool Item::operator== (const Item& other){
	return value == other.value;
}