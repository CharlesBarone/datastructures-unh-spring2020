//
//  main.cpp
//  program3
//
//  Created by Charles Barone on 4/22/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include <iostream>
#include "Runner.hpp"

int main(int argc, const char * argv[]) {
	
	Runner* run = new Runner;
	run->Begin();

	delete run;
	
	return 0;
}
