//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#include <iostream>
#include "Attack.h"
#include <iomanip>

using namespace std;

bool Attack::isReady() {
    return this->m_coolDown == 0;
}

void Attack::toString() {
    std::cout << title << ": " << std::endl << "Damage: " << m_damage << "" << std::endl << "Cooldown: " << m_coolDown
              << "\n\n";

}

Attack::Attack(std::string &title, int damage, int coolDown) : title(title), m_damage(damage), m_coolDown(coolDown) {
    m_maxCoolDown = m_coolDown;
}

void Attack::run() {
    if (m_maxCoolDown > m_coolDown) {
        m_coolDown = m_maxCoolDown+1;
    }




}

