//
//  PayoutTable.cpp
//  program2
//
//  Created by Charles Barone on 3/21/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#include "PayoutTable.hpp"

short PayoutTable::GetPayout(char c) {
    switch(c) {
        case 'A':
            return 7;
            break;
        case 'B':
            return 20;
            break;
        case 'C':
            return 75;
            break;
        case '7':
            return 600;
            break;
    }
    return 0;
}
