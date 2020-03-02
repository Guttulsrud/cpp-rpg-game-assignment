//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#ifndef ARBEIDSKRAV_ATTACK_H
#define ARBEIDSKRAV_ATTACK_H


#include <string>

class Attack {
public:
    explicit Attack(std::string &title, int damage, int coolDown);

    void run();

    void toString();

    bool isReady();

    int m_coolDown{};
    int m_damage{};
    std::string title;

};


#endif
