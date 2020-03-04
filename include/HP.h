#ifndef HP_H
#define HP_H


class HP {
public:

    explicit HP(int hp, int ac) : m_HP(hp), m_AC(ac) {
        m_maxHP = hp;
    }

    void operator-=(int dmg) {
        m_HP -= dmg;
        if(m_HP < 0) {
            m_HP = 0;
        }
    }

    void operator+=(int hp) {
        m_HP += hp;
    }

    int operator==(int comp) {
        return m_HP == comp;
    }

    bool operator!=(int comp) {
        return m_HP != comp;
    }

    bool operator>=(int comp) {
        return m_HP >= comp;
    }

    bool operator>(int comp) {
        return m_HP > comp;
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
