//
//  UnorderedLinkedList.hpp
//  Unordered Linked List
//  Used for generating comparison timings for program4
//
//  Created by Charles Barone on 5/03/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#pragma once

#include <iostream>
#include "UnorderedList.hpp"
#include "Node.hpp"

class UnorderedLinkedList: public UnorderedList{
private:
	int length;
	Node* currentPos; 
	Node* head; 

public:
	
	UnorderedLinkedList(): currentPos{nullptr}, head{nullptr}, length{0}{}
	~UnorderedLinkedList(); 
	void MakeEmpty();
	void PutItem(Item item);
	Item GetItem(int key);
	Item FindItem(Item item);
	void DeleteItem(Item item);
	void ResetList();
	Item GetNextItem();
	int GetLength();

};