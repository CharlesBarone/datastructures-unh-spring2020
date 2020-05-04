//
//  IMove.hpp
//  program3
//
//  Created by Charles Barone on 4/22/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#pragma once

class IMove {
public: 
	void virtual Execute()=0;
	void virtual Undo()=0;
	virtual ~IMove() {};
};