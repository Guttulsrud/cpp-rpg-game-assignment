//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#ifndef ARBEIDSKRAV_PLAYERCHARACTER_H
#define ARBEIDSKRAV_PLAYERCHARACTER_H

#include <string>
#include "Character.h"

class PlayerCharacter : public Character {
public:
    explicit PlayerCharacter(std::string &name, int playerId) : Character(name, playerId) {}

    void runTurn(std::vector<PlayerCharacter> &enemies);
    void runTurn() override;
    int promptAction(std::vector<PlayerCharacter> &vector);
};


#endif
