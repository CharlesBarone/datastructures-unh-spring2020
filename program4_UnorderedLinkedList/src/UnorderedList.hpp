//
//  UnorderedList.hpp
//  Unordered Linked List
//  Used for generating comparison timings for program4
//
//  Created by Charles Barone on 5/03/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#pragma once

#include <iostream>
#include <string.h>
#include "Item.hpp"

class UnorderedList{
public:
	virtual void MakeEmpty()=0;
	virtual void PutItem(Item item)=0;
	virtual Item GetItem(int key)=0;
	virtual Item FindItem(Item item)=0;
	virtual void DeleteItem(Item item)=0;
	virtual void ResetList()=0;
	virtual Item GetNextItem()=0;
	virtual int GetLength()=0;
	virtual ~UnorderedList(){}
};

std::ostream& operator<<(std::ostream& os, UnorderedList& o);