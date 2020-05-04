//
//  Node.hpp
//  Unordered Linked List
//  Used for generating comparison timings for program4
//
//  Created by Charles Barone on 5/03/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#pragma once

#include "Item.hpp"

struct Node{
	Item data;
	Node* next;
};