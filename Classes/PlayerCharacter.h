//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#ifndef ARBEIDSKRAV_PLAYERCHARACTER_H
#define ARBEIDSKRAV_PLAYERCHARACTER_H

#include <string>
#include "Character.h"

class PlayerCharacter : public Character {
public:
    explicit PlayerCharacter(std::string &name, int playerId, int playerClass, int hp) : Character(name, playerId,
                                                                                                   playerClass, hp) {}

    void runTurn();

    void promptAction();

    void printStatus();

    void takeDamage(int dmg);

    PlayerCharacter getPlayerById(int id);

    void attackPlayer(int playerId);
};


#endif
