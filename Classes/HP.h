//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#ifndef ARBEIDSKRAV_HP_H
#define ARBEIDSKRAV_HP_H


class HP {

public:

    explicit HP(int hp, int ac) : m_HP(hp), m_AC(ac) {
        m_maxHP = hp;
    }

    void operator-=(int dmg) {
        m_HP -= dmg;
    }

    void operator+=(int hp) {
        m_HP += hp;
    }

    void operator==(int hp) {
        m_HP = hp;
    }


    int getHP();

    int getMaxHP();

    int getAC();

private:
    int m_HP;
    int m_maxHP;
    int m_AC;
};


#endif
