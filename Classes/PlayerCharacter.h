//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#ifndef ARBEIDSKRAV_PLAYERCHARACTER_H
#define ARBEIDSKRAV_PLAYERCHARACTER_H

#include <string>
#include "Character.h"

class PlayerCharacter : public Character {
public:
    PlayerCharacter(std::string &name, int playerId, class HP hp) : Character(name, playerId, hp) {}

    void promptAction();

    void attackPlayer(int playerId);

    void runTurn();

    Attack promptAttack();
};


#endif
