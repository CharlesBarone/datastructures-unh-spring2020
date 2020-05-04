//
//  main.cpp
//  Unordered Linked List
//  Used for generating comparison timings for program4
//
//  Created by Charles Barone on 5/03/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include <iostream>
#include <chrono>
#include "UnorderedLinkedList.hpp"

int main(int argc, const char * argv[]) {

	std::cout << "Charles Barone - Unordered Linked Listed for Timing Collection for Programming Assgingment 4." << std::endl;

	UnorderedList* list = (UnorderedList*)new UnorderedLinkedList();

	std::cout << "\nEnter Number of Items to randomly generate and add to list: ";
	int x;
	std::cin >> x;

	srand(time(NULL));

	int lastValue;
         
	for(int i = 0; i < x; i++) {
		int random = rand() % 1000000 + 1;
		list->PutItem(Item(i, std::to_string(random)));
		lastValue = random;
	}

	//Prints the contents of UnorderedArrayList() list
	//std::cout << "Items: " << *list << std::endl;

	std::cout << "\nFinished Generating List. Begin Timing test to locate an index of the list." << std::endl;

	std::cout << "Find Item with Value: " << lastValue << std::endl;

	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	std::cout << "\nFound Item:\n\t" << list->FindItem(Item(0, std::to_string(lastValue))) << std::endl; //Find last item added to Unordered Linked List to stay consistent with the timing tests performed in the Red Back Tree program...
	end = std::chrono::system_clock::now();

	std::chrono::duration<double, std::micro> elapsedTime = end - start;

	std::cout << "\nElapsed Time:" << elapsedTime.count() << "μs" << std::endl;

	delete list;
	return 0;
}