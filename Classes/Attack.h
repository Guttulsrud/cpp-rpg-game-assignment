//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#ifndef ARBEIDSKRAV_ATTACK_H
#define ARBEIDSKRAV_ATTACK_H


#include <string>

class Attack {
public:
    void run();
    void toString();
    bool isReady();
    std::string title;

private:
    int m_damage;
    int m_coolDown;
};


#endif
