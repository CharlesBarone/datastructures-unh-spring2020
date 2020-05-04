//
//  SlotMachine.hpp
//  program2
//
//  Created by Charles Barone on 3/21/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#ifndef SlotMachine_hpp
#define SlotMachine_hpp

#include <stdio.h>
#include "Reel.hpp"
#include "PayoutTable.hpp"
#include <vector>

class SlotMachine {
private:
    Reel reel1;
    Reel reel2;
    Reel reel3;
public:
    SlotMachine();
    vector<char> Spin();
    
};

#endif /* SlotMachine_hpp */
