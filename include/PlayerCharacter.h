#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <string>
#include "Character.h"

class PlayerCharacter : public Character {
public:
    PlayerCharacter(std::string &name, int playerId, class HP hp) : Character(name, playerId, hp) {}

    void promptAction();

    void attackPlayer(int playerId);

    Attack promptAttack();

    void runTurn() override;
};


#endif
