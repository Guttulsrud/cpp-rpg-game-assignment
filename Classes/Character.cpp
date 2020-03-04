#include <string>
#include <iostream>
#include "../include/Character.h"

Character::Character(std::string &name, int playerId, class HP hp) : m_name(name), playerId(playerId), HP(hp) {
    addAttack(Attack("Punch", 8, 0, 1));
    addAttack(Attack("Charge", 16, 3, 2));
}

std::vector<Attack> &Character::getAttacks() {
    return m_attacks;
}

std::string Character::getName() {
    return m_name;
}

void Character::addAttack(Attack a) {
    m_attacks.emplace_back(a);
}

void Character::printStatus() {
    std::cout << m_name << ": " << HP.getHP() << "/" << HP.getMaxHP() << "HP - " << HP.getAC() << "AC" << std::endl;
}