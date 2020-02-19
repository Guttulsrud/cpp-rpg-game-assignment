//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#include <string>
#include "Character.h"
#include "PlayerCharacter.h"

Character::Character(std::string &name, int playerId) :  m_name(name), playerId(playerId) {
}

void Character::hit() {

}

void Character::addAttack() {

}

std::vector<Attack> Character::getAttacks() {
    return std::vector<Attack>();
}

int Character::getHp() {
    return 0;
}

std::string Character::getName() {
    return m_name;
}




