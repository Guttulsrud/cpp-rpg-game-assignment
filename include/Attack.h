#ifndef ATTACK_H
#define ATTACK_H

class Attack {
public:

    Attack(std::string title, int damage, int coolDown, int Id);

    bool isReady();

    int m_coolDown;
    int m_id;
    int m_maxCoolDown;
    int m_damage{};
    std::string title;

};


#endif
