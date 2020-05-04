//
//  UnorderedList.cpp
//  Unordered Linked List
//  Used for generating comparison timings for program4
//
//  Created by Charles Barone on 5/03/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "UnorderedList.hpp"

std::ostream& operator<<(std::ostream& os, UnorderedList& o){
	o.ResetList();
	os << "List: [";
	for(int i = 0; i < o.GetLength(); ++i){
		os << "(" << o.GetNextItem() << ")";
		if (i < o.GetLength() - 1) os << ", ";
	}
	os << "]";
	return os;
}