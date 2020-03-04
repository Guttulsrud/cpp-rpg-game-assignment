#include <iostream>
#include "../include/PlayerCharacter.h"
#include "../include/GameManager.h"

void PlayerCharacter::runTurn() {
    std::cout << "\nIt's your turn, " << getName() << "!" << std::endl;
    promptAction();

    for (auto &a : getAttacks()) {
        if (a.m_coolDown > 0) {
            a.m_coolDown--;
        }
    }
}



void PlayerCharacter::promptAction() {
    std::cout << "Who do you want to attack?" << std::endl << std::endl;

    for (auto &p : GameManager::getCharacters()) {
        if (p.playerId != this->playerId) {
            std::cout << "Press " << p.playerId << " to attack " << p.getName() << std::endl;
        }
    }

    int choice;
    std::cin >> choice;
    attackPlayer(choice);
}

Attack PlayerCharacter::promptAttack() {
    std::cout << std::endl << "\t Pick an attack!" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    std::vector<Attack> &attacks = getAttacks();

    bool validChoice = false;
    int attackChoice = 1;

    while (!validChoice) {
        for (auto &a : attacks) {
            std::cout << "Press " << a.m_id << " for ";
            std::cout << a.title << ": " << std::endl << "Damage: " << a.m_damage << "" << std::endl << "Cooldown: " << a.m_coolDown
                      << "\n";
            std::cout << "-----------------------------------" << std::endl;

        }

        std::cin >> attackChoice;
        Attack &attack = attacks[attackChoice - 1];

        if (attack.isReady()) {
            if (attack.m_maxCoolDown > attack.m_coolDown) {
                attack.m_coolDown = attack.m_maxCoolDown + 1;
            }
            validChoice = true;
        } else {
            std::cout << "Attack is not ready yet. Pick another.." << std::endl;
        }
    }

    return attacks[attackChoice - 1];
}


void PlayerCharacter::attackPlayer(int playerId) {
    Attack attack = promptAttack();

    PlayerCharacter &player = GameManager::getCharacters()[playerId - 1];
    int playerAc = player.HP.getAC();
    int attackDamage = attack.m_damage;
    int damage;

    if (playerAc > attackDamage) {
        damage = 0;
    } else {
        damage = attackDamage - playerAc;
    }

    std::cout << getName() << " attacked " << player.getName() << " with " << attack.title << "("
              << attackDamage << "dmg). "
              << player.getName() << " has " << playerAc << "AC and took " << damage
              << " damage! " << std::endl;
    player.HP -= damage;
}


