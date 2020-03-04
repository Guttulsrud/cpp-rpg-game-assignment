//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#include <iostream>
#include <algorithm>
#include "PlayerCharacter.h"
#include "GameManager.h"

using std::cout;
using std::cin;
using std::endl;

void PlayerCharacter::runTurn() {
    cout << "\nIt's your turn, " << getName() << "!" << endl;
    promptAction();

    for(auto &a : getAttacks()) {
        if (a.m_coolDown > 0) {
            a.m_coolDown--;
        }
    }
}


void PlayerCharacter::promptAction() {
    cout << "Who do you want to attack?" << endl << endl;

    std::vector<PlayerCharacter> characters = GameManager::getInstance().gameCharacters;


    for (auto &p : characters) {
        if (p.playerId != this->playerId) {
            std::cout << "Press " << p.playerId << " to attack " << p.getName() << endl;
        }
    }

    int choice;
    cin >> choice;
    attackPlayer(choice);


}

Attack PlayerCharacter::promptAttack() {
    std::cout << std::endl << "Pick an attack" << std::endl;
    std::vector<Attack> &attacks = getAttacks();

    bool validChoice = false;
    int attackChoice = 1;

    while (!validChoice) {
        for (int i = 0; i < attacks.size(); i++) {
            cout << "Press " << i + 1 << " for ";
            attacks[i].toString();
            cout << "-----------------------------------" << std::endl;

        }

        std::cin >> attackChoice;
        Attack &attack = attacks[attackChoice - 1];


        if (attack.isReady()) {
            attack.run();
            validChoice = true;
        } else {
            std::cout << "Attack is not ready yet. Pick another.." << std::endl;
        }
    }

    return attacks[attackChoice - 1];
}


void PlayerCharacter::attackPlayer(int playerId) {
    Attack attack = promptAttack();

    PlayerCharacter &player = GameManager::getInstance().getCharacters()[playerId - 1];
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
              << " damage! " << endl;
    player.takeDamage(damage);
}


