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

    cout << "It's your turn, " << getName() << "!" << endl;
    promptAction();


}

int PlayerCharacter::promptAction() {
    cout << "Who do you want to attack?" << endl << endl;

    std::vector<PlayerCharacter> characters = GameManager::getInstance().gameCharacters;


    for (auto &p : characters) {
        if (p.playerId != this->playerId) {
            std::cout << "Press " << p.playerId << " to attack " << p.getName() << endl;
        }
    }

    int choice;
    cin >> choice;

    auto playerToAttack = std::find_if(characters.begin(), characters.end(),[choice](const PlayerCharacter &player) { return player.playerId == choice; });


    std::cout << "Pick an attack" << std::endl;
    std::vector<Attack> at= getAttacks();
    for(auto &a : at) {

    }
    std::cout << "You attacked " <<  playerToAttack->getName() << endl;

    return 0;
}

void PlayerCharacter::printStatus() {
    std::cout << this->m_name << ": " << this->m_hitPoints << "/100HP" << std::endl;

}


