//
//  ActorFacotry.hpp
//  program3
//
//  Created by Charles Barone on 4/22/20.
//  Copyright © 2020 Charles Barone. All rights reserved.
//

#pragma once

#include "Actor.hpp"

class ActorFactory {
public:
	static Actor* CreateActor(ActorType actor){
		switch(actor){
			case ActorType::Ghost:
				return new Ghost::Actor(100, "Ghost");
			case ActorType::Knight:
				return new Knight::Actor(100, "Knight");
			case ActorType::Warrior:
				return new Warrior::Actor(100, "Warrior");
		}
	}
};