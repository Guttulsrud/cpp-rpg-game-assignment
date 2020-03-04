#ifndef ARBEIDSKRAV_CHARACTER_H
#define ARBEIDSKRAV_CHARACTER_H


#include <vector>
#include "HP.h"
#include "Attack.h"


class Character {
public:
     Character(std::string &name, int playerId, HP hp);

    virtual void runTurn() = 0;

    std::string getName();

    std::vector<Attack> &getAttacks();

    int playerId;
    HP HP;

    void printStatus();

    void addAttack(Attack a);

private:
    std::vector<Attack> m_attacks;

protected:
    std::string m_name;

};


#endif
