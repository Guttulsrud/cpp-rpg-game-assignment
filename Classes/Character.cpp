//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#include <string>
#include "Character.h"
#include "PlayerCharacter.h"

Character::Character(std::string &name, int playerId, int playerClass) :  m_name(name), playerId(playerId), m_class(playerClass) {
}

void Character::hit() {

}

void Character::addAttack(Attack &a) {
    m_attacks.emplace_back(a);
}

std::vector<Attack> Character::getAttacks() {
    return this->m_attacks;
}

int Character::getHp() {
    return 0;
}

std::string Character::getName() {
    return m_name;
}




