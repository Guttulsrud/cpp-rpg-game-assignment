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
    explicit Character(std::string &name, int playerId, int playerClass, int hp);

    virtual void runTurn() = 0;

    void hit();

    void addAttack(Attack a);

    std::vector<Attack> getAttacks();

    int getHp();

    std::string getName();

    int playerId;
    int m_class;

    int m_hitPoints;
private:
    std::vector<Attack> m_attacks;
protected:
    std::string m_name;

    void addAttack(Attack &a);
};


#endif
