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

void PlayerCharacter::runTurn(std::vector<PlayerCharacter> &enemies) {

    cout << "It's your turn, " << getName() << "!" << endl;

    promptAction(enemies);


}

int PlayerCharacter::promptAction(std::vector<PlayerCharacter> &enemies) {
    cout << "Who do you want to attack?" << endl << endl;


    // AddCharacter, getCharacters
    for(auto &p : GameManager::getInstance().gameCharacters) {
        //Insert lambda here
        if (p.playerId != this->playerId) {
            std::cout << "Press " << p.playerId << " to attack " << p.getName() << endl;
        }
    }

    int choice;
    cin >> choice;

    // This is to attack given player by ID
    auto test = std::find_if(enemies.begin(), enemies.end(), [](const PlayerCharacter &player){ return player.playerId == 2;});
    //std::cout << test->getName() << endl;

    return 0;
}

void PlayerCharacter::runTurn() {

}


