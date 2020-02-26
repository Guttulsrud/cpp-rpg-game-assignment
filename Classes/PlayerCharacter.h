//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#ifndef ARBEIDSKRAV_PLAYERCHARACTER_H
#define ARBEIDSKRAV_PLAYERCHARACTER_H

#include <string>
#include "Character.h"

class PlayerCharacter : public Character {
public:
    explicit PlayerCharacter(std::string &name, int playerId, int playerClass) : Character(name, playerId, playerClass) {}

    void runTurn();
    int promptAction();
    void printStatus();
};


#endif
