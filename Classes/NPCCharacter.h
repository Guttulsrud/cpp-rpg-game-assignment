//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#ifndef ARBEIDSKRAV_NPCCHARACTER_H
#define ARBEIDSKRAV_NPCCHARACTER_H


#include <string>
#include "Character.h"

class NPCCharacter : Character{
public:
    explicit NPCCharacter(std::string &name, int playerId) : Character(name, playerId) {}

    void runTurn();
};


#endif //ARBEIDSKRAV_NPCCHARACTER_H
