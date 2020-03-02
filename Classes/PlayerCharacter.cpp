//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#include <iostream>
#include <algorithm>
#include "PlayerCharacter.h"
#include "GameManager.h"
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void PlayerCharacter::runTurn() {
    cout << "\nIt's your turn, " << this->getName() << "!" << endl;
    promptAction();


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

void PlayerCharacter::printStatus() {
    std::cout << this->m_name << ": " << this->m_hitPoints << "/100HP" << std::endl;

}

void PlayerCharacter::takeDamage(int dmg) {
    this->m_hitPoints -= dmg;
}


PlayerCharacter  PlayerCharacter::getPlayerById(int id) {
    std::vector<PlayerCharacter> characters = GameManager::getInstance().gameCharacters;

    auto playerToAttack = std::find_if(characters.begin(), characters.end(),
                                       [id](const PlayerCharacter &player) {
                                           return player.playerId == id;
                                       });
    return *playerToAttack;
}

void PlayerCharacter::attackPlayer(int playerId) {

    PlayerCharacter &playerToAttack = GameManager::getInstance().getCharacters()[playerId-1];

    std::cout << std::endl << "Pick an attack" << std::endl;
    std::vector<Attack> attacks = getAttacks();

    for (int i = 0; i < attacks.size(); i++) {
        cout << "Press " << i << " to use: ";
        attacks[i].toString();

    }

    int wChoice;
    std::cin >> wChoice;

    int attackDmg = attacks[wChoice].m_damage;
    //TODO: Find "true" random instead of rand! <random>

    std::srand(time(0));
    int random;
    int random2;
    random = std::rand() % 10 + 1;
    random2 = std::rand() % 2 + 1;

    int dmg;
    if (random2 < 2) {
        dmg = attackDmg - random;
    } else {
        dmg = attackDmg + random;
    }

    std::cout << getName() << " attacked " << playerToAttack.getName() << " and dealt "
              << dmg << " damage! " << endl;
    playerToAttack.takeDamage(dmg);
}


