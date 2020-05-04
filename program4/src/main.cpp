//
//  main.cpp
//  program4
//
//  Created by Charles Barone on 5/03/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include <iostream>
#include <chrono>
#include "RBT.hpp"

int main(int argc, const char * argv[]) {
	Node<int>* root = nullptr;
	root = createRBT(0);
	root->color = BLACK;

	std::cout << "Charles Barone Red Black Tree - Data Structures Program 4" << std::endl;
	
	std::cout << "\nEnter Number of nodes to insert into to RBT: ";
	int x;
	std::cin >> x;
	if(x != 0) { //Skip if 0
		for(int i = 1; i <= x; i++) {
			root = insertion(root, i);
		}
	}

	//Not required for the assignment, but this is how my printRBT() is implemented
	//printRBT(root);
	//std::cout << std::endl;

	std::cout << "\nFinished generating Red Black Tree. Begin Timing test to locate last added node." << std::endl;

	std::cout << "\nFind Node: " << x;
 	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	FindX(root, x); //Find last item added to RBT to stay consistent with the timing tests performed in the Unordered Linked List program...
	end = std::chrono::system_clock::now();

	std::chrono::duration<double, std::micro> elapsedTime = end - start;

	std::cout	<< "\nElapsed Time:" << elapsedTime.count() << "μs"
				<< "\n\nRBT Height: " << Height(root) << std::endl;

	return 0;
}