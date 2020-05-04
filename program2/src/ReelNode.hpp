//
//  ReelNode.hpp
//  program2
//
//  Created by Charles Barone on 3/21/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#ifndef ReelNode_hpp
#define ReelNode_hpp

#include <stdio.h>
#include "Item.hpp"

struct ReelNode{
    Item data;
    ReelNode* next;
};

#endif /* ReelNode_hpp */
