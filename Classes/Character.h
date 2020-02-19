//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#ifndef ARBEIDSKRAV_CHARACTER_H
#define ARBEIDSKRAV_CHARACTER_H


#include <vector>
#include "HP.h"
#include "Attack.h"

class Character {
public:
    explicit Character(std::string& name, int playerId);

    virtual void runTurn() = 0;
    void hit();
    void addAttack();
    std::vector<Attack> getAttacks();
    int getHp();
    std::string getName();
    int playerId;

private:
    std::vector<Attack> m_attacks;
    std::string m_name;
    int m_hitPoints = 0;
};


#endif
