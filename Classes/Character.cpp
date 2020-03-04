//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#include <string>
#include <iostream>
#include "Character.h"

Character::Character(std::string &name, int playerId, class HP hp) : m_name(name), playerId(playerId), HP(hp) {}


std::vector<Attack> &Character::getAttacks() {
    return m_attacks;
}

std::string Character::getName() {
    return m_name;
}

void Character::addAttack(Attack &a) {
    m_attacks.emplace_back(a);
}

void Character::takeDamage(int dmg) {
    HP -= dmg;
}

void Character::printStatus() {
    std::cout << m_name << ": " << HP.getHP() << "/" << HP.getMaxHP() << "HP - " << HP.getAC() << "AC" << std::endl;
}




