//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#ifndef ARBEIDSKRAV_ATTACK_H
#define ARBEIDSKRAV_ATTACK_H


class Attack {
public:
    void run();
    bool isReady();

private:
    int damage;
    int cooldown;
};


#endif
