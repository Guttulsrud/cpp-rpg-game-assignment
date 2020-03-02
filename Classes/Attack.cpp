//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#include <iostream>
#include "Attack.h"

void Attack::run() {

}

bool Attack::isReady() {
    return false;
}

void Attack::toString() {
    std::cout << title << ": " << m_damage << " damage. Cooldown: " << m_coolDown << ".\n";
}

Attack::Attack(std::string &title, int damage, int coolDown) : title(title), m_damage(damage),
                                                               m_coolDown(coolDown) {}

