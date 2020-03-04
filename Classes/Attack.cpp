#include <iostream>
#include "../include/Attack.h"
#include <utility>


bool Attack::isReady() {
    return this->m_coolDown == 0;
}

Attack::Attack(std::string title, int damage, int coolDown, int id) : title(std::move(title)), m_damage(damage),
                                                                      m_coolDown(coolDown), m_id(id) {
    m_maxCoolDown = m_coolDown;
}

