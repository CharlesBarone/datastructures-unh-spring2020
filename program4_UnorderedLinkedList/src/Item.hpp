//
//  Item.hpp
//  Unordered Linked List
//  Used for generating comparison timings for program4
//
//  Created by Charles Barone on 5/03/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#pragma once

#include <iostream>
#include <string>

class Item {
private:
		int key;
		std::string value;

public:
		Item(){}
		Item(int key, std::string value):
				key{key},
				value{value}
		{}

		int getKey() const{ return key; }
		std::string getValue() const { return value; }
		bool operator< (const Item& other);
		bool operator== (const Item& other);
};
std::ostream& operator<<(std::ostream& os, const Item& i);