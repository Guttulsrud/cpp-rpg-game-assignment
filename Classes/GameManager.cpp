//
// Created by Håkon Guttulsrud on 05.02.2020.
//

#include "windows.h"
#include <iostream>
#include <algorithm>
#include "GameManager.h"
#include "PlayerCharacter.h"
#include "NPCCharacter.h"


void GameManager::startGame() {


    std::cout << "Input number of players" << std::endl;
    int numberOfPlayers;
    std::cin >> numberOfPlayers;

    for (int i = 1; i < numberOfPlayers + 1; i++) {
        std::string name;
        int playerClass;
        std::cout << "Player " << i << ", what is your name?" << std::endl;
        std::cin >> name;

        std::cout << name << ", what is your class?" << std::endl;
        std::cout << "Press 1 for Fighter" << std::endl;
        std::cout << "Press 2 for Druid" << std::endl;
        std::cout << "Press 3 for Kek" << std::endl;
        std::cin >> playerClass;
        gameCharacters.emplace_back(PlayerCharacter(name, i, playerClass, 100));
    }
}


void GameManager::run() {
    int round = 1;
    std::string myKek = "Main Attack";
    std::string myKek2 = "Special Attack";

    std::vector<PlayerCharacter> players = getCharacters();

    gameCharacters[0].addAttack(Attack(myKek, 15, 0));
    gameCharacters[1].addAttack(Attack(myKek, 15, 0));
    gameCharacters[0].addAttack(Attack(myKek2, 15, 0));
    gameCharacters[1].addAttack(Attack(myKek2, 15, 0));

    while (getCharacters().size() > 1) {
        std::cout << "\nRound " << round << " started. " << std::endl << "Stats: " << std::endl;
        for (auto &p : getCharacters()) {
            p.printStatus();
        }

        for (auto &p : gameCharacters) {
            p.runTurn();
        }

        round++;

    }
}

void GameManager::addCharacter(PlayerCharacter const &p) {
    gameCharacters.emplace_back(p);
}

